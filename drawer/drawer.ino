#include <Keypad.h>
#include <Servo.h>

Servo myservoV;
Servo myservoH;
// Movement limits
const int left=110;
const int right=70;
const int top=70;
const int down=110;
const double pi=3.1459;
// Center point
const int mid_h = 70; // horizontal
const int mid_v = 70; // vertical

const int mvdelay = 500; //movement delay

// Define the Keymap
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
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
// setting up the pins
void setup()
{
  myservoV.attach(4); 
  myservoH.attach(2); 
  Serial.begin(9600);
}

// Function for horizontal movement from right to left 
void move_r2l(int r){
  int h=myservoH.read();    // Get the current horizontal position
  for(int i=0;i<=r;i++){
    myservoH.write(h+i);
    delay(mvdelay);
    }
  
  }

// Function for vertical movement from top to down
  void move_t2d(int r){
  int v=myservoV.read();    // Get the current vertical position
  for(int i=0;i<=r;i++){
    myservoV.write(v+i);
    delay(mvdelay);
    }
  }

// Function for diagnol vertical movement from top to down
  void move_t2dd(int r){
  int v=myservoV.read();    // Get the current vertical position
  int h=myservoH.read();     // Get the current horizontal position
  for(int i=0;i<=r;i++){
    myservoV.write(v+i);
    delay(mvdelay);
    myservoH.write(h-i*0.7);
    delay(mvdelay);
    Serial.print("Current Horizontal Position: ");
  Serial.println(myservoH.read());
  Serial.print("Current Vertical Position: ");
  Serial.println(myservoV.read());
    }
  }


// Function for horizontal movement from left to right
void move_l2r(int r){
  int h=myservoH.read();  // Get the current horizontal position
  for(int i=0;i<=r;i++){
    myservoH.write(h-i);
    delay(mvdelay);
    }
  }

// Function for vertical movement from  down to top
  void move_d2t(int r){
  int v=myservoV.read();    // Get the current vertical position
  for(int i=0;i<=r;i++){
    myservoV.write(v-i);
    delay(mvdelay);
    }
  }

// Function for diagnol vertical movement from down to top
  void move_d2td(int r){
  int v=myservoV.read();    // Get the current vertical position
  int h=myservoH.read();     // Get the current horizontal position
  for(int i=0;i<=r;i++){
    myservoV.write(v-i);
    delay(mvdelay);
    myservoH.write(h+i*0.7);
    delay(mvdelay);
    Serial.print("Current Horizontal Position: ");
  Serial.println(myservoH.read());
  Serial.print("Current Vertical Position: ");
  Serial.println(myservoV.read());
    }
  }

  // Function for drawing Circle
void circle(int R)
{
  int x,y;
  double rad;
  // Procedure to draw circle of radius R
  for (int ang=0; ang<=360; ang++) {
    rad=(pi/180)*ang;
    x=(R*cos(rad))+mid_h;
    y=(R*sin(rad))+mid_v;
    myservoH.write(x);
    myservoV.write(y);
    delay(20);
    Serial.print("Current Horizontal Position: ");
  Serial.println(myservoH.read());
  Serial.print("Current Vertical Position: ");
  Serial.println(myservoV.read());
  Serial.println(ang);
  }
}

// Function for drawing a square  
void rhombus(int R)
{
  myservoV.write(mid_v);
  myservoH.write(mid_h);
  move_r2l(R);
  move_t2dd(R);
  move_l2r(R);
  move_d2td(R);
  }
void square(int R)
{
  myservoV.write(mid_v);
  myservoH.write(mid_h);
  move_r2l(R);
  move_t2d(R);
  move_l2r(R);
  move_d2t(R);
  }

void loop()
{
  char key = kpd.getKey();
 
  switch(key){
    case '1':
    square(10);
    break;
    case '2':
    rhombus(10);
    break;
    case '3':
    circle(30);
    break;
    default:
    myservoV.write(mid_v);
    myservoH.write(mid_h);
    break;  
    }
  }
