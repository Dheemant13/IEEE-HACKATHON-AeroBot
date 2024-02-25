#include <Servo.h>

#define TRIGGER_PIN 5 // Define the trigger pin of the ultrasonic sensor
#define ECHO_PIN 4    // Define the echo pin of the ultrasonic sensor

#define SERVO_PIN 0   // Define the pin connected to the servo

#define MAX_DISTANCE 200 // Define the maximum distance for the servo to stop and change direction
#define THRESHOLD_DISTANCE 50 // Define the threshold distance for changing direction

Servo myServo; // Create a servo object

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(TRIGGER_PIN, OUTPUT); // Set trigger pin as output
  pinMode(ECHO_PIN, INPUT);     // Set echo pin as input
  myServo.attach(SERVO_PIN);    // Attach the servo to the pin
}

void loop() {
  long duration, distance;
  
  // Trigger ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Measure the pulse input in ECHO_PIN
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance
  distance = duration * 0.034 / 2;
  
  // Check if distance is within range
  if (distance <= MAX_DISTANCE) {
    // Check if distance is below threshold
    if (distance <= THRESHOLD_DISTANCE) {
      // Move servo in one direction
      myServo.write(0); 
    } 
    else {
      // Move servo in the opposite direction
      myServo.write(180); 
    }
  } 
  else {
    // Stop servo
    myServo.write(90); 
  }
  
  delay(100); // Delay
}
