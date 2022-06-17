const int trigPin1 = 10;
const int echoPin1 = 11;
const int flame =12;

char a;
 int ena = 6;
int enb=9;
int RMA =2;
int RMB = 3;
int LMA = 8;
int LMB = 5;

void Robot_Forward()
 {
    analogWrite(ena,255);
   analogWrite(enb,255);
  digitalWrite(RMA,1);     //Forward
  digitalWrite(RMB,0);
  digitalWrite(LMA,1);
  digitalWrite(LMB,0);
 }

void Robot_Backward()
 {  analogWrite(ena,255);
   analogWrite(enb,255);
  digitalWrite(RMA,0);     //Backward
  digitalWrite(RMB,1);
  digitalWrite(LMA,0);
  digitalWrite(LMB,1);
 } 

void Robot_Right()
  {  analogWrite(ena,255);
   analogWrite(enb,255);
    digitalWrite(RMA,1);     //Right
    digitalWrite(RMB,0);
    digitalWrite(LMA,0);
    digitalWrite(LMB,1);
  }

void Robot_Left()
  {  analogWrite(ena,255);
   analogWrite(enb,255);
    digitalWrite(RMA,0);     //Left
    digitalWrite(RMB,1);
    digitalWrite(LMA,1);
    digitalWrite(LMB,0);
  }

void Robot_Stop()
  {  analogWrite(ena,255);
   analogWrite(enb,255);
    digitalWrite(RMA,0);     //Stop
    digitalWrite(RMB,0);
    digitalWrite(LMA,0);
    digitalWrite(LMB,0);
  }

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(flame, INPUT);

  pinMode(RMA,OUTPUT);    //Robot
  pinMode(RMB,OUTPUT);
  pinMode(LMA,OUTPUT); 
  pinMode(LMB,OUTPUT);
    
  Serial.begin(9600);
  Serial.println("Welcome to Android controlled Spying ROBOT");

  
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
  

  
  


  Serial.println("Robot test");
 while(Serial.available())
    {
       Serial.println("Robot test1");
      a = Serial.read();
      delay(10);
    
    //digitalWrite(led,LOW);
    //Serial.println(c);
   if(distance1 < 30)
  {
   
  
    
    Robot_Backward();
      delay(500);
    Robot_Stop();
     
  }

     else if(a=='F')    //FORWARD
       {
          Serial.println("Forward");
         
          Robot_Forward();
         
          
         
       }
      else if(a=='B')    //BACKWARD
       {
         Serial.println("Backward");
        
         Robot_Backward();
         
       
         
       }
      else if(a=='L')     //LEFT
       {
         Serial.println("Left");
         
         Robot_Left();
         
         
        
       }

     else if(a=='R')    //RIGHT
      {
        Serial.println("Right");
        
        Robot_Right();
       
        
        
      }
     
     else if(a=='S') 
      {
          Serial.println("Stop");

          Robot_Stop();
         
      }
  }
}
