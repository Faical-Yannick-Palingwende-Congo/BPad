/*
  State change detection (edge detection)
    
 Often, you don't need to know the state of a digital input all the time,
 but you just need to know when the input changes from one state to another.
 For example, you want to know when a button goes from OFF to ON.  This is called
 state change detection, or edge detection.
 
 This example shows how to detect when a button or button changes from off to on
 and on to off.
    
 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground (or use the built-in LED on
   most Arduino boards)
 
 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.
    
 http://arduino.cc/en/Tutorial/ButtonStateChange
 
 */

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// variables for the display


#define I2C_ADDR    0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C       lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

// --------------- end display var ----------------

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 7;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the red LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int buttonState2 = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int lastButtonState2 = 0;     // previous state of the button

int lcdCursor = 0;

// ascii char var
int charCode = 0;

void setup() {

 // setup the LCD

 lcd.begin (20,4);
lcdCursor = 0;
	
  
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); 

	lcd.print("B pad"); 

//--------------------

// setup the buttons
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
 // initialize the button 2 pin as a input:
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {

	
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
	buttonState2 = digitalRead(buttonPin2);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
			
			// set the LCD button
			lcdCursor++;
			lcdCursor = lcdCursor % 20 ;

			charCode = charCode * 10 + 1;

      buttonPushCounter++;
		
			lcd.setCursor ( lcdCursor, 1 );
			lcd.print("1");  
			
			Serial.println("cursor");
			Serial.println(lcdCursor);

			Serial.println("charCode");
			Serial.println(charCode);
  		
      Serial.println("on 1");
      Serial.print("number of button 1 pushes:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off 1"); 
    }
  }

// ----------------------------

 // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:



      // set the LCD button
			lcdCursor++;
			lcdCursor = lcdCursor % 20 ;

			charCode = charCode * 10;

      buttonPushCounter2++;
		
			lcd.setCursor ( lcdCursor, 1 );
			lcd.print("0");  
			
			Serial.println("cursor");
			Serial.println(lcdCursor);

			Serial.println("charCode");
			Serial.println(charCode);




      Serial.println("on 2");
      Serial.print("number of button 2 pushes:  ");
      Serial.println(buttonPushCounter2);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off 2"); 
    }
  }

// --------------------------
  // save the current state as the last state, 
  //for next time through the loop
 // for the 2 buttons
  lastButtonState = buttonState;
	lastButtonState2 = buttonState2;

	String resultString = convertToAscii(charCode);

	Serial.println("char is ");
	Serial.println(resultString);

	
	lcd.setCursor ( 0, 3 );
	lcd.print("    ");
  lcd.setCursor ( 0, 3 );
	lcd.print(resultString);  
  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
		
  } else {
   digitalWrite(ledPin, LOW);
  }
  
}

