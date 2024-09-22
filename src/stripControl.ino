#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 30 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int threshold;
bool conscecutive;
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  threshold = 0;
  Serial.begin(9600);
  Serial.setTimeout(1);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.fill(pixels.Color(0,150,0),0,30);
  pixels.setBrightness(5);
  pixels.show();
}
void dimDown(){
    int brightness = pixels.getBrightness();
    if(pixels.getBrightness()>5 && (brightness-8 >= 5)){
      threshold+=-1;
      pixels.setBrightness(brightness-5);
      pixels.show();
    }
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
    pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels.show();
    delay(5);                         //  Update strip to match                          //  Pause for a moment
  }
}
void colorWipeOp(uint32_t color, int wait) {
  for(int i=pixels.numPixels()-1; i>=0; i--) { // For each pixel in strip...
    pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels.show();
    delay(5);                         //  Update strip to match                          //  Pause for a moment
  }
}
void brightnessSet(int brightness){
  if(brightness>pixels.getBrightness()){
    while(pixels.getBrightness()!=brightness){
      pixels.setBrightness(pixels.getBrightness()+1);
      pixels.show();
      delay(1);
    }
  }
  else{
    while(pixels.getBrightness()!=brightness){
      pixels.setBrightness(pixels.getBrightness()-1);\
      pixels.show();
      delay(1);
    }
  }
}
bool colorSwitch = true;
bool peakTest;
void loop() {
  while(!Serial.available()); // Set all pixel colors to 'off'
  String message;
  message = Serial.readString();
  message.toUpperCase();
  pixels.setBrightness(message.toInt());
  pixels.show();
  //brightnessSet(message.toInt());
  /*if(message.toInt() == 1){
    pixels.setBrightness(200);
    if(colorSwitch){
      colorSwitch = false;
      colorWipe(pixels.Color(150,0,0),0);
    }
    else{
      colorSwitch = true;
      colorWipeOp(pixels.Color(0,150,0),0);
    }

  }
  else{
    pixels.setBrightness(5);
    pixels.show();
  }*/
}
