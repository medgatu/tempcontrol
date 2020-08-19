#include <Keypad.h> //The keypad and LCD i2c libraries
#include <Wire.h>
#include <LCD.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#define DHTPIN 5
#define DHTTYPE DHT11
#define I2C_ADDR 0x27 //defining the LCD pins
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {13,12,11,10}; //Rows 0 to 3 //if you modify your pins you should modify this too
byte colPins[numCols]= {9,8,7,6}; //Columns 0 to 3
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
DHT sensor(DHTPIN, DHTTYPE);
int relay_pin = 2;

void setup()
           {
            sensor.begin();
            pinMode(relay_pin, OUTPUT);
            digitalWrite(relay_pin, HIGH);
            Serial.begin(9600);
            lcd.begin (16,2);
            lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
            lcd.setBacklight(HIGH);
            lcd.home ();
            
            }
            lcd.home ();
            lcd.print("press 1 for heat");
            lcd.setCursor(0, 1)
            lcd.print("press 2 for cool");
            char keypressed = myKeypad.getKey();
            while(keypressed == NO_KEY || keypressed ==  '3' || keypressed == 'A'|| keypressed == '4' || keypressed == '5' || keypressed == '6' ||keypressed == 'B' ||keypressed == '7' || keypressed == '8' || keypressed == '9' || keypressed == 'C' ||keypressed == '*' || keypressed == '0' || keypressed == '#' || keypressed == 'D')
{
              keypressed = myKeypad.getKey();
              delay(100);
            }
            
            //lcd.clear();
            //lcd.setCursor(0, 0);
            int horc = keypressed;
            if (keypressed == '1')
              lcd.print("Heating Mode");
            else
              lcd.print("Cooling Mode");
            delay (4000);
            //lcd.clear();
            //lcd.print("Enter Desired Temp:");
           // lcd.setCursor(0, 1);
            keypressed = NO_KEY;

