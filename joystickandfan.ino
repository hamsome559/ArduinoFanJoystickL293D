// Joystick controls DC motor speed and direction via L293D
// Uses Y-axis only

const int Y_pin = A1;  // Joystick Y-axis
#define ENABLE 10       // L293D EN1,2 (PWM)
#define DIRA 8         // Direction A
#define DIRB 9         // Direction B

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
}

void loop() {
  int y = analogRead(Y_pin);   // Read joystick (0–1023)
  int speedVal = 0;

  if (y > 530) {  // Joystick pushed forward
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    speedVal = map(y, 530, 1023, 0, 255); // Forward speed
  } 
  else if (y < 490) {  // Joystick pulled backward
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    speedVal = map(y, 490, 0, 0, 255);    // Reverse speed
  } 
  else {
    speedVal = 0; // Joystick centered → stop
  }

  analogWrite(ENABLE, speedVal); // Set motor speed
  delay(20); // small delay for stability
}
