#include <Servo.h>
char Button = 8;
int claw=0;
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
void start();
void initial();
void setup() 
{
//initializing the button to have a pullup resistor from the arduino
pinMode(Button,INPUT_PULLUP);

 //initializing the motors to the arduino
 motor1.attach(1);
 motor2.attach(2);
 motor3.attach(3);
 motor4.attach(4);
 motor5.attach(5);
 
//setting all the positions of the servos to zero
 motor1.write(0);
 motor2.write(0);
 motor3.write(0);
 motor4.write(0);
 motor5.write(0);

}

void loop() {
 //checking the status of the button whether its pressed or not
  bool button_state = digitalRead(Button);
  if(button_state== true)
{
  //if the button is pressed the sequence will be initialized with a 120*pi/180 for the claw *it can be changed actually based on the mechanical design*
  void start();
}
else if(button_state==false)
{
  //if the button is not pressed the motors will be reset to the inital values
  void initial();
}



}
//the sequence for the robot movement
void start(){
  motor1.write(90);
  delay(5000);
  motor2.write(45);
  delay(5000);
  motor3.write(90);
  delay(5000);
  motor4.write(90);
  delay(5000);
  motor5.write(120);
  delay(5000);
  motor1.write(0);
  delay(5000);
  motor2.write(90);
  delay(5000);
  motor5.write(0);
  delay(5000);
  motor2.write(0);
}
//the initial value for and the reseting for the ARM
void initial(){
  motor1.write(0);
  delay(5000);
  motor2.write(30);
  delay(5000);
  motor3.write(0);
  delay(5000);
  motor4.write(0);
  delay(5000);
  motor5.write(0);
  delay(5000);
}
