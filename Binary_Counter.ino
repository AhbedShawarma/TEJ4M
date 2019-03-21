/*
 * Name: Abhay
 * Date: March 4, 2019
 * Description: A program that lights up LEDs to count in binary, when a button is pressed, the counting will pause
 */

// makes an array of ints that stores numbers corresponding to the arduino pin they are connected to
int ledPin[] = {6, 5, 4, 3};
// declares an integer that is used for incremeting the decimal number
int count = 0;

void setup() {
  // pre: none
  // post: initializes the pins that are needed to be used
  
  // initializes the pins the LEDs are connected to
  for (int i = 0; i < 4; i++) {
      pinMode(ledPin[i], OUTPUT);
  }
  // initializes the pin the button is connected to
  pinMode(8, INPUT_PULLUP);
}


void displayBinary(byte numToShow) {
  // pre: takes in a number in the decimal numbering system
  // post: writes either a high or low to each LED to show the binary number

  // a for loop that runs four times, once for each LED
  for (int i = 0; i < 4; i++) {
    // writes to the ith LED by coverting the decimal number to binary 
    // and turns the LED on if the ith bit in the binary number is 1 and turns the LED off if the ith bit in the binary number is 0
     digitalWrite(ledPin[i], bitRead(numToShow, i));
  }
}

// the loop function runs over and over again forever
void loop() {
  // if the button is not pressed, the count is incremented by 1 so the next binary number will show
  // if the button is pressed, the counting will stop so the LEDs will show the current number count is stopped at
  if (!(digitalRead(8))) {
    count++;
  }
  // calls the displayBinary function and passes the count parameter to light up LEDs
  displayBinary(count);
  // has a 300ms delay for each run
  delay(300);
}
