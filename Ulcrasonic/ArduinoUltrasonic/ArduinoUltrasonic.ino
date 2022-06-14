#define BAUFRATE 9600
#define OUTPIN 12

String inString = "";
int i = 1;
void setup()
{
  Serial.begin(BAUFRATE);
  pinMode(OUTPIN, OUTPUT);

}

void loop()
{

  if (Serial.available() > 0)
  {
    char digit = Serial.read();
    if (digit != '\r') {
      inString += digit;
      if (inString == "go") {
        digitalWrite(OUTPIN, HIGH);
      } if (inString == "stop") {
        digitalWrite(OUTPIN, LOW);
      }
    }
    else {
      Serial.println("Rez: " + inString);
      inString = "";
    }
  }
  i ++;
  Serial.println("Rez: ");
  delay(1000);
}
