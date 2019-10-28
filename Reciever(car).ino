/*NRF MODULE SINGLE STRUCT CODE 
 MAHEDEE,CSE Arduino Wireless Communication 
RECIEVER  SETUP 
*/    #define inA 38  //// low , high te froward e jabe   
#define inB 39   
#define inC 44  
#define inD 45   
#define ena 12    
#define enb 11

//////////////////           ////////////
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

 typedef struct{    //  STRUCT DFN
  int A;
  int B;
}
A_t;

A_t duino1;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int xx [1] ;


void setup() {
  Serial.begin(57600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();


  //////////////


    pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);
}
void loop() {
  if (radio.available()) {
  bool dd = false; 
  while (radio.available())
  {
   radio.read(&duino1,sizeof(duino1));
   
    Serial.print ("x = ");
    Serial.print(duino1.A);
    Serial.print ("\t");
     Serial.print ("y = ");
    Serial.println(duino1.B);
    if(x>=-10&&x<=10 && y>=-10&&y<=10)
  {
    ////gari daraye thakbe
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
    analogWrite(ena,0);
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
    analogWrite(enb,0);
    delay (5000);
  }
  else if(x>=35&&x<=50 && y>=-10&&y<=10)
  {
    ////gari shamne/front e jabe
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
    analogWrite(ena,200);
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
    analogWrite(enb,200);
    delay (5000);
  }

   else if(x>=-35&&x<=-50 && y>=-10&&y<=10)
  {
    ////gari piche/back e jabe
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
    analogWrite(ena,150);
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
    analogWrite(enb,150);
    delay (5000);
  }

  else if(x>=-10&&x<=10 && y>=-35&&y<=-50)
  {
    ////gari bame/left e jabe
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
    analogWrite(ena,100);
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
    analogWrite(enb,100);
    delay (5000);
  }
  else if(x>=-10&&x<=10 && y>=35&&y<=50)
  {
    ////gari dane/right e jabe
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
    analogWrite(ena,100);
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
    analogWrite(enb,100);
    delay (5000);
  }
  }
}
}
