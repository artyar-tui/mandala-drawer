#include <Keypad.h>
#include <Servo.h>

Servo myservoV;
Servo myservoH;

// Movement step
const int mv_step=1;

// Movement limits
const int left=110;
const int right=70;
const int top=70;
const int down=110;

// Value of Pi
const double pi=3.1459;

// Center point
const int mid_h = 70; // horizontal
const int mid_v = 70; // vertical

// Value of delay
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
// setting up the pins
void setup()
{
	myservoV.attach(4); 
	myservoH.attach(2); 
	Serial.begin(9600);
}

// Function for horizontal movement from right to left 
void move_r2l(int r)
{
	int h=myservoH.read();		// Get the current horizontal position
	for(int i=0;i<=r;i++){
		myservoH.write(h+i);
		delay(mvdelay);
	}
}

// Function for vertical movement from top to down
void move_t2d(int r)
{
	int v=myservoV.read();		// Get the current vertical position
	for(int i=0;i<=r;i++)
	{
		myservoV.write(v+i);
		delay(mvdelay);
	}
}

// Function for diagnol vertical movement from top to bottom
void move_t2dd(int r)
{
	int v=myservoV.read();		// Get the current vertical position
	int h=myservoH.read();		// Get the current horizontal position
	for(int i=0;i<=r;i++)
	{
		myservoV.write(v+i);
		myservoH.write(h-i*0.7);
		delay(mvdelay);
	}
}

// Function for horizontal movement from left to right
void move_l2r(int r)
{
	int h=myservoH.read();		// Get the current horizontal position
	for(int i=0;i<=r;i++)
	{
		myservoH.write(h-i);
		delay(mvdelay);
	}
}

// Function for vertical movement from	bottom to top
void move_d2t(int r)
{
	int v=myservoV.read();		// Get the current vertical position
	for(int i=0;i<=r;i++)
	{
		myservoV.write(v-i);
		delay(mvdelay);
	}
}

// Function for diagnol vertical movement from bottom to top
void move_d2td(int r)
{
	int v=myservoV.read();		// Get the current vertical position
	int h=myservoH.read();		// Get the current horizontal position
	for(int i=0;i<=r;i++)
	{
		myservoV.write(v-i);
		myservoH.write(h+i*0.7);
		delay(mvdelay);
	}
}

// Function for drawing Circle
void circle(int R)
{
	int x,y;
	double rad;
	// Procedure to draw circle of radius R
	for (int ang=0; ang<=360; ang++)
	{
		rad=(pi/180)*ang;	// Converting degree to radians
		x=(R*cos(rad))+mid_h;	// Calculation of x cooridinates
		y=(R*sin(rad))+mid_v;	// Calculation of y cooridinates
		myservoH.write(x);
		myservoV.write(y);
		delay(mvdelay);
	}
}

// Function for drawing a rhombus 
void rhombus(int R)
{
	myservoV.write(mid_v);
	myservoH.write(mid_h);
	move_r2l(R);
	move_t2dd(R);
	move_l2r(R);
	move_d2td(R);
}

// Function for drawing a square
void square(int R)
{
	myservoV.write(mid_v);
	myservoH.write(mid_h);
	move_r2l(R);
	move_t2d(R);
	move_l2r(R);
	move_d2t(R);
}

// Function for Lissajous Curve
void lissajous_curve(int R)
{
	int x,y;
	double rad;
	// Procedure to draw Lissajous curve
	for (int ang=0; ang<=360; ang++)
	{
		rad=(pi/180)*ang;	// Converting degree to radians
		x=R*sin(rad)+mid_h;	// Calculation of x cooridinates
		y=R*cos(3*rad)+mid_v;	// Calculation of y cooridinates
		myservoH.write(x);
		myservoV.write(y);
		delay(20);	 
	}
}
	
	
void polarRose(int R)
{
	int x,y;
	double rad;
	// Procedure to draw Polar rose with R leaves R is an integer, the curve will be rose-shaped with 
	//2k petals if R is even, and R petals if k is odd.
	for (int ang=0; ang<=360; ang++)
	{
		rad=(pi/180)*ang;	// Converting degree to radians
		x=cos(R*rad)*cos(rad)+mid_h;	// Calculation of x cooridinates
		y=cos(R*rad)*sin(rad)+mid_v;	// Calculation of y cooridinates
		myservoH.write(x);
		myservoV.write(y);
		delay(20);	 
	}
		
}
	
void loop()
{
	char key = kpd.getKey();
 
	switch(key){
	case '1':
		square(10);
		break;
	
	case '2':
		// Function for vertical movement from	down to top
		move_d2t(mv_step);
		break;
	
	case '3':
		rhombus(10);
		break;
	
	case '4':
		// Function for horizontal movement from right to left 
		move_r2l(mv_step);
		break;
	
	case '5':
		myservoV.write(mid_v);
		myservoH.write(mid_h);
		break;

	case '6':
		// Function for horizontal movement from left to right
		move_l2r(mv_step);
		break;
	
	case '7':
		circle(30);
		break;
	
	case '8':
		// Function for vertical movement from top to bottom
		move_t2d(mv_step);
		break;
	
	case '9':
		lissajous_curve(10);
		break;
	
	case '*':
		break;
	
	case '0':
		polarRose(2);
		break;
	
	case '#':
		break;
	}
}
