const int RIGHT_PWM_PIN = 5;
const int LEFT_PWM_PIN = 6;
const int RIGHT_ENABLE_PIN = 9;
const int LEFT_ENABLE_PIN = 10;
const int PWM_INPUT_PIN = 3;


const int PWM_FREQ = 1000;
const int DUTY_CYCLE = 255;


void setup() {

  pinMode(RIGHT_PWM_PIN,OUTPUT);
  pinMode (LEFT_PWM_PIN,OUTPUT);

 
  pinMode(RIGHT_ENABLE_PIN, OUTPUT);
  pinMode(LEFT_ENABLE_PIN, OUTPUT);

 
  Serial.begin(9600);
}

void loop() {
 
  int input_pwm = pulseIn(PWM_INPUT_PIN, HIGH, 20000); 
 
  
  int right_duty_cycle, left_duty_cycle;
  if (input_pwm >= 1505) {
    right_duty_cycle = map(input_pwm, 1500, 2000, 0, DUTY_CYCLE);
    left_duty_cycle = 0;
  } 
  if (input_pwm <= 1493) {
    right_duty_cycle = 0;
    left_duty_cycle = map(input_pwm, 1500, 1000, 0, DUTY_CYCLE);
  }
 
 
  analogWrite(RIGHT_PWM_PIN, right_duty_cycle);
  analogWrite(LEFT_PWM_PIN, left_duty_cycle);
 


 
  delay(100);
}