/* Arduino USB Keyboard HID 
 */
 
#include <IRremote.h>

int IRpin = 4;  // pin for the IR sensor
int LED = 13;    // LED pin  
IRrecv irrecv(IRpin);
decode_results results;

#define F13	104
#define F14	105
#define F15     106
#define power 107 //F16
#define menu  108
#define test  109
#define plus  110
#define minus 111
#define prev  112
#define next  113
#define play  114
#define Ck     115 //F24
#define back   41 //escape
#define zero     39 //keyboard 0
#define one     30
#define two     31
#define three     32
#define four     33
#define five     34
#define six     35
#define seven     36
#define eight     37
#define nine     38

 
uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */
 
#define PIN_F13_KEY 5
#define PIN_F14_KEY 6
#define PIN_F15_KEY 7
 
int state = 1;
boolean toggle1 = false;
boolean toggle2 = false;
boolean toggle3 = false;
boolean toggle4 = false;
long lastDebounceTime1 = 0;
long lastDebounceTime2 = 0;
long lastDebounceTime3 = 0;
long lastDebounceTime4 = 0;
long debounceDelay = 200;
 
void setup() 
{
  Serial.begin(9600);
  // enable digital input for buttons
  pinMode(PIN_F13_KEY, INPUT);
  pinMode(PIN_F14_KEY, INPUT);
  pinMode(PIN_F15_KEY, INPUT);
  // enable internal pull-ups
  digitalWrite(PIN_F13_KEY, 1); 
  digitalWrite(PIN_F14_KEY, 1); 
  digitalWrite(PIN_F15_KEY, 1); 
  
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED, OUTPUT); //LED 13 enable
 
 
  delay(200);
}
 
void loop() 
{
  //Buttons:
  if (keypress(PIN_F13_KEY, toggle1, lastDebounceTime1)){
    buf[2] = F13;
   Serial.write(buf, 8);	// Send keypress
   releaseKey();	 
  } 
 
  if (keypress(PIN_F14_KEY, toggle2, lastDebounceTime2)) {
    buf[2] = F14;
   Serial.write(buf, 8);	// Send keypress
   releaseKey();	  
  } 
 
  if (keypress(PIN_F15_KEY, toggle3, lastDebounceTime3)) {
    buf[2] = F15;
   Serial.write(buf, 8);	// Send keypress
   releaseKey();	  
  } 
  
  
  //IR:
  
  digitalWrite(LED, LOW);
  
  if (irrecv.decode(&results)) 
    {
      irrecv.resume();   // Receive the next value
    }
  int code = results.value;
  if (results.value == 4294967295){
    code = 0;
  }  
      switch(remotepress(code, toggle4, lastDebounceTime4))
      {

        case 16753245: //Power button
        buf[2] = power;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16769565: //Menu button
        buf[2] = menu;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16720605: //test button
        buf[2] = test;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16712445: //+ button
        buf[2] = plus;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16750695: //- button
        buf[2] = minus;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16769055: //prev button
        buf[2] = prev;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16748655: //next button
        buf[2] = next;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16754775: //play button
        buf[2] = play;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16761405: //back button
        buf[2] = back;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16738455: //0 button
        buf[2] = zero;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16724175: //1 button
        buf[2] = one;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16718055: //2 button
        buf[2] = two;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16743045: //3 button
        buf[2] = three;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16716015: //4 button
        buf[2] = four;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16726215: //5 button
        buf[2] = five;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16734885: //6 button
        buf[2] = six;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16728765: //7 button
        buf[2] = seven;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16730805: //8 button
        buf[2] = eight;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16732845: //9 button
        buf[2] = nine;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        case 16756815: //C button
        buf[2] = Ck;
        Serial.write(buf, 8);	// Send keypress
        releaseKey();
        break;
        
        default:
        digitalWrite(LED, HIGH);
  
  } //switch

} //void loop
 
 
 
//button function
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
}

boolean keypress(int key, boolean &toggle, long &lastDebounceTime)
{
  if(!digitalRead(key) && toggle == false)
  {
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      toggle = true;
      lastDebounceTime = millis();
      return true;
    }
  }
  
  else if(!digitalRead(key) && toggle == true)
  {
    return false;
  }
  
  else if(digitalRead(key) && toggle == true)
  {
    toggle = false;
    return false;
  }
  
  else
    return false;
   
}
   
int remotepress(int value, boolean &toggle, long &lastDebounceTime)
{
  if(value && toggle == false)
  {
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      toggle = true;
      lastDebounceTime = millis();
      return value;
    }
  }
  
  else if(value && toggle == true)
  {
    return 0;
  }
  
  else if(!value && toggle == true)
  {
    toggle = false;
    return 0;
  }
  
  else
    return 0;
   
}    
  
