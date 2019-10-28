/*NRF MODULE SINGLE STRUCT CODE 
 SUPTO,MCE Arduino Wireless Communication 
TRANSMITTER SETUP 
*/      
              
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

typedef struct{                         // Struct dfn
  int A;
  int B;  // add multiple variable if needed 

}
A_t;

A_t duino1; 

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
/////////////    SENSOR PART ///////////      
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

MPU6050 mpu;

int16_t accY, accZ,accX;
int accAnglexx  ;
int accAngleyy ;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  
  mpu.initialize(); // SENSOR INITIALIZATION
}
void loop() {
  
///////////// SENSOR READING ///////////////
  accZ = mpu.getAccelerationZ();
  accY = mpu.getAccelerationY();
  accX = mpu.getAccelerationX();
  
   
  accAnglexx = atan2(accY, accZ)*RAD_TO_DEG; // X AXIS ER VALUE
  if(isnan(accAnglexx));
  else
  duino1.A =accAnglexx;
  Serial.print("x=");
  Serial.print( accAnglexx);
  Serial.print("\t");
   
   
  accAngleyy = atan2(accX, accZ)*RAD_TO_DEG; // Y ER VALUE 
  if(isnan(accAngleyy));
  else
  duino1.B=accAngleyy;
  Serial.print("y=");
  Serial.println( accAngleyy);

  radio.write (&duino1,sizeof(duino1));//// SENDING THE VALUE
    
}
