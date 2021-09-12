// M.2/5 Project 
// Create By Piyawish
// Arduino IDE (C++)


#include <Wire.h>                // การเรียกใช้งาน library ของจอ LCD
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); // กำหนดของจอ LCD

int aRead = A0;  // กำหนดค่า Analog ของเซนเซอร์ตรวจจับ
float Pressure = 0; // กำหนดค่า ความดัน ของเซนเซอร์ตรวจจับเพื่อใช้คำณวนค่าฝุ่น
int led = 2;  // กำหนดค่า Digital ของเซนเซอร์ตรวจจับ
int buzzer = 11; // กำหนดขา Digital ของลำโพง buzzer 

void setup() {
  Serial.begin(9600); // กำหนดค่าความเร็วในการแสดงผล
  pinMode(led, OUTPUT); // กำหนดขา Digital ของเซนเซอร์ตรวจจับเป็น OUTPUT
  pinMode(aRead, INPUT); // กำหนดขา Analog ของเซนเซอร์ตรวจจับเป็น OUTPUT
  pinMode(buzzer , OUTPUT); // กำหนดขา Digital ของลำโพง buzzer เป็น OUTPUT
  lcd.init();                      // ตั้งค่าเซตอัพของจอ LCD 
  lcd.init();
  
}

void loop() {
  digitalWrite(led, LOW);  // จ่ายไฟค่า Digital ของเซนเซอร์ตรวจจับเป็น 0V  
  delayMicroseconds(300);  // ดีเลย์ 300/1000000 วินาที

  Pressure = analogRead(aRead);  // กำหนดค่าความดันค่าความดันเป็นค่า Analog ของเซนเซอร์ตรวจจับ
  delayMicroseconds(50); // ดีเลย์ 50/1000000 วินาที

  digitalWrite(led, HIGH); // จ่ายไฟค่า Digital ของเซนเซอร์ตรวจจับเป็น 5V
  delayMicroseconds(10000); // ดีเลย์ 10000/1000000 วินาที
  delay(1000); // ดีเลย์ 1 วิ

  if (Pressure > 36.455) { // สร้างเงื่อนไขค่าความดัน
    float dust = (Pressure / 1024 - 0.0356) * 120000 * 0.035 ; // คำนวณค่าฝุ่นจากค่าความดัน

    if (dust >= -50 && dust <= 50) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่าหรือเท่ากับ -50 และ น้อยกว่าหรือเท่ากับ 50

      lcd.print("Tiptop"); // แสดงผลคำว่า Tiptop ผ่านทางหน้าจอ LCD
      lcd.setCursor(0,1); // เซตตำแหน่งข้อความไว้ที่พิกัด (0,l)
      lcd.print(dust); // แสดงผลค่าฝุ่นผ่านทางหน้าจอ LCD
      
      Serial.print(dust) ; Serial.print(" : Tiptop\n" ); // แสดงผลค่าฝุ่นและคำว่า Tiptop ผ่าน Serial Monitor
      digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
      delay(50); // ดีเลย์ 50/1000 วินาที
      digitalWrite(buzzer , LOW);  // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
      delay(50); // ดีเลย์ 50/1000 วินาที

      lcd.clear () ; // เคลียร์ค่าในจอ LCD

     ;

    }

    if (dust > 50 && dust < 250) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่า 50 และ น้อยกว่าหรือเท่ากับ 250
      
      lcd.print("Nice Weather"); // แสดงผลคำว่า Nice Weather ผ่านทางหน้าจอ LCD
      lcd.setCursor(0,1); // เซตตำแหน่งข้อความไว้ที่พิกัด (0,l)
      lcd.print(dust); // แสดงผลค่าฝุ่นผ่านทางหน้าจอ LCD
      
      
      Serial.print(dust) ; Serial.print(" : Nice Weather\n" ); // แสดงผลค่าฝุ่นและคำว่า Nice Weather ผ่าน Serial Monitor
      digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
      delay(150); // ดีเลย์ 150/1000 วินาที
      digitalWrite(buzzer , LOW); // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
      delay(150); // ดีเลย์ 150/1000 วินาที

      lcd.clear () ; // เคลียร์ค่าในจอ LCD

      
      
    }

    if (dust >= 250 && dust <= 900) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่าหรือเท่ากับ 250 และ น้อยกว่าหรือเท่ากับ 900
      

      lcd.print("Normal Weather"); // แสดงผลคำว่า Normal Weather ผ่านทางหน้าจอ LCD
      lcd.setCursor(0,1); // เซตตำแหน่งข้อความไว้ที่พิกัด (0,l)
      lcd.print(dust); // แสดงผลค่าฝุ่นผ่านทางหน้าจอ LCD
      
     
      Serial.print(dust) ; Serial.print(" : Normal Weather\n" ); // แสดงผลค่าฝุ่นและคำว่า Normal Weather ผ่าน Serial Monitor
      digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
      delay(175); // ดีเลย์ 175/1000 วินาที
      digitalWrite(buzzer , LOW);  // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
      delay(175); // ดีเลย์ 175/1000 วินาที

      lcd.clear() ;  // เคลียร์ค่าในจอ LCD

     
     
    }

    if (dust > 900 && dust <= 2000) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่า 900 และ น้อยกว่าหรือเท่ากับ 2000
      
      lcd.print("Bad Weather"); // แสดงผลคำว่า Bad Weather ผ่านทางหน้าจอ LCD
      lcd.setCursor(0,1); // เซตตำแหน่งข้อความไว้ที่พิกัด (0,l)
      lcd.print(dust); // แสดงผลค่าฝุ่นผ่านทางหน้าจอ LCD
      
      
      
      Serial.print(dust) ; Serial.print(" : Bad Weather\n" );  // แสดงผลค่าฝุ่นและคำว่า Bad Weather ผ่าน Serial Monitor    
      digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
      delay(750);  // ดีเลย์ 750/1000 วินาที
      digitalWrite(buzzer , LOW);  // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
      delay(750);  // ดีเลย์ 750/1000 วินาที

      lcd.clear () ;  // เคลียร์ค่าในจอ LCD

      
    }

    if (dust > 2000 && dust <= 10000) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่า 2000 และ น้อยกว่าหรือเท่ากับ 10000

      lcd.print("Terrible Weather"); // แสดงผลคำว่า Terrible Weather ผ่านทางหน้าจอ LCD
      lcd.setCursor(0,1); // เซตตำแหน่งข้อความไว้ที่พิกัด (0,l)
      lcd.print(dust); // แสดงผลค่าฝุ่นผ่านทางหน้าจอ LCD
      
      
      
      Serial.print(dust) ; Serial.print(" : Terrible Weather\n" ); // แสดงผลค่าฝุ่นและคำว่า Terrible Weather ผ่าน Serial Monitor
      digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
      delay(1250); // ดีเลย์ 1250/1000 วินาที
      digitalWrite(buzzer , LOW);  // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
      delay(1250); // ดีเลย์ 1250/1000 วินาที

      lcd.clear () ;  // เคลียร์ค่าในจอ LCD

     
    }

    if (dust > 10000) { // สร้างเงื่อนไขจากค่าฝุ่น มากกว่า 10000

     lcd.print("Error"); // แสดงผลคำว่า Error ผ่านทางหน้าจอ LCD
     
     
     

     
     Serial.println("Error" ); // แสดงผลคำว่า Error ผ่าน Serial Monitor
     digitalWrite(buzzer , HIGH); // เปิดลำโพง buzzer(ทำให้มีเสียง)
     delay(3000); // ดีเลย์ 3000/1000 วินาที
     digitalWrite(buzzer , LOW); // ปิดลำโพง buzzer(ทำให้ไม่มีเสียง)
     delay(3000); // ดีเลย์ 3000/1000 วินาที

     lcd.clear () ;  // เคลียร์ค่าในจอ LCD

 
    }

   
  

  }



}
