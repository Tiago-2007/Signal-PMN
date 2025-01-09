/*
	Programador..............: (c) Tiago Machado
    Data.....................: 08/01/2025
    Observações..............: Um sensor de  movimentos
*/

  const int BAUD_RATE = 9600;

  const byte TRIGGER_PIN = 11;
  const byte ECHO_PIN = 12;
  
  const int MEASUREMENT_CYCLE = 6000;
  const int PULSE_TRIGGER_TIME = 10;

  float highLevelTime, distance;

  void setup(void)     {
	  Serial.begin(BAUD_RATE);

    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop(void) {
	Serial.println("A ler o sonar.....");
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(MEASUREMENT_CYCLE);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(PULSE_TRIGGER_TIME);
  digitalWrite(TRIGGER_PIN, LOW);
  
  highLevelTime = pulseIn(ECHO_PIN, HIGH);
  Serial.println("High Level Time: " + String(highLevelTime)); 
  distance =	((highLevelTime * 0.0340) / 2);
  Serial.println("Distance: " + String(distance)); 	
}
               
