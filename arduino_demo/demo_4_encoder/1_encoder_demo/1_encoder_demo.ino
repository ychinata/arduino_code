#include "rotary_encoder.h"

void setup() {
    Serial.begin(115200);//9600 ok?
    ROTARYENCODER_Init();
}

void loop() {
    ROTARYENCODER_Show();
}

