void formJsonObject(int headerNumber, float value) {
  String json;   
    switch(headerNumber) {
      case 1:
        json += "{";
        json += "\"power\":\"";
        json += value;
        json += "\",";
        break;
      case 2:
        json += "\"temperature\":\"";
        json += value;
        json += "\",";
        break;
      case 3:
        json += "\"humidity\":\"";
        json += value;
        json += "\",";
        break;
      case 4:
        boolean state;
        json += "\"relay\":\"";
        if (value == 0.0) {
          state = false;
        } else {
          state = true;
        }
        json += state;
        json += "\"}";
        break;
      }
    
    wifi.println(json);
    Serial.println(json);
}
