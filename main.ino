
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int angle_change = 1; 
int buttonState = 0;
int old_buttonState = 0;

const int array_length = 6;
const int buttonPin = 2;
// led pins
int ledArray[6]={13, 12, 11, 10, 7, 6};
int ledState[6]={0, 0, 0, 0, 0, 0};

// random number for random lights
int randNumber;

int number_of_states = 10;
// variable value from 0 to 7
int christmas_state = 0;
int old_christmas_state = 0;


int checkbutton(int button){
  if(old_buttonState == button){
    // do nothing to state
    return christmas_state;
  }
  else{
    long int start_time = millis();
    while(true){
      // if the button is pressed down for 20 milliseconds then switch state
      if( millis()-start_time > 400){
        if(christmas_state >= number_of_states-1){
          old_buttonState = button;
          
          // goes to off state
          return 0;
        }
        else{
          old_buttonState = button;
          return christmas_state + 1;
        }
      }
      // check to see if button reverts (would mean it was random switching)
      if(old_buttonState == button){
        return christmas_state;
      }
    }
    
  }
}

void turn_off_on_random_light(){
  // array_length should be number of leds
  // pick a random led
  randNumber = int(random(array_length));

  // if led was off turn on, otherwise turn off
  if(ledState[randNumber] == 0){
    digitalWrite(ledArray[randNumber], HIGH);
    ledState[randNumber] = 1;
  } else{
    digitalWrite(ledArray[randNumber], LOW);
    ledState[randNumber] = 0;
  }
  
}

/*
  Songs taken from:
  More songs available at https://github.com/robsoncouto/arduino-songs

                                              Robson Couto, 2019
*/

// Alejandro: connect a 100 ohm resistor between ground

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to whichever pin you want to use
int buzzer = 8;

