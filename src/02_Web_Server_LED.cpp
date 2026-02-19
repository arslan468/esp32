#include <Arduino.h> 
#include <WiFi.h> // esp32 üzerinde ki wi fi modülünü kullanmak için
#include <WebServer.h> // http isteklerini işleyen kütüphane

const char* WifiName = "11 Pro";
const char* psw = "12345678.";

WebServer server(80); // server adında bir nesne oluşturup standart http portu olan 80 numaralı porttan istek atmasını söyledik

#define LED_PIN 2 // esp32 üzerinde ki mavi led i tanımlar 
String getHtml() // mikrodenetleyici üzerinde dosya sistemi kurmak yerine tüm kodu bir string ifade ile rame gömüyoruz
{
  return "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
         "<style>body{font-family: Arial; text-align: center; margin-top: 50px; background-color: #222; color: #fff;}"
         ".btn{padding: 15px 32px; font-size: 24px; text-decoration: none; color: white; border-radius: 8px; display: inline-block; margin: 10px;} "
         ".on{background-color: #4CAF50;} .off{background-color: #f44336;}</style></head>"
         "<body><h1>ESP32 Kontrol Paneli</h1>"
         "<div><a href=\"/on\" class=\"btn on\">LED AC</a>"
         "<a href=\"/off\" class=\"btn off\">LED KAPAT</a></div></body></html>";
}

void setup() 
{
  Serial.begin(9600); // termianl ile haberleşme için
  pinMode(LED_PIN, OUTPUT); // esp32 üzerinde ki mavi ledi çıkış olarak ayarladık
  WiFi.begin(WifiName, psw); //modeme bağlantı kurmak için 
  while (WiFi.status() != WL_CONNECTED) //bağlantı kuruncaya kadar
  {
    delay(500);
    Serial.print("."); //ekrana nokta atar
  }

  Serial.println("\nWifi Baglandi");
  Serial.print("Tarayıcıya girilcek IP adresi: ");
  Serial.println(WiFi.localIP()); 

  //Ana sayfa girişi olduğunda
  server.on("/", []()
  {
    server.send(200, "text/html", getHtml());
  });

  // /on istendiği zaman
  server.on("/on", [] () 
  {
    digitalWrite(LED_PIN, HIGH);
    server.sendHeader("Location", "/");// ledi yaktıktan sonra ana sayfaya yönlendirir
    server.send(303);
  });

  server.on("/off", []()
  {
    digitalWrite(LED_PIN, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.begin();

}

void loop() {
  server.handleClient();//istekelri dinler
}