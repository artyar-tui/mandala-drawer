#include <Keypad.h>
#include <Servo.h>

Servo myservoV;
Servo myservoH;

// Movement delimitation
const int left = 10;
const int right = 180;
const int bottom = 10;
const int top = 180;

// Center point
const int mid_h = (right-left)/2; // horisontal
const int mid_v = (top-bottom)/2; // vertical

const int mvdelay = 100; //movement delay

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

void setup()
{
  myservoV.attach(4); 
  myservoH.attach(2); 
}

void move_h(int dist) {
	dir=dist>0?1:-1; // Direction, -1 for left; +1 for right
	int serv_x = myservoH.read(); // Current horisontal position
	for (int i=0; i != dist; dir) {
		myservoH.write(serv_x+dir); // Move
		delay(mvdelay); // Wait for mechanical part
	}
}

void move_v(int dist)
{
	dir=dist>0?1:-1; // Direction, -1 for up; +1 for down
	int serv_y = myservoV.read(); // Current vertical position
	for (int i=0; i != dist; dir) {
		myservoV.write(serv_y+dir); // Move
		delay(mvdelay); // Wait for mechanical part
	}
}

void move_dr(int R)
{
	// move down and right
	for (int pos=0; pos<=R; pos+=1) {
		myservoV.write(myservoV.read()-pos);
		myservoH.write(myservoH.read()+pos);
		delay(mvdelay);
	}
}

void move_dl(int R)
{
	// move down and left
	for (int pos=0; pos<=R; pos+=1) {
		myservoV.write(myservoV.read()-pos);
		myservoH.write(myservoH.read()-pos);
		delay(mvdelay);
	}
}

void move_ul(int R)
{ 
	// move up and left
	for (int pos=0; pos<=R; pos+=1) {
		myservoV.write(myservoV.read()+pos);
		myservoH.write(myservoH.read()-pos);
		delay(mvdelay);
	}
}

void move_ur(int R)
{
	// move up and right
	for (int pos=0; pos<=R; pos+=1) {
		myservoV.write(myservoV.read()+pos);
		myservoH.write(myservoH.read()+pos);
		delay(mvdelay);
	}
}

void draw_square(int a)
{
	// Procedure that draws square with side a
	// set initial position to top left
	myservoH.write(mid_h-a);
	myservoV.write(mid_v-a);
	// draw 4 lines
	move_h(a); // from top left to right
	move_v(a); // from top right to bottom
	move_h(-a); // from bottom right to left
	move_v(-a); // from bottom left to top
}

void draw_rhombus(int R)
{
	// Procedure that draws a rhombus(in fact square) of a maximum radius R
	// set initial position to top
	myservoH.write(mid_h);
	myservoV.write(mid_v+R);
	// draw 4 diagonal lines
	move_dr(R); // from top to right
	move_dl(R); // from right to bottom
	move_ul(R); // from bottom to left
	move_ur(R); // from left to top
}

void draw_circle(int R)
{
	// Procedure to draw circle of radius R
	for (int ang=0; ang<360; ang+=1) {
		myservoH = (R*cos(ang));
		myservoV = (R*sin(ang));
	}
}

void draw_ccircle(int R)
{
	// Procedure to draw circle of radius R counterclockwise
	for (int ang=360; ang>0; ang-=1) {
		myservoH = (R*cos(ang));
		myservoV = (R*sin(ang));
	}
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '5':
	// set drawer in central position
	myservoH.write(mid_h);
	myservoV.write(mid_v);
        break;

      case '4':
	// move drawer left
        move_h(-3);
        break;

      case '6':
	// move drawer right
        move_h(+3);
        break;

      case '8':
	// move drawer up
        move_v(+3);
        break;

      case '2':
	// move drawer down
        move_v(-3);
        break;

      case '1':
        draw_rhombus(30);
        break;

      case '3':
        draw_square(30);
        break;

      case '7':
        draw_circle(30);
        break;

      case '9':
        draw_ccircle(30);
        break;
    }
  }
}
