#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

#include <Wire.h>
#include <RFduinoBLE.h>

int ADXAddress=0xA7>>1;
int reding = 0;
int val = 0;
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z0,Z1,Z_out;
double Xg,Yg,Zg;

void setup() {

  Serial.begin(9600);
  Wire.begin();
  RFduinoBLE.begin();
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_2D);
  Wire.write(8);
  Wire.endTransmission();
}



void loop() {
  //RFduino_ULPDelay( SECONDS(1) );
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2){
    X0=Wire.read();
    X1=Wire.read();
    X1=X1<<8;
    X_out=X0+X1;
  }


  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2){
    Y0=Wire.read();
    Y1=Wire.read();
    Y1=Y1<<8;
    Y_out=Y0+Y1;
  }

  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2){
    Z0=Wire.read();
    Z1=Wire.read();
    Z1=Z1<<8;
    Z_out=Z0+Z1;
  }
 
  RFduinoBLE.sendFloat(X_out);
  RFduinoBLE.sendFloat(Y_out);
  RFduinoBLE.sendFloat(Z_out);
  //RFduinoBLE.send = (myarray, 5);
}
