// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int i = 0;
//long FEEDINGDELAY = 43200000; // 12 hours
  long FEEDINGDELAY = 86400000; // 24 hours
//long FEEDINGDELAY = 60000;

long endtime; 
long now;

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.println("FISH FEEDER 1.1");
  myservo.write(0);
  delay(15);
  
  
  // FEED THE FISH..
  Serial.print("FEEDING FISH NOW ");

  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
 
 
void loop() 
{ 
  // process times
  now = millis();
  endtime = now + FEEDINGDELAY;
  
  while(now < endtime) {
   myservo.write(0);
   Serial.print("soon... ");
   Serial.println(endtime-now);
   delay(20000);
   now = millis();   
  }
  
  // FEED THE FISH..
  Serial.print("FEEDING FISH at ");
  Serial.println(now);
while(i<1) {

  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  i=i+1;
}
while((i>=1) && (i<2)) {
   for(pos =0; pos < 100; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 100; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  i=i+1;
}
}
