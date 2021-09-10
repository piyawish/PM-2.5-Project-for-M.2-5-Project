# PM-2.5-Project-for-M.2-5-Project

```

// M.2/5 Project 
// Create By Piyawish


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int aRead = A0;
float Pressure = 0;
int led = 2;
int buzzer = 11;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(aRead, INPUT);
  pinMode(buzzer , OUTPUT);
  lcd.init();                      
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  

}

void loop() {
  digitalWrite(led, LOW);
  delayMicroseconds(300);

  Pressure = analogRead(aRead);
  delayMicroseconds(50);

  digitalWrite(led, HIGH);
  delayMicroseconds(10000);
  delay(1000);

  if (Pressure > 36.455) {
    float dust = (Pressure / 1024 - 0.0356) * 120000 * 0.035 ;

    if (dust >= -50 && dust <= 50) {

      lcd.print("Tiptop");
      lcd.setCursor(2,1);
      
      
      Serial.print(dust) ; Serial.print(" : Tiptop\n" );
      digitalWrite(buzzer , HIGH); 
      delay(50); 
      digitalWrite(buzzer , LOW); 
      delay(50); 

      lcd.clear () ;

     ;

    }

    if (dust > 50 && dust < 150) {
      
      lcd.print("Nice Weather");
      lcd.setCursor(2,1);
      
      
      
      Serial.print(dust) ; Serial.print(" : Nice Weather\n" );
      digitalWrite(buzzer , HIGH); 
      delay(150); 
      digitalWrite(buzzer , LOW); 
      delay(150); 

      lcd.clear () ;

      
      
    }

    if (dust >= 150 && dust <= 650) {
      Serial.print(dust) ; Serial.print(" : Normal Weather\n" );

      lcd.print("Normal Weather");
      lcd.setCursor(2,1);
     
      
      digitalWrite(buzzer , HIGH); 
      delay(175); 
      digitalWrite(buzzer , LOW); 
      delay(175); 

      lcd.clear() ;

     
     
    }

    if (dust > 650 && dust <= 2000) {
      
      lcd.print("Bad Weather");
      lcd.setCursor(2,1);
      
      
      
      Serial.print(dust) ; Serial.print(" : Bad Weather\n" );     
      digitalWrite(buzzer , HIGH); 
      delay(750); 
      digitalWrite(buzzer , LOW); 
      delay(750); 

      lcd.clear () ;

      
    }

    if (dust > 2000 && dust <= 10000) {

      lcd.print("Terrible Weather");
      lcd.setCursor(2,1);
      
      
      
      Serial.print(dust) ; Serial.print(" : Terrible Weather\n" );
      digitalWrite(buzzer , HIGH); 
      delay(1250); 
      digitalWrite(buzzer , LOW); 
      delay(1250); 

      lcd.clear () ;

     
    }

    if (dust > 10000) {

     lcd.print("Error");
     lcd.setCursor(2,1);
     
     

     
     Serial.println("Error" );
     digitalWrite(buzzer , HIGH); 
     delay(3000); 
     digitalWrite(buzzer , LOW); 
     delay(3000); 

     lcd.clear () ;

 
    }

   
  

  }



}

}

```
