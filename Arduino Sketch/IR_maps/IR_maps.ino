/*
 Some Sample code of how to use your IR remote
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

#include <IRremote.h>

int IRpin = 11;  // pin for the IR sensor
int LED = 13;    // LED pin  
IRrecv irrecv(IRpin);
decode_results results;

boolean LEDon = true; // initializing LEDon as true

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED, OUTPUT);
}

void loop() 
{
   
  if (irrecv.decode(&results)) 
    {
      irrecv.resume();   // Receive the next value
    }
  
  switch(results.value)
 {

  case 16753245: //Power button
  // do this
  break;
  
  case 16769565: //Menu button
  // do another thing
  break;
  
  case 16720605: //test button
  // feed my dog for me
  break;
  
  case 16712445: //+ button
  // feed my dog for me
  break;
  
  case 16750695: //- button
  // feed my dog for me
  break;
  
  case 16769055: //prev button
  // feed my dog for me
  break;
  
  case 16748655: //next button
  // feed my dog for me
  break;
  
  case 16754775: //play button
  // feed my dog for me
  break;
  
  case 16761405: //back button
  // feed my dog for me
  break;
  
  case 16738455: //0 button
  // feed my dog for me
  break;
  
  case 16724175: //1 button
  // feed my dog for me
  break;
  
  case 16718055: //2 button
  // feed my dog for me
  break;
  
  case 16743045: //3 button
  // feed my dog for me
  break;
  
  case 16716015: //4 button
  // feed my dog for me
  break;
  
  case 16726215: //5 button
  // feed my dog for me
  break;
  
  case 16734885: //6 button
  // feed my dog for me
  break;
  
  case 16728765: //7 button
  // feed my dog for me
  break;
  
  case 16730805: //8 button
  // feed my dog for me
  break;
  
  case 16732845: //9 button
  // feed my dog for me
  break;
  
  case 16756815: //C button
  // feed my dog for me
  break;
  
  default:
  digitalWrite(LED, HIGH);
  
  }
  
}
