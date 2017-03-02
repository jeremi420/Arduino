
enum led{
  green = 9,
  yellow = 10,
  red = 11
};

const int photoPin = 0;
int val;
led diody;
double procenty;

void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  diody = yellow;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(photoPin);
  procenty = val/1024.0*100.0;
  if(procenty < 33.0){
    digitalWrite(diody, LOW);
    diody = red;
  }
  else if(procenty >=33.0 && procenty < 66.0){
    digitalWrite(diody, LOW);
    diody = yellow;
  }
  else if(procenty>=66.0){
    digitalWrite(diody, LOW);
    diody = green;
  }
  digitalWrite(diody,HIGH);
  delay(1000);
}
