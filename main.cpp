#include <Arduino.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>

#define HALF_ANDROID

#ifdef HALF_ANDROID
  #define M_FORWARD 'A'
  #define M_BACKWARD 'I'
  #define M_LEFT 'S'
  #define M_RIGHT 'D'
  #define M_STOP 'F'
  #define AUTO 'U'
  #define LUCI_ON  'J'
  #define LUCI_OFF 'O'
#else #ifdef RC_APP
  #define M_FORWARD 'F'
  #define M_BACKWARD 'B'
  #define M_LEFT 'L'
  #define M_RIGHT 'R'
  #define M_STOP 'S'
  #define AUTO 'X'
  #define LUCI_ON  'W'
  #define LUCI_OFF 'w'
#endif

AF_DCMotor right_motor(2);
AF_DCMotor left_motor (3);

const int right_speed = 255;
const int left_speed  = 230;

#define led_1 A0
#define led_2 A1

const int trig_pin = 4;
const int echo_pin = 5;
bool auto_state = false;
int n_auto = 0;

const int tx = 2;
const int rx = 3;
char c;

SoftwareSerial blue(tx,rx);

void forward()
{
    right_motor.setSpeed(right_speed);
    left_motor.setSpeed(left_speed);
    right_motor.run(FORWARD);
    left_motor.run(FORWARD);
}

void backward()
{
    right_motor.setSpeed(right_speed);
    left_motor.setSpeed(left_speed);
    right_motor.run(BACKWARD);
    left_motor.run(BACKWARD);
}

void left()
{
    right_motor.setSpeed(right_speed);
    left_motor.setSpeed(0);
    right_motor.run(FORWARD);
    left_motor.run(RELEASE);
}

void right()
{
    right_motor.setSpeed(0);
    left_motor.setSpeed(left_speed);
    left_motor.run(FORWARD);
    right_motor.run(RELEASE);
}

void m_stop()
{
    right_motor.setSpeed(0);
    left_motor.setSpeed(0);
    right_motor.run(RELEASE);
    left_motor.run(RELEASE);
    auto_state = false;
}

void luci_on()
{
  analogWrite(led_1, 255);
  analogWrite(led_2, 255);
}

void luci_off()
{
  analogWrite(led_1, 0);
  analogWrite(led_2, 0);
}

void guida_autonoma()
{
  auto_state = true;
  right_motor.run(FORWARD);
  left_motor.run(FORWARD);
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  
  int dis = duration * 0.034 / 2; 
  Serial.println(dis);
  
  if(dis <= 10) {
    left_motor.run(FORWARD);
    right_motor.run(RELEASE);
  }
}

void setup()
{
  blue.begin(9600);
  Serial.begin(9600);
  luci_off();
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop()
{
  if(blue.available())
  {
    c = blue.read();
    Serial.println(c);
  }

  
  if(c == M_FORWARD) forward();
  if(c == M_BACKWARD) backward();
  if(c == M_RIGHT) right();
  if(c == M_LEFT) left();
  if(c == M_STOP) m_stop();
  if(c == LUCI_ON) luci_on();
  if(c == LUCI_OFF) luci_off();
}
