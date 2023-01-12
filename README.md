# CleanAir
An IoT based smart air quality monitoring and assessment system.

This project utilizes an ESP8266 microcontroller and various sensors to measure air quality and sends the data to an MQTT broker and an InfluxDB database. The MQTT broker used in this project is Mosquitto and the data is visualized using Grafana.

## Hardware

- ESP8266 development board (e.g. NodeMCU)
- Air quality sensors (e.g. MQ-135)
- Breadboard and jumpers

## Software

- Arduino IDE for programming the ESP8266
- Mosquitto MQTT Broker
- InfluxDB
- Grafana (for visualizing data)

## Setup

1. Install Arduino IDE and the necessary ESP8266 board support.
2. Connect the ESP8266 development board to your computer and select the correct board and serial port in Arduino IDE.
3. Download the project code and open it in Arduino IDE.
4. Update the WiFi and MQTT credentials with your network details.
5. Update the InfluxDB credentials and location in the code as per your requirement.
6. Upload the code to the ESP8266 board.
7. Install and set up Mosquitto MQTT Broker, InfluxDB and Grafana on your computer or a server.
8. Configure the data source in Grafana to point to your InfluxDB instance.
9. You should now see the air quality data being sent and displayed in real-time.

## Usage

The ESP8266 will automatically connect to your WiFi network and start sending data to the MQTT broker and InfluxDB database. You can view the data in real-time using Grafana.

You can customize the code as per your requirement and add/remove sensors as per your need.

## Notes

- Make sure the ESP8266 is getting enough power supply and its connected to the correct pinout of the sensor.
- You may need to adjust the sensitivity settings of the sensor as per your environment.
- The code is written assuming that the device is deployed in a indoor environment, adjust the code as per your requirement.
- Be sure to keep the MQTT broker, InfluxDB and Grafana updated and secured.

## References

- [MQTT Broker](https://mosquitto.org/)
- [InfluxDB](https://www.influxdata.com/)
- [Grafana](https://grafana.com/)
- [ESP8266](https://www.espressif.com/en/products/hardware/esp8266ex/overview)
- [MQ-135](https://www.winsen-sensor.com/products/gas-sensor/mq-135.html)
