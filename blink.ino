#define green1 2
#define red1 3
#define yellow1 4
#define green2 5
#define red2 7
#define yellow2 6

void setup() {
  // put your setup code here, to run once:
  pinMode (green1, OUTPUT);
  pinMode (red1, OUTPUT);
  pinMode (yellow1, OUTPUT);
  pinMode (green2, OUTPUT);
  pinMode (red2, OUTPUT);
  pinMode (yellow2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 blinking();
 dim();
 off();
}

void blinking(){

  digitalWrite(green1, HIGH);
  delay(300);

  digitalWrite(red1, HIGH);
  delay(300);

  digitalWrite(yellow1, HIGH);
  delay(300);

  digitalWrite(green2, HIGH);
  delay(300);

  digitalWrite(red2, HIGH);
  delay(300);

  digitalWrite(yellow2, HIGH);
  delay(300);

  digitalWrite(yellow2, LOW);
  delay(300);

  digitalWrite(red2, LOW);
  delay(300);

  digitalWrite(green2, LOW);
  delay(300);
  
  digitalWrite(yellow1, LOW);
  delay(300);

 digitalWrite(red1, LOW);
  delay(300);

 digitalWrite(green1, LOW);
  delay(300);

}

void dim () {

  digitalWrite(green1, HIGH);
  delay(300);

  for (int bri = 0; bri <= 255; bri++) {
    analogWrite(red1, bri);
    delay(5);
  }

  for (int bri = 255; bri >= 0; bri--) {
    analogWrite(red1, bri);
    delay(5);
  }

  delay(300);

  digitalWrite(yellow1, HIGH);
  delay(300);

  delay(300);

  for (int bri = 0; bri <= 255; bri++) {
    analogWrite(green2, bri);
    delay(5);
  }

  for (int bri = 255; bri >= 0; bri--) {
    analogWrite(green2, bri);
    delay(5);
  }

  delay(300);

  digitalWrite(red2, HIGH);
  delay(300);

  delay(300);

  for (int bri = 0; bri <= 255; bri++) {
    analogWrite(yellow2, bri);
    delay(5);
  }

  for (int bri = 255; bri >= 0; bri--) {
    analogWrite(yellow2, bri);
    delay(5);
  }

}

void off (){
  digitalWrite(yellow2, HIGH);
  delay(300);

  digitalWrite(red2, HIGH);
  delay(300);

  digitalWrite(green2, HIGH);
  delay(300);

  digitalWrite(yellow1, HIGH);
  delay(300);

  digitalWrite(red1, HIGH);
  delay(300);

  digitalWrite(green1, HIGH);
  delay(300);

  digitalWrite(green1, LOW);
  delay(300);

  digitalWrite(red1, LOW);
  delay(300);

  digitalWrite(yellow1, LOW);
  delay(300);
  
  digitalWrite(green2, LOW);
  delay(300);

 digitalWrite(red2, LOW);
  delay(300);

 digitalWrite(yellow2, LOW);
  delay(300);

}
