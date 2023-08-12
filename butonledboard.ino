/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-button-toggle-led
 */
 #include <ezButton.h>

/*

#define BUTTON_PIN 21  // ESP32 pin GIOP16, which connected to button
#define LED_PIN    18  // ESP32 pin GIOP18, which connected to led

// variables will change:
int led_state = LOW;    // the current state of LED
int button_state;       // the current state of button
int last_button_state;  // the previous state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode hıghdayım basınca low olucam
  pinMode(LED_PIN, OUTPUT);          // set ESP32 pin to output mode

  button_state = digitalRead(BUTTON_PIN);
}

void loop() {
  last_button_state = button_state;      // save the last state
  button_state = digitalRead(BUTTON_PIN); // read new state

  if (last_button_state == HIGH && button_state == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    led_state = !led_state;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, led_state);
  }
/*
  if (last_button_state == LOW && button_state == HIGH) { //basılı tuttukça yanar ama bunu kaldırdığında bastığında durum değiştirir
    Serial.println("The button is unpressed");

    // toggle state of LED
    led_state = !led_state;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, led_state);
  }
  */
//}



/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-button-toggle-led
 */


/*
#include <ezButton.h>

#define BUTTON_PIN 21  // ESP32 pin GIOP16, which connected to button
#define LED_PIN    18  // ESP32 pin GIOP18, which connected to led

ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 7;

// variables will change:
int led_state = LOW;   // the current state of LED

void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(LED_PIN, OUTPUT);   // set ESP32 pin to output mode
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("The button is pressed");

    // toggle state of LED
    led_state = !led_state;

    // control LED arccoding to the toggleed sate
    digitalWrite(LED_PIN, led_state);
  }
}

*/


//2 buton 2 led

/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-button-debounce
 */




#define BUTTON_PIN 21  // ESP32 pin GIOP16, which connected to button
#define LED_PIN    18  // ESP32 pin GIOP18, which connected to led

#define NBUTTON_PIN 13  // ESP32 pin GIOP16, which connected to button
#define NLED_PIN    14 
// variables will change:
int led_state = LOW;    // the current state of LED
int button_state;       // the current state of button
int last_button_state; 

int nled_state = LOW;    // the current state of LED
int nbutton_state;       // the current state of button
int nlast_button_state;  // the previous state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode hıghdayım basınca low olucam
  pinMode(LED_PIN, OUTPUT);          // set ESP32 pin to output mode

  pinMode(NBUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode hıghdayım basınca low olucam
  pinMode(NLED_PIN, OUTPUT);  

  button_state = digitalRead(BUTTON_PIN);
  nbutton_state = digitalRead(NBUTTON_PIN);

}

void loop() {
  last_button_state = button_state;      // save the last state
  button_state = digitalRead(BUTTON_PIN); // read new state

  if (last_button_state == HIGH && button_state == LOW) {
    Serial.println("The button is pressed");
    Serial.println("---");

    // toggle state of LED
    led_state = !led_state;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, led_state);
  }

  

  nlast_button_state = nbutton_state;      // save the last state
  nbutton_state = digitalRead(NBUTTON_PIN); // read new state

  if (nlast_button_state == HIGH && nbutton_state == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    nled_state = !nled_state;

    // control LED arccoding to the toggled state
    digitalWrite(NLED_PIN, nled_state);
  }
}


