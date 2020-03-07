/*
  Projekt 02

  Raumschiff Steuerzentrale

  erstellt am 11. August 2019
  von koenig-hub

*/

// Variable um den Zustand des Schalters zu speichern
int schalterZustand = 0;

// setup wird standardmässig nur einmal beim Starten des Programms aufgerufen
void setup() {
  // Pin aud Eingang oder Ausgang setzen
  pinMode(3,OUTPUT); // Pin 3 Ausgang (grüne LED) 
  pinMode(4,OUTPUT); // Pin 4 Ausgang (rote LED) 
  pinMode(5,OUTPUT); // Pin 5 Ausgang (rote LED) 
  pinMode(2,INPUT); // Pin 2 Eingang (Taster)
}

// loop wird nach setup aufgerufen und danach unendlich oft wiederholt
void loop() {
  // put your main code here, to run repeatedly:
  schalterZustand = digitalRead(2);
  if (schalterZustand == LOW) {
    // LOW -> der Schalter wird nicht gedrückt
    digitalWrite(3,HIGH); // grüne LED leuchtet
    digitalWrite(4,LOW); // rote LED 4 leuchtet nicht
    digitalWrite(5,LOW); // rote LED 5 leuchtet nicht
  } else {
    // ELSE = HIGH -> der Schalter wird gedrückt
    digitalWrite(3,LOW); // grüne LED leuchtet nicht
    digitalWrite(4,LOW); // rote LED 4 leuchtet nicht
    digitalWrite(5,HIGH); // rote LED 5 leuchtet

    delay(250); // Warte eine Viertelsekunde
    
    digitalWrite(4,HIGH); // rote LED 4 leuchtet
    digitalWrite(5,LOW); // rote LED 5 leuchtet nicht

    delay(250); // Warte eine Viertelsekunde
    
  }
}
