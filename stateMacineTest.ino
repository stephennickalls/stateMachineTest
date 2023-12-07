
#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

enum class programState: uint8_t {
  IDLE,
  READING,
  ADVERTISING
};

// Function to convert programState to string
const char* programStateToString(programState state) {
  switch (state) {
    case programState::IDLE: return "IDLE";
    case programState::READING: return "READING";
    case programState::ADVERTISING: return "ADVERTISING";
    default: return "UNKNOWN";
  }
};

void setup() {
  Serial.begin(115200);
  debugln("Setup complete");
}

void loop() {
  stateMachineTest();
}

void stateMachineTest(){
  static unsigned long timer = millis();

  // track current state
  static programState currentState = programState::IDLE;

  switch (currentState) {
    case programState::IDLE:
      // print state
      debug("program state: ");
      debugln(programStateToString(currentState));
      // condition to switch state
      if (millis() - timer >= 1000){
          currentState = programState::READING;
          timer = millis();
      };
      break;

    case programState::READING:
      // print state
      debug("program state: ");
      debugln(programStateToString(currentState));
      // condition to switch state
      if (millis() - timer >= 5000){
          currentState = programState::ADVERTISING;
          timer = millis();
      };
      break;

    case programState::ADVERTISING:
          debug("program state: ");
          debugln(programStateToString(currentState));
      // condition to switch state
      if (millis() - timer >= 10000){
          currentState = programState::IDLE;
          timer = millis();
      };
      break;

  default:
    debugln("In the default....something terrible has happend");
  }
}



