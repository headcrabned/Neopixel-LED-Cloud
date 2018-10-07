int star1Loc = 5;
int star2Loc = 17;
int moonLoc = 2;



void Sunset(){
  for(int i = 0; i< ledCount;i++){
    newR[i] = random(100,256);//redish
    newG[i] = random(120);
    newB[i] = random(100);
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================

void Night_Clear(){
  for(int i = 0; i< ledCount;i++){
    newR[i] = random(0,50);//redish
    newG[i] = random(10,30);
    newB[i] = random(50,100);
  }
    int star1 = random(50,255);
    int star2 = random(50,255);
    newR[star1Loc] = star1;
    newG[star1Loc] = star1;
    newB[star1Loc] = star1;
    newR[star2Loc] = star2;
    newG[star2Loc] = star2;
    newB[star2Loc] = star2;
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR/2,thisG/2,thisB/2);
    }
    //moon
    setHSV(moonLoc,75,220,255); //make pixel 2 a yellow moon
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================
byte StormR[] = {85 ,0  ,125,0  ,128,15 ,128,0,0,0};
byte StormG[] = {145,0  ,137,100,66 ,36 ,230,0,0,0};
byte StormB[] = {122,0  ,141,130,255,44 ,255,0,0,0};

void Night_Stormy(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(11);
    newR[i] = StormR[matrixPos];
    newG[i] = StormG[matrixPos];
    newB[i] = StormB[matrixPos];
  }

  //Set a few pixels to twinkle
    int star1 = random(50,255);
    int star2 = random(50,255);
    newR[star1Loc] = star1;
    newG[star1Loc] = star1;
    newB[star1Loc] = star1;
    newR[star2Loc] = star2;
    newG[star2Loc] = star2;
    newB[star2Loc] = star2;
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR/8,thisG/8,thisB/8);//half the brightness
    }
    //moon
    setHSV(moonLoc,75,220,255); //make pixel 2 a yellow moon
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
  int lightningMaybe = random(255);
  if(lightningMaybe > 245){
    lightning(random(20,150),260,150); //random length, hue, saturation
    one_color_RGB(0,0,0);
    for(int i = 0; i< ledCount;i++){
      oldR[i] = 0;
      oldG[i] = 0;
      oldB[i] = 0;
    }
  }
}
//============================================================
byte SunR[] = {255,230,255,230,255,210,255,0,50};
byte SunG[] = {255,255,255,255,255,220,255,0,50};
byte SunB[] = {255,255,255,255,255,220,255,0,50};

void Day_Sunny(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(10);
    newR[i] = SunR[matrixPos];
    newG[i] = SunG[matrixPos];
    newB[i] = SunB[matrixPos];
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    //delay(20);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================


void Day_Stormy(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(10);
    newR[i] = StormR[matrixPos]*.8;
    newG[i] = StormG[matrixPos]*.8;
    newB[i] = StormB[matrixPos]*.8;
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR/4,thisG/4,thisB/4);//1/4 the brightness
    }
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
  int lightningMaybe = random(255);
  if(lightningMaybe > 230){
    lightning(random(20,150),240,128); //random length, hue, saturation
    one_color_RGB(0,0,0);
    for(int i = 0; i< ledCount;i++){
      oldR[i] = 0;
      oldG[i] = 0;
      oldB[i] = 0;
    }
  }
  
}
//============================================================
//Sunrise Pallete
byte SunriseR[] = {16 ,255,255,255,255,255,255};
byte SunriseG[] = {160,110,120,20,110,235,138};
byte SunriseB[] = {255,0  ,20 ,40 ,9  ,91 ,49 };

void Sunrise(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(8);
    newR[i] = SunriseR[matrixPos];
    newG[i] = SunriseG[matrixPos];
    newB[i] = SunriseB[matrixPos];
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    delay(2);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================
void Day_Cold(){
  for(int i = 0; i< ledCount;i++){
    int brightness = random(20,255);
    newR[i] = brightness-20;
    newG[i] = brightness;
    newB[i] = 255; //nice and blue
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    delay(5);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================

void Overcast(){
  for(int i = 0; i< ledCount;i++){
    int shade = random(0,204);
    newR[i] = shade;
    newG[i] = shade;
    newB[i] = shade*1.2; //slight blue tint to overcast
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    delay(1);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================
//Wildfire Pallete
byte WildR[] = {255,170,58,242  ,0  ,197};
byte WildG[] = {72 ,30 ,24,175,0    ,38};
byte WildB[] = {31 ,15 ,23,84  ,0   ,16};

void Wildfire(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(6);
    newR[i] = WildR[matrixPos];
    newG[i] = WildG[matrixPos];
    newB[i] = WildB[matrixPos];
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================

void Rainbow(){
  for(int i = 0; i< ledCount;i++){
    newR[i] = random(90,256);//redish
    newG[i] = random(90,256);
    newB[i] = random(90,256);
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================

//Wildfire2 Pallete
byte WildR2[] = {26 ,50  ,108,5  ,245,47};
byte WildG2[] = {84 ,155 ,182,40 ,167,47};
byte WildB2[] = {158,159 ,253,122,119,107};

void Wildfire2(){
  for(int i = 0; i< ledCount;i++){
    int matrixPos = random(6);
    newR[i] = WildR[matrixPos];
    newG[i] = WildG[matrixPos];
    newB[i] = WildB[matrixPos];
  }
  
  for(int n = 0; n < 256; n++){  //update over time
    for(int i=0;i<ledCount;i++){    //update each pixel
      int thisR = map(n,0,nmax,oldR[i],newR[i]);
      int thisG = map(n,0,nmax,oldG[i],newG[i]);
      int thisB = map(n,0,nmax,oldB[i],newB[i]);
      strip.setPixelColor(i,thisR,thisG,thisB);
    }
    strip.show();
    //delay(10);
  }
  
  for(int i = 0; i< ledCount;i++){
    oldR[i] = newR[i];
    oldG[i] = newG[i];
    oldB[i] = newB[i];
  }
}
//============================================================
void ColorCycle(){
  for(int i = 0;i<361;i++){
      setAllHSV(i,255,255);
      delay(40);
      strip.show();
  }
}

void Rave(){
  for(int i=0;i<90;i++){
  setAllHSV(4*i,255,255);
  strip.show();
  }
}




