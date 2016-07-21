# Mandala Drawer
## Project Description:
Madala drawer is able to draw  circles,square and others geometrical shapes. User can select from the keypad to draw a specific shape.
Two servo motors make it possible to draw objects on a piece of paper.

## Components Required:
1.	Arduino UNO
2.	Bread Board
3.	Two servo motors
4.	Jumper wires 
5.	Pen/Laser
6.	Keypad
7.	Small spring (from any old ballpoint, in case we using pen) 
8.	A tube of diammeter larger than the pen, in case we using pen.

## Schematic Diagram
![Schematic](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/Schematic.PNG)

## Setup
1. Download the source code and [keypad library](http://playground.arduino.cc/Code/Keypad#Download)
2. Put the Keypad folder in "arduino/libraries/". For guidance see the picture below ![Path](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/fig1.PNG)

3. Open drawer.ino with the Arduino IDE 
4. Connect the USB cable with PC and Arduino UNO. 
5. Wait for the mmoment while the driver is being installed.

6. Click on 'Tools' then select 'Port' to which arduino is connected. ![Port](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/fig2.png)

7. Click on the Verify button as shown in the figure below to verify the code.![Verify](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/fig3.png)

8. Click on the Upload button as shown in the figure below to load the code to Arduino UNO.![Upload](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/fig4.png)

9. Your Mandala drawer is ready to work.

## Keypad buttons functions:
1.  Square
2.  Vertical movement from bottom to top
3.  Rhombus
4.  Horizontal movement from right to left
5.  Center position
6.  Horizontal movement from left to right
7.  Circle
8.  Vertical movement from top to bottom
9.  Lissajous Curve
0.  Polar Rose

## Hardware Setup
![Hardware](https://github.com/artyar-tui/mandala-drawer/blob/master/Schematic/20160630_073728.jpg)
