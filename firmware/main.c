#include <Arduino.h>

#define METAL_DETECTOR_PIN 2  // Input from 555 Timer IC
#define BUZZER_PIN 3          // Buzzer output
#define LED_PIN 4             // LED indicator

volatile unsigned long pulseCount = 0;
unsigned long lastTime = 0;
float frequency = 0.0;

// Interrupt Service Routine (ISR) for counting pulses
void countPulse() {
    pulseCount++;
}

void setup() {
    Serial.begin(9600);
    
    pinMode(METAL_DETECTOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    // Attach interrupt to detect frequency pulses
    attachInterrupt(digitalPinToInterrupt(METAL_DETECTOR_PIN), countPulse, RISING);
}

void loop() {
    unsigned long currentTime = millis();
    
    if (currentTime - lastTime >= 1000) {  // Calculate frequency every 1 second
        frequency = pulseCount;
        pulseCount = 0;
        lastTime = currentTime;

        Serial.print("Detected Frequency: ");
        Serial.print(frequency);
        Serial.println(" Hz");

        if (frequency > 1000) {  // Adjust threshold based on metal type
            digitalWrite(BUZZER_PIN, HIGH);
            digitalWrite(LED_PIN, HIGH);
        } else {
            digitalWrite(BUZZER_PIN, LOW);
            digitalWrite(LED_PIN, LOW);
        }
    }
}
