//Version 2 made by Gusbell

// สิ่งที่แก้ไข 1) แก้ function เหลือเพียง 2 var 
//         2) ลด Relay เหลือ 2 ตัว
//         3) แก้คำใน LCD

#include <Keypad.h>
#include <avr/wdt.h>
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int relay1 = 11; // กำหนดขา 2 คุมรีเลย์ตัวที่ 1 กาแฟ
int relay2 = 12; // กำหนดขา 2 คุมรีเลย์ตัวที่ 2 น้ำเชื่อม
int Reset = 10;
LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 20 chars and 4 line display

void setup() {
  digitalWrite(Reset, HIGH);
  delay(200); 
  pinMode(Reset, OUTPUT);  
  
  pinMode(relay1, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 11 เป็น OUTPUT
  pinMode(relay2, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 12 เป็น OUTPUT
  Serial.begin(9600);

  Serial.println("Coffee Project V2 by 'Kitpipat Jaritwong'");
  Serial.println("Input data...");
  
  lcd.begin(20, 4); // initialize the lcd
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(0,1);
  lcd.print("*   Coffee Mixer   *");
  lcd.setCursor(0,2);
  lcd.print("*                  *");
  lcd.setCursor(0,3);
  lcd.print("********************");
  delay(3000);
  lcd.clear();
 
  lcd.setCursor(0, 0);
  lcd.print("Cup Volume :");
  lcd.setCursor(0, 1);
  lcd.print("1=250 2=300 3=350");
  lcd.setCursor(0, 2);
  lcd.print("Sweetness :");
  lcd.setCursor(0, 3);
  lcd.print("1:0 2:10 3:20 4:30");
  
}
char val;
int v_cup;
int a_sweet;
int t1;
int t2;
int incomingByte = 0;
byte Length=0;

void loop() 
{
  Keypad_func();
  switch(Length)
  {
    case 11:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("70% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("0% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total mix 250 ml");
      v_cup=250;
      a_sweet=0;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 12:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("60% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("10% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 250 ml");
      v_cup=250;
      a_sweet=10;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 13:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("50% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("20% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 250 ml");
      v_cup=250;
      a_sweet=20;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 14:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("40% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("30% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 250 ml");
      v_cup=250;
      a_sweet=30;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 15:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("30% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("40% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 250 ml");
      v_cup=250;
      a_sweet=40;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 21:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("70% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("0% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total mix 300 ml");
      v_cup=300;
      a_sweet=0;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 22:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("60% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("10% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 300 ml");
      v_cup=300;
      a_sweet=10;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 23:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("50% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("20% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 300 ml");
      v_cup=300;
      a_sweet=20;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 24:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("40% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("30% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 300 ml");
      v_cup=300;
      a_sweet=30;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 25:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("30% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("40% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 300 ml");
      v_cup=300;
      a_sweet=40;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 31:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("70% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("0% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total mix 350 ml");
      v_cup=350;
      a_sweet=0;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 32:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("60% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("10% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 350 ml");
      v_cup=350;
      a_sweet=10;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 33:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("50% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("20% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 350 ml");
      v_cup=350;
      a_sweet=20;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 34:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("40% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("30% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 350 ml");
      v_cup=350;
      a_sweet=30;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;

     case 35:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Coffee with");
      lcd.setCursor(0, 1);
      lcd.print("30% Coffee");
      lcd.setCursor(0, 2);
      lcd.print("40% Syrup");
      lcd.setCursor(0, 3);
      lcd.print("Total coffee 350 ml");
      v_cup=350;
      a_sweet=40;
      t1=v_cup*((70-a_sweet)/4000);
      t2=v_cup*(a_sweet/167);
      relay();
      break;
    }
}

void ArduinoReset()
{
  wdt_enable(WDTO_15MS);
  while (1)
  {
  }
}

void Keypad_func()
{
  
char key = keypad.getKey();
 if (key != NO_KEY)
   {
    if ( (key >= '0') && (key<= '9') )
      {
       Length = Length *10;
       Length = Length + key -'0';
      }
    if ( key == '#')
     {
      Serial.println("resetting");
      ArduinoReset();
     }
   }
  else
     {
      Keypad_func();
     }
}

void software_Reboot()
{
  wdt_enable(WDTO_15MS);
  while(1)
  {
  }
}
void relay() 
{ 
  digitalWrite(relay1, 0);   // สั่งเปิดรีเลย์
  digitalWrite(relay2, 0);   // สั่งเปิดรีเลย์
  delay(2000);              

  digitalWrite(relay1, 1);   // สั่งปิดรีเลย์
  delay(t1);
  digitalWrite(relay1, 0);   // สั่งปิดรีเลย์
  digitalWrite(relay2, 1);   // สั่งเปิดรีเลย์
  delay(t2);
}
