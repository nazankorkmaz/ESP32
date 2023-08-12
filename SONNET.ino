#include <Adafruit_GFX.h>    // include Core graphics library
#include <Adafruit_ST7735.h> // include Hardware-specific library
#include <SPI.h>

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield

#define TFT_CS     17
#define TFT_RST    14  // you can also connect this to the Arduino reset                      
#define TFT_DC     16  // in which case, set this #define pin to -1!

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST); Bu yapılandırıcıyı kullanarak ST7735 TFT ekranını paralel bağlantı ile kontrol edebilirsiniz.
// Option 2: use any pins but a little slower!

//Hangi yapılandırıcıyı kullanmanız gerektiğini belirlemek için, ST7735 TFT ekranınızın bağlantı türüne (SPI veya paralel) ve
//kullanmak istediğiniz bağlantı pinlerine bakmanız gerekmektedir. Eğer SPI tabanlı bir bağlantı kullanıyorsanız, ilk yapılandırıcıyı kullanmalısınız. 

#define TFT_SCLK 15   // set these to be whatever pins you like!
#define TFT_MOSI 2   // set these to be whatever pins you like!

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST); //ST7735 TFT ekranını SPI bağlantısı ile kontrol edebilirsiniz.

float p = 3.1415926;

void setup(void) {

  Serial.begin(9600);

  // Use this initializer if you're using a 1.8" TFT

  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  delay(200);
  // Use this initializer (uncomment) if you're using a 1.44" TFT
  tft.initR(INITR_GREENTAB);   // initialize a ST7735S chip, black tab
  // Use this initializer (uncomment) if you're using a 0.96" 180x60 TFT
  //tft.initR(INITR_MINI160x80);   // initialize a ST7735S chip, mini display

  tft.fillScreen(ST7735_BLACK);
  delay(500);

  // large block of text

  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);

  delay(1000);




/*
void loop() {

  uint16_t time = millis(); //Bu, kodun başlangıç zamanını ölçmek için kullanılır.
  tft.fillScreen(ST7735_BLACK);

  time = millis() - time; //time değişkenine, millis() fonksiyonunun mevcut değeri ile başlangıç zamanı arasındaki fark atanır. Bu, kodun çalışma süresini ölçmek için kullanılır.
  Serial.print("Hello! ST7735 TFT Test");
  Serial.println("Initialized");
 
  Serial.println("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  tft.invertDisplay(true);
  delay(500);

  Serial.println(time, DEC); //time değişkenini seri bağlantı üzerinden ondalık (DEC) olarak yazdırır. Bu, kodun çalışma süresini seri terminale yazdırarak işlemin ne kadar sürede tamamlandığını gösterir.

  tft.invertDisplay(false);

  delay(500);

}
*/

//setupın içindeyim hala

  // tft print function!

  tftPrintTest();

  delay(4000);

  //---------------------------------------
  for(int16_t i=0; i<6;i++){
    tft.drawPixel(tft.width()/2, tft.height()/2, ST7735_GREEN);

  }

  delay(500);

  // line draw test

  testlines(ST7735_YELLOW);

  delay(500);

  // optimized lines

  testfastlines(ST7735_RED, ST7735_BLUE);

  delay(500);

  testdrawrects(ST7735_GREEN);

  delay(500);

  testfillrects(ST7735_YELLOW, ST7735_MAGENTA);

  delay(500);

  tft.fillScreen(ST7735_BLACK);

  testfillcircles(10, ST7735_BLUE); //içi dolu çemberler çizer

  testdrawcircles(10, ST7735_WHITE);

  delay(500);

  testroundrects();

  delay(500);

  testtriangles();

  delay(500);

  mediabuttons();

  delay(500);

  Serial.println("done");

  delay(1000);

}

void loop() {

  tft.invertDisplay(true);

  delay(500);

  tft.invertDisplay(false);

  delay(500);

}

void testlines(uint16_t color) {

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=0; x < tft.width(); x+=6) {

    tft.drawLine(0, 0, x, tft.height()-1, color);

  }

  for (int16_t y=0; y < tft.height(); y+=6) {

    tft.drawLine(0, 0, tft.width()-1, y, color);

  }

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=0; x < tft.width(); x+=6) {

    tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);

  }

  for (int16_t y=0; y < tft.height(); y+=6) {

    tft.drawLine(tft.width()-1, 0, 0, y, color);

  }

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=0; x < tft.width(); x+=6) {

    tft.drawLine(0, tft.height()-1, x, 0, color);

  }

  for (int16_t y=0; y < tft.height(); y+=6) {

    tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);

  }

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=0; x < tft.width(); x+=6) {

    tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);

  }

  for (int16_t y=0; y < tft.height(); y+=6) {

    tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);

  }

}

void testdrawtext(char *text, uint16_t color) {

  tft.setCursor(0, 0);

  tft.setTextColor(color);

  tft.setTextWrap(true);

  tft.print(text);

}

