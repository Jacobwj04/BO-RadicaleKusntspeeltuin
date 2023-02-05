#include <FastLED.h> 

// We define touch sensor here and connect this with the arduino board
#define touchPin1 2 
#define touchPin2 3 
#define touchPin3 4 

// We define ledstrip here and connect this with the arduino board
#define ledStrip1 7 
#define LedStrip2 8
#define LedStrip3 9

// Total ledlights is 300, we use per ledlight 60
#define NUM_LEDS 60

// For each ledstrip we use another color
CRGB white[NUM_LEDS];
CRGB red[NUM_LEDS];
CRGB blue[NUM_LEDS];

int ledPin = 13; 
 
  void setup() {
    delay(2000);
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(Pin1, INPUT);
    pinMode(Pin2, INPUT);
    pinMode(Pin3, INPUT);

    FastLED.addLeds<WS2811, ledStrip1, RGB>(white, NUM_LEDS);
    FastLED.addLeds<WS2811, ledStrip2, RGB>(red, NUM_LEDS);
    FastLED.addLeds<WS2811, ledStrip3, RGB>(blue, NUM_LEDS);
  }


  void loop() {
     if (digitalRead(touchPin1) == HIGH){
        for(int i = 60; NUM_LEDS > 0; i--) {
        white[i] = 0x2F4F4F;

        //digitalWrite(ledPin, HIGH);
//        Serial.println("Sensor 1 TOUCHED");
        }
     }
    else  {
        // Count all the leds and turn them into black
        for (int i=0; i<white; i++){ 
           white[i] = CRGB::Black;
        }
        delay(10);
    }
  

    if (digitalRead(touchPin2) == HIGH){
      for(int i = 60; NUM_LEDS > 0; i--) {
        red[i] = CRGB:: red;

      delay(10);
    }
  }
    else {
//      digitalWrite(touchPin2,LOW);
        for (int i=0; i<NUM_LEDS; i++){
         red[i] = CRGB::Black;
    }
  }
  
    if (digitalRead(touchPin3) == HIGH){
      for(int i = 60; NUM_LEDS > 0; i--) {
      blue[redLed] = CRGB:: blue;

      delay(10);
    }
  }
  
    else {
//      digitalWrite(ledPin3,LOW);
      for (int i=0; i<NUM_LEDS; i++){
         blue[i] = CRGB::Black;
      }
  }
  FastLED.show();
}
