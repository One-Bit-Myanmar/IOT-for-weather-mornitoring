#include <WiFi.h>  // Use <ESP8266WiFi.h> for ESP8266
#include <PubSubClient.h>
#include <DHT.h>

// MQTT server details
const char* mqtt_server = "broker.mqttdashboard.com";  // Or your local Mosquitto broker IP
const int mqtt_port = 1883;
const char* mqtt_topic = "iot/weather";

// DHT sensor setup
#define DHTPIN 15        // DHT sensor pin
#define DHTTYPE DHT22    // DHT22 sensor type
DHT dht(DHTPIN, DHTTYPE);

// MQTT client setup
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();

  WiFi.begin("Wokwi-GUEST", "", 6);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Reading temperature and humidity from DHT22
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed
  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Create JSON payload
  String payload = "{\"temperature\": ";
  payload += String(temp);
  payload += ", \"humidity\": ";
  payload += String(humidity);
  payload += "}";

  // Publish the message
  Serial.print("Publishing message: ");
  Serial.println(payload);
  client.publish(mqtt_topic, (char*) payload.c_str());

  delay(2000);  // Wait before sending next update
}
