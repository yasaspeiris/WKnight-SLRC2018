void nrfsetup() {
  Serial.println(myRadio.begin());
  myRadio.setChannel(115);
  myRadio.setPALevel(RF24_PA_MAX);
  //myRadio.setDataRate( RF24_250KBPS ) ;
  myRadio.openWritingPipe( addresses[0]);
  myRadio.openReadingPipe(1, addresses[1]);
  delay(1000);
}


void nrfsendSum(int sum) {
  data.sum = sum;
  data.command = 'n';
  myRadio.write(&data, sizeof(data));
  Serial.print("\nSum:");
  Serial.print(data.sum);

}

void nrfsendCmd(char cmd) {
  data.command = cmd;
  myRadio.write(&data, sizeof(data));
  Serial.print("\nCommand:");
  Serial.print(data.command);


}
