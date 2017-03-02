const int bluePin = 9;
const int greenPin = 10;
const int redPin = 11;

struct RGB{
  byte r, g, b;
};

void setup() {
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
}

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
unsigned int i;
RGB dioda;

void loop() {
  for(i=0;i<360;i++){
    dioda = hsvToRgb(i,255,255);
    analogWrite(redPin,dioda.r);
    analogWrite(redPin,dioda.r);
    analogWrite(bluePin,dioda.b);
    delay(20);
  }

}
