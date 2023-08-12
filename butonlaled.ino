/*
const int buttonPin = 4;  // Butonun bağlı olduğu pin numarası
//const int ledPin = 5;     // LED'in bağlı olduğu pin numarası

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Buton pini giriş olarak ayarlanır ve dahili pull-up direnci etkinleştirilir yani bastığında low olur
  //pinMode(ledPin, OUTPUT);            // LED pini çıkış olarak ayarlanır
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // Buton basıldığında
  Serial.println("bastı"); 
    //digitalWrite(ledPin, HIGH);         // LED'i yakar
  } else {
    Serial.println("bıraktı");
    
    //digitalWrite(ledPin, LOW);          // Buton basılmadığında LED'i söndürür
  }
}
*/

/*
#define BUTTON_PIN 21 // GIOP21 pin connected to button

// Variables will change:
int lastState = LOW; // the previous state from the input pin
int currentState;     // the current reading from the input pin

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  pinMode(BUTTON_PIN, INPUT_PULLDOWN); //dahili bir pull-down direncini etkinleştirerek, butonun bağlı olduğu pini bir düğmeye basılmadığında LOW seviyede tutar. Buton basıldığında, pinden gelen sinyal yükselir (HIGH).
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == HIGH && currentState == LOW)
  {
    Serial.print("The state changed from LOW to HIGH    "); //bıraktı 0 yazdı
    Serial.println(currentState);
    
  }
  if(lastState == LOW && currentState==HIGH)
  {
    Serial.print("L2H ");
    Serial.println(currentState); //bastı
  }
    

  // save the last state
  lastState = currentState;
}

//lowda poulldown tanımladığım için bastığımda l2h bıraktığımda ilk ifi yazdırır.
*/


#include <ezButton.h>

ezButton button(21);  // create ezButton object that attach to pin 7;

void setup() {
    Serial.begin(9600);
    button.setDebounceTime(500); //. Debounce süresi, buton basıldığında veya bırakıldığında istikrarlı bir durum elde etmek için beklenen süreyi belirler.
    button.setCountMode(COUNT_FALLING); // butonun düşen kenar (falling edge) ile tetiklendiğini belirtir. Yani, butonun basıldığı anda sayma işlemi başlar.
   
  //Bu ayarlar, butonun stabil durumunu sağlamak ve doğru sayım yapmak için önemlidir. Debounce süresi, mekanik butonun titreşimlerinden kaynaklanan yanlış tetiklemeleri önlemek için kullanılır.
  //Sayma modu ise butonun nasıl tetikleneceğini belirtir.
}

void loop() {
  button.loop(); // MUST call the loop() function first
   unsigned long count=0;
  int a;
  static int btnState=0;
  a=btnState;
  btnState = button.getStateRaw(); //, basılmış bir buton için genellikle LOW (0) değeri döndürülürken, serbest bırakılmış bir buton için HIGH (1) değeri döndürülür.
  if(a != btnState)
    Serial.println(btnState);

  if(button.isPressed()==1)
    Serial.println("The button is pressed");

  if(button.getCount()!=count)
  {
    count = button.getCount();
     Serial.println(count);
  }
      
}


 