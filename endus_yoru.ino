#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#define TFT_CS         17
#define TFT_RST        14
#define TFT_DC         16
#define TFT_MOSI 2 //SDA neden buraya bağlandı **
#define TFT_SCLK 15

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB); //tft.initR(INITR_REDTAB); ** //tft.initR(INITR_REDTAB); ** komutu, ST7735S çipini başlatır ve ekranın başlangıç ayarlarını yapar. 
  tft.fillScreen(ST7735_YELLOW); ///ekranı o renkle doldurur
  
  //testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ",ST77XX_BLUE);//ST77XX_MAGENTA
  //delay(1000);
  // tft print function!
 // tftPrintTest();
}

void loop() {
  // put your main code here, to run repeatedly:

    // Örnek renk dizisi
    
    //tft.setCursor(0, 20);
    //tft.setFont(&FreeMonoBoldOblique12pt7b);
    //tft.setTextColor(ST77XX_WHITE);
    //tft.setRotation(4); //0 dikey- 1 yatay - 2diğer dikey -3 diğer yatay bu kadar ama 4 yaparsan tekrar  baştan ilerler mesela
    //tft.setTextSize(1); 
    tft.println("BASLA"); 
    
    tft.drawCircle(88, 88, 10,  0x001F);
    delay(300);
    tft.fillCircleHelper(20, 50, 15, 2, 1, 0x07E0);
    delay(250);

    uint16_t colors[] = {0xF800, 0x07E0, 0x001F};  // Kırmızı, Yeşil, Mavi
    uint16_t colors_n[] = { 0,0x07E0,0};  // Kırmızı, Yeşil, Mavi

// Bit eşlemesini çizme
    int16_t a = 70;
    int16_t b = 70;
    int16_t width = 50;
    int16_t height = 80;

    tft.drawRGBBitmap(a+30, b, colors, width, height); //değişik
    delay(400);
    tft.drawRGBBitmap(a, b, colors_n, width, height); //değişik


    tft.invertDisplay(true);   //i true ise ekranın daha az parlaklıkla çalışmasını sağlar, false ise, tam parlaklık durumudur, varsayılan olarak ekran tam parlaklık modunda çalışır.
    delay(500);
    tft.invertDisplay(false); //yukarıda mavi aşağıda sarı oluyor
    delay(500);
    
    tft.fillScreen(ST7735_BLUE);
    

    int16_t x;
    for(x=7;x<=100;x++)
    {
      tft.drawPixel(x,5,1);
      delay(100);
    }

    tft.fillScreen(ST7735_WHITE);

    int16_t y;
    for(y=5;y<=140;y++)
    {
      tft.drawPixel(5,y,3);
      delay(100);
    }
    
    tft.fillScreen(ST7735_RED);

    for(x=7;x<=100;x++)
    {
      tft.drawPixel(x,140,5);
      delay(100);
    }

     tft.fillScreen(ST7735_BLUE);
}

/*
//void testdrawtext(char *text, uint16_t color, uint16_t bg) 
void testdrawtext(char *text, uint16_t color){
  tft.setCursor(0, 0);
  tft.setTextColor(color);
 // tft.setTextColor(color,bg); //(color,ST7735_BLUE); **
  tft.setTextWrap(true);  //false ayarı kullanılsaydı, metin ekranın sınırlarını aştığında kesilerek bir sonraki karakter yazdırılmazdı.
  tft.print(text);
  }
  */

/*
void tftPrintTest() {
  // tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 20);
  //tft.setFont(&FreeMonoBoldOblique12pt7b);
  tft.setTextColor(ST77XX_WHITE);
  tft.setRotation(4); //0 dikey- 1 yatay - 2diğer dikey -3 diğer yatay bu kadar ama 4 yaparsan tekrar  baştan ilerler mesela
  tft.setTextSize(1); //1 den 5e kadar 10px 20px gider
  tft.println("END");
  tft.setTextColor(ST77XX_WHITE);
tft.setCursor(100, 157); // tft 128*160 1.8
  tft.setTextSize(2);
  tft.println("ELE"); 
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(0, 90); // 0px sağa 40px aşağıya
  tft.setTextSize(5);
  //tft.println(" ");
  tft.println("12023");
}
*/
