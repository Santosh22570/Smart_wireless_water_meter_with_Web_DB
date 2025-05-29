#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FLOW_SENSOR_PIN 2  // Interrupt pin for Flow Rate Sensor
#define VALVE_PIN 8        // Digital pin to control Flyrobo Valve

volatile int flowPulseCount = 0;
float flowRate = 0.0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address may vary

void pulseCounter() {
  flowPulseCount++;
}

void setup() {
  pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, RISING);

  pinMode(VALVE_PIN, OUTPUT);
  digitalWrite(VALVE_PIN, LOW);  // Valve initially closed

  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  flowPulseCount = 0;
  sei();
  delay(1000);  // Count pulses for 1 second
  cli();

  // Convert pulses to flow rate (L/min or similar depending on sensor)
  flowRate = (flowPulseCount / 7.5);  // Example conversion for YF-S201

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Flow: ");
  lcd.print(flowRate);
  lcd.print(" L/min");

  // Send to ESP32 via Serial if needed
  Serial.println(flowRate);

  // Control valve logic (e.g., open if user bucket needed)
  // digitalWrite(VALVE_PIN, HIGH or LOW);
}
