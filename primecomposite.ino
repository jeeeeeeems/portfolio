
/* Laganson, Sunshine P.
  Legaspi, Jemarinette B.
  Nadala, Jovan p.
  BSCpE 302 B */

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
 for ( int num = 0; num <= 100; num++){
    int prime = 1;

    if (num <= 1){
      Serial.print(num);
      Serial.println("; neither prime nor composite");
    }
    else {
      for ( int x = 2 ; x*x <= num; x++) 
      {
        if (num % x == 0) {
          prime = 0;
        }
      }

      if (prime == 1) 
      {
        Serial.print(num);
        Serial.println("; prime");
      }
      else 
      {
        Serial.print(num);
        Serial.println(";composite");
      } 
    } 
  }
  while (true);
  delay (1000);
}

  