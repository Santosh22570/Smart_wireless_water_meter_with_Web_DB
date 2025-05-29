#include <WiFi.h>
#include "ThingSpeak.h"

// Pin Definitions
#define PH_PIN 34              // Analog input for pH sensor
#define TDS_PIN 35             // Analog input for TDS sensor
#define OVERFLOW_PIN 23        // Digital input for overflow indicator
#define RELAY_PIN 22           // Output to Relay controlling Water Pump

// WiFi Credentials
const char* ssid = "Phone";          // Your WiFi SSID
const char* password = "alpha123";   // Your WiFi Password

// ThingSpeak Settings
unsigned long channelNumber = 2819273;
const char* writeAPIKey = "7KJBVKDC1ZJ6AY28";

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Pin setup
  pinMode(PH_PIN, INPUT);
  pinMode(TDS_PIN, INPUT);
  pinMode(OVERFLOW_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump OFF initially

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  ThingSpeak.begin(client);
}

void loop() {
  int phRaw = analogRead(PH_PIN);
  int tdsRaw = analogRead(TDS_PIN);
  bool overflow = digitalRead(OVERFLOW_PIN);

  // Convert analog readings
  float phValue = phRaw * (14.0 / 4095.0);      // Basic conversion (ADC to pH)
  float tdsValue = tdsRaw * (1000.0 / 4095.0);  // Basic conversion (ADC to ppm)

  Serial.printf("pH: %.2f | TDS: %.2f ppm | Overflow: %s\n", phValue, tdsValue, overflow ? "YES" : "NO");

  // Relay Logic: Stop pump if overflow detected
  if (overflow) {
    digitalWrite(RELAY_PIN, LOW);  // Turn OFF pump
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn ON pump
  }

  // Upload to ThingSpeak
  ThingSpeak.setField(1, phValue);
  ThingSpeak.setField(2, tdsValue);
  ThingSpeak.setField(3, overflow ? 1 : 0);

  int response = ThingSpeak.writeFields(channelNumber, writeAPIKey);

  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully.");
  } else {
    Serial.printf("Error sending data. HTTP error code: %d\n", response);
  }

  delay(15000);  // Wait 15 seconds for next update (ThingSpeak rate limit)
}
