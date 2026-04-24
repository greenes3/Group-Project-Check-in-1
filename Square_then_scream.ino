#define ENA 9
#define IN1 12 
#define IN2 11
#define ENB 6
#define IN3 7
#define IN4 8

#define SPEED 190
const int buzzer = 13;

void moveForward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
}

void turnRight(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(865);
}

void moveStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}

void MakeASquare(){
  for (int i = 0; i < 4; i++) {
    moveForward();
    moveStop();
    turnRight();
    moveStop();
  }
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 4; i++) {
    MakeASquare();
    tone(buzzer, 2000);
    delay(10000);
    noTone(buzzer);
  }
}
void loop(){

}