#include <Servo.h> 

//Forward  direction pwm pin
const int fpwm = 9;
//Reverse direction pwm pin
const int rpwm = 7;
//Steering servo pwm pin
const int servo_pin = 11;
//Input serial message bytes length
const int msg_length_bytes = 32; //msg = X;XXX;XXX;
//Minimal steering angle allowed in degrees
const int min_angle = 50;
//Maximal steering angle allowed in degrees
const int max_angle = 110;

const int RED = 5;
const int BLUE = 4;
const int GREEN = 3;

int dir, steering, throttle;
char data[msg_length_bytes];

Servo Steer;

void setup() {
  Serial.begin(9600);
  Steer.attach(servo_pin);
  pinMode(fpwm, OUTPUT);
  pinMode(rpwm, OUTPUT);
  
}

void loop() {
  
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
 
  if(Serial.available() > 0){

    analogWrite(RED, 255);
    analogWrite(GREEN, 255);
    analogWrite(BLUE, 255);
    
    Serial.readBytesUntil('.', data, msg_length_bytes);
    sscanf(data, "%01d;%03d;%03d;", &dir, &throttle, &steering);

    //Check if new angle in bounds
    if (steering < min_angle) steering = min_angle;
    if (steering > max_angle) steering = max_angle;
    
    Steer.write(steering);

    if (throttle > 255) throttle = 255;
    
    if (dir == 0) {
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      analogWrite(fpwm, throttle);
      digitalWrite(rpwm, 0);
    }
    else {
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 255);
      digitalWrite(fpwm, 0);
      analogWrite(rpwm, throttle);
    }
    
  }
}
