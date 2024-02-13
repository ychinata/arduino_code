

/*
void doEncoderA() {
    // look for a low-to-high on channel A
    if (digitalRead(encoderPinA) == HIGH) { 
        // check channel B to see which way encoder is turning
        if (digitalRead(encoderPinB) == LOW) {  
            encoderCounter = encoderCounter + 1;         // CW
        } else {
            encoderCounter = encoderCounter - 1;         // CCW
        }
    } else {   // must be a high-to-low edge on channel A                                       
        // check channel B to see which way encoder is turning  
        if (digitalRead(encoderPinB) == HIGH) {   
            encoderCounter = encoderCounter + 1;          // CW
        } else {
            encoderCounter = encoderCounter - 1;          // CCW
        }
    }
    // Serial.println(encoder0Pos, DEC);          
    // use for debugging - remember to comment out
}

void doEncoderB() {
    // look for a low-to-high on channel B
    if (digitalRead(encoderPinB) == HIGH) {   
        // check channel A to see which way encoder is turning
        if (digitalRead(encoderPinA) == HIGH) {  
            encoderCounter = encoderCounter + 1;         // CW
        } else {
            encoderCounter = encoderCounter - 1;         // CCW
        }
    } else { // Look for a high-to-low on channel B
        // check channel B to see which way encoder is turning  
        if (digitalRead(encoderPinA) == LOW) {   
            encoderCounter = encoderCounter + 1;          // CW
        } else {
            encoderCounter = encoderCounter - 1;          // CCW
        }
    }
}

*/