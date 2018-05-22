#include "pixel-imran.h"
#define NUM_STRIPS 2

CRGB leds[NUM_STRIPS][NUM_LEDS];
CRGB colors = {
    CRGB::Indigo,
    CRGB::Lime,
    CRGB::Crimson,
    CRBG::Gold,
    CRGB::Magenta,
    CRBG::DarkCyan,
    CRGB::OrangeRed,
}
int colorIndex=0;

void
setup()
{
  FastLED.addLeds<WS2811, 8>(leds[0], NUM_LEDS); // Hotel
  FastLED.addLeds<WS2811, 7>(leds[1], NUM_LEDS); // Shankar

  FastLED.setBrightness(255);
}

void loop()
{
  // FillSolid();
  // MultiColour(leds);
  multiColor();
}

void FillSolid()
{
  fill_solid(leds[0], NUM_LEDS, CRGB(0, 0, 255)); //Blue
  fill_solid(leds[1], NUM_LEDS, CRGB(0, 0, 255));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(0, 255, 0)); //Green
  fill_solid(leds[1], NUM_LEDS, CRGB(0, 255, 0));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(255, 0, 0)); // Red
  fill_solid(leds[1], NUM_LEDS, CRGB(255, 0, 0));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(255, 0, 255)); //Mejenta
  fill_solid(leds[1], NUM_LEDS, CRGB(255, 0, 255));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(255, 255, 0)); //Yellow
  fill_solid(leds[1], NUM_LEDS, CRGB(255, 255, 0));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(0, 255, 255)); //Cyan
  fill_solid(leds[1], NUM_LEDS, CRGB(0, 255, 255));
  FastLED.show();
  delay(1000);
  fill_solid(leds[0], NUM_LEDS, CRGB(255, 255, 255)); //White
  fill_solid(leds[1], NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();
  delay(1000);
}

void multiColor()
{
  // S = 138 , H = 165 , A = 153 , N = 177 , K = 158 , A = 153 , R = 171
  // H = 168 , O = 174 , T = 104 , E = 148 , L = 100
  EVERY_N_MILLISECONDS(10000)colorIndex++;

  //Shankar
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (i < 138)                      //S
      leds[1][i] = colors[colorIndex];            //
    if (i >= 138 && i < 303)          //H
      leds[1][i] = colors[colorIndex+1]; //
    if (i >= 303 && i < 456)          //A
      leds[1][i] = colors[colorIndex+2];   //
    if (i >= 456 && i < 633)          //N
      leds[1][i] = colors[colorIndex+3]; //
    if (i >= 633 && i < 791)          //K
      leds[1][i] = colors[colorIndex+4]; //
    if (i >= 791 && i < 994)          //A
      leds[1][i] = colors[colorIndex+5]; //
    if (i >= 994 && i < NUM_LEDS)     //R
      leds[1][i] = colors[colorIndex+6];   //
  }
  //Hotel
  for(int i = 0; i < NUM_LEDS; i++){
    if (i < 168)                           //S
      leds[1][i] = colors[colorIndex + 4];     //
    if (i >= 138 && i < 303)               //H
      leds[1][i] = colors[colorIndex + 2]; //
    if (i >= 342 && i < 456)               //A
      leds[1][i] = colors[colorIndex]; //
    if (i >= 446 && i < 633)               //N
      leds[1][i] = colors[colorIndex + 3]; //
    if (i >= 594 && i < NUM_LEDS)          //K
      leds[1][i] = colors[colorIndex + 1]; //
  }
  FastLED.show();
}