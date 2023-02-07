#include <FastLED.h>

#define touchPin1 2 
#define touchPin2 3 
#define touchPin3 4

#define ledStrip1 7
#define ledStrip2 8
#define ledStrip3 9

#define NUM_LEDS 60 // Total ledlights is 300, we use per ledlight 100

//#define CLOCK_PIN 13 // Frequentie veranderen qua data

// for each ledstrip we use another color
CRGB white[NUM_LEDS];
CRGB red[NUM_LEDS];
CRGB blue[NUM_LEDS];

void setup()
{
  Serial.begin(9600);
  pinMode(touchPin1, INPUT);
  pinMode(touchPin2, INPUT);
  pinMode(touchPin3, INPUT);

  pinMode(ledStrip1, OUTPUT); 
  pinMode(ledStrip2, OUTPUT);
  pinMode(ledStrip3, OUTPUT);

  FastLED.addLeds<NEOPIXEL, ledStrip1>(white, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, ledStrip2>(red, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, ledStrip3>(blue, NUM_LEDS); 
} 

void loop() // If the ledstrip is "touched", the ledstrip turns on
{
  if (digitalRead(touchPin1) == HIGH){
    for (int i=0; i<NUM_LEDS; i++){
      white[i] = CRGB::White;
      delay(10);
    }
  }
  else { 
    for (int i=0; i<white; i++){
      white[i] = CRGB::Black; 
    }
  }
// Ledstrip red
  if (digitalRead(touchPin2) == HIGH){
    for (int i=0; i<NUM_LEDS; i++){
      red[i] = CRGB::Red;
      delay(10);
    }
  }
  else { 
    for (int i=0; i<white; i++){
      red[i] = CRGB::Black; 
    }
  }

// Ledstrip blue
  if (digitalRead(touchPin3) == HIGH){
    for (int i=0; i<NUM_LEDS; i++){
      blue[i] = CRGB::Blue;
      delay(10);
    }
  }
  else { 
    for (int i=0; i<NUM_LEDS; i++){
      blue[i] = CRGB::Black; 
    }
  } 
  FastLED.show(); 
}