String convertToAscii(int x)
{		
	String charAsci="";

	switch(x){
      case 0:
        charAsci = "NULL";
        break;      
			case 1:
        charAsci = "SOH";
        break;
      case 10:
        charAsci = "STX";
        break;
      case 11:
        charAsci = "EXT";
        break;
      case 100:
        charAsci = "EOT";
        break;
      case 101:
        charAsci = "ENQ";
        break;
      case 110:
        charAsci = "ACK";
        break;
      case 111:
        charAsci = "BEL";
        break;
      case 1000:
        charAsci = "BS";
        break;
      case 1001:
        charAsci = "TAB";
        break;
      case 1010:
        charAsci = "LF";
        break;
      case 1011:
        charAsci = "VT";
        break;
      case 1100:
        charAsci = "FF";
        break;
      case 1101:
        charAsci = "CR";
        break;
      case 1110:
        charAsci = "SO";
        break;
      case 1111:
        charAsci = "SI";
        break;
      case 10000:
        charAsci = "DLE";
        break;
      case 10001:
        charAsci = "DC1";
        break;
      case 10010:
        charAsci = "DC2";
        break;
      case 10011:
        charAsci = "DC3";
        break;
      case 10100:
        charAsci = "DC4";
        break;
      case 10101:
        charAsci = "NAK";
        break;
      case 10110:
        charAsci = "SYN";
        break;
      case 10111:
        charAsci = "ETB";
        break;
      case 11000:
        charAsci = "CAN";
        break;
      case 11001:
        charAsci = "EM";
        break;
      case 11010:
        charAsci = "SUB";
        break;
      case 11011:
        charAsci = "ESC";
        break;
      case 11100:
        charAsci = "FS";
        break;
      case 11101:
        charAsci = "GS";
        break;
      case 11110:
        charAsci = "RS";
        break;
      case 11111:
        charAsci = "US";
        break;
      case 100000:
        charAsci = "SPACE";
        break;
      case 100001:
        charAsci = "!";
        break;
      case 100010:
        charAsci = "\"";
        break;
      case 100011:
        charAsci = "#";
        break;
      case 100100:
        charAsci = "$";
        break;
      case 100101:
        charAsci = "%";
        break;
      case 100110:
        charAsci = "&";
        break;
      case 100111:
        charAsci = "\'";
        break;
      case 101000:
        charAsci = "(";
        break;
      case 101001:
        charAsci = ")";
        break;
      case 101010:
        charAsci = "*";
        break;
      case 101011:
        charAsci = "+";
        break;
      case 101100:
        charAsci = ",";
        break;
      case 101101:
        charAsci = "-";
        break;
      case 101110:
        charAsci = ".";
        break;
      case 101111:
        charAsci = "/";
        break;
      case 110000:
        charAsci = "0";
        break;
      case 110001:
        charAsci = "1";
        break;
      case 110010:
        charAsci = "2";
        break;
      case 110011:
        charAsci = "3";
        break;
      case 110100:
        charAsci = "4";
        break;
      case 110101:
        charAsci = "5";
        break;
      case 110110:
        charAsci = "6";
        break;
      case 110111:
        charAsci = "7";
        break;
      case 111000:
        charAsci = "8";
        break;
      case 111001:
        charAsci = "9";
        break;
      case 111010:
        charAsci = ":";
        break;
      case 111011:
        charAsci = ";";
        break;
      case 111100:
        charAsci = "<";
        break;
      case 111101:
        charAsci = "=";
        break;
      case 111110:
        charAsci = ">";
        break;
      case 111111:
        charAsci = "?";
        break;
      case 1000000:
        charAsci = "aro"; // was arobase
        break;
      case 1000001:
        charAsci = "A";
        break;
      case 1000010:
        charAsci = "B";
        break;
      case 1000011:
        charAsci = "C";
        break;
      case 1000100:
        charAsci = "D";
        break;
      case 1000101:
        charAsci = "E";
        break;
      case 1000110:
        charAsci = "F";
        break;
      case 1000111:
        charAsci = "G";
        break;
      case 1001000:
        charAsci = "H";
        break;
      case 1001001:
        charAsci = "I";
        break;
      case 1001010:
        charAsci = "J";
        break;
      case 1001011:
        charAsci = "K";
        break;
      case 1001100:
        charAsci = "L";
        break;
      case 1001101:
        charAsci = "M";
        break;
      case 1001110:
        charAsci = "N";
        break;
      case 1001111:
        charAsci = "O";
        break;
      case 1010000:
        charAsci = "P";
        break;
      case 1010001:
        charAsci = "Q";
        break;
      case 1010010:
        charAsci = "R";
        break;
      case 1010011:
        charAsci = "S";
        break;
      case 1010100:
        charAsci = "T";
        break;
      case 1010101:
        charAsci = "U";
        break;
      case 1010110:
        charAsci = "V";
        break;
      case 1010111:
        charAsci = "W";
        break;
      case 1011000:
        charAsci = "X";
        break;
      case 1011001:
        charAsci = "Y";
        break;
      case 1011010:
        charAsci = "Z";
        break;
      case 1011011:
        charAsci = "[";
        break;
      case 1011100:
        charAsci = "LOL";
        break;
      case 1011101:
        charAsci = "]";
        break;
      case 1011110:
        charAsci = "?";
        break;
      case 1011111:
        charAsci = "";
        break;
      /*case 1100000:
        charAsci = "`";
        break;*/
      case 1100001:
        charAsci = "a";
        break;
      case 1100010:
        charAsci = "b";
        break;
      case 1100011:
        charAsci = "c";
        break;
      case 1100100:
        charAsci = "d";
        break;
      case 1100101:
        charAsci = "e";
        break;
      case 1100110:
        charAsci = "f";
        break;
      case 1100111:
        charAsci = "g'";
        break;
      case 1101000:
        charAsci = "h";
        break;
      case 1101001:
        charAsci = "i";
        break;
      case 1101010:
        charAsci = "j";
        break;
      case 1101011:
        charAsci = "k";
        break;
      case 1101100:
        charAsci = "l";
        break;
      case 1101101:
        charAsci = "m";
        break;
      case 1101110:
        charAsci = "n";
        break;
      case 1101111:
        charAsci = "o";
        break;
      case 1110000:
        charAsci = "p";
        break;
      case 1110001:
        charAsci = "q";
        break;
      case 1110010:
        charAsci = "r";
        break;
      case 1110011:
        charAsci = "s";
        break;
      case 1110100:
        charAsci = "t";
        break;
      case 1110101:
        charAsci = "u";
        break;
      case 1110110:
        charAsci = "v";
        break;
      case 1110111:
        charAsci = "w";
        break;
      case 1111000:
        charAsci = "x";
        break;
      case 1111001:
        charAsci = "y";
        break;
      case 1111010:
        charAsci = "z";
        break;
      case 1111011:
        charAsci = "{";
        break;
      case 1111100:
        charAsci = "|";
        break;
      case 1111101:
        charAsci = "}";
        break;
      case 1111110:
        charAsci = "~";
        break;
      case 1111111:
        charAsci = "DEL";
      /*break;
      case 10000000:
        charAsci = "Ç";
        break;
      case 10000001:
        charAsci = "û";
        break;
      case 10000010:
        charAsci = "é";
        break;
      case 10000011:
        charAsci = "â";
        break;
      case 10000100:
        charAsci = "ä";
        break;
      case 10000101:
        charAsci = "à";
        break;
      case 10000110:
        charAsci = "å";
        break;
      case 10000111:
        charAsci = "ç";
        break;
      case 10001000:
        charAsci = "ê";
        break;
      case 10001001:
        charAsci = "ë";
        break;
      case 10001010:
        charAsci = "è";
        break;
      case 10001011:
        charAsci = "ï";
        break;
      case 10001100:
        charAsci = "î";
        break;
      case 10001101:
        charAsci = "ì";
        break;
      case 10001110:
        charAsci = "Ä";
        break;
      case 10001111:
        charAsci = "Å";
        break;
      case 10010000:
        charAsci = "É";
        break;
      case 10010001:
        charAsci = "æ";
        break;
      case 10010010:
        charAsci = "Æ";
        break;
      case 10010011:
        charAsci = "ô";
        break;
      case 10010100:
        charAsci = "ö";
        break;
      case 10010101:
        charAsci = "ò";
        break;
      case 10010110:
        charAsci = "û";
        break;
      case 10010111:
        charAsci = "ù";
        break;
      case 10011000:
        charAsci = "ÿ";
        break;
      case 10011001:
        charAsci = "Ö";
        break;
      case 10011010:
        charAsci = "Ü";
        break;
      case 10011011:
        charAsci = "155";
        break;
      case 10011100:
        charAsci = "£";
        break;
      case 10011101:
        charAsci = "¥";
        break;
      case 10011110:
        charAsci = "158";
        break;
      case 10011111:
        charAsci = "?";
        break;
      case 10100000:
        charAsci = "á";
        break;
      case 10100001:
        charAsci = "í";
        break;
      case 10100010:
        charAsci = "ó";
        break;
      case 10100011:
        charAsci = "ú";
        break;
      case 10100100:
        charAsci = "ñ";
        break;
      case 10100101:
        charAsci = "Ñ"; */
        break;
      case 10100110:
        charAsci = "166";
        break;
      case 10100111:
        charAsci = "?";
      /*break;
      case 10101000:
        charAsci = "¿";*/
        break;
      case 10101001:
        charAsci = "169";
      /*break;
      case 10101010:
        charAsci = "¬";*/
        break;
      case 10101011:
        charAsci = "171";
        break;
      case 10101100:
        charAsci = "172";
      /*break;
      case 10101101:
        charAsci = "¡";*/
        break;
      case 10101110:
        charAsci = "«";
        break;
      case 10101111:
        charAsci = "»";
        break;
      case 10110000:
        charAsci = "176";
        break;
      case 10110001:
        charAsci = "177";
        break;
      case 10110010:
        charAsci = "178";
        break;
      case 10110011:
        charAsci = "179";
        break;
      case 10110100:
        charAsci = "180";
        break;
      case 10110101:
        charAsci = "181";
        break;
      case 10110110:
        charAsci = "182";
        break;
      case 10110111:
        charAsci = "183";
        break;
      case 10111000:
        charAsci = "184";
        break;
      case 10111001:
        charAsci = "185";
        break;
      case 10111010:
        charAsci = "186";
        break;
      case 10111011:
        charAsci = "187";
        break;
      case 10111100:
        charAsci = "188";
        break;
      case 10111101:
        charAsci = "189";
        break;
      case 10111110:
        charAsci = "190";
        break;
      case 10111111:
        charAsci = "191";
        break;
      case 11000000:
        charAsci = "192";
        break;
      case 11000001:
        charAsci = "193";
        break;
      case 11000010:
        charAsci = "194";
        break;
      case 11000011:
        charAsci = "195";
        break;
      case 11000100:
        charAsci = "196";
        break;
      case 11000101:
        charAsci = "197";
        break;
      case 11000110:
        charAsci = "198";
        break;
      case 11000111:
        charAsci = "199";
        break;
      case 11001000:
        charAsci = "200";
        break;
      case 11001001:
        charAsci = "201";
        break;
      case 11001010:
        charAsci = "202";
        break;
      case 11001011:
        charAsci = "203";
        break;
      case 11001100:
        charAsci = "204";
        break;
      case 11001101:
        charAsci = "205";
        break;
      case 11001110:
        charAsci = "206";
        break;
      case 11001111:
        charAsci = "207";
        break;
      case 11010001:
        charAsci = "208";
        break;
      case 11010000:
        charAsci = "209";
        break;
      case 11010010:
        charAsci = "210";
        break;
      case 11010011:
        charAsci = "211";
        break;
      case 11010100:
        charAsci = "212";
        break;
      case 11010101:
        charAsci = "213";
        break;
      case 11010110:
        charAsci = "214";
        break;
      case 11010111:
        charAsci = "215";
        break;
      case 11011000:
        charAsci = "216";
        break;
      case 11011001:
        charAsci = "217";
        break;
      case 11011010:
        charAsci = "218";
        break;
      case 11011011:
        charAsci = "219";
        break;
      case 11011100:
        charAsci = "220";
        break;
      case 11011101:
        charAsci = "221";
        break;
      case 11011110:
        charAsci = "222";
        break;
      case 11011111:
        charAsci = "223";
        break;
      case 11100000:
        charAsci = "ß";
        break;
      case 11100010:
        charAsci = "226";
      /*break;
      case 11100011:
        charAsci = "?";
        break;
      case 11100100:
        charAsci = "?";
        break;
      case 11100101:
        charAsci = "229";
        break;
      case 11100110:
        charAsci = "µ";*/
        break;
      case 11100111:
        charAsci = "231";
        break;
      case 11101000:
        charAsci = "232";
        break;
      case 11101001:
        charAsci = "233";
      /*break;
      case 11101010:
        charAsci = "?";*/
        break;
      case 11101011:
        charAsci = "235";
      /*break;
      case 11101100:
        charAsci = "?";*/
        break;
      case 11101101:
        charAsci = "237";
        break;
      case 11101110:
        charAsci = "238";
        break;
      case 11101111:
        charAsci = "239";
        break;
      case 11110000:
        charAsci = "240";
      /*break;
      case 11110001:
        charAsci = "±";
        break;
      case 11110010:
        charAsci = "?";
        break;
      case 11110011:
        charAsci = "?";*/
        break;
      case 11110100:
        charAsci = "244";
        break;
      case 11110101:
        charAsci = "245";
        break;
      case 11110110:
        charAsci = "÷";
        break;
      case 11110111:
        charAsci = "?";
        break;
      case 11111000:
        charAsci = "?";
        break;
      case 11111001:
        charAsci = "·?";
        break;
      case 11111010:
        charAsci = "·";
      /*break;
      case 11111011:
        charAsci = "?";*/
        break;
      case 11111100:
        charAsci = "252";
        break;
      case 11111101:
        charAsci = "253";
        break;
      case 11111110:
        charAsci = "254";
        break;
      case 11111111:
        charAsci = "255";
      default:
        charAsci = "";
    }
return charAsci ;
}