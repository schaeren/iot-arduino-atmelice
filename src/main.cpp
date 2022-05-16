#include <Arduino.h>

int myVar = 0;
unsigned long myDelay = 1000;

void setup() {  
    Serial.begin(115200); 
    while (!Serial);
    Serial.println("setup() started.");

    // Other initialization
    myVar = 1;
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() { 
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);

    delay(myDelay);
    Serial.println(myVar);
    myVar++;
}