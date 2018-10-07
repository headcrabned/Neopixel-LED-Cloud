/*
Animated LED cloud with multiple weather patterns
Connect a strip of addressable LEDs to an arduino with GND to GND, LED power to Vin, and LED data to Pin 6
Tested on an Arduino Uno with Adafruit neopixels. Will work with other strips, but 
will require changes to the the "strip" settings below.

With 30 LEDs, it can be powered over USB, or a good 2A external phone charging battery connected to the arduino.

To build, place in a folder named "Cloud_Main", open "Cloud_Main.ino" with the Arduino IDE.
In the Arduino IDE, select your matching board, and use the plugin manager to install the Adafruit_NeoPixel library.

To construct a cloud, tape 2 wire coat hangers together, both upright with a right angle between them.
Tape the Arduino up near the hooks, and arrange the LED strip to wind throughout the volume, facing outwards as
much as possible.

Then fill that volume with polyester fill (which goes in stuffed animals) to cover the LEDs. Clear tape can help
keep the cloud together. Arrange the polyfill so that the hangers and LED strip are hidden.
*/

#include <Adafruit_NeoPixel.h>
#define PIN 6
#define ledCount 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledCount, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)
//Adafruit_NeoPixel stripOld = Adafruit_NeoPixel(ledCount, 7, NEO_GRB + NEO_KHZ800);
//Adafruit_Neopixel stripNew = Adafruit_NeoPixel(ledCount, 8, NEO_GRB + NEO_KHZ800);
int oldR[ledCount];
int oldG[ledCount];
int oldB[ledCount];

int newR[ledCount];
int newG[ledCount];
int newB[ledCount];
int nmax = 255;


//---LED FX VARS
int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 150;                //-HUE (0-255)
int ibright = 50;             //-BRIGHTNESS (0-255)
int isat = 240;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR
int TOP_INDEX = ledCount/2;
int BOTTOM_INDEX = 0;
int thissat = 255;
int EVENODD = ledCount%2;
int time = 0;
int sunnyBrightness = 200;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0)); //EXTRA RANDOMNESS!!!!!
}
void loop() {
  boolean DemoMode = true;
  
  if(DemoMode){
    long time = millis();
    time /= 15000;
    switch (time % 17){
      case 0:
        Sunrise();
        break;
      case 1:
        Overcast();
        break;
      case 2:
        Day_Cold();
        break;
      case 3:
        Day_Stormy();
        break;
      case 4:
        Wildfire();
        break;
      case 5:
        Wildfire2();
        break;
      case 6:
        Day_Sunny();
        break;
      case 7:
        Sunset();
        break;
      case 8:
        Night_Clear();
        break;
      case 9:
        Night_Stormy();
        break;
      case 10:
        Rainbow();
        break;
      case 11:
        ColorCycle();
        break;
      case 12:
        rainbowCycle(5);
        break;
      case 13:
        flame();
        break;
      case 14:
        rgb_propeller();
        break;
      case 15:
        Day_Stormy();//ems_lightsSTROBE();
        break;
      case 16:
        Rave();
        break;
      default:
        Day_Stormy();
    }
  }
    else{ //set DemoMode false and test functions here!
      Sunrise();
    }
  }
  //Wildfire();
  //Sunset();
  //one_color_RGB(150,0,255);

  //Sunset();
  //delay(1000);
  //random_burst();
  //flame();
  //ems_lightsSTROBE();
  //rgb_propeller();

void lightning(int length, int hue, int sat){ //200,240,128 is nice and blueish
  for(int i = 0; i<length;i++){
    flicker(hue, sat);
    strip.show();
  }
}
  
//============================EFFECTS===========================================================




void flicker(int thishue, int thissat) {            //-m9-FLICKER EFFECT
  int random_bright = random(0,255);
  int random_delay = random(10,100);
  int random_bool = random(random_bright);
  if (random_bool < 10) {
    delay(random_delay);
    for(int i = 0 ; i < ledCount; i++ ) {
      setHSV(i, thishue, thissat, random_bright); 
    }
  }
}

void one_color_RGB(char R, char G, char B){      //set all to one RGB
  for(int i = 0; i < ledCount; i++){
    strip.setPixelColor(i,R,G,B);
  }
  strip.show();
}

void flame() {                                    //-m22-FLAMEISH EFFECT
  int idelay = random(0,35);
  float hmin = 0.1; float hmax = 45.0;
  float hdif = hmax-hmin;
  int randtemp = random(0,3);
  float hinc = (hdif/float(TOP_INDEX))+randtemp;
  int ihue = hmin;
  for(int i = 0; i <= TOP_INDEX; i++ ) {
    ihue = ihue + hinc;
    //leds[i] = CHSV(ihue, thissat, 255);
    setHSV(i,ihue,thissat,30);
    int ih = horizontal_index(i);    
    //leds[ih] = CHSV(ihue, thissat, 255);    
    setHSV(ih,ihue,thissat,30);
    //leds[TOP_INDEX].r = 255; leds[TOP_INDEX].g = 255; leds[TOP_INDEX].b = 255;  
    //strip.setPixelColor(TOP_INDEX, 255,255,255);  //Don't need no white pixel on top
    strip.show();    
    delay(idelay);
  }
}

