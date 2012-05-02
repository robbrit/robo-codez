/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 Modified 4 Sep 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:

/*const int leftMotorPin = 11; // Analog output pin that the LED is attached to
const int rightMotorPin = 10; // Analog output pin that the LED is attached to

const int leftPower = 255;
const int rightPower = 255;

void left90(){
  analogWrite(leftMotorPin, leftPower);
  analogWrite(rightMotorPin, 0);
  delay(1200);
  stop();
}

void right90(){
  analogWrite(leftMotorPin, 0);
  analogWrite(rightMotorPin, rightPower);
  delay(1100);
  stop();
}

void forward(){
  analogWrite(leftMotorPin, leftPower);
  analogWrite(rightMotorPin, rightPower);
}

void stop(){
  analogWrite(leftMotorPin, 0);
  analogWrite(rightMotorPin, 0);
}

void setup() {
}

void loop() {
  forward();
  delay(3000);
  
  stop();
  
  delay(1000);
  
  right90();
  
  delay(1000);
  
  left90();
  left90();
  
  delay(1000);
  
  right90();
  
  delay(1000);
}*/
