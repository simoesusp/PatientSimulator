/*
  Software serial multple serial test
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 This example code is in the public domain.
 ls --color=never
 */
#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

SoftwareSerial mySerial(7, 8); // RX, TX

byte  serIn;
int code[] = {32,154,149,117}; //This is the stored UID (Unlock Card)
int codeRead = 0;
String rfidCode;
char charBuf[50];

void setup() {
  pinMode(13,OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
 
}

void loop() { // run over and over
  if(mySerial.available()>0){
          serIn = mySerial.read(); 
          Serial.println(char(serIn));       
          if (char(serIn) == '1'){
            while (!rfid.PICC_IsNewCardPresent());
            delay(100);
            readRFID();
            delay(1000);
          }
   serIn = 0;            
  }
}


void readRFID()
{

  rfid.PICC_ReadCardSerial();
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

 
     
  
    printDec(rfid.uid.uidByte, rfid.uid.size);  //imprime o RFID


    // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    rfidCode = rfidCode + buffer[i];
  }
  rfidCode.toCharArray(charBuf, 50);
  mySerial.write(charBuf);

  rfidCode = "";
  memset(buffer, '\0', sizeof(buffer));  
  memset(charBuf, '\0', sizeof(charBuf));   
}