void testfastlines(uint16_t color1, uint16_t color2) {

  tft.fillScreen(ST7735_BLACK);

  for (int16_t y=0; y < tft.height(); y+=5) {

    tft.drawFastHLine(0, y, tft.width(), color1);

  }

  for (int16_t x=0; x < tft.width(); x+=10) {

    tft.drawFastVLine(x, 0, tft.height(), color2);

  }

}

void testdrawrects(uint16_t color) {

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=0; x < tft.width(); x+=10) {

    tft.drawRect(tft.width()/5 -x/5, tft.height()/2 -x/5 , x, x, color); //(x, y) noktasından başlayarak, belirtilen genişlik (w) ve yükseklik (h) değerleri ile bir dikdörtgen çizer.

  }

}
/* //DENEME
void testfillrects(uint16_t color1, uint16_t color2) {

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=20; x < tft.width()-1; x+=6) {

    tft.fillRect(tft.width()/2 +x/5, tft.height()/2 +x/2 , x, x, color1);

    tft.drawRect(tft.width()/2 +x/2, tft.height()/2 +x/5 , x, x, color2);

  }

}
*/

void testfillrects(uint16_t color1, uint16_t color2) {

  tft.fillScreen(ST7735_BLACK);

  for (int16_t x=tft.width()-1; x > 6; x-=6) {

    tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);

    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);

  }

}
/*
void testfillcircles(uint8_t radius, uint16_t color) {

  for (int16_t x=radius+10; x < tft.width(); x+=radius*2) { //10sağa

    for (int16_t y=radius+20; y < tft.height(); y+=radius*2) {//20aşağıya hali
      tft.fillCircle(x, y, radius, color);

    }

  }

}
*/

void testfillcircles(uint8_t radius, uint16_t color) {

  for (int16_t x=radius; x < tft.width(); x+=radius*2) {

    for (int16_t y=radius; y < tft.height(); y+=radius*2) {

      tft.fillCircle(x, y, radius, color);

    }

  }

}


void testdrawcircles(uint8_t radius, uint16_t color) {

  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {

    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {

      tft.drawCircle(x, y, radius, color);

    }

  }

}

void testtriangles() {

  tft.fillScreen(ST7735_BLACK);

  int color = 0xF800;

  int t;

  int w = tft.width()/2;

  int x = tft.height()-1;

  int y = 0;

  int z = tft.width();

  for(t = 0 ; t <= 15; t++) {

    tft.drawTriangle(w, y, y, x, z, x, color);

    x-=4;

    y+=4;

    z-=4;

    color+=100;

  }

}

void testroundrects() {

  tft.fillScreen(ST7735_BLACK);

  int color = 100;

  int i;

  int t;

  for(t = 0 ; t <= 4; t+=1) {

    int x = 0;

    int y = 0;

    int w = tft.width()-2;

    int h = tft.height()-2;

    for(i = 0 ; i <= 16; i+=1) {

      tft.drawRoundRect(x, y, w, h, 15, color); //radius: Yuvarlak köşelerin yarıçapı.

      x+=2;

      y+=3;

      w-=4;

      h-=6;

      color+=1100;

    }

    color+=100;

  }

}

void tftPrintTest() {

  tft.setTextWrap(false);

  tft.fillScreen(ST7735_BLACK);

  tft.setCursor(0, 30);

  tft.setTextColor(ST7735_RED);

  tft.setTextSize(1);

  tft.println("Hello World!");

  tft.setTextColor(ST7735_YELLOW);

  tft.setTextSize(2);

  tft.println("Hello World!");

  tft.setTextColor(ST7735_GREEN);

  tft.setTextSize(3);

  tft.println("Hello World!");

  tft.setTextColor(ST7735_BLUE);

  tft.setTextSize(4);

  tft.print(1234.567);

  delay(500);

  tft.setCursor(0, 0);

  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_WHITE);

  tft.setTextSize(0);

  tft.println("Hello World!");

  tft.setTextSize(1);

  tft.setTextColor(ST7735_GREEN);

  tft.print(p, 6); //verilen değişkenin değerini belirtilen ondalık basamak sayısıyla birlikte yazdırır.

  tft.println(" Want pi?");

  tft.println(" ");

  tft.print(8675309, HEX); // print 8,675,309 out in HEX!

  tft.println(" Print HEX!");

  tft.println(" ");

  tft.setTextColor(ST7735_WHITE);

  tft.println("Sketch has been");

  tft.println("running for: ");

  tft.setTextColor(ST7735_MAGENTA);

  tft.print(millis() / 1000); // programın başlangıcından bu yana geçen süreyi saniye cinsinden ekranda görüntüler.

  tft.setTextColor(ST7735_WHITE);

  tft.print(" seconds.");

}

void mediabuttons() {

  // play

  tft.fillScreen(ST7735_BLACK);

  tft.fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);

  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);

  delay(500);

  // pause

  tft.fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);

  tft.fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);

  tft.fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);

  delay(500);

  // play color

  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);

  delay(50);

  // pause color

  tft.fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);

  tft.fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);

  // play color

  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);

}
