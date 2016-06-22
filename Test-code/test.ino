#include <Keypad.h>
#include <Servo.h>
Servo myservoV;
Servo myservoH;

int pos = 0;
int i=0;
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 12, 11, 10 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  // put your setup code here, to run once:

myservoV.attach(4); 
  myservoH.attach(2); 
        }



void loop() {
  // put your main code here, to run repeatedly:
 char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1':
        for (i=1; i<=3; i+=1) {
          for (pos=10; pos<=180; pos+=1) {
            myservoH.write(pos);
            // myservoV.write(50-pos);
            delay(100);
          }
          myservoH.write(10);
          delay(1000);
        }
        myservoH.write(10);
        break;
      case '2':
        myservoV.write(10);        
        break;
      case '8':
        myservoV.write(180);        
        break;
      case '6':
        myservoH.write(10);        
        break;
      case '4':
        myservoH.write(180);        
        break;
      case '5':
        myservoH.write(95);
        myservoV.write(95);
        break;
      default:
        myservoH.write(95);
        myservoV.write(95);        
}


}
}
