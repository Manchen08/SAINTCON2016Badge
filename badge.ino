#include <NewPing.h>
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(13,14,15,1); 
const int FLEX_PIN = A0;

int bend = 0;

/* we always wait a bit between updates of the display */
unsigned long delaytime=35;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,15);
  /* and clear the display */
  lc.clearDisplay(0);
}

void checkPainLvl(){
  bend = analogRead(FLEX_PIN);
  if (bend < 350){
    clearDisp();
    lc.setRow(0,1,B00011101);
    lc.setRow(0,2,B00011100);
    lc.setChar(0,3,'c',false);
    lc.setRow(0,4,B00010111);
    delay(2000);
    clearDisp();
  }
}

void circles(){
  
  for(int i=0; i < 8; i++){
    if(i==2){
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00010000);
      delay(delaytime);
      lc.setRow(0,i,B00100000);
      delay(delaytime);  
      lc.setRow(0,i,B01000000);
      delay(delaytime);
      lc.setRow(0,i,B00000010);
      delay(delaytime);
      lc.setRow(0,i,B00000100);
      delay(delaytime);
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      checkPainLvl();
      
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00011000);
      delay(delaytime);
      lc.setRow(0,i,B00111000);
      delay(delaytime);  
      lc.setRow(0,i,B01111000);
      delay(delaytime);
      lc.setRow(0,i,B00111010);
      delay(delaytime);
      lc.setRow(0,i,B00111100);
      delay(delaytime);
      lc.setRow(0,i,B00111000);
    }else if(i==3){
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00010000);
      delay(delaytime);
      lc.setRow(0,i,B00100000);
      delay(delaytime);  
      lc.setRow(0,i,B01000000);
      delay(delaytime);
      lc.setRow(0,i,B00000010);
      delay(delaytime);
      lc.setRow(0,i,B00000100);
      delay(delaytime);
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      checkPainLvl();
      
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00011000);
      delay(delaytime);
      lc.setRow(0,i,B00011001);
      delay(delaytime);  
      lc.setRow(0,i,B00011101);
      delay(delaytime);
    
    }else if(i==4){
              lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00010000);
      delay(delaytime);
      lc.setRow(0,i,B00100000);
      delay(delaytime);  
      lc.setRow(0,i,B01000000);
      delay(delaytime);
      lc.setRow(0,i,B00000010);
      delay(delaytime);
      lc.setRow(0,i,B00000100);
      delay(delaytime);
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      checkPainLvl();
      
      lc.setRow(0,i,B00001000);
      delay(delaytime);
      lc.setRow(0,i,B00010000);
      delay(delaytime);
      lc.setRow(0,i,B00010001);
      delay(delaytime);  
      lc.setRow(0,i,B00010101);
      delay(delaytime);
    }else{
    lc.setRow(0,i,B00001000);
    delay(delaytime);
    lc.setRow(0,i,B00010000);
    delay(delaytime);
    lc.setRow(0,i,B00100000);
    delay(delaytime);  
    lc.setRow(0,i,B01000000);
    delay(delaytime);
    lc.setRow(0,i,B00000010);
    delay(delaytime);
    lc.setRow(0,i,B00000100);
    delay(delaytime);
    lc.setRow(0,i,B00001000);
    delay(delaytime);
    checkPainLvl();
    lc.setRow(0,i,B00010000);
    delay(delaytime);
    lc.setRow(0,i,B00100000);
    delay(delaytime);  
    lc.setRow(0,i,B01000000);
    delay(delaytime);
    lc.setRow(0,i,B00000010);
    delay(delaytime);
    lc.setRow(0,i,B00000100);
    delay(delaytime);
    lc.setRow(0,i,B10000000);
    delay(delaytime);
    lc.setRow(0,i,B00000000);
    delay(delaytime);
    }
    

  }
}

