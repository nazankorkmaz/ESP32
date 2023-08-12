// pin tanımlamaları
//interruptla butona basuldığında yanıp sönen söner ve diğeri yanar serial moniitörde butona basıldı yazar.
const int ledkirmizi = 2;
const int ledyesil = 4;
const int buton = 17;
boolean butondurum = 0;
boolean leddurum = LOW;

// LED'i yakıp söndürmek için gerekli zamanlama değişkenleri
unsigned long simdikizaman = 0;
unsigned long oncekizaman = 0;

// Butona basılıp basılmadığını takip eden KESME fonksiyonumuz
void IRAM_ATTR butonKontrol() {
    butondurum = 1; //butondurum bayrağını 1'e çekerek ana koda bilgi gönderiyoruz
    digitalWrite(ledkirmizi, LOW);//her ne olursa olsun kırmızı led sönsün
}

void setup() {
  // Serial portu açalım
  Serial.begin(115200);

  // Butonun bağlı olduğu pini INPUT olarak tanımlayalım
  pinMode(buton, INPUT_PULLUP);
  // butonu kesme olarak tanımlamak için aşağıdaki tanımlamayı yapıyoruz
  attachInterrupt(digitalPinToInterrupt(buton), butonKontrol, HIGH); //HIGH oldukça çalışacak //nodemcu için çalışmaz. nodemcu için RISING yapın

  // Başlangıç için ledleri sönük yapalım
  pinMode(ledkirmizi, OUTPUT);
  pinMode(ledyesil, OUTPUT);
  digitalWrite(ledkirmizi, LOW);
  digitalWrite(ledyesil, LOW);
}

void loop() {
  // şu anki zamanı sürekli olarak simdikizaman değişkenine atayalım
  simdikizaman = millis();
  // Kesme fonksiyonumuzu kullanarak gönderdiğimiz butondurum değişkenine göre kırmızı ledi söndürüp yeşil ledi yakalım
  if (butondurum == 1) {
    Serial.println("BUTONA BASILDI");
    digitalWrite(ledyesil, HIGH);
    delay(500);
    butondurum = 0; //güncelleyelim ki düzgün çalışsın
  }
  //butona basılmamış demek ki, yeşili söndürüp kırmızıyı saniyede bir yakalım
 else{
  digitalWrite(ledyesil, LOW); //yeşil ledi söndürelim.
  //her 100 milisaniyede bir kırmızı ledi millis fonk kullanarak yakıp söndürelim.
  if ((simdikizaman - oncekizaman) >= 100) {
    oncekizaman = simdikizaman; //oncekizamanı da güncelleyelim ki düzgün çalışsın
    if (leddurum == LOW) {
      leddurum = HIGH;
      Serial.println("Kırmızı LED Yanıyor");
    } else {
      leddurum = LOW;
      Serial.println("Kırmızı LED Söndü");
    }
  }

  digitalWrite(ledkirmizi, leddurum);

 }

}

