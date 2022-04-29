#include "pitches.h" // contains the frequency values for all
//the notes
// notes in the melody – constant values defining frequency
// for each used note
/*int melody[] = {
                 NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_FS4, NOTE_FS4, NOTE_E4, 0,
                 NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_CS4, NOTE_B3, 0, 
                 NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_CS4, NOTE_A3, NOTE_A3, NOTE_E4, NOTE_D4, 0};*/
  int melody[] = {
         NOTE_A6, NOTE_B6, NOTE_CS7
  };
int noteDurations[] = 
{ 
 4, 4, 4
};
void setup()
{
  int melodySize = sizeof(melody) / sizeof(4);
  for (int thisNote = 0; thisNote < melodySize; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.3/2;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
    void loop() { } // no need to repeat the melody
