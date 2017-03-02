int tempVal;
const int tempPin = 1;
const int ledPin =  13;

RGB hsvToRgb(uint16_t h, uint8_t s, uint8_t v){
  uint8_t f = (h % 60) * 255 / 60;
  uint8_t p = (255 - s) * (uint16_t)v / 255;
  uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
  uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
  uint8_t r = 0, g = 0, b = 0;
  switch((h / 60) % 6){
    case 0: r=v; g=t; b=p; break;
    case 1: r=q; g=v; b=p; break;
    case 2: r=p; g=v; b=t; break;
    case 3: r=p; g=q; b=v; break;
    case 4: r=t; g=p; b=v; break;
    case 5: r=v; g=p; b=q; break;
  }
  return (RGB){r, g, b};
}

void setup() {
  pinMode(ledPin, OUTPUT);
  analogReference(INTERNAL);
  Serial.begin(9600);
  Serial.println("LABEL,czas,temperatura");
  Serial.println("RESETTIMER");
}

void loop() {
  Serial.print("DATA,TIME,");
  tempVal = analogRead(tempPin);
  float tempCel = tempVal/9.31;
  Serial.println(tempCel);
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