void inCircle(){
  unsigned long timer = 100;

  //Light up bottom row
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00001000);
    delay(timer); 
  }

  //Round right corner
  lc.setRow(0,7,B00011000);
  delay(timer);
  lc.setRow(0,7,B00111000);
  delay(timer);
  lc.setRow(0,7,B01111000);
  delay(timer);
  
  //Light up top row down
  for(int i=6; i != 0; i--){
    lc.setRow(0,i,B01001000);
    delay(timer); 
  }

  //Round left corner and begin off bottom row
  lc.setRow(0,0,B01001000);
  delay(timer);
  lc.setRow(0,0,B01001010);
  delay(timer);
  lc.setRow(0,0,B01001110);
  delay(timer);
  lc.setRow(0,0,B01000110);
  delay(timer);

  //turn off bottom row
  for(int i=1; i < 7; i++){
    lc.setRow(0,i,B01000000);
    delay(timer); 
  }
  checkPainLvl();
  //round right corner
  lc.setRow(0,7,B01110000);
  delay(timer);
  lc.setRow(0,7,B01100000);
  delay(timer);
  lc.setRow(0,7,B01000000);
  delay(timer);
  
  //turn off top row
  for(int i=7; i != 0; i--){
    lc.setRow(0,i,B00000000);
    delay(timer); 
  }

  //turn off left corner
  lc.setRow(0,0,B00000110);
  delay(timer);
  lc.setRow(0,0,B00000100);
  delay(timer);
}

void dispName(){
  unsigned int timer = 600;
  
  lc.setIntensity(0,3);
  lc.setRow(0,2,B00111000);
  lc.setRow(0,3,B00011101);
  lc.setRow(0,4,B00010101);
  for(int i = 3; i < 16; i++){
    lc.setIntensity(0,i);
    delay(timer);
  }

  lc.setIntensity(0,0);
  delay(timer);
  
  lc.setIntensity(0,15);
  delay(timer);
  checkPainLvl();
  lc.setIntensity(0,0);
  delay(timer);
  lc.setIntensity(0,15);
  delay(timer);
  
  lc.setIntensity(0,0);
  delay(timer);
  lc.setIntensity(0,15);
  delay(timer);
  delay(timer);
  delay(timer);
  delay(timer);

  for(int i = 0; i < 4; i++){
    lc.setRow(0,0+i,B11111111);
    lc.setRow(0,7-i,B11111111);
    delay(200);
  }
  delay(300);
}

void clearDisp(){
  
  for(int i = 0; i < 8; i++){
    lc.clearDisplay(i);
  }
  
}

void psych(){
  int timer = 50;
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B01001000);
    delay(timer); 
  }
  delay(400);
  for(int i=0; i < 10; i++){
    lc.setRow(0,i-2, B01111111);
    lc.setRow(0,i-1, B01001111);
    lc.setRow(0,i,B01001001);
    delay(timer); 
  }

  delay(300);
}

void goodbye(){
  lc.setRow(0,0,B01111011);  
  lc.setRow(0,1,B00011101);
  lc.setRow(0,2,B00011101);
  lc.setRow(0,3,B00111101);
  lc.setRow(0,4,B00011111);
  lc.setRow(0,5,B00111011);
  lc.setRow(0,6,B01001111);
  
  delay(4000);
}
void slowDown(){
  int timer = 1;
  do{
  checkPainLvl();
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00001000); 
  }
  delay(timer);
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00010000); 
  }
  delay(timer);
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00100000); 
  }
  delay(timer);
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B01000000); 
  }
  delay(timer);
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00000010); 
  }
    delay(timer);
  for(int i=0; i < 8; i++){
    lc.setRow(0,i,B00000100); 
  }
    delay(timer); 
    timer++;            
  }while(timer < 50);

  timer = 10;
}

void loop() { 
  goodbye();
  clearDisp();
  circles();
  clearDisp();
  checkPainLvl();
  clearDisp();
  inCircle();
  clearDisp();
  checkPainLvl();
  clearDisp();
  dispName();
  clearDisp();
  checkPainLvl();
  psych();
  clearDisp();
  checkPainLvl();
  clearDisp();
  slowDown();
  clearDisp();
}
