#include <Servo.h>
#include <PCF8574.h>
#include <Wire.h>


Servo myServo;
int button_1 = 12;
bool buttonState = false; // To keep track of button state
bool lastButtonState = false; // To keep track of previous button state
bool servoState = false; // To keep track of servo state
PCF8574 pcf8574(0x20);

void setup() {
  Serial.begin(9600);
  pinMode(button_1, INPUT_PULLUP);
  myServo.attach(11);
  pcf8574.begin();
}

void loop() {
  buttonState = digitalRead(button_1);
  
  // Check if button is pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    servoState = !servoState; // Toggle servo state
    if (servoState) {
      myServo.write(180); // Move servo to 180 degrees
    } else {
      myServo.write(0); // Move servo to 0 degrees
    }
  }
  
  lastButtonState = buttonState; // Update lastButtonState for next iteration
}
