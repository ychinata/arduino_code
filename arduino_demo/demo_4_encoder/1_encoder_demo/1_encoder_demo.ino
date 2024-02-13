#include "rotary_encoder.h"

void setup() {
    Serial.begin(9600);//原始值为115200
    ROTARYENCODER_Init();
}

void loop() {
    ROTARYENCODER_Show();
}

