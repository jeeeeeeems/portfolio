int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int numOfRegisters = 2;
byte* registerState;

long effectId = 0;
long prevEffect = 0;
long effectRepeat = 0;
long effectSpeed = 30;

void setup() {
  //allocation of memory for register state
  registerState = new byte[numOfRegisters];
  for (size_t i = 0; i < numOfRegisters; i++) {
    registerState[i] = 0;
  }

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  //different effect is chosen
  do{
    effectId = random(6);
  } while (effectId == prevEffect);
  prevEffect = effectId;

  //number of repetition
  switch (effectId) {
    case 0: case 1: case 4: case 5:
      effectRepeat = random(1, 2);
      break;
    case 3:
      effectRepeat = random(1, 5);
      break;
  }

  //execution of effects
  for (int i = 0; i < effectRepeat; i++) {
    effectSpeed = random(10, 90);
    switch (effectId) {
      case 0: cascadeDown(effectSpeed); break;
      case 1: cascadeReverse(effectSpeed); break;
      case 3: bounce(effectSpeed); break;
      case 4: cascadeMirror(effectSpeed); break;
      case 6: shrinkMirror(effectSpeed); break;
    }
  }

  blink(100);
  fade(10);
}

//downward cascade
void cascadeDown (int speed){
  for (int i = 0; i < 16; i++){
    for (int k = i; k < 16; k++){
      regWrite(k, HIGH);
      delay(speed);
      regWrite(k, LOW);
    }

    regWrite(i, HIGH);
  }
}

//reverse cascade
void cascadeReverse (int speed){
  for (int i = 15; i >= 0; i--){
    for (int k = 0; k < i; k++){
      regWrite(k, HIGH);
      delay(speed);
      regWrite(k, LOW);
    }
    regWrite(i, HIGH);
  }
}

//bounce effect
void bounce(int speed){
  int prevI = 0;
  for (int i = 0; i < 16; i++){
    regWrite(prevI, LOW);
    regWrite(i, HIGH);
    prevI = i;

    delay(speed);
  }
  for (int i = 15; i >= 0; i--){
    regWrite(prevI, LOW);
    regWrite(i, HIGH);
    prevI = i;

    delay(speed);
  }
}

//cascade mirror effect
void cascadeMirror(int speed){
  for (int i = 0; i < 8; i++){
    for (int k = i; k < 8; k++)
    {
      regWrite(k, HIGH);
      regWrite(15 - k, HIGH);
      delay(speed);
      regWrite(k, LOW);
      regWrite(15 - k, LOW);
    }
    regWrite(i, HIGH);
    regWrite(15 - i, HIGH);
  }
}

//shrink mirror effect
void shrinkMirror(int speed){
  for (int i = 7; i >= 0; i--){
    for (int k = 0; k <= i; k++)
    {
      regWrite(k, HIGH);
      regWrite(15 - k, HIGH);
      delay(speed);
      regWrite(k, LOW);
      regWrite(15 - k, LOW);
    }
    regWrite(i, HIGH);s
    regWrite(15 - i, HIGH);
  }
}

//function to control shitt register
void regWrite(int pin, bool state){
  int reg = pin / 8;
  int actualPin = pin - (8 * reg);
  digitalWrite(latchPin, LOW);
  for (int i = 0; i < numOfRegisters; i++){
    byte* states = &registerState[i];
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }
    shiftOut(dataPin, clockPin, MSBFIRST, *states);
  }
  digitalWrite(latchPin, HIGH);
}

//blink effect
void blink (int speed) {
  for (int i = 0; i < 10; i++) {
    setLeds(0b1010101010101010); 
    delay(speed);
    setLeds(0b0101010101010101); 
    delay(speed);
  }
}

//sending pattern to shift registers
void setLeds(uint16_t pattern) {
  registerState[0] = pattern & 0xFF;
  registerState[1] = (pattern >> 8) & 0xFF;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, registerState[1]);
  shiftOut(dataPin, clockPin, MSBFIRST, registerState[0]);
  digitalWrite(latchPin, HIGH);
}

//fade effect
void fade(int delayTime) {
  for (int i = 0; i < 16; i++) {
    for (int brightness = 0; brightness < 256; brightness += 16) {
      setLed(i, brightness);
      delay(delayTime);
    }
    for (int brightness = 255; brightness >= 0; brightness -= 16) {
      setLed(i, brightness);
      delay(delayTime);
    }
  }
}

//set individual LED brightness
void setLed(int led, int brightness) {
  uint16_t pattern = 0;
  if (brightness > 128) {
    pattern |= (1 << led);
  }
  registerState[0] = pattern & 0xFF;
  registerState[1] = (pattern >> 8) & 0xFF;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, registerState[1]);
  shiftOut(dataPin, clockPin, MSBFIRST, registerState[0]);
  digitalWrite(latchPin, HIGH);
}