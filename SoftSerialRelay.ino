/*
 * Dieses Programm bildet eine Brücke zwischen zwei Seriellen Schnittstellen
 * 
 * Bei der ersten handelt es sich um die "Hardware"- Schnittstelle "Serial"
 * Die zweite ist eine mit zwei beliebigen Digitalpins realisierte "Sorware-Serial"=> Mehr Infos im Netz
 * 
 * Die Pins der Software-Serial müssen einfach mit zwei Drähten mit der Gegenstelle (z.B. dem Wifly-Modul) verbunden werden.
 */
 
#include <SoftwareSerial.h> // Verwende die SoftwareSerial-Library

SoftwareSerial mySerial(3, 2); // Hier geben wir die Empfangs (Receive, RX) und Sende (Transmit, TX) Pins an.

void setup()
{
  Serial.begin(19200); // indem wir die Verbindunbg zum PC langsam einstellen, vermeiden wir, dass Daten schneller entgegengenommen werden, als sie weitergereicht werden können...
  mySerial.begin(19200); // 19200 ist die maximale Baudrate, bei der der Empfang über SoftwareSerial noch funktioniert.
}

void loop() // run over and over
{
  // Wenn Daten auf der Software-Serial empfangen wurden, reiche sie an die Hardware-Serial weiter
  if (mySerial.available())Serial.write(mySerial.read());
  
  // Wenn Daten auf der Hardware-Serial empfangen wurden, reiche sie an die Software-Serial weiter
  if (Serial.available())mySerial.write(Serial.read());
}

