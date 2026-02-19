# ESP32 Geliştirme

Bu repo, ESP32 ve C/C++ kullanarak geliştirdiğim gömülü sistem ve IoT projelerini içerir.

## 📖 Proje Hakkında

Bu depo, ESP32 mikrodenetleyicisi için geliştirilen C/C++ tabanlı uygulamaları barındırır. Temel donanım kontrolünden (GPIO) başlayarak, yerel ağ üzerinden cihaz yönetimi (Web Server) ve IoT konseptlerine kadar uzanan pratik eğitim projelerini içermektedir. Temel amaç, gömülü sistemler ve ağ haberleşmesi alanındaki çalışmaları adım adım ve modüler bir yapıda dokümante etmektir.

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
**Geliştirici:** Mehmet Alp Arslan (KTÜ Yazılım Mühendisliği)

