#include <AFMotor.h> 
 
AF_DCMotor motor3(3, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR12_1KHZ); 
const int pingPin = 22; 
// ------------------------------------------------------------------------------
void setup() 
{ 
  Serial.begin(9600);                 // set up Serial library at 9600 bps 

  motor3.setSpeed(200); 
  motor4.setSpeed(200); 
} 
long microsecondsToInches(long microseconds){ 
  return microseconds / 74 / 2; 
} 
// ------------------------------------------------------------------------------
long ping ()                       // This is the code that runs the PING ))) Sensor 
{ 
  long duration, inches; 
  pinMode(pingPin, OUTPUT); 
  digitalWrite(pingPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(pingPin, HIGH); 
  delayMicroseconds(5); 
  digitalWrite(pingPin, LOW); 
  pinMode(pingPin, INPUT); 
  duration = pulseIn(pingPin, HIGH);  
  inches = microsecondsToInches(duration); 
  return inches; 
} // ------------------------------------------------------------------------------
void forward()                    // This function moves all the wheels forward 
{ 
  
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD); 
} 
// ------------------------------------------------------------------------------
void backward()                    // This function moves all the wheels backwards 
{     
  
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
} 
// ------------------------------------------------------------------------------
void haltMotors()                   // This function stops all the motors (It is better to stop the motors before changing direction) 
{ 

  motor3.run(RELEASE); 
  motor4.run(RELEASE);
} 
// ------------------------------------------------------------------------------
void turnRight()                    // This function turns the robot right
{

  motor3.run(FORWARD); 
  motor4.run(BACKWARD); 
} 
// ------------------------------------------------------------------------------
void loop() {                         // This is the main program that will run over and over
  long duration, inches;                // Declare the variables "duration" and "inches"duration = pulseIn(pingPin, HIGH); 
  inches = ping();                      // Set the inches variable to the ﬂoat returned by the ping() function. 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();
  
  while (inches > 8){                    // While the robot is 8 inches away from an object. 
    inches = ping(); 
    forward();                            // Move the robot forward. 
  } 
  haltMotors();                         // Stop the motors for 2 seconds, before changing direction. 
  delay(1000);             
  while (inches < 10){                  // Until the robot is 10 inches away from the object, go backward. 
    inches = ping(); 
    backward();                           // Move the robot backward. 
  } 
  turnRight();                          // Once the robot is done moving backward, turn the robot right. 
  delay(1500);                          // Note!  Change this value (greater or smaller) to adjust how much the robot turns right 
  haltMotors(); 
  delay(1000); 
} 
