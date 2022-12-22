#include <SPI.h>
#include "RF24.h"

#define button 2

RF24 radio(7, 8); //CE, SS

uint8_t address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //PC와 아두이노간 통신라인
  radio.begin(); //아두이노-RF모듈간 통신라인
  radio.setPALevel(RF24_PA_MAX); 
  radio.openWritingPipe(address);
  radio.stopListening();

  pinMode(button,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  if(digitalRead(button) == LOW){
    //버튼이 눌려진경우
    c = '1';
  }else{
    //버튼이 눌려지지 않은 경우
    c = '0';
  }
  radio.write(&c,sizeof(c));
  delay(10);
}