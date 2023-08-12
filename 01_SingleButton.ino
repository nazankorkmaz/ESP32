/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example reads the state of a button without debounce and print it to Serial Monitor.
 */

#include <ezButton.h>
#include <Adafruit_GFX.h>    // include Core graphics library
#include <Adafruit_ST7735.h> // include Hardware-specific library
#include <SPI.h>

#define TFT_CS     17
#define TFT_RST    14  // you can also connect this to the Arduino reset                      
#define TFT_DC     16  // in which case, set this #define pin to -1!

#define TFT_SCLK 15   // set these to be whatever pins you like!
#define TFT_MOSI 2   // set these to be whatever pins you like!


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST); //ST7735 TFT ekranını SPI bağlantısı ile kontrol edebilirsiniz.

ezButton button(25);  // create ezButton object that attach to pin 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  button.loop(); // MUST call the loop() function first

  int btnState = button.getState();
  Serial.println(btnState);
}
