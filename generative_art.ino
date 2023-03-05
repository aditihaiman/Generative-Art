#include "TFT_eSPI.h"
#include "image.h"
TFT_eSPI tft= TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

//image scrolling code from https://github.com/VolosR/ImageScroll


int imageW=480;
int imageH=299;

int screenW=240;
int screenH=135;
int m=imageW;

int start=1;
unsigned short imageS[32400]={0}; //screenW * screen H


void setup() {
tft.init();
tft.setRotation(1);

tft.fillScreen(TFT_BLACK);

sprite.createSprite(240, 135);
sprite.setTextColor(TFT_RED);
sprite.setTextSize(6);
sprite.fillSprite(TFT_BLACK);
sprite.setSwapBytes(true);



}

int pos=0;
int x=random(240);
int y=random(135);
int changeX=1;
int changeY=1;

void loop() {
  //sprite.fillScreen(TFT_BLACK);

  pos=x+imageW*y;
  start=pos;
  m=screenW+pos;
  for(int i=0;i<screenW*screenH;i++)
  {
  if(start%m==0)
  {
  start=start+(imageW-screenW);
  m=m+imageW;
  }
  imageS[i]=birds[start];
  start++;
  
  }
  x=x+changeX;
  if(x==imageW-screenW-1 || x<0)
  changeX=changeX*-1;

   y=y+changeY;
  if(y==imageH-screenH-1 || y<0)
  changeY=changeY*-1;
  
  sprite.pushImage(0,0,screenW,screenH,imageS);

  sprite.drawString("EXTINCT", 0, 50);

  sprite.pushSprite(0, 0);

  

}
