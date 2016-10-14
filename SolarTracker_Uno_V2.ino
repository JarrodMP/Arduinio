// my Library C:\ArduinoProjects\Arduino\libraries
// or default installed ones 
// C:\Users\Jarrod\Documents\Arduino\libraries
// how to use http://playground.arduino.cc/Code/SimpleTimer
// add lirary in sketch include lirary down load from http://playground.arduino.cc/Code/SimpleTimer#GetTheCode
#include <SimpleTimer.h> ;
 //Global variables accessed from all functions 

 int Direction = 0;
 
// Values for direction
int directionEast=  -1;
int directionWest=  1;
// initialize
bool isiteast = -1;
bool isitwest = -1;

int firstRelay = 10;
int secondRelay = 11;
   


int lightPinA = 12;
int lightPinB = 13;

// the timer object
SimpleTimer timer;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println("Uptime (Minutes): 0 ");
Serial.println("Start timer    ");
//timer.setInterval(4*500, rapidRead);
timer.setInterval(1*10*1000, repeatMe);//10 seconds
Serial.println("  whereisthesun()     ");
timer.setInterval(1*1000, whereisthesun); // 1 seconds

}

void loop() {
  // put your main code here, to run repeatedly:
 timer.run();
}

void rapidRead() {
  // use to do tests

}


// a function to be executed periodically
void repeatMe() {
    Serial.print("Uptime (seconds): ");
    Serial.println((millis() / 1000));//millis are 1 000 thousand of a sec 
}

 void  whereisthesun()
      {
    
      delay(100);
      pinMode(lightPinA, INPUT);
      pinMode(lightPinB, INPUT);
      delay(100);
      isiteast = digitalRead(lightPinA);
      isitwest = digitalRead(lightPinB);
      delay(100); 
      Serial.print(" isiteast  ");Serial.print(isiteast);Serial.println(" OK ");
      Serial.print(" isitwest  ");Serial.print(isitwest);Serial.println(" OK ");
      delay(100); 

    if   ( isiteast  == 0  and   isitwest == 0   )
    {
    
    }
     
    if   ( isiteast  == 0  and   isitwest == 0   )
      {
         Serial.println("It is to  Dark   ");
         delay(100); 
         
         pinMode(firstRelay, OUTPUT);
         pinMode(secondRelay, OUTPUT);
        
         digitalWrite(firstRelay,LOW);
         digitalWrite(secondRelay, LOW);
         delay(100); 
       }                      
       else
       {
          if ( isiteast == 1 and isitwest == 1 ) 
          {
            
                  
            Serial.println("It Aligned    " ) ;
              
              pinMode(firstRelay, OUTPUT);
              pinMode(secondRelay, OUTPUT);
                      
              digitalWrite(firstRelay, HIGH);
              digitalWrite(secondRelay, HIGH);
              delay(100); 
                    
             
           }
           else 
           {
                                                   
              if (isiteast == 1 ) 
              {
              
               Serial.println("                          in the east   ");
              
              RunMotorAnalogue(directionEast) ;
               
              }
                       
                if (isitwest == 1 ) 
                {
                   
               Serial.println("                          in the west   ");
                 RunMotorAnalogue(directionWest) ;
                      
                 }
           }
           delay(100);         
          }  
}


void RunMotorAnalogue(int Direction) 
{
   Serial.println(" Initialize motor ");
    delay(100);
    pinMode(firstRelay, OUTPUT);
    pinMode(secondRelay, OUTPUT);

 if (Direction == 0 ) //standstill
        {
        
             Serial.println("                              stand still    " );
    
        }  

        if (Direction == -1 ) //east
        {

           pinMode(firstRelay, OUTPUT);
          pinMode(secondRelay, OUTPUT);
          delay(100);
            digitalWrite(firstRelay, LOW);
            digitalWrite(secondRelay, HIGH);
             Serial.println("                              Running motor East " );
    
        }    
            
        else
        {
          if (Direction == 1 ) // west
          {
             pinMode(firstRelay, OUTPUT);
          pinMode(secondRelay, OUTPUT);
          delay(100);
            digitalWrite(firstRelay, HIGH);
            digitalWrite(secondRelay, LOW);
            Serial.println("                               Running motor West " );
          }
          
        }
        delay(100); 
}



