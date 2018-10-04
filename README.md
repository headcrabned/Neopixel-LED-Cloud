# Neopixel-LED-Cloud
Arduino LED strip animations for a poly-fill cloud decoration
Has multiple weather animations for sunrise, sunset, thunderstorm, night, etc.
Video demo at https://youtu.be/35biNvnYktg<https://youtu.be/35biNvnYktg>

Connect a strip of addressable LEDs to an arduino with GND to GND, LED power to Vin, and LED data to Pin 6
Tested on an Arduino Uno with Adafruit neopixels. Will work with other strips, but 
will require changes to the the "strip" settings below.

With 30 LEDs, it can be powered over USB, or a good 2A external phone charging battery connected to the arduino.

To build, place in a folder named "Final_Demo", open "Final_Demo.ino" with the Arduino IDE.
In the Arduino IDE, select your matching board, and use the plugin manager to install the Adafruit_NeoPixel library.

To construct a cloud, tape 2 wire coat hangers together, both upright with a right angle between them.
Tape the Arduino up near the hooks, and arrange the LED strip to wind throughout the volume, facing outwards as
much as possible.

Then fill that volume with polyester fill (which goes in stuffed animals) to cover the LEDs. Clear tape can help
keep the cloud together. Arrange the polyfill so that the hangers and LED strip are hidden.
