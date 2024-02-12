/*
https://blog.csdn.net/lihe4151021/article/details/121776815
顺时针转一圈：80
逆时针转一圈：-80
*/
//volatile long temp, encoderCounter =0; //This variable will increase or decreas depending on the rotation of encoder
int temp = 0;
int encoderCounter = 0; //This variable will increase or decreas depending on the rotation of encoder
int encoderPinA = 2; //interrupt pin 2 
int encoderPinB = 3; //interrrupt pin 3

void setup() {
    Serial.begin(115200);
    pinMode(encoderPinA, INPUT); 
    pinMode(encoderPinB, INPUT); 
    //Setting up interrupt
    //attach an interrupt to pin encoderPinA & encoderPinA of the Arduino, and when the pulse is in the CHANGE edge 
    //  called the function doEncoderA()/doEncoderB()
    //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 isDigitalPin nr 3 on moust Arduino.
    attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoderA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoderPinB), doEncoderB, CHANGE);
}

//Serial.print(bh1750Val_lux);                                     //串口打印对应的值
//Serial.println("[lx]");                                      //串口打印对应的值

void loop() {
    // Send the value of counter
    if ( encoderCounter!= temp) {
        //double angle = encoderCounter*360/172032.0;//ppr=172032
        double angle = encoderCounter*4.5;  //一圈对应数值80
        //Serial.println(encoderCounter);
        Serial.print(angle);
        Serial.println("°");
        temp = encoderCounter;
    }
}
//

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

