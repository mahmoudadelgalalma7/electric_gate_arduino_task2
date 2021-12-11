int Buzzer_Pin = 9;
int LDC1_Pin = A0;
int LDC2_Pin = A1;
int Poeple_Inside = 0;
int space = 0;
int enter = 0;
int quit = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(Buzzer_Pin,OUTPUT);
pinMode(LDC1_Pin,INPUT);
pinMode(LDC2_Pin,INPUT);
Serial.begin(9600);
}


void loop() {
  
  // put your main code here, to run repeatedly:
 int LDC1_sensor = analogRead(LDC1_Pin);
 int LDC2_sensor = analogRead(LDC2_Pin);

// Print Number of Persons at room
Serial.println( Poeple_Inside);


  //  Enter The room
if (space > 0) {
    if ( LDC1_sensor <= 300 && LDC2_sensor > 300 && enter == 0) {
     enter++;
    }
}

if (LDC2_sensor <= 300 && LDC1_sensor > 300 && enter > 0) { 
    Poeple_Inside++;
    quit = 0;
    enter = 0;
    space=0;
  }
  
 // Space from one man to other
if (LDC2_sensor > 300 && LDC1_sensor > 300) {
  space++;
}

  // Exit The room
if (space > 0) {
    if ( LDC2_sensor <= 300 && LDC1_sensor > 300  && enter == 0) {
      quit++; 
      }
}
if (LDC1_sensor <= 300 && LDC2_sensor > 300 && quit > 0) { 
    Poeple_Inside--;
    enter =0;
    quit = 0;
    space=0;
  }


  // There isn't People in the Room
if (Poeple_Inside < 0) {
  Poeple_Inside = 0;
}
 // The Max Number of People at room is 5
if (Poeple_Inside > 5) {
  Poeple_Inside = 5;
}


// If People at room equal 5 The buzzer will open
if (Poeple_Inside == 5 || Poeple_Inside > 5) {
analogWrite(Buzzer_Pin,HIGH);
} else {
 analogWrite(Buzzer_Pin,LOW);

}


}
