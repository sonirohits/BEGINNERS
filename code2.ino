#include<Servo.h>// include the servo library
Servo myservo;
#define ldr1 A0 // set ldr 1 analog input pin
#define ldr2 A1

int pos=90; // initalizing position of servo motor
int tolerance = 20;
void setup(){
  myservo.attach(9);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  myservo.write(pos);// starting position of servo motor
  delay(1000);
}

void loop(){
 int val1=analogRead(ldr1);// read the value of ldr 1
 int val2=analogRead(ldr2);

 if((abs(val1 -val2)<= tolerance)  ||  (abs(val2-val1)<=tolerance))
{
}
else{
  if(val1>val2){
    pos = pos+1;// decreament the 90 degree position of the horizontal servo motor
  }
  if(val1 < val2){
    pos =pos-1; // increament 
  }
}
if(pos>180){
  pos = 180;
}
if(pos < 0){
  pos= 0;
}
myservo.write(pos); // write starting position of motor
delay(100);
}


