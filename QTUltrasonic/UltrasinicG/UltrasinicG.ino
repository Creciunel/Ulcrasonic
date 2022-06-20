int flag = 0;
int OnTime = 0;
int peiod = 0;

unsigned long lastTime;
unsigned long lastTimeON;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial) {
    ;
  }
  digitalWrite(LED_BUILTIN, HIGH);
  if (millis() > 100) digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  if (Serial.available() > 1) {
    char key = Serial.read();
    int val = Serial.parseInt();
    switch (key)
    {
      case 's': flag = val;
        break;
      case 't': OnTime = val;
        break;
      case 'p': peiod = val;
        break;
    }
    //    Serial.println(val);
    Serial.println("Flag " + String(flag));
    Serial.println("Time " + String(OnTime));
    Serial.println("Period " + String(peiod));
  }
  if (flag) {
    if (millis() - lastTimeON > OnTime * 1000) {
      lastTimeON = millis();
      digitalWrite(LED_BUILTIN, HIGH);
      if (millis() > 100) digitalWrite(LED_BUILTIN, LOW);
    }
    if (millis() - lastTime > (peiod - OnTime) * 1000) {
      lastTime = millis();
      digitalWrite(LED_BUILTIN, HIGH);
      if (millis() > 100) digitalWrite(LED_BUILTIN, LOW);
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
