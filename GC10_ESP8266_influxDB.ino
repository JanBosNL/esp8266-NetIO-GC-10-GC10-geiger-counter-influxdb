
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <InfluxDb.h>
#include <SoftwareSerial.h>

#define BAUD_RATE 9600

SoftwareSerial geiger(D8, D7, false, 8); //Here you choose the pins you connect the Orange and Blue wire to. 
                                        // D8=RX Orange D7=TX Blue
 #define INFLUXDB_HOST "***.***.***.***" // CHoose the IP your database server is running on. 
 //#define INFLUXDB_USER "YOUR influxDB LOGIN credentials"  //leave if you dont have acces protection
 //#define INFLUXDB_PASS "YOUR influxDB Password"           //leave if you dont have acces protection
 #define INFLUXDB_PORT "1337" // 
 #define INFLUXDB_DATABASE "Your influxDB name" // prepare make and set this database up on your database server first 
                                                  //or set it to your already running database

#define WIFI_SSID "Your acces point name"
#define WIFI_PASS "Your acces point Password"

ESP8266WiFiMulti WiFiMulti;
Influxdb influx(INFLUXDB_HOST);



void setup() {
  Serial.begin(BAUD_RATE);
  geiger.begin(BAUD_RATE);

  Serial.println(" ### Hello ###");

  WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WIFI");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  influx.setDb("Your influxDB name"); // Change to your Database name

  Serial.println("Setup done");

  }


//int loopCount = 0; // for testing purposes

  void loop() {

     
  //loopCount++; // for testing purposes

  if (geiger.available() > 0) {
       int red = geiger.readStringUntil('\r').toInt();// read the incoming data as string until('\r');
  
  InfluxData row("temperature");
  row.addTag("device", "alpha");
  row.addTag("sensor", "one");
  row.addTag("mode", "pwm");
  //row.addValue("loopCount", loopCount); // for testing purposes
  //row.addValue("value", random(10, 40)); // sends  random numbers to your database for testing purposes.
  row.addValue("CPM", (red));

  influx.write(row);

  delay(5000);
  }
  }  
