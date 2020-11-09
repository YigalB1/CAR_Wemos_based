#include "arduino.h"
//#include "WEMOS_Motor.h"
#include "Wemos_motor_classes.h"

int pwm;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30,_MOTOR_A, 1000);//Motor A
Motor M2(0x30,_MOTOR_B, 1000);//Motor B


void setup() {
  //Serial.begin(250000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {



  digitalWrite(LED_BUILTIN, HIGH);   // Arduino: turn the LED on (HIGH)
                                     // D1 Mini: turns the LED *off*
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // Arduino: turn the LED off (LOW)
                                     // D1 Mini: turns the LED *on*
  delay(1000);                       // wait for a second
  return;

  for (pwm = 0; pwm <= 100; pwm++)
  {
    M1.setmotor( _CW, pwm);
    M2.setmotor(_CW, 100-pwm);
    //Serial.printf("A:%d%, B:%d%, DIR:CW\r\n", pwm,100-pwm);
  }
  
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  Serial.println("Motor A&B STOP");
  delay(200);
  
  for (pwm = 0; pwm <=100; pwm++)
  {
    M1.setmotor(_CCW, pwm);
    M2.setmotor(_CCW, 100-pwm);
    //Serial.printf("A:%d%, B:%d%, DIR:CCW\r\n", pwm,100-pwm);

  }
  
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  delay(200);
  Serial.println("Motor A&B STOP");

  M1.setmotor(_SHORT_BRAKE);
  M2.setmotor( _SHORT_BRAKE);
  Serial.println("Motor A&B SHORT BRAKE");  
  delay(1000);
  
  M1.setmotor(_STANDBY);//Both Motor standby
  //M2.setmotor( _STANDBY);
  Serial.println("Motor A&B STANDBY");  
  delay(1000);
  
}