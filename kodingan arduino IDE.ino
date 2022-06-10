#include <AntaresESP8266HTTP.h>

#define ACCESSKEY "8fe0cf53bf23dba6:07dc7b12f54bcc93"       // Ganti dengan access key akun Antares anda
#define WIFISSID "Redmi 9"         // Ganti dengan SSID WiFi anda
#define PASSWORD "ngadingadi"     // Ganti dengan password WiFi anda

#define projectName "smartplan"   // Ganti dengan application name Antares yang telah dibuat
#define deviceName "sensor"     // Ganti dengan device Antares yang telah dibuat

AntaresESP8266HTTP antares(ACCESSKEY);    // Buat objek antares
String str;

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT); 
  antares.setDebug(false);   // Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
}

void loop() { //Ini buat kodingan kita
  float hasil = digitalRead(0);
  if (hasil == 0) //buzzer on
  {
    Serial.println("Hambatan Terdeteksi");
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    str = "terdeteksi";
  }
  if (hasil == 1 ) //buzzer off
  {
    Serial.println ("Tidak Ada Hambatan");
    digitalWrite (4, 0);
    digitalWrite(5, 0);
    str = "tidak terdeteksi";
  }
  
  antares.add("detected", str);

//   Kirim dari penampungan data ke Antares
  antares.send(projectName, deviceName);
}
