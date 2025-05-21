#define DIR_PIN 4
#define STEP_PIN 5

// How long to spin in each direction (milliseconds)
#define SPIN_TIME 3000  // 3 seconds forward, 3 seconds backward

// Step pulse speed (lower microseconds = faster motor)
#define STEP_DELAY_US 1000  // Adjust for speed (500-2000 is typical)

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Start by spinning forward
  digitalWrite(DIR_PIN, HIGH);
}

void loop() {
  static unsigned long lastDirectionChange = 0;
  static bool direction = true;  // true = forward, false = backward

  // Step the motor
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(STEP_DELAY_US);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(STEP_DELAY_US);
  
  // Change direction every SPIN_TIME milliseconds
  if (millis() - lastDirectionChange >= SPIN_TIME) {
    direction = !direction;  // Flip direction
    digitalWrite(DIR_PIN, direction ? HIGH : LOW); // Set new direction
    lastDirectionChange = millis();
  }
}
