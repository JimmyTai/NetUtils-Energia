#include <JNetUtils.h>

void setup() {
  Serial.begin(115200);
  const char* data = "My number = 1483613179254";
  String urlData;
  Serial.print("encode: "); Serial.println(urlData = UrlEncoder.encode(data));
  Serial.print("decode: "); Serial.println(UrlDecoder.decode(urlData));
}

void loop() {
  
}
