int speaker = 3; // name of the speaker key
int read1;
// musical notes
int C6 = 1046;
int CS6 = 1109;
int D6 = 1175;
int DS6 = 1245;
int E6 = 1319;

void setup() {
  pinMode(speaker,OUTPUT);
}

void loop() {
tone(speaker, C6);
delay(100);
tone(speaker, CS6);
delay(200);
tone(speaker, D6);
delay(200);
tone(speaker, DS6);
delay(1000);
tone(speaker, E6);
delay(200);
tone(speaker, CS6);
delay(1000);
}
