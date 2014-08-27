RC_Car
======

This report is an explanation of the design and implementation of a remote control car. The remote control car is controlled wirelessly through bluetooth via an android app. The android app I used to control my RC car is the Arduino Bluetooth RC Car on google playstore. The car communicates to the android app via a bluetooth module using USART. 
The bluetooth module uses a SPP connection with a Braud Rate of 9600 which is default for android. When programming the microcontroller be sure to have CDVLK and JTAGEN deselected so that there is no issue with the USART. USART willl use the microcontroller’s internal clock which is by default set at 8 mHz.
In this folder is the code for the car, along with some diagrams of the circuit. The diagrams which are included are for creating the H-Bridge and connecting the rest of the parts to the microcontroller. 

User Guide:

	The car is controlled via the Arduino Bluetooth RC Car android app on google playstore. A picture of the app is provided labled android_app.jpg.

Controls:

   -The arrow keys control the car’s movement ( up = forward, down = backward, right = right, left = left). 
 	
   -The top left hand corner button controls the headlights.
	
   -The top left hand corner light flashes red when disconnected from the car and green when connected
	
   -The settings button allows you to connect to the HC-06 bluetooth module


The car starts off stopped with its brake lights on, when you move the car via controls brake lights turn off. The LCD mounted on the front of the car displays a face, when the car turns the eyes look in that direction. The car moves only while holding down the movement buttons, it is stopped otherwise. If the car becomes disconnected from the bluetooth android app than the car will stop.


Technologies and Components Used:

	-Android app controller can be found here: (https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en). 
	
	-microcontroller -- atmega1284
	
	-2 DC Motors
	
	-4 TIP120 NPN Transistors -- used to create 2 H-Bridges
	
	-4 TIP42g PNP Transistors -- used to create 2 H-Bridges
	
	-8 1N40003-1N40004  -- used to create 2 H-Bridges
	
	-8 1k ohm resistors -- used to create 2 H--Bridges
	
	-20x4 backlit LCD 
	
	-HC-06 bluetooth module can be found here: (http://www.amazon.com/Arduino-Wireless-Bluetooth-Transceiver-Module/dp/B0093XAV4U/ref=sr_1_1?ie=UTF8&qid=1409133418&sr=
	-8-1&keywords=hc+06).
	
	-4 LEDs (2 red for brake lights, 2 blue for headlights)
	
	-4 330 ohm resistors -- for LEDs
	
	-2 9 volt batteries -- one used for microcontroller
	
	-4 1.5 volt batteries (AA)
	
	-3.3 volt regulator -- used for connecting bluetooth module to power
	
	-5 volt regulator -- for microcontroller power
	
	-10k potentiometer
	
	-small breadboard
	
	-car body form (I made mine out of aluminum sheet metal from Home Depot)
	
	-AVR Studio 6 -- for programming microcontroller


Demo Video:
//add demo video link ********

Source FIles:

	//add source files with description of each ********
