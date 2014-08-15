
#include "Wire.h"
#define AltAddress 0x76 // Master Read from Address, the device address is 0xed

void setup()
{
  Wire.begin(); // wake up I2C bus
  Serial.begin(9600);
  
  // Send reset sequence once system is powered on
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0x1E); // reset sequence for the sensor during startup
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  
 // Read C1 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA2); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C1byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C1byte1);
  byte C1byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C1byte2);
  
  unsigned int C1 = ((C1byte1<<8) | C1byte2);
  Serial.println("coefficient C1:  ");
  Serial.println(C1);
  
   // Read C2 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA4); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C2byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C2byte1);
  byte C2byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C2byte2);
  
  unsigned int C2 = ((C2byte1<<8) | C2byte2);
  Serial.println("coefficient C2:  ");
  Serial.println(C2);
  
     // Read C3 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA6); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C3byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C3byte1);
  byte C3byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C3byte2);
  
  unsigned int C3 = ((C3byte1<<8) | C3byte2);
  Serial.println("coefficient C3:  ");
  Serial.println(C3);
  
  
       // Read C4 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA8); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C4byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C4byte1);
  byte C4byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C4byte2);
  
  unsigned int C4 = ((C4byte1<<8) | C4byte2);
  Serial.println("coefficient C4:  ");
  Serial.println(C4);
    
       // Read C5 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xAA); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C5byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C5byte1);
  byte C5byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C5byte2);
  
  unsigned int C5 = ((C5byte1<<8) | C5byte2);
  Serial.println("coefficient C5:  ");
  Serial.println(C5);
  
       // Read C6 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xAE); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C6byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C6byte1);
  byte C6byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C6byte2);
  
  long C6 = (long)C6byte1<<8 | (long)C6byte2;
  Serial.println("coefficient C6:  ");
  Serial.println(C6);
//  
  // get all of the coefficients C1: 0xA2, C2: 0xA4, C3: 0xA6, C4: 0xA8, C5: 0xAA, C6: 0xAE. 
  
  
}
 
void getAltData(byte *a, byte *b, byte *c)
{
  
  //I2C command to initiate a pressure conversion
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0x50); // Command to initiate pressure conversion for D1
  Wire.endTransmission(); // "Thanks, goodbye..."
  delay(500);
  // I2C ADC read Sequence
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0x00); // "ADC read command
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // now get the data from the ADC
  Wire.requestFrom(AltAddress, 3); // "Hey, CN75 @ 0x48 - please send me the contents of your first three registers"
  *a = Wire.read(); // first received byte stored here
  *b = Wire.read(); // second received byte stored here
  *c = Wire.read(); // third received byte stored here
}
 
void showCN75data()
{
  
  
 // Read C1 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA2); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C1byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C1byte1);
  byte C1byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C1byte2);
  
  unsigned int C1 = ((C1byte1<<8) | C1byte2);
  Serial.println("coefficient C1:  ");
  Serial.println(C1);
  
   // Read C2 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA4); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C2byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C2byte1);
  byte C2byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C2byte2);
  
  unsigned int C2 = ((C2byte1<<8) | C2byte2);
  Serial.println("coefficient C2:  ");
  Serial.println(C2);
  
     // Read C3 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA6); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C3byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C3byte1);
  byte C3byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C3byte2);
  
  unsigned int C3 = ((C3byte1<<8) | C3byte2);
  Serial.println("coefficient C3:  ");
  Serial.println(C3);
  
  
       // Read C4 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xA8); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C4byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C4byte1);
  byte C4byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C4byte2);
  
  unsigned int C4 = ((C4byte1<<8) | C4byte2);
  Serial.println("coefficient C4:  ");
  Serial.println(C4);
  
       // Read C5 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xAA); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C5byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C5byte1);
  byte C5byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C5byte2);
  
  unsigned int C5 = ((C5byte1<<8) | C5byte2);
  Serial.println("coefficient C5:  ");
  Serial.println(C5);
  
       // Read C6 coefficient from Prom
 // I2C command to read memory address
  Wire.beginTransmission(AltAddress); // "Hey, CN75 @ 0x48! Message for you"
  Wire.write(0xAE); // I2C command to read memory address
  Wire.endTransmission(); // "Thanks, goodbye..."
  
  // Command to read Prom
  Wire.requestFrom(AltAddress, 2); // "Hey, CN75 @ 0x48 - please send me the contents of your first two registers"
  //Serial.println("PromReadByte1:  ");
  byte C6byte1 = Wire.read(); // first received byte stored here
  //Serial.println(C6byte1);
  byte C6byte2 = Wire.read(); // second received byte stored here
  //Serial.println("PromReadByte2:  ");
  //Serial.println(C6byte2);
  
  long C6 = (long)C6byte1<<8 | (long)C6byte2;
  Serial.println("coefficient C6:  ");
  Serial.println(C6);
  
  // get all of the coefficients C1: 0xA2, C2: 0xA4, C3: 0xA6, C4: 0xA8, C5: 0xAA, C6: 0xAE. 
  
  
  byte aa,bb,cc;
  //float temperature=0;
  getAltData(&aa,&bb,&cc);
  Serial.println("first byte: ");
  Serial.println(aa,BIN);
  Serial.println("second byte: ");
  Serial.println(bb,BIN);
  Serial.println("third byte: ");
  Serial.println(cc,BIN);

  long D2 = (long)aa<<16 | (long)bb<<8 | (long)cc;
  Serial.println("coefficient D2:  ");
  Serial.println(D2);
  
  delay(2000);
}
 
void loop()
{
  showCN75data();
}
