# ESP32 Geliştirme

Bu repo, ESP32 ve C/C++ kullanarak geliştirdiğim gömülü sistem ve IoT projelerini içerir.

## 📂 Projeler
* **01_Blink:** Temel GPIO kontrolü (LED yakıp söndürme).
* **02_Web_Server_LED:** Yerel ağ üzerinden web arayüzü ile donanım kontrolü.

## ⚙️ Kurulum ve Kullanım
* **Ortam:** VS Code + PlatformIO
* **Kart:** ESP32 DevKitC V1

## ⚠️ Önemli PlatformIO Notu
PlatformIO, `src` klasöründeki tüm `.cpp` dosyalarını aynı anda derlemeye çalışır. Birden fazla dosyada `setup()` ve `loop()` fonksiyonu varsa çakışma hatası (`multiple definition`) alırsınız.
* **Çözüm:** O an üzerinde çalışmadığınız projelerin uzantısını `.cpp` yerine `.txt` yaparak derleyiciden gizleyin. (Örn: `01_Blink.txt`)

---
