# esp8266-NetIO-GC-10-GC10-geiger-counter-influxdb
NetIO GC-10 GC10 geiger counter serial connected to an esp8266 via softserial, sending data to influxdb.

You need a running influxDB database. I run one one a raspberry pi connected to my network.
ESP8266 i use a NodeMCU v2
NetIO Devices Co,. Ltd Japan Model: GC-10 geiger counter (a.k.a "kinoko geiger")

The nodeMCU is programmed through the arduino IDE and needs the following librarys.

https://github.com/tobiasschuerg/ESP8266_Influx_DB <InfluxDb.h>

https://github.com/scottwday/EspSoftSerial <SoftwareSerial.h>

https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi <ESP8266WiFi.h> & <ESP8266WiFiMulti.h>

#######WARNING#########WARNING##########WARNING############WARNING do not connect any other power suply to the GC-10 geiger counter when feeding the GC-10 geiger counter from your nodeMCU 5V or Vin or Vu You might otherwise damage your GC-10 geiger counter. 

[![The serial uart pins](https://raw.githubusercontent.com/JanBosNL/esp8266-NetIO-GC-10-GC10-geiger-counter-influxdb/master/firefox_xA6hXShZJs.png)] 

Black goes to gnd on the nodeMCU

Orange goes to a pin of choise which wil function as a RX pin on the nodeMCU the RX pin is a softwareserial pin defined in the code. I choose pin D8

Blue goes to a pin of choise which wil function as a TX pin on the nodeMCU the TX pin is a softwareserial pin defined in the code. I choose pin D7

Red is 5v line that will feed the geigercounter. It is connected to the 5V or Vin pin on the NodeMCU. #WARNING# do not connect any other power suply to the GC-10 geiger counter when feeding the GC-10 geiger counter from your nodeMCU You might otherwise damage your GC-10 geiger counter. 

After setting up all your influxDB account info and your WIFI ssid + Password the nodeMCU will automaticly connect to your database. The geigercounter will start counting and send a serial linefeed to the nodemcu. The nodeMCU now takes these measurements and sends them to the database every 5 seconds.

[![assembled](https://raw.githubusercontent.com/JanBosNL/esp8266-NetIO-GC-10-GC10-geiger-counter-influxdb/master/WhatsApp%20Image%202019-11-28%20at%2012.40.13.jpeg)] 

You can now visualise the data collected in your influxDB. I use Grafana for this. 

[![assembled](https://raw.githubusercontent.com/JanBosNL/esp8266-NetIO-GC-10-GC10-geiger-counter-influxdb/master/WhatsApp%20Image%202019-11-29%20at%2016.47.44(1).jpeg)] 

The top right CPM is this geigercounter. It is now part of my ever growing open source non cloud weather and other sensor station

The code can be easely changed to connect other serial divices. 
