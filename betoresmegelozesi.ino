const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int pir = 7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(pir, INPUT);

  randomSeed(analogRead(0));
}

void loop() {

  int motion = digitalRead(pir);

  if (motion == HIGH) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(200);

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(200);
    }
  } 
  else {
    int led = random(2, 5);
    int state = random(0, 2);
    int waitTime = random(500, 4000);

    digitalWrite(led, state);
    delay(waitTime);
  }
}
}
