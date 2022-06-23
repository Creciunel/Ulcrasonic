int flag = 0;
int flagTime = 0;
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
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("On Time");

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
  //  Agoritmul de conectare
  if (flag) {
    if (millis() - lastTimeON > OnTime * 1000 and flagTime == 0) {
      lastTimeON = millis();
      lastTime = millis();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("off Time");

      flagTime = 1;
    }
    if (millis() - lastTime > peiod  * 1000 and flagTime == 1) {
      lastTime = millis();
      lastTimeON = millis();
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("on Time");

      flagTime = 0;
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
