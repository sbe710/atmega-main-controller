int relay = 4;
float relayState;

void getRelayState() {
  formJsonObject(relay, relayState);
}

void relayOFF() {
  digitalWrite(relayPin, LOW);
  bluetooth.println("OFF");
  ::relayState = 0.0;
}

void relayON() {
  digitalWrite(relayPin, HIGH);
  bluetooth.println("ON");
  ::relayState = 1.0;
}

