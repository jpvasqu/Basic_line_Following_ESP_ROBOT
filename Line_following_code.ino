// Define motor control pins
int MOTOR_PIN1 = D3; // Motor pin 1 connected to GPIO pin D3
int MOTOR_PIN2 = D4; // Motor pin 2 connected to GPIO pin D4
int MOTOR_PIN3 = D5; // Motor pin 3 connected to GPIO pin D5
int MOTOR_PIN4 = D6; // Motor pin 4 connected to GPIO pin D6
int MOTOR_SPEED = 180; // Motor speed

// Define IR sensor pins
int LEFT_SENSOR = D0; // Left IR sensor connected to analog pin A0
int RIGHT_SENSOR = D1; // Right IR sensor connected to analog pin A1

void setup() {
  // Set motor pins as outputs
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);
  
  // Set sensor pins as inputs
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
}

void loop() {
  int LS = digitalRead(LEFT_SENSOR);
  int RS = digitalRead(RIGHT_SENSOR);

  if(LS == LOW){
    right_turn();
  }

  else if(RS == LOW){
    left_turn();
  }
  else if(LS == HIGH && RS == HIGH){
    forward();
  }

}

void forward(){
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, LOW);

  digitalWrite(MOTOR_PIN3, HIGH);
  digitalWrite(MOTOR_PIN4, LOW);
}
void left_turn(){
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, LOW);

  digitalWrite(MOTOR_PIN3, LOW);
  digitalWrite(MOTOR_PIN4, HIGH);
}
void right_turn(){
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, HIGH);

  digitalWrite(MOTOR_PIN3, HIGH);
  digitalWrite(MOTOR_PIN4, LOW);
}
