//Assalamualaikum...ini buat kode di inonya
#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char*namawifi="XTNET";
const char*paswwifi="Xst45ansr";
const char*destinasi="http://192.168.4.149:5000/post"; //diganti dgn ip msg msg
DHT dht(26, DHT11);

void setup(){
  Serial.begin(115200);
  WiFi.begin(namawifi, paswwifi);
  Serial.print("konekin");
  while(WiFi.status()!= WL_CONNECTED){
    delay(1000);
    Serial.print("@");
  }
  Serial.print("Udah konek");
  dht.begin(); //ini bwat mulay sensor
}

void loop(){
  float Bapan=dht.readHumidity();
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin(destinasi);
    http.addHeader("Content-Type", "application/json");
    String datakirim="{\"Klm\":"+ String(Bapan)+"}";
    int responhttp=http.POST(datakirim);
    if (responhttp > 0) {
      String respon = http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(responhttp);
      Serial.print("Response: ");
      Serial.println(respon);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(responhttp);
      Serial.print("Error description: ");
      Serial.println(http.errorToString(responhttp).c_str());
    }

    http.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
  Serial.println("kelembapannya ");
  Serial.print(Bapan);
  Serial.print("%");
  delay(2500); //nunggu 2,5 detik ya
}
