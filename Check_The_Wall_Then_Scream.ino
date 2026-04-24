#define ENA 9
#define IN1 12 
#define IN2 11
#define ENB 6
#define IN3 7
#define IN4 8

#define SPEED 190
const int trigPin = 2;
const int echoPin = 3;
const int buzzer = 13;

long duration;
int distance;

void moveForwardUntilWall(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  for (int t = 0; t < 1000; t += 50) {
    delay(50);

    int wallDistance = getDistance();

    if (wallDistance <= 50 && wallDistance > 0) {
      moveStop();

      tone(buzzer, 2000);
      delay(10000);
      noTone(buzzer);

      moveBackward();
      moveStop();

      return;
    }
  }
}

void turnRight(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(865);
}

void moveBackward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(700);
}

void moveStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}

int getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 16; i++){
    moveForwardUntilWall();
    moveStop();
    turnRight();
    moveStop();
  }
}
void loop() {

}