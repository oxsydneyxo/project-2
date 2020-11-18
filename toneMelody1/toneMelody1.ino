/*
  Melody

  Plays a melody

  Base code by Tom Igoe:
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_B3,0, 
  NOTE_B3, NOTE_A3, 
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, 
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3,0,

  NOTE_A4, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_B3,0, 
  NOTE_B3, NOTE_A3, 
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, 
  NOTE_G3, NOTE_C4, NOTE_B3, NOTE_A3,NOTE_G3 
};


const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int noteDurations[] = {
  3, 3, 3, 6, 3, 3, 
  5, 3, 
  3, 3, 3, 3, 
  3, 3, 3, 4,4,

  3, 3, 3, 6, 3, 3, 
  5, 3, 
  3, 3, 3, 3, 
  6, 3, 3, 3, 3
};

void setup() {
Serial.begin(9600);

// initialize pin 9 as an output for the speaker:
  pinMode(9, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 34; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(9, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    // stop the tone playing:
  }
  }else{
    noTone(9);
  }
  
 Serial.println(buttonState);
}
