#include <SoftwareSerial.h>
// if You use SoftwareSerial lib, declare object for GSM
SoftwareSerial mySerial(10, 11);  //(RX,TX)

const int trigPin1 = 8;
const int echoPin1 = 9;
const int led = 13;
char a;

void Robot_Forward()
 {
  digitalWrite(2,1);     //Forward
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
 }

void Robot_Backward()
 {
  digitalWrite(2,0);     //Backward
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
 } 

void Robot_Right()
  {
    digitalWrite(2,1);     //Right
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
  }

void Robot_Left()
  {
    digitalWrite(2,0);     //Left
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
  }

void Robot_Stop()
  {
    digitalWrite(2,0);     //Stop
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
  }

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(led, OUTPUT);
  pinMode(2,OUTPUT);    //Robot
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  Serial.println("Welcome to Android controlled Robot with Obstacle detection");
  mySerial.println("Welcome to Android controlled Robot with Obstacle detection");
  delay(1000);  
}

void loop()
{
 
  long duration1, r1;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH);
  r1 = 3.4 * duration1 / 2;     
  float distance1 = r1 / 100.00;
  
 /* Serial.print("Fire = ");
  Serial.println(distance1);
  delay(500);*/
  
  
 if(distance1 < 30)
  {
    mySerial.println("Obstacle detected\n");
    Serial.println("Obstacle detected\n");
    
    digitalWrite(led,HIGH);
    Robot_Stop();
    delay(500);
  }

 while(mySerial.available())
    {
      a = mySerial.read();
      delay(10);
    
    //Serial.println(c);
  
      if(a=='f')    //FORWARD
       {
          mySerial.println("Forward");
          Serial.println("Forward");
          
          digitalWrite(led,HIGH);
          Robot_Forward();
          delay(50);
          digitalWrite(led,LOW);
          delay(500);
       }
      else if(a=='b')    //BACKWARD
       {
         Serial.println("Backward");
         mySerial.println("Backward");
         
         digitalWrite(led,HIGH);
         Robot_Backward();
         delay(50);
         digitalWrite(led,LOW);
         delay(500);
       }
      else if(a=='l')     //LEFT
       {
         Serial.println("Left");
         mySerial.println("Left");
         
         digitalWrite(led,HIGH);
         Robot_Left();
         delay(50);
         digitalWrite(led,LOW);
         delay(500);
       }

     else if(a=='r')    //RIGHT
      {
        Serial.println("Right");
        mySerial.println("Right");
        
        digitalWrite(led,HIGH);
        Robot_Right();
        delay(50);
        digitalWrite(led,LOW);
        delay(500);
      }
     
     else if(a=='s') 
      {
          Serial.println("Stop");
          mySerial.println("Stop");
          
          digitalWrite(led,LOW);
          Robot_Stop();
          delay(50);
          
      }
  }
}
