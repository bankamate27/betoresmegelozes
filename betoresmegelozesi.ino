const int led1 = 2; 
const int led2 = 3; 
const int led3 = 4; 
const int pir = 7; 
const int buzzer = 8; 
enum State {DISARMED, ARMED_IDLE, WARNING, ALARM}; 
State state = ARMED_IDLE; 
unsigned long lastMotionTime = 0; 
unsigned long alarmStartTime = 0; 
bool motionStable = false; 

void setup() { 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(pir, INPUT); 
  randomSeed(analogRead(0));} 

void loop() { 
  int motion = digitalRead(pir); 
  unsigned long now = millis(); 
  if (motion == HIGH) { 
    if (now - lastMotionTime > 2000) { 
      motionStable = true;} 
    lastMotionTime = now;} 
else {  
  motionStable = false;}  
  switch(state) { 
 case ARMED_IDLE: 
      idleSimulation(); 
      if (motionStable) { 
        state = WARNING; 
        alarmStartTime = now; } 
      break; 
    case WARNING: 
      warningMode(); 
      if (now - alarmStartTime > 5000) { 
        state = ALARM;} 
      break; 
    case ALARM: 
      alarmMode(); 
      if (!motionStable) { 
        state = ARMED_IDLE;  } 
      break; 
    case DISARMED: 
      allOff(); 
      break;} 
}  
void idleSimulation() { 
  int led = random(2, 5); 
  int stateVal = random(0, 2); 
  digitalWrite(led, stateVal); 
  delay(100); 
} 
void warningMode() { 
  for (int i = 0; i < 2; i++) { 
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
    digitalWrite(led3, HIGH); 
    tone(buzzer, 1000); 
    delay(200); 
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    noTone(buzzer); 
    delay(200); 
  } 
} 

void alarmMode() { 
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, HIGH); 
  tone(buzzer, 2000); 
} 

void allOff() { 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  noTone(buzzer); 
}
