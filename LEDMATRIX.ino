/*
 * Name: Abhay
 * Date: March 11, 2019
 * Description: This program turns on and off LEDs in a LED matrix to show different sprites on the matrix to make an animation
 */


// creates an array of the pins that the LEDs in the matrix are conneted to
byte ledPins[16] = {14, 15, 16, 17, 18, 19, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
// creates an array to store the pins that the cathodes are connected to
byte cathodes[8] = {ledPins[12], ledPins[2], ledPins[3], ledPins[9], ledPins[5], ledPins[10], ledPins[14], ledPins[15]};
// creates an array to store the pins that the anodes are connected to
byte anodes[8] = {ledPins[8], ledPins[13], ledPins[7], ledPins[11], ledPins[0], ledPins[6], ledPins[1], ledPins[4]};
// NOTE: the LEDs that are the cathodes and anodes according to 

// declares a variable for the duration that the frames will appear
int duration = 150;

void setup() {
  // pre: none
  // post: initializes the pins that are needed to be used and turns off all LEDs on the matrix
  
  // initializes the pins the LEDs are connected to to output
  for (byte i = 0; i < 16; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // sets all of the anodes to LOW so they are off
  for (byte i = 0; i < 8; i++) {
    digitalWrite(anodes[i], LOW);
  }
  // sets all of the cathodes to HIGH so they are off
  for (byte i = 0; i < 8; i++) {
    digitalWrite(cathodes[i], HIGH);
  }
}

void showSprite(byte sprite[], int duration) {
  // pre:  the function takes in a byte array which consists of 8 binary numbers and the duration that the frame will last on the screen
  // post: draws the pattern from the array to the LED matrix for the number of times as the duration is set to

  // a for loop that keeps redrawing the sprite on the screen for the number of times the duration is set to
  for (byte x = 0; x < duration; x++) {

    // a for loop used to iterate through the anodes
    for (byte i = 0; i < 8; i++) {
        
        // turn on the ith anode
        digitalWrite(anodes[i], HIGH);
        
        // a for loop used to iterate through the cathodes
        for (byte j = 0; j < 8; j++) {
        
          // turns the jth cathode on or off by returning 1 or 0 through bitRead
          // bitRead reads the bit 7-j (7-j to horizontally flip the sprite) of the ith binary number in the sprite to determine whether to turn on or off the cathode
          digitalWrite(cathodes[j], bitRead(sprite[i], 7-j));
          
          // turns off the jth cathode
          digitalWrite(cathodes[j], HIGH);
        }
        // turns off the ith anode
        digitalWrite(anodes[i], LOW);
    }
  }
}

// declares all of the arrays that show each frame:
// the sprites for the letter P
byte spriteP[] = { B11111111,B11000011,B11011011,B11011011,B11000011,B11011111,B11011111,B11111111};
byte spriteP1[] = { B11111111,B11000011,B01011011,B01011011,B01000011,B01011111,B11011111,B11111111};
byte spriteP2[] = { B11111111,B01000011,B11011011,B11011011,B11000011,B11011111,B01011111,B11111111};
byte spriteP3[] = { B11111111,B01000011,B00011011,B00011011,B00000011,B00011111,B01011111,B11111111};
byte spriteP4[] = { B01111111,B00000011,B01011011,B11011011,B11000011,B01011111,B00011111,B01111111};
byte spriteP5[] = { B00111111,B00000011,B00111011,B01111011,B01100011,B00111111,B00011111,B00111111};
byte spriteP6[] = { B00111111,B00000011,B00011011,B01011011,B01000011,B00011111,B00011111,B00111111};
byte spriteP7[] = { B01111111,B00100011,B00011011,B00011011,B00000011,B00011111,B00111111,B01111111};
byte spriteP8[] = { B00111111,B00000011,B00111011,B01111011,B01100011,B00111111,B00011111,B00111111};
byte spriteP9[] = { B00011111,B00000011,B00011011,B00111011,B00100011,B00011111,B00001111,B00011111};
byte spriteP10[] = { B00111111,B00010011,B00001011,B00001011,B00000011,B00001111,B00011111,B00111111};
byte spriteP11[] = { B00011111,B00000011,B00011011,B00111011,B00110011,B00011111,B00001111,B00011111};
byte spriteP12[] = { B00001111,B00000011,B00001011,B00011011,B00010011,B00001111,B00000111,B00001111};
byte spriteP13[] = { B00011111,B00001011,B00000011,B00000011,B00000011,B00000111,B00001111,B00011111};
byte spriteP14[] = { B00001111,B00000011,B00001011,B00011011,B00011011,B00001111,B00000111,B00001111};
byte spriteP15[] = { B10000111,B00000011,B00000011,B00001011,B00001011,B00000111,B00000011,B10000111};
byte spriteP16[] = { B10001111,B00000111,B00000011,B00000011,B00000011,B00000011,B00000111,B10001111};
byte spriteP17[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};

// the sprites for the letter A
byte spriteA[] = { B11111111,B11000011,B11011011,B11011011,B11000011,B11011011,B11011011,B11111111};
byte spriteA1[] = { B11111111,B11000011,B01011011,B01011011,B01000011,B01011011,B11011011,B11111111};
byte spriteA2[] = { B11111111,B01000011,B11011011,B11011011,B11000011,B11011011,B01011011,B11111111};
byte spriteA3[] = { B11111111,B01000011,B00011011,B00011011,B00000011,B00011011,B01011011,B11111111};
byte spriteA4[] = { B01111111,B00000011,B01011011,B11011011,B11000011,B01011011,B00011011,B01111111};
byte spriteA5[] = { B00111111,B00000011,B00111011,B01111011,B01100011,B00111011,B00011011,B00111111};
byte spriteA6[] = { B00111111,B00000011,B00011011,B01011011,B01000011,B00011011,B00011011,B00111111};
byte spriteA7[] = { B01111111,B00100011,B00011011,B00011011,B00000011,B00011011,B00111011,B01111111};
byte spriteA8[] = { B00111111,B00000011,B00111011,B01111011,B01100011,B00111011,B00011011,B00111111};
byte spriteA9[] = { B00011111,B00000011,B00011011,B00111011,B00100011,B00011011,B00001011,B00011111};
byte spriteA10[] = { B00111111,B00010011,B00001011,B00001011,B00000011,B00001011,B00001011,B00111111};
byte spriteA11[] = { B00011111,B00000011,B00011011,B00111011,B00110011,B00011011,B00001011,B00011111};
byte spriteA12[] = { B00001111,B00000011,B00001011,B00011011,B00010011,B00001011,B00000011,B00001111};
byte spriteA13[] = { B00011111,B00001011,B00000011,B00000011,B00000011,B00000011,B00001011,B00011111};
byte spriteA14[] = { B00001111,B00000011,B00001011,B00011011,B00011011,B00001011,B00000011,B00001111};
byte spriteA15[] = { B10000111,B00000011,B00000011,B00001011,B00001011,B00000011,B00000011,B10000111};
byte spriteA16[] = { B10001111,B00000111,B00000011,B00000011,B00000011,B00000011,B00000111,B10001111};
byte spriteA17[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};

// the sprites for the letter C
byte spriteC[] = { B11111111,B11000011,B11011111,B11011111,B11011111,B11011111,B11000011,B11111111};
byte spriteC1[] = { B11111111,B11000011,B01011111,B01011111,B01011111,B01011111,B11000011,B11111111};
byte spriteC2[] = { B11111111,B01000011,B11011111,B11011111,B11011111,B11011111,B01000011,B11111111};
byte spriteC3[] = { B11111111,B01000011,B00011111,B00011111,B00011111,B00011111,B01000011,B11111111};
byte spriteC4[] = { B01111111,B00000011,B01011111,B11011111,B11011111,B01011111,B00000011,B01111111};
byte spriteC5[] = { B00111111,B00000011,B00011111,B01011111,B01011111,B00011111,B00000011,B00111111};
byte spriteC6[] = { B01111111,B00100011,B00011111,B00011111,B00011111,B00011111,B00100011,B01111111};
byte spriteC7[] = { B00111111,B00000011,B00111111,B01111111,B01111111,B00111111,B00000011,B00111111};
byte spriteC8[] = { B00011111,B00000011,B00011111,B00111111,B00111111,B00011111,B00000011,B00011111};
byte spriteC9[] = { B00111111,B00010011,B00001111,B00001111,B00001111,B00001111,B00010011,B00111111};
byte spriteC10[] = { B00011111,B00000011,B00011111,B00111111,B00111111,B00011111,B00000011,B00011111};
byte spriteC11[] = { B00001111,B00000011,B00001111,B00011111,B00011111,B00001111,B00000011,B00001111};
byte spriteC12[] = { B00011111,B00001011,B00000111,B00000111,B00000111,B00000111,B00001011,B00011111};
byte spriteC13[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};
byte spriteC14[] = { B10001111,B00000111,B00000011,B00000011,B00000011,B00000011,B00000111,B10001111};
byte spriteC15[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};

// the sprites for the letter M
byte spriteM[] = { B11111111,B10010011,B10101011,B10101011,B10111011,B10111011,B10111011,B11111111};
byte spriteM1[] = { B11111111,B10010011,B00101011,B00101011,B00111011,B00111011,B10111011,B11111111};
byte spriteM2[] = { B11111111,B00010011,B10101011,B10101011,B10111011,B10111011,B00111011,B11111111};
byte spriteM3[] = { B01111111,B00010011,B00101011,B10101011,B10111011,B00111011,B00111011,B01111111};
byte spriteM4[] = { B11111111,B01010011,B00101011,B00101011,B00111011,B00111011,B01111011,B11111111};
byte spriteM5[] = { B01111111,B00010011,B01101011,B11101011,B11111011,B01111011,B00111011,B01111111};
byte spriteM6[] = { B00111111,B00010011,B00101011,B01101011,B01111011,B00111011,B00011011,B00111111};
byte spriteM7[] = { B01111111,B00110011,B00001011,B00001011,B00011011,B00011011,B00111011,B01111111};
byte spriteM8[] = { B00111111,B00010011,B00101011,B01101011,B01111011,B00111011,B00011011,B00111111};
byte spriteM9[] = { B00011111,B00000011,B00001011,B00101011,B00111011,B00011011,B00001011,B00011111};
byte spriteM10[] = { B00111111,B00010011,B00001011,B00001011,B00001011,B00001011,B00011011,B00111111};
byte spriteM11[] = { B00011111,B00000011,B00011011,B00111011,B00111011,B00011011,B00001011,B00011111};
byte spriteM12[] = { B00001111,B00000011,B00001011,B00011011,B00011011,B00001011,B00000011,B00001111};
byte spriteM13[] = { B00011111,B00001011,B00000011,B00000011,B00000011,B00000011,B00001011,B00011111};
byte spriteM14[] = { B00001111,B00000011,B00001011,B00011011,B00011011,B00001011,B00000011,B00001111};
byte spriteM15[] = { B10000111,B00000011,B00000011,B00001011,B00001011,B00000011,B00000011,B10000111};
byte spriteM16[] = { B10001111,B00000111,B00000011,B00000011,B00000011,B00000011,B00000111,B10001111};
byte spriteM17[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};

// the sprites for the letter N
byte spriteN[] = { B11111111,B11011011,B11001011,B11001011,B11010011,B11010011,B11011011,B11111111};
byte spriteN1[] = { B11111111,B11011011,B01001011,B01001011,B01010011,B01010011,B11011011,B11111111};
byte spriteN2[] = { B11111111,B01011011,B11001011,B11001011,B11010011,B11010011,B01011011,B11111111};
byte spriteN3[] = { B11111111,B01011011,B00001011,B00001011,B00010011,B00010011,B01011011,B11111111};
byte spriteN4[] = { B01111111,B00011011,B01001011,B11001011,B11010011,B01010011,B00011011,B01111111};
byte spriteN5[] = { B00111111,B00011011,B00001011,B01001011,B01010011,B00010011,B00011011,B00111111};
byte spriteN6[] = { B01111111,B00111011,B00001011,B00001011,B00010011,B00010011,B00111011,B01111111};
byte spriteN7[] = { B00111111,B00011011,B00101011,B01101011,B01110011,B00110011,B00011011,B00111111};
byte spriteN8[] = { B00011111,B00001011,B00001011,B00101011,B00110011,B00010011,B00001011,B00011111};
byte spriteN9[] = { B00111111,B00011011,B00001011,B00001011,B00000011,B00000011,B00011011,B00111111};
byte spriteN10[] = { B00011111,B00001011,B00011011,B00111011,B00110011,B00010011,B00001011,B00011111};
byte spriteN11[] = { B00001111,B00000011,B00001011,B00011011,B00010011,B00000011,B00000011,B00001111};
byte spriteN12[] = { B00011111,B00001011,B00000011,B00000011,B00000011,B00000011,B00001011,B00011111};
byte spriteN13[] = { B00001111,B00000011,B00001011,B00011011,B00011011,B00001011,B00000011,B00001111};
byte spriteN14[] = { B10000111,B00000011,B00000011,B00001011,B00001011,B00000011,B00000011,B10000111};
byte spriteN15[] = { B10001111,B00000111,B00000011,B00000011,B00000011,B00000011,B00000111,B10001111};
byte spriteN16[] = { B10000111,B00000011,B00000111,B00001111,B00001111,B00000111,B00000011,B10000111};

// the sprites to be shown after each letter
byte spriteDone1[] = { B11000111,B10000011,B00000001,B00000001,B00000001,B00000001,B10000011,B11000111};
byte spriteDone2[] = { B11000011,B10000001,B00000011,B00000111,B00000111,B00000011,B10000001,B11000011};
byte spriteDone3[] = { B11100011,B11000001,B10000000,B10000000,B10000000,B10000000,B11000001,B11100011};
byte spriteDone4[] = { B11100001,B11000000,B10000001,B10000011,B10000011,B10000001,B11000000,B11100001};
byte spriteDone5[] = { B11110001,B11100000,B11000000,B11000000,B11000000,B11000000,B11100000,B11110001};
byte spriteDone6[] = { B11110000,B11100000,B11000000,B11000001,B11000001,B11000000,B11100000,B11110000};
byte spriteDone7[] = { B11111000,B11110000,B11100000,B11100000,B11100000,B11100000,B11110000,B11111000};
byte spriteDone8[] = { B11111100,B11111000,B11110000,B11110000,B11110000,B11110000,B11111000,B11111100};
byte spriteDone9[] = { B11111110,B11111100,B11111000,B11111000,B11111000,B11111000,B11111100,B11111110};
byte spriteDone10[] = { B11111111,B11111110,B11111100,B11111100,B11111100,B11111100,B11111110,B11111111};
byte spriteDone11[] = { B11111111,B11111111,B11111110,B11111110,B11111110,B11111110,B11111111,B11111111};
byte spriteDone12[] = { B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};

void drawEndSprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites that are shown after each letter 
  showSprite(spriteDone1, duration);
  showSprite(spriteDone2, duration);
  showSprite(spriteDone3, duration);
  showSprite(spriteDone4, duration);
  showSprite(spriteDone5, duration);
  showSprite(spriteDone6, duration);
  showSprite(spriteDone7, duration);
  showSprite(spriteDone8, duration);
  showSprite(spriteDone9, duration);
  showSprite(spriteDone10, duration);
  showSprite(spriteDone11, duration);
  showSprite(spriteDone12, duration);
}

void drawPSprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites for the letter P
  showSprite(spriteP, duration);
  showSprite(spriteP1, duration);
  showSprite(spriteP2, duration);
  showSprite(spriteP3, duration);
  showSprite(spriteP4, duration);
  showSprite(spriteP5, duration);
  showSprite(spriteP6, duration);
  showSprite(spriteP7, duration);
  showSprite(spriteP8, duration);
  showSprite(spriteP9, duration);
  showSprite(spriteP10, duration);
  showSprite(spriteP11, duration);
  showSprite(spriteP12, duration);
  showSprite(spriteP13, duration);
  showSprite(spriteP14, duration);
  showSprite(spriteP15, duration);
  showSprite(spriteP16, duration);
  showSprite(spriteP17, duration);
}

void drawASprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites for the letter A
  showSprite(spriteA, duration);
  showSprite(spriteA1, duration);
  showSprite(spriteA2, duration);
  showSprite(spriteA3, duration);
  showSprite(spriteA4, duration);
  showSprite(spriteA5, duration);
  showSprite(spriteA6, duration);
  showSprite(spriteA7, duration);
  showSprite(spriteA8, duration);
  showSprite(spriteA9, duration);
  showSprite(spriteA10, duration);
  showSprite(spriteA11, duration);
  showSprite(spriteA12, duration);
  showSprite(spriteA13, duration);
  showSprite(spriteA14, duration);
  showSprite(spriteA15, duration);
  showSprite(spriteA16, duration);
  showSprite(spriteA17, duration);
}

void drawCSprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites for the letter C
  showSprite(spriteC, duration);
  showSprite(spriteC1, duration);
  showSprite(spriteC2, duration);
  showSprite(spriteC3, duration);
  showSprite(spriteC4, duration);
  showSprite(spriteC5, duration);
  showSprite(spriteC6, duration);
  showSprite(spriteC7, duration);
  showSprite(spriteC8, duration);
  showSprite(spriteC9, duration);
  showSprite(spriteC10, duration);
  showSprite(spriteC11, duration);
  showSprite(spriteC12, duration);
  showSprite(spriteC13, duration);
  showSprite(spriteC14, duration);
  showSprite(spriteC15, duration);
}

void drawMSprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites for the letter P
  showSprite(spriteM, duration);
  showSprite(spriteM1, duration);
  showSprite(spriteM2, duration);
  showSprite(spriteM3, duration);
  showSprite(spriteM4, duration);
  showSprite(spriteM5, duration);
  showSprite(spriteM6, duration);
  showSprite(spriteM7, duration);
  showSprite(spriteM8, duration);
  showSprite(spriteM9, duration);
  showSprite(spriteM10, duration);
  showSprite(spriteM11, duration);
  showSprite(spriteM12, duration);
  showSprite(spriteM13, duration);
  showSprite(spriteM14, duration);
  showSprite(spriteM15, duration);
  showSprite(spriteM16, duration);
  showSprite(spriteM17, duration);
}
void drawNSprites() {
  // pre:  all pins that connect to the LEDs are initialized
  // post: draws all of the sprites for the letter P
  showSprite(spriteN, duration);
  showSprite(spriteN1, duration);
  showSprite(spriteN2, duration);
  showSprite(spriteN3, duration);
  showSprite(spriteN4, duration);
  showSprite(spriteN5, duration);
  showSprite(spriteN6, duration);
  showSprite(spriteN7, duration);
  showSprite(spriteN8, duration);
  showSprite(spriteN9, duration);
  showSprite(spriteN10, duration);
  showSprite(spriteN11, duration);
  showSprite(spriteN12, duration);
  showSprite(spriteN13, duration);
  showSprite(spriteN14, duration);
  showSprite(spriteN15, duration);
  showSprite(spriteN16, duration);
}

void loop() {
  // shows the letter P and erase it
  drawPSprites();
  drawEndSprites();

  // shows the letter A and erase it
  drawASprites();
  drawEndSprites();

  // shows the letter C and erase it
  drawCSprites(); 
  drawEndSprites();

  // shows the letter M and erase it
  drawMSprites(); 
  drawEndSprites();

  // shows the letter A and erase it
  drawASprites();
  drawEndSprites();
  
  // shows the letter N and erase it
  drawNSprites();
  drawEndSprites();
}
