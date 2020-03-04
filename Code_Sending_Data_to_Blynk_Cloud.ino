#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "ys-bgddnk15mukxdN_G1x8BXdTeVuBLc";
char ssid[] = "peter1";
char pass[] = "147147147";
#define TRIGGERPIN D1
#define ECHOPIN    D2
#define pump  D4
BlynkTimer timer;
long distance;
long duration;
String display1;
void sendSensor()
{
 Blynk.virtualWrite(V1, display1);
 delay (200);
}
void setup()
{
 // Debug console
 pinMode(pump,OUTPUT);
 Serial.begin(9600);
pinMode(TRIGGERPIN, OUTPUT);
 pinMode(ECHOPIN, INPUT);
 Blynk.begin(auth, ssid, pass);
 // You can also specify server:
 //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
 //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
 timer.setInterval(1000L, sendSensor);
}
void loop()
{
 Blynk.run();
 timer.run();
long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  display1 =String(distance);
  Serial.println("Cm");
 // lcd.print(7, 1, distance);
 if(distance <20 && distance <=70 ){
 digitalWrite(pump,LOW);
 }
 else
 {
  digitalWrite(pump,HIGH);
 }
 delay(2000);
}
