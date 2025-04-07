// columns
const int dataPin1 = 4;   
const int latchPin1 = 3;  
const int clockPin1 = 2;  

// rows
const int dataPin2 = 7;  
const int latchPin2 = 6;  
const int clockPin2 = 5;  

// 8x8 font ( character stored row-wise)
const byte fontSet[11][8] = {

  // L
  {0b00000000,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b11111111,
    0b11111111,
    0b0000000}, 
   
    
   //A
    {0b0000000,
    0b11111111,
    0b11000011,
    0b11000011,
    0b11111111,
    0b11000011,
    0b11000011,
    0b00000000},
    
    //G
    {0b0000000,
    0b11111111,
    0b00000011,
    0b00000011,
    0b11110011,
    0b11000011,
    0b11111111,
    0b00000000},
    
    
   //N
    {0b0000000,
    0b11000011,
    0b11000111,
    0b11001011,
    0b11010011,
    0b11100011,
    0b11000011,
    0b00000000},
    
    //S
    {0b0000000,
    0b11111111,
    0b00000011,
    0b11111111,
    0b11000000,
    0b11000000,
    0b11111111,
    0b00000000},

    
    //O
    {0b0000000,
    0b11111111,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11111111,
    0b00000000},
    
    //SPACE
    {0b00000000,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b00000000},
   
    //E
    {0b00000000,
    0b11111111,
    0b00000011,
    0b11111111,
    0b11111111,
    0b00000011,
    0b11111111,
    0b00000000},
    
    
    //P
    {0b00000000,
    0b11111111,
    0b11000011,
    0b11000011,
    0b11111111,
    0b00000011,
    0b00000011,
    0b00000000},
    
    
    //I
    {0b00000000,
    0b11111111,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b11111111,
    0b00000000},
    
    //D
    {0b00000000,
    0b01111111,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b01111111,
    0b00000000},
    

};

void setup() {
  pinMode(dataPin1, OUTPUT);
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);

  pinMode(dataPin2, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
}


void loop() {
  scrollText();
}

void scrollText() {
  const int message[] = {0, 1, 2, 1, 3, 4, 5, 3, 6, 0, 7, 2, 1, 4, 8, 9, 6, 3, 1, 10, 1, 0, 1 };  // " LAGANSON |||||| LEGASPI |||||| NADALA "
  const int messageLength = sizeof(message) / sizeof(message[0]);

  byte scrollBuffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int letterIndex = 0; letterIndex < messageLength; letterIndex++) {
    for (int scroll = 0; scroll < 8; scroll++) {
      for (int i = 7; i > 0; i--) {
        scrollBuffer[i] = scrollBuffer[i - 1];
      }
      scrollBuffer[0] = fontSet[message[letterIndex]][7 - scroll]; // Load new column on right side

      for (int displayCycles = 0; displayCycles < 5; displayCycles++) {
        for (int row = 0; row < 8; row++) {
          digitalWrite(latchPin1, LOW);
          digitalWrite(latchPin2, LOW);

          shiftOut(dataPin1, clockPin1, MSBFIRST, ~scrollBuffer[row]);  // columns
          shiftOut(dataPin2, clockPin2, MSBFIRST, (1 << row));          // rows

          digitalWrite(latchPin1, HIGH);
          digitalWrite(latchPin2, HIGH);

          delayMicroseconds(5000);
        }
      }
    }
    delay(100);
  }
}
