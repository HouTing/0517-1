const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int timer = 100;
int pinCount = 11;

int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // an array of pin numbers to which LEDs are attached
void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
   int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, 1023, 0, 500);

 
 
 
    if(ledLevel<250)
    {
      for (int thisPin = 0; thisPin < pinCount; thisPin++) 
      {
       // turn the pin on:
       digitalWrite(ledPins[thisPin], HIGH);
       delay(timer);
        // turn the pin off:
       digitalWrite(ledPins[thisPin], LOW);
      }
  
      // loop from the highest pin to the lowest:
      for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) 
      {
         // turn the pin on:
        digitalWrite(ledPins[thisPin], HIGH);
        delay(timer);
       // turn the pin off:
        digitalWrite(ledPins[thisPin], LOW);
      }
    }
   
    
    else
    {
      for (int thisPin = 0; thisPin <= 8; ) 
      {
       // turn the pin on:
       digitalWrite(ledPins[thisPin], HIGH);
       delay(500);
        // turn the pin off:
       digitalWrite(ledPins[thisPin], LOW);
       thisPin=thisPin+2;
      }
      for (int thisPin = 9; thisPin >= 1; thisPin-2) 
      {
         // turn the pin on:
        digitalWrite(ledPins[thisPin], HIGH);
        delay(500);
       // turn the pin off:
        digitalWrite(ledPins[thisPin], LOW);
        thisPin=thisPin-2;
      }
    }
  
}