void rgb_propeller() {                           //-m27-RGB PROPELLER 
  idex++;
  int thishue = 80;
  int thisdelay = 100;
  int ghue = (thishue + 80) % 255;
  int bhue = (thishue + 160) % 255;
  int N3  = int(ledCount/3);
  int N6  = int(ledCount/6);  
  int N12 = int(ledCount/12);  
  for(int i = 0; i < N3; i++ ) {
    int j0 = (idex + i + ledCount - N12) % ledCount;
    int j1 = (j0+N3) % ledCount;
    int j2 = (j1+N3) % ledCount;    
    //leds[j0] = CHSV(thishue, thissat, 255);
    setHSV(j0,thishue,thissat,255);
    //leds[j1] = CHSV(ghue, thissat, 255);
    setHSV(j1,ghue,thissat,255);
    //leds[j2] = CHSV(bhue, thissat, 255);
    setHSV(j2,bhue,thissat,255);    
  }
  strip.show();    
  delay(thisdelay);  
}


void ems_lightsSTROBE() {                  //-m26-EMERGENCY LIGHTS (STROBE LEFT/RIGHT)
  int thishue = 0;
  int thathue = (thishue + 160) % 255;
  int thisdelay = 100;
  for(int x = 0 ; x < 5; x++ ) {
    for(int i = 0 ; i < TOP_INDEX; i++ ) {
        //leds[i] = CHSV(thishue, thissat, 255);
        setHSV(i,thishue,thissat,255);
    }
    strip.show(); delay(thisdelay); 
    one_color_RGB(0, 0, 0);
    strip.show(); delay(thisdelay);
  }
  for(int x = 0 ; x < 5; x++ ) {
    for(int i = TOP_INDEX ; i < ledCount; i++ ) {
        //leds[i] = CHSV(thathue, thissat, 255);
        setHSV(i,thathue,thissat,255);
    }
    strip.show(); delay(thisdelay);
    one_color_RGB(0, 0, 0);
    strip.show(); delay(thisdelay);
  }
}


void random_burst() {                         //-m4-RANDOM INDEX/COLOR
  int idex = random(0, ledCount);
  int ihue = random(0, 255);  
  //leds[idex] = CHSV(ihue, thissat, 255);
  setHSV(idex,ihue,200,50);
  strip.show();
  delay(100);
}


void rainbowCycle(uint8_t wait) {          //Rainbow
  uint16_t i, j;

  for(j=0; j<256*10; j++) { // 10 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {        //wheel
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//============================================Helpers===============================================

word wordMap(word x, word in_min, word in_max, word out_min, word out_max)//word is an unsigned int. Is this faster than longs? maybe
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setHSV(int led, unsigned int hue, byte sat, byte val)            //Set led by hue, saturation, value
{
        unsigned char r,g,b;
        unsigned int H_accent = hue/60;
        unsigned int bottom = ((255 - sat) * val)>>8;
        unsigned int top = val;
        unsigned char rising  = ((top-bottom)  *(hue%60   )  )  /  60  +  bottom;
        unsigned char falling = ((top-bottom)  *(60-hue%60)  )  /  60  +  bottom;

        switch(H_accent) {
        case 0:
                r = top;
                g = rising;
                b = bottom;
                break;

        case 1:
                r = falling;
                g = top;
                b = bottom;
                break;

        case 2:
                r = bottom;
                g = top;
                b = rising;
                break;

        case 3:
                r = bottom;
                g = falling;
                b = top;
                break;

        case 4:
                r = rising;
                g = bottom;
                b = top;
                break;

        case 5:
                r = top;
                g = bottom;
                b = falling;
                break;
        }
        strip.setPixelColor(led, r, g, b);
}

void setAllHSV(unsigned int  h, byte  s, byte  v)        //Set all leds to one HSV
{
  for (int i = 0; i< ledCount;i++)
  {
    setHSV(i, h, s, v);
  }
}

//---FIND ADJACENT INDEX CLOCKWISE
int adjacent_cw(int i) {
  int r;
  if (i < ledCount - 1) {r = i + 1;}
  else {r = 0;}
  return r;
}

//---FIND ADJACENT INDEX COUNTER-CLOCKWISE
int adjacent_ccw(int i) {
  int r;
  if (i > 0) {r = i - 1;}
  else {r = ledCount - 1;}
  return r;
}

//---FIND INDEX OF HORIZONAL OPPOSITE LED
int horizontal_index(int i) {
  //-ONLY WORKS WITH INDEX < TOPINDEX
  if (i == BOTTOM_INDEX) {return BOTTOM_INDEX;}
  if (i == TOP_INDEX && EVENODD == 1) {return TOP_INDEX + 1;}
  if (i == TOP_INDEX && EVENODD == 0) {return TOP_INDEX;}
  return ledCount - i;  
}
