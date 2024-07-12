from flask import Flask, render_template, redirect, url_for, flash
import os
import glob
import secrets

CAMERA_FOLDER_PATH = "/home/pi/camera"
LOG_FILE_NAME = CAMERA_FOLDER_PATH + "/log/photo_logs.txt"
photo_counter = 0

app = Flask(__name__, static_url_path=CAMERA_FOLDER_PATH, static_folder=CAMERA_FOLDER_PATH)

# Set the secret key to a sufficiently random value
app.secret_key = secrets.token_hex(16)

def get_latest_photo_info():
    message = ""
    line_counter = 0
    last_photo_file_name = ""
    if os.path.exists(LOG_FILE_NAME):
        with open(LOG_FILE_NAME, "r") as f:
            for line in f:
                line_counter += 1
                last_photo_file_name = line.strip()
        global photo_counter
        difference = line_counter - photo_counter
        message = f"{difference} photos were taken since you last checked."
        photo_counter = line_counter
    else:
        message = "No photos found."
    return {
        "message": message,
        "latest_photo": last_photo_file_name
    }

@app.route("/")
def index():
    return render_template('index.html')

@app.route("/check-movement")
def check_movement():
    photo_info = get_latest_photo_info()
    return render_template('secure_house.html', message=photo_info["message"], latest_photo=photo_info["latest_photo"])

@app.route('/clean-camera-directory')
def clean_camera_directory():
    camera_directory = CAMERA_FOLDER_PATH
    jpg_files = sorted(glob.glob(os.path.join(camera_directory, '*.jpg')), key=os.path.getctime)

    if len(jpg_files) > 1:
        latest_file = jpg_files[-1]
        files_to_delete = jpg_files[:-1]
        
        for file_path in files_to_delete:
            os.remove(file_path)
        
        flash(f"Deleted {len(files_to_delete)} files, kept the latest file: {os.path.basename(latest_file)}.")
    elif len(jpg_files) == 1:
        latest_file = jpg_files[0]
        flash(f"Only one file found, kept the file: {os.path.basename(latest_file)}.")
    else:
        flash("No files to delete.")

    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

