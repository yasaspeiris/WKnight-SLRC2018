/* Servo setup -
   servosetup()
   pickup()
   putdown()
*/

void servosetup() {

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
  for (int m = 0 ; m < 3; m++) {
    digitalWrite(YELLOWLED, HIGH);
    delay(500);
    digitalWrite(YELLOWLED, LOW);
    delay(500);
  }

  setServo(COINTOSSERRIGHT,16);//Set coin tray to zero position
  setServo_invert(COINTOSSERLEFT,16);

  setServo(EJECTRIGHT, 5); //Set ejector servos to zero
  setServo_invert(EJECTLEFT, 5);

  setServo(LEFTPANE, 0); //Set ejector servos to zero
  setServo(RIGHTPANE, 180);

  setServo(MAINARMRIGHT, 126);// Set magnetic bed to zero pos
  setServo_invert(MAINARMLEFT, 126);

  delay(1000);



}

///         MAIN ARM

void lower_mainarm() {
  for (int i = 124; i >= 12; i--) {
    setServo(MAINARMRIGHT, i+5);
    setServo_invert(MAINARMLEFT, i);
    delay(8);
  }

  delay(1000);

}

void raise_mainarm() {
  for (int i = 12; i <= 124; i++) {
    setServo(MAINARMRIGHT, i+5);
    setServo_invert(MAINARMLEFT, i);
    delay(8);
  }

  delay(1000);

}

//      COIN TRAY

void raise_cointray() {
  setServo(COINTOSSERRIGHT, 80);
  setServo_invert(COINTOSSERLEFT, 80);
  delay(500);
}

void lower_cointray() {
  setServo(COINTOSSERRIGHT, 20);
  setServo_invert(COINTOSSERLEFT, 20);
  delay(500);
}

void shake_cointray(){
  setServo(COINTOSSERRIGHT, 20);
  setServo_invert(COINTOSSERLEFT, 20);
  delay(200);

  setServo(COINTOSSERRIGHT, 40);
  setServo_invert(COINTOSSERLEFT, 40);
  delay(200);

  setServo(COINTOSSERRIGHT, 20);
  setServo_invert(COINTOSSERLEFT, 20);
  delay(200);
  

  
}

//      COIN EJECTOR

void raise_coinejector() {
  setServo(EJECTRIGHT, 5);
  setServo_invert(EJECTLEFT, 5);
  delay(500);
}

void mid_coinejector(){
  setServo(EJECTRIGHT, 130);
  setServo_invert(EJECTLEFT, 130);
  delay(500);
}

void lower_coinejector(){
  setServo(EJECTRIGHT, 180);
  setServo_invert(EJECTLEFT, 180);
  delay(500);
}

//Servo Angle Assign Functions - PCA9685

void setServo(int channel, int angle) {
  if (angle < 0) {
    angle = 0;
  } else if (angle > 180) {
    angle = 180;
  }
  pwm.setPWM(channel, 0, (int)((angle * 2.5) + 150));
}

void setServo_invert(int channel, int angle) {
  if (angle < 0) {
    angle = 0;
  } else if (angle > 180) {
    angle = 180;
  }
  pwm.setPWM(channel, 0, (int)((angle * -2.5) + 600));
}

void openred(){
  setServo(LEFTPANE,0);
  setServo(RIGHTPANE,180);
  delay(300);
}

void opengreen(){
   setServo(LEFTPANE,180);
  setServo(RIGHTPANE,180);
  delay(500);
}

void openblue(){
   setServo(LEFTPANE,0);
  setServo(RIGHTPANE,0);
  delay(500);
}

void closepanes(){
  setServo(LEFTPANE,0);
  setServo(RIGHTPANE,180);
  delay(300);
}
