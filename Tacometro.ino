/*
 * TACÓMETRO
 */

const int DATA_PIN            = 4;

const int NUMBER_OF_CYLINDERS = 4;
const int RPM_UPDATE_INTERVAL = 30;

unsigned long lastUpdateTime  = 0;
volatile int sparkFireCount   = 0;
int lastRpmValue              = 0;

void incrementRpmCount () {
  sparkFireCount++;
}

void setup() {
  pinMode(DATA_PIN, INPUT_PULLUP);
  attachInterrupt(1, incrementRpmCount, FALLING);
  Serial.begin(9600);
}

const int FIRES_PER_REV = (360 / (720 / NUMBER_OF_CYLINDERS));

void loop() {
  if ((millis() - lastUpdateTime) > RPM_UPDATE_INTERVAL) {
    int currentRpm = (sparkFireCount * (1000 / RPM_UPDATE_INTERVAL) * 60) / FIRES_PER_REV;
    int averagedRpm = (currentRpm + lastRpmValue) / 2;

    Serial.println(averagedRpm);

    sparkFireCount = 0;
    lastUpdateTime = millis();
    lastRpmValue = currentRpm;
  }
}
