void setup() {
  Serial.begin(115200);
  lightsandswsetup();
  motorsetup();
  servosetup();
  colorsensorsetup();
  nrfsetup();
  //vlxsetup();
}

void loop() {
  int val1 = digitalRead(STARTSWITCH);
  int val2 = digitalRead(MODESW);
  int val3 = digitalRead(CALSW);

  char c = checkcolor();
  

  if ( val1 == 0) {
    digitalWrite(BLUELED, HIGH);
    nrfsendCmd('s');
    nrfsendCmd('s');
    //nrfsendSum(0);
    delay(1000);
    digitalWrite(BLUELED, LOW);

    delay(2000);


    SetMasterPower(55); SetSlavePower(55); // Exit white Box
    QTRCRead();
    SetMasterPower(60); SetSlavePower(60);
    while (SensorPanelVal == 1023) {
      QTRCRead();
    }
    delay(69); //hehe
    setBrakes(255, 255);

    maze_solve();
    delay(PADDING);
    //Now at end of maze


    QTRCRead();
    SetMasterPower(-60); SetSlavePower(-60);
    while (SensorPanelVal == 1023) {
      QTRCRead();
    }
    setBrakes(255, 255);
    reverseline(60, 600);
    delay(PADDING);//bring out of box
    linedegreetravel('R', TURNSPEED);
    delay(PADDING); //turn around


    which_turn = 1; //signal that this is the path to simplify
    maze_solve();
    delay(PADDING);
    //now back at starting square

    QTRCRead();
    SetMasterPower(-60); SetSlavePower(-60);
    while (SensorPanelVal == 1023) {
      QTRCRead();
    }
    setBrakes(255, 255);
    reverseline(60, 600);
    delay(PADDING);
    //bring out of white square

    linedegreetravel('L', TURNSPEED);
    delay(PADDING);
    //turn

    which_turn = 2;
    if (which_turn == 2) {
      if (totalSum % 2 == 0) {
        nrfsendCmd('r');
      } else {
        nrfsendCmd('l');
      }
    }
    digitalWrite(GREENLED,HIGH);
    gotostart();
    delay(PADDING);
    digitalWrite(GREENLED,LOW);
    

    QTRCRead();
    SetMasterPower(60); SetSlavePower(60);
    while (SensorPanelVal == 1023) {
      QTRCRead();
    }
    delay(69);
    setBrakes(255, 255);
    delay(PADDING);
    nodetravelcurve(40); // ALL OKAY UP TO HERE


    
    QTRCRead();
    SetMasterPower(60); SetSlavePower(60);
    while (SensorPanelVal == 1023) {
      QTRCRead();
    } //bypass 10 cm line
    delay(400);
    setBrakes(255, 255);
    delay(PADDING);

    

    temp = nodetravel(55);
    delay(PADDING); //at beginning of square
    

    if (totalSum % 2 == 0) {
      linedegreetravel('R', TURNSPEED);
      delay(PADDING);
      temp = nodetravel(55);
      delay(PADDING);
      linedegreetravel('R', TURNSPEED);
      delay(PADDING);

    } else {
      linedegreetravel('L', TURNSPEED);
      delay(PADDING);
      temp = nodetravel(55);
      delay(PADDING);
      linedegreetravel('L', TURNSPEED);
      delay(PADDING);

    }

    //unloading

    which_turn = 5;
    
    temp = nodetravel(55);
    delay(PADDING);

    linedegreetravel('L',TURNSPEED);
    delay(PADDING);
    temp = nodetravel(45);
    delay(PADDING);
    raise_cointray();
    lower_cointray();
    raise_cointray();
    lower_cointray();
    delay(700);
    analogWrite(11, 120);
    delay(20);
    reverseline(60, 500);
    delay(PADDING);
    linedegreetravel('L',TURNSPEED);
    delay(PADDING);


    nodetravel(55);
    delay(PADDING);

    linedegreetravel('L',TURNSPEED);
    delay(PADDING);
    nodetravel(45);
    delay(PADDING);
    opengreen();
    delay(200);
    raise_cointray();
    lower_cointray();
    raise_cointray();
    lower_cointray();
    delay(700);
    closepanes();

    analogWrite(11, 120);
    delay(20);
    reverseline(60, 500);
    delay(PADDING);
    linedegreetravel('L',TURNSPEED);
    delay(PADDING);


    nodetravel(55);
    delay(PADDING);


    linedegreetravel('L',TURNSPEED);
    delay(PADDING);
    nodetravel(45);
    delay(PADDING);
    openblue();
    delay(200);
    raise_cointray();
    lower_cointray();
    raise_cointray();
    lower_cointray();
    closepanes();

    analogWrite(11, 120);
    delay(20);
    analogWrite(11, 120);
    delay(20);
    analogWrite(11, 120);
    delay(20);
    analogWrite(11, 120);
    delay(20); 
    



  }

  if (val3 == 0) {
    digitalWrite(YELLOWLED, HIGH);
    QTRCcallibrate();
    digitalWrite(YELLOWLED, LOW);
  }
  if (val2 == 0) {
    delay(1000);
    nodetravelcurve(40);
  }

}