// HARRY POTTER
int harrypotter_tempo = 144;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int harrypotter_melody[] = {


  // Hedwig's theme fromn the Harry Potter Movies
  // Socre from https://musescore.com/user/3811306/scores/4906610
  
  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  REST,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int harrypotter_notes = sizeof(harrypotter_melody) / sizeof(harrypotter_melody[0]) / 2;

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int harrypotter_wholenote = (60000 * 4) / harrypotter_tempo;

int harrypotter_divider = 0, harrypotter_noteDuration = 0;


// MERRY CHRISTMAS
// change this to make the song slower or faster
int merry_christmas_tempo = 140;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int merry_christmas_melody[] = {

  // We Wish You a Merry Christmas
  // Score available at https://musescore.com/user/6208766/scores/1497501
  
  NOTE_C5,4, //1
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

  NOTE_F5,2, NOTE_C5,4, //8 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int merry_christmas_notes = sizeof(merry_christmas_melody) / sizeof(merry_christmas_melody[0]) / 2;

// this calculates the duration of a whole note in ms
int merry_christmas_wholenote = (60000 * 4) / merry_christmas_tempo;

int merry_christmas_divider = 0, merry_christmas_noteDuration = 0;


// STAR WARS
// change this to make the song slower or faster
int star_wars_tempo = 108;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int star_wars_melody[] = {
  
  // Dart Vader theme (Imperial March) - Star wars 
  // Score available at https://musescore.com/user/202909/scores/1141521
  // The tenor saxophone part was used
  
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int star_wars_notes = sizeof(star_wars_melody) / sizeof(star_wars_melody[0]) / 2;

// this calculates the duration of a whole note in ms
int star_wars_wholenote = (60000 * 4) / star_wars_tempo;

int star_wars_divider = 0, star_wars_noteDuration = 0;


//  NEVER GONNA GIVE YOU UP
// change this to make the song slower or faster
int never_gonna_tempo = 114;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int never_gonna_melody[] = {

  // Never Gonna Give You Up - Rick Astley
  // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
  // Arranged by Chlorondria

  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
  REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
  NOTE_B4,16, NOTE_A4,2, REST,4, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
  NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
   
  NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
  REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int never_gonna_notes = sizeof(never_gonna_melody) / sizeof(never_gonna_melody[0]) / 2;

// this calculates the duration of a whole note in ms
int never_gonna_wholenote = (60000 * 4) / never_gonna_tempo;

int never_gonna_divider = 0, never_gonna_noteDuration = 0;


// MII channel theme
// change this to make the song slower or faster
int mii_tempo = 114;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int mii_melody[] = {
  
  // Mii Channel theme 
  // Score available at https://musescore.com/user/16403456/scores/4984153
  // Uploaded by Catalina Andrade 
  
  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //1
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, REST,4, REST,8, NOTE_CS4,8,
  NOTE_D4,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
  NOTE_E5,-4, NOTE_DS5,8, NOTE_D5,8, REST,8, REST,4,
  
  NOTE_GS4,8, REST,8, NOTE_CS5,8, NOTE_FS4,8, REST,8,NOTE_CS5,8, REST,8, NOTE_GS4,8, //5
  REST,8, NOTE_CS5,8, NOTE_G4,8, NOTE_FS4,8, REST,8, NOTE_E4,8, REST,8,
  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,8, REST,4, NOTE_E4,8, NOTE_E4,8,
  NOTE_E4,8, REST,8, REST,4, NOTE_DS4,8, NOTE_D4,8, 

  NOTE_CS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //9
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, REST,8,
  REST,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
  NOTE_E5,2, NOTE_D5,8, REST,8, REST,4
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int mii_notes = sizeof(mii_melody) / sizeof(mii_melody[0]) / 2;

// this calculates the duration of a whole note in ms
int mii_wholenote = (60000 * 4) / mii_tempo;

int mii_divider = 0, mii_noteDuration = 0;



void play_song(int tempo, int melody[], int notes, int wholenote, int divider, int noteDuration){
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    // calculates the duration of each note
    buttonState = digitalRead(buttonPin);
    old_christmas_state = christmas_state;
    christmas_state = checkbutton(buttonState);
    if(old_christmas_state != christmas_state){
      // the button has been pressed so get out of here
      break;
    }
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    if(noteDuration <10){
      delay(noteDuration);
    } else{
      pos += angle_change;
      turn_off_on_random_light(); // flash lights to the beat of the song
      myservo.write(pos);
      if(pos >= 165){
        angle_change = -1;
      }
      else if(pos <= 0){
        angle_change = 1;
      }
      delay(noteDuration);
    }
    

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setting up LED pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  randomSeed(analogRead(0)); // for random lights

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  christmas_state = checkbutton(buttonState);
  Serial.println(christmas_state);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:


  switch (christmas_state) {
    case 0:
      // turn off lights
      for(int i = 0; i<array_length; i++){
        digitalWrite(ledArray[i], LOW);
      }
      christmas_state = 1;
      break;
    case 1: 
      // off
      delay(500);
      break;
    case 2:
      // just blinking lights
      for(int i = 0; i<array_length; i++){
        digitalWrite(ledArray[i], HIGH);
        delay(150);
        digitalWrite(ledArray[i], LOW);
        delay(1);
      }
      break;
    case 3:
      // just pulsating lights
      for(int x = 1; x<40; x++){
        for(int i = 0; i<array_length; i++){
          digitalWrite(ledArray[i], HIGH);
        }
        delay(x);
        for(int i = 0; i<array_length; i++){
          digitalWrite(ledArray[i], LOW);
        }
        delay(2);
      }
      for(int x = 40; x>0; x--){
        for(int i = 0; i<array_length; i++){
          digitalWrite(ledArray[i], HIGH);
        }
        delay(x);
        for(int i = 0; i<array_length; i++){
          digitalWrite(ledArray[i], LOW);
        }
        delay(2);
      }
      break;
    case 4:
      // servo and blinking lights
      for(int i = 0; i<array_length; i++){
        digitalWrite(ledArray[i], HIGH);
        delay(75);
        pos += angle_change;
        myservo.write(pos);
        if(pos >= 165){
          angle_change = -1;
        }
        else if(pos <= 0){
          angle_change = 1;
        }
        delay(75);
        digitalWrite(ledArray[i], LOW);
        delay(1);
      }
      
      break;
    case 5:
      play_song(merry_christmas_tempo, merry_christmas_melody, merry_christmas_notes, merry_christmas_wholenote, merry_christmas_divider, merry_christmas_noteDuration);
      break;
    case 6:
      play_song(star_wars_tempo, star_wars_melody, star_wars_notes, star_wars_wholenote, star_wars_divider, star_wars_noteDuration);
      break;
    case 7:
      play_song(harrypotter_tempo, harrypotter_melody, harrypotter_notes, harrypotter_wholenote, harrypotter_divider, harrypotter_noteDuration);
      break;
    case 8:
      play_song(never_gonna_tempo, never_gonna_melody, never_gonna_notes, never_gonna_wholenote, never_gonna_divider, never_gonna_noteDuration);
      break;
    case 9: 
      play_song(mii_tempo, mii_melody, mii_notes, mii_wholenote, mii_divider, mii_noteDuration);
      break;
  }
  

}
