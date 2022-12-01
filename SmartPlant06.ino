#define BLYNK_TEMPLATE_ID           "TMPLV1XVzXqG"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "6NpMUyGPEA9EgwxNTC4l8G65SYLfvBBG"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Hywasx";
char pass[] = "bolodechocolate";

const int SoilSensor = 34;

int moistureLevel;
const int sensor = 32;
int sensorValue = 0;

BlynkTimer timer;

void SendSensorWaterSoil()
{
  moistureLevel = analogRead(SoilSensor);
  moistureLevel = map(moistureLevel, 0, 3000, 3000, 0);
  moistureLevel = map(moistureLevel, 3000, 0, 100, 0);

  Blynk.virtualWrite(V6, moistureLevel);
}
void SendLightSensor()
{
  sensorValue = analogRead(sensor);
  moistureLevel = map(sensorValue, 1400, 0, 100, 0);
  Blynk.virtualWrite(V8, sensorValue);
}
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth,ssid,pass);
  
  //timer.setInterval(3600000L,SendSensorWaterSoil); //manda info pra cloud do blynk a cada uma hora
  //timer.setInterval(900000L,SendLightSensor); //manda a info a cada meia hora
  
  timer.setInterval(3000L,SendSensorWaterSoil); //teste
  timer.setInterval(3000L,SendLightSensor); //teste

  //ESP.deepSleep(30e6);
}

void loop()
{
  Blynk.run();
  timer.run();

}
