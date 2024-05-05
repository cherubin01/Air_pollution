#include <ESP8266WiFi.h> // allows the ESP8266 chip to connect to a WiFi network.
#include <SPI.h> // ESP8266 chip to communicate with other devices using the SPI protocol.
#include <Wire.h> //ESP8266 chip to communicate with other devices using the I2C protocol.
#include "MQ135.h" //This line includes the MQ135 library which is a library that allows the use of a gas sensor MQ135.
String apiKey = "3MWL3S3LLTMZ6YML"; // Enter your Write API key from ThingSpeak
const char *ssid = "Nainika";     // replace with your wifi ssid and wpa2 key
const char *pass = "12345678g";
const char* server = "api.thingspeak.com";
WiFiClient client; //This line creates an instance of the WiFiClient class which allows the ESP8266 chip to connect to the ThingSpeak server.
void setup()
{
  Serial.begin(9600);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected");
}
  void loop()
  {
    MQ135 gasSensor = MQ135(A0);
    float air_quality = gasSensor.getPPM()/1000;
    Serial.print("Air Quality: ");  
    Serial.print(air_quality);
    Serial.println("  PPM");   
    Serial.println();
    if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(air_quality);
    postStr += "r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    Serial.println("Data Send to Thingspeak");
  }
    client.stop();
    Serial.println("Waiting...");
    delay(2000);      // thingspeak needs minimum 15 sec delay between updates.
}
