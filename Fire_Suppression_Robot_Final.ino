// RUN CODE WHEN 6 FEET AWAY FROM FIRE

// DEFINE PARAMETERS
const int on = 2;                   // LINEAR ACTUATOR (TRIGGER) DOWN/ON RELAY
const int off = 3;                  // LINEAR ACTUATOR (TRIGGER) UP/OFF RELAY
const int down = 4;                 // LINEAR ACTUATOR (ARM) DOWN RELAY
const int up = 5;                   // LINEAR ACTUATOR (ARM) UP RELAY
const int speed_l = 6;              // LEFT DC MOTOR SPEED RELAY
const int LM1 = 7;                  // LEFT DC MOTOR FORWARD
const int LM2 = 8;                  // LEFT DC MOTOR BACKWARD
const int speed_r = 11;             // RIGHT DC MOTOR SPEED RELAY
const int RM1 = 12;                 // RIGHT DC MOTOR FORWARD
const int RM2 = 13;                 // RIGHT DC MOTOR BACKWARD
int right_s = A0;                   // FLAME SENSOR INTERFACE (RIGHT)
int center_s = A1;                  // FLAME SENSOR INTERFACE (CENTER)
int left_s = A2;                    // FLAME SENSOR INTERFACE (LEFT)
int top_s = A3;                     // FLAME SENSOR INTERFACE (TOP)
int bottom_s = A4;                  // FLAME SENSOR INTERFACE (BOTTOM)
boolean fire = false;

// INPUT AND OUTPUTS
void setup() {
    Serial.begin(9600);
    pinMode(off, OUTPUT);           // LINEAR ACTUATOR (TRIGGER) UP/OFF OUTPUT
    pinMode(on, OUTPUT);            // LINEAR ACTUATOR (TRIGGER) DOWN/ON OUTPUT
    pinMode(up, OUTPUT);            // LINEAR ACTUATOR (ARM) UP OUTPUT
    pinMode(down, OUTPUT);          // LINEAR ACTUATOR (ARM) DOWN OUTPUT
    pinMode(speed_l, OUTPUT);       // LEFT DC MOTOR SPEED OUTPUT
    pinMode(LM1, OUTPUT);           // LEFT DC MOTOR FOWARD OUTPUT
    pinMode(LM2, OUTPUT);           // LEFT DC MOTOR BACKWARD OUTPUT
    pinMode(speed_r, OUTPUT);       // RIGHT DC MOTOR SPEED OUTPUT
    pinMode(RM1, OUTPUT);           // RIGHT DC MOTOR FORWARD OUTPUT
    pinMode(RM2, OUTPUT);           // RIGHT DC MOTOR SPEED OUTPUT
    pinMode(right_s, INPUT);        // FLAME SENSOR INPUT (RIGHT)
    pinMode(center_s, INPUT);       // FLAME SENSOR INPUT (CENTER)
    pinMode(left_s, INPUT);         // FLAME SENSOR INPUT (LEFT)
    pinMode(top_s, INPUT);          // FLAME SENSOR INPUT (TOP)
    pinMode(bottom_s, INPUT);       // FLAME SENSOR INPUT (BOTTOM)
}

void loop() {
  // IF NO FIRE DETECTED
  if (digitalRead(bottom_s) == 1 && digitalRead(center_s) == 1 && digitalRead(top_s) == 1) {

    // HALT ARM AND TRIGGER OFF
    digitalWrite(down, LOW);
    digitalWrite(up, LOW);
    digitalWrite(off, HIGH);
    digitalWrite(on, LOW);

  }

  // IF CENTER OR TOP SENSOR DETECTS FIRE
  if (digitalRead(center_s) == 0 || digitalRead(top_s) == 0) {

    // MOVE ARM UP
    digitalWrite(down, LOW);
    digitalWrite(up, HIGH);
  }

  // IF BOTTOM SENSOR DETECTS FIRE
  if (digitalRead(bottom_s) == 0) {

    // EXTINGUISH FIRE AND RETRACT
    digitalWrite(down, LOW);
    digitalWrite(up, LOW);
    digitalWrite(off, LOW);
    digitalWrite(on, HIGH);
    delay(3000);
    digitalWrite(off, HIGH);
    digitalWrite(on, LOW);
    delay(1000);
    digitalWrite(down, HIGH);
    digitalWrite(up, LOW);
    delay(3000);   

  }
 }
