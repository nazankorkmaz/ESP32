#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#define TFT_CS         17
#define TFT_RST        14
#define TFT_DC         16
#define TFT_MOSI 2 //SDA neden buraya bağlandı ** ----spı veri hattı
#define TFT_SCLK 15

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB); //tft.initR(INITR_REDTAB); ** komutu, ST7735S çipini başlatır ve ekranın başlangıç ayarlarını yapar. 
  tft.fillScreen(ST77XX_BLACK); //ekranı o renkle doldurur

  // testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
  //delay(1000);
  // tft print function!
  tftPrintTest();
}

void loop() {
  // put your main code here, to run repeatedly:

  /*  tft.invertDisplay(true); //i true ise ekranın daha az parlaklıkla çalışmasını sağlar, false ise, tam parlaklık durumudur, varsayılan olarak ekran tam parlaklık modunda çalışır.
    delay(500);
    tft.invertDisplay(false); //yukarıda mavi aşağıda sarı oluyor
    delay(500);*/
}


/*void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true); //false ayarı kullanılsaydı, metin ekranın sınırlarını aştığında kesilerek bir sonraki karakter yazdırılmazdı.
  tft.print(text);
  }*/


void tftPrintTest() {
  // tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 20);
  //tft.setFont(&FreeMonoBoldOblique12pt7b);
  tft.setTextColor(ST77XX_WHITE);
  tft.setRotation(1); //0 dikey- 1 yatay - 2diğer dikey -3 diğer yatay bu kadar ama 4 yaparsan tekrar  baştan ilerler mesela
  tft.setTextSize(2); //1 den 5e kadar 10px 20px gider
  tft.println("ENDUSTRIYEL");
  tft.setTextColor(ST77XX_WHITE);
tft.setCursor(0, 40); // 0px sağa 40px aşağıya
  tft.setTextSize(2);
  tft.println("ELEKTRONIK"); 
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(0, 90); // tft 128*160 1.8
  tft.setTextSize(5);
  //tft.println(" ");
  tft.println("13831");
}