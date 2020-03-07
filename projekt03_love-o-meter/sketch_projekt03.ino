/*
  Projekt 03

  Love-o-meter

  modified 22. Februar 2020
  by Elias König

*/

// Pin an welchem der Temperatursensor angeschlossen ist
const int sensorPin = A0;
// Ausgangstemperatur (je tiefer der Wert umso schneller leuchten die LEDs)
const float ausgangsTemperatur = 24.0;

// setup wird standarmässig nur einmal beim Starten des Programms aufgerufen
void setup() {
  Serial.println("Setup gestartet");
  Serial.begin(9600);
  // Pin 2,3 und 4 auf Ausgang (OUTPUT) und LOW setzen.
  for(int pinNummer = 2; pinNummer < 5; pinNummer++) {
    // Setze pin als Ausgang
	pinMode(pinNummer,OUTPUT);
    // pin auf LOW setzen. LOW bedeuted LED ist ausgeschalten
	digitalWrite(pinNummer,LOW);
    Serial.print("Pin Nummer ");
    Serial.println(pinNummer);
	Serial.println(" als Ausgang gesetzt.");
  }
  Serial.println("Setup beendet");
}

// loop wird nach setup aufgerufen und danach unendlich oft wiederholt
void loop() {
  // lese den Wert des Temperatursensors
  int sensorWert = analogRead(sensorPin);
  
  Serial.print("Sensor Wert: ");
  Serial.print(sensorWert);  
  
  // berechne Spannung in Volt
  float spannung = (sensorWert/1024.0) * 5.0;  
  Serial.print(", Spannung in Volt: ");
  Serial.print(spannung);
  Serial.print(", Temperatur in C: ");
  
  // berechne Temperatur in Grad (Celcius)
  float temperatur = (spannung - .5) * 100;
  Serial.println(temperatur);

  // ist die gemessene Temperatur tiefer als die Ausgangstemperatur -> alle LEDs ausgeschalten
  if(temperatur < ausgangsTemperatur) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);   
  // ist die gemessene Temperatur zwischen 2 und 4 Grad  höher die Ausgangstemperatur -> LED an Pin 2 einschalten
  } else if((temperatur >= ausgangsTemperatur+2) && (temperatur < ausgangsTemperatur+4)) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);     
  // ist die gemessene Temperatur zwischen 4 und 6 Grad  höher die Ausgangstemperatur -> LEDs an Pin 2 und 3 einschalten
  } else if((temperatur >= ausgangsTemperatur+4) && (temperatur < ausgangsTemperatur+6)) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);     
  // ist die gemessene Temperatur zwischen 6 und 8 Grad  höher die Ausgangstemperatur -> LEDs an Pin 2, 3 und 4 einschalten
  } else if((temperatur >= ausgangsTemperatur+6) && (temperatur < ausgangsTemperatur+8)) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);     
  }
  
  // Warte bis zur nächsten Messung (nächster loop) 1000 Millisekunden (1 Sekunde)
  delay(1000);  
}
