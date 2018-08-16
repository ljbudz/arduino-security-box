#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int locked = 180;    // locked position of servo
int unlocked = 90;   // unlocked position of servo

 void setup(){
 myservo.attach(3);  // attaches the servo on pin 3 to the servo object 
 myservo.write(locked); // locks box
 }

 void loop(){
  
 }