while (keypressed == NO_KEY){
            int keypressed1()
                        {
                            int keypressed = keypad.getKey();
                            switch (keypressed)
                                     {
                                         case NO_KEY: break;
                                         case '0': case '1': case '2': case '3': case '4':
                                                 case '5': case '6': case '7': case '8': case '9':
                                                      {
                                                           lcd.print(keypressed);
                                                           keypressed = digit1;
                                                           break;
                                                      }
                                            case '*':
                                                 {
                                                      voltage2(); // put characters
                                                      break;
                                                 }
                                     }             
                           return digit1;
                        }
                        
                        //Voltage - Digit 2//
                        int keypressed2()
                        {
                            int keypressed = keypad.getKey();
                            switch (keypressed)
                                     {
                                            case NO_KEY: break;
                                            case '0': case '1': case '2': case '3': case '4':
                                                 case '5': case '6': case '7': case '8': case '9':
                                                      {
                                                           lcd.print(keypressed);
                                                           keypressed = digit2;
                                                           break;
                                                      }
                                            case '*':
                                                 {
                                                      voltage2();
                                                      break;
                                                 }
                                     }             
                           
                           return digit2;
}
return digit1;
return digit2;
}


                  int desired ()
{
    int input;
    input = (10*digit1)+(1*digit2);
    input = desired;
    return desired;
}

            

                

                       
                                               
                      
              void loop() {
                        lcd.clear();
                        float t = sensor.readTemperature();
                        if (isnan(t)) {
                        lcd.print("Failed");
                        delay(1000);
                        return;
                        }
                        lcd.setCursor(0,0);
                        lcd.print("Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        if (horc == c){
                        if (t > desired){
                        digitalWrite(relay_pin, LOW);
                        lcd.setCursor(0,1);
                        lcd.print("Fan is ON ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        Else{
                        digitalWrite(relay_pin, HIGH);
                        lcd.setCursor(0,1);
                        lcd.print("Fan is OFF ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        }
                        Else{
                        if (t < desired){
                        digitalWrite(relay_pin, LOW);
                        lcd.setCursor(0,1);
                        lcd.print("Heater is ON ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        Else{
                        digitalWrite(relay_pin, HIGH);
                        lcd.setCursor(0,1);
                        lcd.print("Heater is OFF ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        delay(2000);
                        }
                                    delay(2000);
                                   }
                        
/* 
void loop()
{
         char keypressed = myKeypad.getKey();
         if (keypressed != NO_KEY)
             {
              lcd.clear();
              lcd.print(keypressed);
//            Serial.println(keypressed); Uncomment this to show it on the serial monitor too
              }

}
void loop()
{
         char keypressed = myKeypad.getKey();
         
         if (keypressed ==  '#')
             {
              lcd.clear();
              lcd.print(keypressed);
              */

____________________________________________________________________________
//Hello, This is the code to use a 4x4 keypad matrix with and Arduino and show the result on an LCD screen
//You should wire you keypad from 8to1 (keypad pins) to 9to2 Arduino digital pins
//SurtrTech
/*

#include <Keypad.h> //The keypad and LCD i2c libraries
#include <Wire.h>
#include <LCD.h>

#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#define I2C_ADDR 0x27 //defining the LCD pins
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {13,12,11,10}; //Rows 0 to 3 //if you modify your pins you should modify this too
byte colPins[numCols]= {9,8,7,6}; //Columns 0 to 3
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
int main(){
  
}

void setup()
           {
            Serial.begin(9600);
            lcd.begin (16,2);
            lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
            lcd.setBacklight(HIGH);
            lcd.home ();
            lcd.print("press 1 for heat");
            lcd.setCursor(0, 1)
            lcd.print("press 2 for cool");
            char keypressed = myKeypad.getKey();
            while(keypressed == NO_KEY || keypressed ==  '3' || keypressed == 'A'|| keypressed == '4' || keypressed == '5' || keypressed == '6' ||keypressed == 'B' ||keypressed == '7' || keypressed == '8' || keypressed == '9' || keypressed == 'C' ||keypressed == '*' || keypressed == '0' || keypressed == '#' || keypressed == 'D')
{
              keypressed = myKeypad.getKey();
              delay(100);
            }
            
            lcd.clear();
            lcd.setCursor(0, 0);
            int horc = keypressed;
            if (keypressed == '1')
              lcd.print("Heating Mode");
            else
              lcd.print("Cooling Mode");
            delay (4000);
            lcd.clear();
            lcd.print("Enter Desired Temp:");
            lcd.setCursor(0, 1);
            keypressed = NO_KEY;
            charCounter = 0;
            while (keypressed1 = NO_KEY || keypressed2 = NO_KEY){
              keypressed1 = myKeypad.getKey();
              keypressed2 = myKeypad.getKey();
              int desired1 = keypressed1;
              int desired2 = keypressed2;
              lcd.print(keypressed1);
              lcd.print(keypressed2);
            }
            
                DHT sensor(DHTPIN, DHTTYPE);
                int relay_pin = 9;

                       
                        
                        
                        void setup() {
                        lcd.begin(16,2);
                        sensor.begin();
                        pinMode(relay_pin, OUTPUT);
                        digitalWrite(relay_pin, HIGH);
                        }
                        void loop() {
                        lcd.clear();
                        float t = sensor.readTemperature();
                        if (isnan(t)) {
                        lcd.print("Failed");
                        delay(1000);
                        return;
                        }
                        lcd.setCursor(0,0);
                        lcd.print("Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        If (horc == c){
                        if (t > desired){
                        digitalWrite(relay_pin, LOW);
                        lcd.setCursor(0,1);
                        lcd.print("Fan is ON ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        Else{
                        digitalWrite(relay_pin, HIGH);
                        lcd.setCursor(0,1);
                        lcd.print("Fan is OFF ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        }
                        Else{
                        if (t < desired){
                        digitalWrite(relay_pin, LOW);
                        lcd.setCursor(0,1);
                        lcd.print("Heater is ON ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        Else{
                        digitalWrite(relay_pin, HIGH);
                        lcd.setCursor(0,1);
                        lcd.print("Heater is OFF ");
                        delay(10);
                        lcd.print("Current Temp: ");
                        lcd.print(t);
                        lcd.print(" C");
                        }
                        delay(2000);
                        }
                                    delay(2000);
                                   }
                        
void loop()
{
         char keypressed = myKeypad.getKey();
         if (keypressed != NO_KEY)
             {
              lcd.clear();
              lcd.print(keypressed);
//            Serial.println(keypressed); Uncomment this to show it on the serial monitor too
              }

}
void loop()
{
         char keypressed = myKeypad.getKey();
         
         if (keypressed ==  '#')
             {
              lcd.clear();
              lcd.print(keypressed);
//            Serial.println(keypressed); Uncomment this to show it on the serial monitor too
              }














____________________________________________________________________________

http://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){
  lcd.backlight();
  lcd.init(); 
}

void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print(customKey);
  }
}


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x21, 16, 2);  

void setup(){
  lcd.backlight();
  lcd.init();
}

void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(customKey);
  }
}

int motorPin = 3;

void setup() {

}

void loop() {
   digitalWrite(motorPin, HIGH);
}

int motorPin = 9;

void setup() {
   pinMode(motorPin, OUTPUT);
   Serial.begin(9600);
   while (! Serial);
   Serial.println("Speed 0 to 255");
}

void loop() {
   if (Serial.available()) {
      int speed = Serial.parseInt();
      if (speed >= 0 && speed <= 255) {
         analogWrite(motorPin, speed);
      }
   }
}
https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm
./
