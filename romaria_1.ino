//ROMARIA by Leandro Niero

#include <FastLED.h>

// Defining LED parameters
#define NUM_LEDS 9

#define DATA_PIN 3

#define COLOR_ORDER BGR

// Defining the array of leds
CRGB leds[NUM_LEDS];

const int trigPin = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int echoPin = 5; // Arduino pin connected to Ultrasonic Sensor's ECHO pin



// variables
float duration, distance;

float brightness;

int sensorValue = 0;
int VAL;

CRGB gBackgroundColor = CRGB::Black;

void setup() {

  //setting inputs and outputs

  pinMode(trigPin, OUTPUT); // set arduino pin to output mode
  pinMode(echoPin, INPUT);  // set arduino pin to input mode

  //initialise serial port for data
  Serial.begin(9600);
  delay(5000);
  Serial.write(0);


  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); // GRB ordering is assumed

}

void loop() {


  //measuring distance

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * .0343) / 2;

  //writing sensor value

  if (Serial.available() > 0) {
    char input = Serial.read();
    int sensorValue = analogRead(A0);

  }

  //LED colour parameters
  leds[0] = CRGB(255, 255, 255);
  leds[1] = CRGB(255, 255, 255);
  leds[2] = CRGB(255, 255, 255);
  leds[3] = CRGB(255, 255, 255);
  leds[4] = CRGB(255, 255, 255);
  leds[5] = CRGB(255, 255, 255);
  leds[6] = CRGB(255, 255, 255);
  leds[7] = CRGB(255, 255, 255);
  leds[8] = CRGB(255, 255, 255);



  //mapping brightness

  brightness = map(distance, 0, 150, 255, 0);

  FastLED.setBrightness(brightness);

  //blinking red and white if distance bigger 60cm
  if (distance > 100) {
    FastLED.setBrightness(5);

    leds[0] = CRGB::Red; FastLED.show(); delay(120);
    leds[1] = CRGB::Red; FastLED.show(); delay(120);
    leds[2] = CRGB::Red; FastLED.show(); delay(120);
    leds[3] = CRGB::Red; FastLED.show(); delay(120);
    leds[4] = CRGB::Red; FastLED.show(); delay(120);
    leds[5] = CRGB::Red; FastLED.show(); delay(120);
    leds[6] = CRGB::Red; FastLED.show(); delay(120);
    leds[7] = CRGB::Red; FastLED.show(); delay(120);
    leds[8] = CRGB::Red; FastLED.show(); delay(120);


  }



  //blinking red, yellow, orange and white if distance bigger 50cm

  if (distance > 75 && distance < 100) {

    FastLED.setBrightness(30);
    leds[0] = CRGB::Red; FastLED.show(); delay(110);
    leds[1] = CRGB::Yellow; FastLED.show(); delay(110);
    leds[2] = CRGB::Red; FastLED.show(); delay(110);
    leds[3] = CRGB::Yellow; FastLED.show(); delay(110);
    leds[4] = CRGB::Orange; FastLED.show(); delay(110);
    leds[5] = CRGB::Yellow; FastLED.show(); delay(110);
    leds[6] = CRGB::Red; FastLED.show(); delay(110);
    leds[7] = CRGB::Yellow; FastLED.show(); delay(110);
    leds[8] = CRGB::Red; FastLED.show(); delay(110);
  }

  //blinking blue and green if distance bigger 40cm
  if (distance > 50 && distance < 75) {

    FastLED.setBrightness(70);
    leds[0] = CRGB::Green; FastLED.show(); delay(100);
    leds[1] = CRGB::Aqua; FastLED.show(); delay(100);
    leds[2] = CRGB::Green; FastLED.show(); delay(100);
    leds[3] = CRGB::Blue; FastLED.show(); delay(100);
    leds[4] = CRGB::Green; FastLED.show(); delay(100);
    leds[5] = CRGB::Blue; FastLED.show(); delay(100);
    leds[6] = CRGB::Green; FastLED.show(); delay(100);
    leds[7] = CRGB::Aqua; FastLED.show(); delay(100);
    leds[8] = CRGB::Green; FastLED.show(); delay(100);
  }

  //blinking purple, green and blue if distance bigger 40cm
  if (distance > 40 && distance < 50) {
    FastLED.setBrightness(80);
    leds[0] = CRGB::Purple; FastLED.show(); delay(90);
    leds[1] = CRGB::Green; FastLED.show(); delay(90);
    leds[2] = CRGB::Blue; FastLED.show(); delay(90);
    leds[3] = CRGB::Magenta; FastLED.show(); delay(90);
    leds[4] = CRGB::Purple; FastLED.show(); delay(90);
    leds[5] = CRGB::Magenta; FastLED.show(); delay(90);
    leds[6] = CRGB::Blue; FastLED.show(); delay(90);
    leds[7] = CRGB::Green; FastLED.show(); delay(90);
    leds[8] = CRGB::Purple; FastLED.show(); delay(90);

  }

  //blinking purple and blue if distance bigger 30cm
  if (distance > 30 && distance < 40) {
    FastLED.setBrightness(95);
    leds[0] = CRGB::Blue; FastLED.show(); delay(80);
    leds[1] = CRGB::Purple; FastLED.show(); delay(80);
    leds[2] = CRGB::Blue; FastLED.show(); delay(80);
    leds[3] = CRGB::Purple; FastLED.show(); delay(80);
    leds[4] = CRGB::Blue; FastLED.show(); delay(80);
    leds[5] = CRGB::Purple; FastLED.show(); delay(80);
    leds[6] = CRGB::Blue; FastLED.show(); delay(80);
    leds[7] = CRGB::Purple; FastLED.show(); delay(80);
    leds[8] = CRGB::Blue; FastLED.show(); delay(80);


  }

  //blinking blue and yellow if distance smaller 20cm
  if (distance < 30) {
    FastLED.setBrightness(100);

    leds[0] = CRGB::Blue; FastLED.show(); delay(70);
    leds[1] = CRGB::Yellow; FastLED.show(); delay(70);
    leds[2] = CRGB::Blue; FastLED.show(); delay(70);
    leds[3] = CRGB::Yellow; FastLED.show(); delay(70);
    leds[4] = CRGB::White; FastLED.show(); delay(70);
    leds[5] = CRGB::Yellow; FastLED.show(); delay(70);
    leds[6] = CRGB::Blue; FastLED.show(); delay(70);
    leds[7] = CRGB::Yellow; FastLED.show(); delay(70);
    leds[8] = CRGB::Blue; FastLED.show(); delay(70);
  }



  //pint distance
  Serial.println(distance);





}
