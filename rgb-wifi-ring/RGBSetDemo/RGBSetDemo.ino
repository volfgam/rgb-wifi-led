#include <FastLED.h>
#define NUM_LEDS 12
#define BRIGHTNESS 255
int r;
int g;
int b;

CRGBArray<NUM_LEDS> leds;

void setup() { 
  FastLED.addLeds<NEOPIXEL,5>(leds, NUM_LEDS); 
  //leds.fadeToBlackBy(40);
  desligaTodos();
  FastLED.setBrightness(BRIGHTNESS);
  delay(3000);
}

void loop(){ 
  
  int ledsAcesos = 6;
  corAleatoria();
  for(int i = 0; i < NUM_LEDS; i++) {   
    //if (i != 3 && i != 6 && i != 8) {
      
    //}
    ligaLed(i);  
    int aDesligar = i - ledsAcesos;
    if (aDesligar < 0)
    {
        aDesligar = NUM_LEDS - abs(aDesligar);
    }
    apagaLed(aDesligar);
    
    FastLED.delay(70);
     
  }
}

void apagaLed(int index) {
  leds[index].setRGB(0,0,0);
}

void corAleatoria() {
  r = random8();
  g = random8();
  b = random8();
}

void ligaLed(int index) {
  leds[index].setRGB(r,g,b);
}

void desligaTodos() {
   for(int i = 0; i < NUM_LEDS; i++) {   
     leds[i].setRGB(0,0,0);
   }
}


// fade everything out
    //leds.fadeToBlackBy(40);

    // let's set an led value
    //leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    //leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    //FastLED.delay(33);
    // CHSV( random8(), 255, random8());
