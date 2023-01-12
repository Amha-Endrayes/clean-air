#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* mqttServer = "your_MQTT_SERVER";
const int mqttPort = 1883;
const char* mqttUser = "your_MQTT_USERNAME";
const char* mqttPassword = "your_MQTT_PASSWORD";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      Serial.println("Connected to MQTT broker");
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read sensor data
  value = analogRead(A0);

  // Prepare the MQTT message
  snprintf (msg, 75, "sensor/data value=%ld", value);

  // Publish the MQTT message
  client.publish("sensor/data", msg);
  Serial.println(msg);

  delay(1000);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266Client", mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT broker");
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
