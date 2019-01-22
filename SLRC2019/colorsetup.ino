
void colorsensorsetup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}
char checkcolor() {
  int rfreq, gfreq, bfreq = 0;

  for (int k = 0; k < 5; k++) {
    // Setting red filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    frequency = map(frequency, 25, 72, 255, 0);
    rfreq += frequency;


    // Setting Green filtered photodiodes to be read
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    frequency = map(frequency, 30, 90, 255, 0);
    gfreq += frequency;

    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    frequency = map(frequency, 25, 70, 255, 0);
    bfreq += frequency;


  }

  rfreq = rfreq / 5;
  gfreq = gfreq / 5;
  bfreq = bfreq / 5;
//
//  Serial.print("B= ");//printing name
//  Serial.print(bfreq);//printing RED color frequency
//  Serial.print("  ");
//
//  Serial.print("G= ");//printing name
//  Serial.print(gfreq);//printing RED color frequency
//  Serial.print("  ");
//
//  Serial.print("R= ");//printing name
//  Serial.print(rfreq);//printing RED color frequency
//  Serial.println("  ");
//  
  if (rfreq >10 && bfreq <0 && gfreq<0)  {
    return 'R';
  }else if(bfreq >10 && gfreq <0 && rfreq<0){
    return 'B';
  }else if(gfreq >-100 && bfreq >-100 && rfreq<-180){
    return 'G';
  }else{
    return 'N';
  }

}
