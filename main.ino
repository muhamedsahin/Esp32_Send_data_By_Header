#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "MUHAMMED";
const char* password = "MUHAMMED579fatihsahin";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.print("Bağlanılıyor...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi bağlandı.");

    if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("https://mfs.cuersy.xyz/esp32/upload.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String postData = "POSTData=hello%20world";
    int httpCode = http.POST(postData);
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println(httpCode);
      Serial.println(response);
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
}

void loop() {
}
