#include <LiquidCrystal.h>
#include <Servo.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

Servo myservo;  // create servo object to control a servo
int locked = 180;    // locked position of servo
int unlocked = 90;   // unlocked position of servo

#define joyX A0 // define joy stick pins
#define joyY A1

// create arrows on LCD screen 

byte uparrow[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

byte downarrow[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100
};

byte rightarrow[8] = {
  0b00000,
  0b00100,
  0b00110,
  0b11111,
  0b00110,
  0b00100,
  0b00000,
  0b00000
};

byte leftarrow[8] = {
  0b00000,
  0b00100,
  0b01100,
  0b11111,
  0b01100,
  0b00100,
  0b00000,
  0b00000
};

 int green = 11;  // define pins for LEDs
 int red = 10;
 
void setup()
{
 myservo.attach(3);  // attaches the servo on pin 3 to the servo object 
 myservo.write(locked); // locks box
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Beat the game to"); // print a simple message
 lcd.setCursor(0,1);
 lcd.print("unlock the box!");
 delay(4000);
 lcd.clear();
 lcd.setCursor(5,0);
 lcd.print("Begin!");
 delay(1000);
 lcd.clear();

 lcd.createChar(0, uparrow);  // defining the arrows as variables
 lcd.createChar(1, downarrow);
 lcd.createChar(2, rightarrow);
 lcd.createChar(3, leftarrow);

 pinMode(green, OUTPUT); // green LED
 pinMode(red, OUTPUT); // red LED

 Serial.begin(9600);
}

unsigned long time;

int counter1 = 0;  // setting up counters for each arrow
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;
int counter7 = 0;
int counter8 = 0;

long randnum = random(0,4);  // creating randomized arrows
long randnum2 = random(0,4);
long randnum3 = random(0,4);
long randnum4 = random(0,4);
long randnum5 = random(0,4);
long randnum6 = random(0,4);
long randnum7 = random(0,4);
long randnum8 = random(0,4);

int speed = 1000; // delay for first round

bool winning = true; // variable for whether the user is winning or not

int direction[4][2] = { {0, 495},     // up
                        {1023, 495},  // down
                        {518,0},      // right
                        {518, 1023}   // left
                        };

void loop(){ //------------------------------------------beginning of loop---------------------------------------------
 
 while(counter8 < 17 && winning == true) { 
  
    int xValue = analogRead(joyX); // reading joystick movemenrt
    int yValue = analogRead(joyY);
   
    //print the values with to plot or view
    Serial.print(xValue);  
    Serial.print("\t");
    Serial.println(yValue);
  
    lcd.setCursor(8,1); // moving cursor along bottom line
    lcd.print("-");
   
    lcd.setCursor(counter1,0); // setting cursor to the first cell
    lcd.write(byte(randnum));
    counter1 = counter1 + 2; // increasing by 2 spaces 
  
        if(counter1 == 10 && abs(xValue- direction[randnum][0]) < 200 && abs(yValue - direction[randnum][1]) < 200){
          digitalWrite(green, HIGH); // turning green LED on if user moves joystick in correct direction
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter1 == 10) {
          digitalWrite(red, HIGH); // turning red LED on if user does not move joystick in correct direction
          delay(200);
          digitalWrite(red, LOW);
          winning = false; // user missed arrow and losses game
        }
  
        if(counter1 > 2){ // beginning next arrow after previous arrow has moved 2 spaces
          lcd.setCursor(counter2,0);
          lcd.write(byte(randnum2));
          counter2 = counter2 + 2;
        }
  
        if(counter2 == 10 && abs(xValue- direction[randnum2][0]) < 200 && abs(yValue - direction[randnum2][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter2 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }    
      
        if(counter2 > 2){
          lcd.setCursor(counter3,0);
          lcd.write(byte(randnum3));
          counter3 = counter3 + 2;   
        }  
  
        if(counter3 == 10 && abs(xValue- direction[randnum3][0]) < 200 && abs(yValue - direction[randnum3][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter3 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }        
  
       if(counter3 > 2){
         lcd.setCursor(counter4,0);
         lcd.write(byte(randnum4));
         counter4 = counter4 + 2;   
       }     
       
       if(counter4 == 10 && abs(xValue- direction[randnum4][0]) < 200 && abs(yValue - direction[randnum4][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter4 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter4 > 2){
         lcd.setCursor(counter5,0);
         lcd.write(byte(randnum5));
         counter5 = counter5 + 2;   
       } 
  
       if(counter5 == 10 && abs(xValue- direction[randnum5][0]) < 200 && abs(yValue - direction[randnum5][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter5 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter5 > 2){
         lcd.setCursor(counter6,0);
         lcd.write(byte(randnum6));
         counter6 = counter6 + 2;   
       }      
  
       if(counter6 == 10 && abs(xValue- direction[randnum6][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter6 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter6 > 2){
         lcd.setCursor(counter7,0);
         lcd.write(byte(randnum7));
         counter7 = counter7 + 2;   
       }        
  
       if(counter7 == 10 && abs(xValue- direction[randnum7][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter7 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter7 > 2){
         lcd.setCursor(counter8,0);
         lcd.write(byte(randnum8));
         counter8 = counter8 + 2; 
       }
  
       if(counter8 == 10 && abs(xValue- direction[randnum8][0]) < 200 && abs(yValue - direction[randnum8][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter8 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }             
                                             
      delay(speed); 
      lcd.clear();
  }
  
  // if user misses arrow, end game
  
  while(winning == false){
    lcd.setCursor(4,0);
    lcd.print("You Lose!");
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW); 
    lcd.clear();
    delay(500);
  }
  
  // resetting variables for next round 
  
  counter1 = 0;
  counter2 = 0;
  counter3 = 0;
  counter4 = 0;
  counter5 = 0;
  counter6 = 0;
  counter7 = 0;
  counter8 = 0;
  
  randnum = random(0,4);
  randnum2 = random(0,4);
  randnum3 = random(0,4);
  randnum4 = random(0,4);
  randnum5 = random(0,4);
  randnum6 = random(0,4);
  randnum7 = random(0,4);
  randnum8 = random(0,4);
  
  lcd.print("Faster...");
  for(int text=0; text<16; text++) {
    lcd.scrollDisplayRight();
    delay(400);
  }
  
  speed = speed/1.5; // increasing speed
  
  while(counter8 < 17 && winning == true) {
  
    int xValue = analogRead(joyX); // redefining user input from joystick
    int yValue = analogRead(joyY);
   
    //print the values with to plot or view
    Serial.print(xValue);
    Serial.print("\t");
    Serial.println(yValue);
  
    lcd.setCursor(8,1);
    lcd.print("-");
   
    lcd.setCursor(counter1,0);
    lcd.write(byte(randnum));
    counter1 = counter1 + 2;
  
        if(counter1 == 10 && abs(xValue- direction[randnum][0]) < 200 && abs(yValue - direction[randnum][1]) < 200){
          digitalWrite(green, HIGH); // turning green LED on if user moves joystick in correct direction
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter1 == 10) {
          digitalWrite(red, HIGH); // turning red LED on if user does not move joystick in correct direction
          delay(200);
          digitalWrite(red, LOW);
          winning = false; // user missed arrow and losses game
        }
  
        if(counter1 > 2){ // beginning next arrow after previous arrow has moved 2 spaces
          lcd.setCursor(counter2,0);
          lcd.write(byte(randnum2));
          counter2 = counter2 + 2;
        }
  
        if(counter2 == 10 && abs(xValue- direction[randnum2][0]) < 200 && abs(yValue - direction[randnum2][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter2 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }    
      
        if(counter2 > 2){
          lcd.setCursor(counter3,0);
          lcd.write(byte(randnum3));
          counter3 = counter3 + 2;   
        }  
  
        if(counter3 == 10 && abs(xValue- direction[randnum3][0]) < 200 && abs(yValue - direction[randnum3][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter3 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }        
  
       if(counter3 > 2){
         lcd.setCursor(counter4,0);
         lcd.write(byte(randnum4));
         counter4 = counter4 + 2;   
       }     
       
       if(counter4 == 10 && abs(xValue- direction[randnum4][0]) < 200 && abs(yValue - direction[randnum4][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter4 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter4 > 2){
         lcd.setCursor(counter5,0);
         lcd.write(byte(randnum5));
         counter5 = counter5 + 2;   
       } 
  
       if(counter5 == 10 && abs(xValue- direction[randnum5][0]) < 200 && abs(yValue - direction[randnum5][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter5 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter5 > 2){
         lcd.setCursor(counter6,0);
         lcd.write(byte(randnum6));
         counter6 = counter6 + 2;   
       }      
  
       if(counter6 == 10 && abs(xValue- direction[randnum6][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter6 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter6 > 2){
         lcd.setCursor(counter7,0);
         lcd.write(byte(randnum7));
         counter7 = counter7 + 2;   
       }        
  
       if(counter7 == 10 && abs(xValue- direction[randnum7][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter7 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter7 > 2){
         lcd.setCursor(counter8,0);
         lcd.write(byte(randnum8));
         counter8 = counter8 + 2; 
       }
  
       if(counter8 == 10 && abs(xValue- direction[randnum8][0]) < 200 && abs(yValue - direction[randnum8][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter8 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }             
                                             
      delay(speed);
      lcd.clear();
  }
  
  while(winning == false){
    lcd.setCursor(4,0);
    lcd.print("You Lose!");
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW); 
    lcd.clear();
    delay(500);
  }
  
  counter1 = 0;
  counter2 = 0;
  counter3 = 0;
  counter4 = 0;
  counter5 = 0;
  counter6 = 0;
  counter7 = 0;
  counter8 = 0;
  
  randnum = random(0,4);
  randnum2 = random(0,4);
  randnum3 = random(0,4);
  randnum4 = random(0,4);
  randnum5 = random(0,4);
  randnum6 = random(0,4);
  randnum7 = random(0,4);
  randnum8 = random(0,4);
  
  lcd.print("FASTER!");
  for(int text=0; text<16; text++) {
    lcd.scrollDisplayRight();
    delay(400);
  }
  
  speed = speed/1.5;
  
  while(counter8 < 17 & winning == true) {
  
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
   
    //print the values with to plot or view
    Serial.print(xValue);
    Serial.print("\t");
    Serial.println(yValue);
  
    lcd.setCursor(8,1);
    lcd.print("-");
   
    lcd.setCursor(counter1,0);
    lcd.write(byte(randnum));
    counter1 = counter1 + 2;
  
        if(counter1 == 10 && abs(xValue- direction[randnum][0]) < 200 && abs(yValue - direction[randnum][1]) < 200){
          digitalWrite(green, HIGH); // turning green LED on if user moves joystick in correct direction
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter1 == 10) {
          digitalWrite(red, HIGH); // turning red LED on if user does not move joystick in correct direction
          delay(200);
          digitalWrite(red, LOW);
          winning = false; // user missed arrow and losses game
        }
  
        if(counter1 > 2){ // beginning next arrow after previous arrow has moved 2 spaces
          lcd.setCursor(counter2,0);
          lcd.write(byte(randnum2));
          counter2 = counter2 + 2;
        }
  
        if(counter2 == 10 && abs(xValue- direction[randnum2][0]) < 200 && abs(yValue - direction[randnum2][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter2 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }    
      
        if(counter2 > 2){
          lcd.setCursor(counter3,0);
          lcd.write(byte(randnum3));
          counter3 = counter3 + 2;   
        }  
  
        if(counter3 == 10 && abs(xValue- direction[randnum3][0]) < 200 && abs(yValue - direction[randnum3][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter3 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }        
  
       if(counter3 > 2){
         lcd.setCursor(counter4,0);
         lcd.write(byte(randnum4));
         counter4 = counter4 + 2;   
       }     
       
       if(counter4 == 10 && abs(xValue- direction[randnum4][0]) < 200 && abs(yValue - direction[randnum4][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter4 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter4 > 2){
         lcd.setCursor(counter5,0);
         lcd.write(byte(randnum5));
         counter5 = counter5 + 2;   
       } 
  
       if(counter5 == 10 && abs(xValue- direction[randnum5][0]) < 200 && abs(yValue - direction[randnum5][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter5 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter5 > 2){
         lcd.setCursor(counter6,0);
         lcd.write(byte(randnum6));
         counter6 = counter6 + 2;   
       }      
  
       if(counter6 == 10 && abs(xValue- direction[randnum6][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter6 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter6 > 2){
         lcd.setCursor(counter7,0);
         lcd.write(byte(randnum7));
         counter7 = counter7 + 2;   
       }        
  
       if(counter7 == 10 && abs(xValue- direction[randnum7][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter7 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter7 > 2){
         lcd.setCursor(counter8,0);
         lcd.write(byte(randnum8));
         counter8 = counter8 + 2; 
       }
  
       if(counter8 == 10 && abs(xValue- direction[randnum8][0]) < 200 && abs(yValue - direction[randnum8][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter8 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }             
                                             
      delay(speed);
      lcd.clear();
  }
  
  while(winning == false){
    lcd.setCursor(4,0);
    lcd.print("You Lose!");
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW); 
    lcd.clear();
    delay(500);
  }
  
  counter1 = 0;
  counter2 = 0;
  counter3 = 0;
  counter4 = 0;
  counter5 = 0;
  counter6 = 0;
  counter7 = 0;
  counter8 = 0;
  
  randnum = random(0,4);
  randnum2 = random(0,4);
  randnum3 = random(0,4);
  randnum4 = random(0,4);
  randnum5 = random(0,4);
  randnum6 = random(0,4);
  randnum7 = random(0,4);
  randnum8 = random(0,4);
  
  lcd.print("HYPERSPEED!!!");
  for(int text=0; text<16; text++) {
    lcd.scrollDisplayRight();
    delay(400);
  }
  
  speed = speed/1.5;
  
  while(counter8 < 17 && winning == true) {
  
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
   
    //print the values with to plot or view
    Serial.print(xValue);
    Serial.print("\t");
    Serial.println(yValue);
  
    lcd.setCursor(8,1);
    lcd.print("-");
   
    lcd.setCursor(counter1,0);
    lcd.write(byte(randnum));
    counter1 = counter1 + 2;
  
        if(counter1 == 10 && abs(xValue- direction[randnum][0]) < 200 && abs(yValue - direction[randnum][1]) < 200){
          digitalWrite(green, HIGH); // turning green LED on if user moves joystick in correct direction
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter1 == 10) {
          digitalWrite(red, HIGH); // turning red LED on if user does not move joystick in correct direction
          delay(200);
          digitalWrite(red, LOW);
          winning = false; // user missed arrow and losses game
        }
  
        if(counter1 > 2){ // beginning next arrow after previous arrow has moved 2 spaces
          lcd.setCursor(counter2,0);
          lcd.write(byte(randnum2));
          counter2 = counter2 + 2;
        }
  
        if(counter2 == 10 && abs(xValue- direction[randnum2][0]) < 200 && abs(yValue - direction[randnum2][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter2 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }    
      
        if(counter2 > 2){
          lcd.setCursor(counter3,0);
          lcd.write(byte(randnum3));
          counter3 = counter3 + 2;   
        }  
  
        if(counter3 == 10 && abs(xValue- direction[randnum3][0]) < 200 && abs(yValue - direction[randnum3][1]) < 200){
          digitalWrite(green, HIGH);
          delay(200);
          digitalWrite(green, LOW);
        }
        
        else if(counter3 == 10) {
          digitalWrite(red, HIGH);
          delay(200);
          digitalWrite(red, LOW);
          winning = false;
        }        
  
       if(counter3 > 2){
         lcd.setCursor(counter4,0);
         lcd.write(byte(randnum4));
         counter4 = counter4 + 2;   
       }     
       
       if(counter4 == 10 && abs(xValue- direction[randnum4][0]) < 200 && abs(yValue - direction[randnum4][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter4 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter4 > 2){
         lcd.setCursor(counter5,0);
         lcd.write(byte(randnum5));
         counter5 = counter5 + 2;   
       } 
  
       if(counter5 == 10 && abs(xValue- direction[randnum5][0]) < 200 && abs(yValue - direction[randnum5][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter5 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter5 > 2){
         lcd.setCursor(counter6,0);
         lcd.write(byte(randnum6));
         counter6 = counter6 + 2;   
       }      
  
       if(counter6 == 10 && abs(xValue- direction[randnum6][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter6 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter6 > 2){
         lcd.setCursor(counter7,0);
         lcd.write(byte(randnum7));
         counter7 = counter7 + 2;   
       }        
  
       if(counter7 == 10 && abs(xValue- direction[randnum7][0]) < 200 && abs(yValue - direction[randnum6][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter7 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }    
          
       if(counter7 > 2){
         lcd.setCursor(counter8,0);
         lcd.write(byte(randnum8));
         counter8 = counter8 + 2; 
       }
  
       if(counter8 == 10 && abs(xValue- direction[randnum8][0]) < 200 && abs(yValue - direction[randnum8][1]) < 200){
         digitalWrite(green, HIGH);
         delay(200);
         digitalWrite(green, LOW);
       }
        
       else if(counter8 == 10) {
         digitalWrite(red, HIGH);
         delay(200);
         digitalWrite(red, LOW);
         winning = false;
       }             
                                             
      delay(speed);
      lcd.clear();
  }
  
  // user has completed game
  // unlock box
  
  int unlock = 1; // set variable to unlock only once
  
    while(winning == true){
      lcd.setCursor(1,0);
      lcd.print("Access Granted...");
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW); 
      lcd.clear();
      delay(500);  
        if(unlock == 1){
          myservo.write(unlocked);  
          unlock = 0;
        }
    }
}

