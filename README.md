# esp8266-NetIO-GC-10-GC10-geiger-counter-influxdb
NetIO GC-10 GC10 geiger counter serial connected to an esp8266 via softserial, sending data to influxdb.

You need a running influxDB database. I run one one a raspberry pi connected to my network.
ESP8266 i use a NodeMCU v2
NetIO Devices Co,. Ltd Japan Model: GC-10 geiger counter (a.k.a "kinoko geiger")

The nodeMCU is programmed through the arduino IDE and needs the following librarys.

https://github.com/tobiasschuerg/ESP8266_Influx_DB <InfluxDb.h>

https://github.com/scottwday/EspSoftSerial <SoftwareSerial.h>

https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi <ESP8266WiFi.h> & <ESP8266WiFiMulti.h>



