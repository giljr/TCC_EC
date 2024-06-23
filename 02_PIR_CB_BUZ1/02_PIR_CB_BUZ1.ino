/*
  Project : Arduino Start Up Project
  Ino File: 02_PIR_CB_BUZ1.ino
  link: https://rainmaker.espressif.com/docs/get-started.html

   Objective: 
      
      This example demonstrates the ESP RainMaker integration with a standard Motion Sensor device using an ESP32.
      This is the node that sends informations for mobile.
      Code for BUZZER N1

                    
   Authors:     OLIVEIRA, Gilberto Jr.
   
   Hardware:    Development Boards:
                  WiFi LoRa 32(V2) https://heltec.org/project/wifi-lora-32-v3/   
                  Produced by Heltec Automation                
   
   Software:    Arduino IDE
                                
   Connections: PIR GPIO 16
                
   Date:   Jun 2024
*/

#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include "AppInsights.h"

#define DEFAULT_POWER_MODE true
const char *service_name = "PROV_1234";
const char *pop = "abcd1234";

// GPIO for motion sensor
#if CONFIG_IDF_TARGET_ESP32C3
static int gpio_motion_sensor = 7;
#else
// GPIO for virtual device
static int gpio_motion_sensor = 16;
#endif

/* Variable for reading pin status*/
bool motion_detected = false;

// The framework provides some standard device types like switch, lightbulb, fan, temperature sensor.
static Device *my_motion_sensor = NULL;
// Set the device name (PIR#number)
const char *DNAME = "PIR#3";

void sysProvEvent(arduino_event_t *sys_event)
{
    switch (sys_event->event_id) {
    case ARDUINO_EVENT_PROV_START:
#if CONFIG_IDF_TARGET_ESP32S2
        Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on SoftAP\n", service_name, pop);
        printQR(service_name, pop, "softap");
#else
        Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on BLE\n", service_name, pop);
        printQR(service_name, pop, "ble");
#endif
        break;
    case ARDUINO_EVENT_PROV_INIT:
        wifi_prov_mgr_disable_auto_stop(10000);
        break;
    case ARDUINO_EVENT_PROV_CRED_SUCCESS:
        wifi_prov_mgr_stop_provisioning();
        break;
    default:;
    }
}

void write_callback(Device *device, Param *param, const param_val_t val, void *priv_data, write_ctx_t *ctx)
{
    const char *device_name = device->getDeviceName();
    const char *param_name = param->getParamName();

    if (strcmp(param_name, "Motion Detection State") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
        motion_detected = val.val.b;
        param->updateAndReport(val);
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(gpio_motion_sensor, INPUT);

    Node my_node;
    my_node = RMaker.initNode("ESP RainMaker Node");

    // Initialize motion sensor device
    my_motion_sensor = new Device("Motion Sensor", "esp.device.motion-sensor");
    if (!my_motion_sensor) {
        return;
    }
    // Add standard name parameter
    my_motion_sensor->addNameParam(DNAME);

    // Initialize the motion detection state parameter value
    esp_rmaker_param_val_t motion_detected_val = esp_rmaker_bool(motion_detected);

    // Add motion detection state switch parameter
    Param motion_switch_param("Motion Detection State", ESP_RMAKER_PARAM_TOGGLE, motion_detected_val, PROP_FLAG_READ);
    motion_switch_param.addUIType(ESP_RMAKER_UI_TOGGLE);
    my_motion_sensor->addParam(motion_switch_param);

    // Set write callback for motion sensor
    my_motion_sensor->addCb(write_callback);

    // Add motion sensor device to the node
    my_node.addDevice(*my_motion_sensor);

    // This is optional
    RMaker.enableOTA(OTA_USING_TOPICS);
    // If you want to enable scheduling, set time zone for your region using setTimeZone().
    // The list of available values are provided here https://rainmaker.espressif.com/docs/time-service.html
    // RMaker.setTimeZone("Asia/Shanghai");
    // Alternatively, enable the Timezone service and let the phone apps set the appropriate timezone
    RMaker.enableTZService();

    RMaker.enableSchedule();
    RMaker.enableScenes();

    // Enable ESP Insights. Instead of using the default http transport, this function will
    // reuse the existing MQTT connection of Rainmaker, thereby saving memory space.
    initAppInsights();

    RMaker.enableSystemService(SYSTEM_SERV_FLAGS_ALL, 2, 2, 2);

    RMaker.start();

    WiFi.onEvent(sysProvEvent);
#if CONFIG_IDF_TARGET_ESP32S2
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_SOFTAP, WIFI_PROV_SCHEME_HANDLER_NONE, WIFI_PROV_SECURITY_1, pop, service_name);
#else
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, pop, service_name);
#endif
}

void loop()
{
    // Check motion sensor state
    bool current_state = digitalRead(gpio_motion_sensor);
    if (current_state != motion_detected) {
        motion_detected = current_state;
        
        // Retrieve the device name
        const char *device_name = DNAME;

        Serial.printf("Motion detected: %s on %s\n", motion_detected ? "true" : "false", device_name);

        if (my_motion_sensor) {
            // Update and report the boolean value
            my_motion_sensor->updateAndReportParam("Motion Detection State", motion_detected);
        }
    }
    delay(100);
}
