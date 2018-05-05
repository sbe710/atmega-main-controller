void getTemp() {
  check = dht.read();
  int temp = 2, hum = 3;
    switch (check) {
      case DHT_OK:
        bluetooth.print("Temperature = ");
        bluetooth.print(dht.getTemperatureC());
        formJsonObject(temp, dht.getTemperatureC());
        bluetooth.println("C \t");
        bluetooth.print("Humidity = ");
        bluetooth.print(dht.getHumidity());
        formJsonObject(hum, dht.getHumidity());
        bluetooth.print("%");
        break;
      case DHT_ERROR_CHECKSUM:
        Serial.println("Checksum error");
        break;
      case DHT_ERROR_TIMEOUT:
        Serial.println("Time out error");
        break;
      default:
        Serial.println("Unknown error");
        break;
      }
}
