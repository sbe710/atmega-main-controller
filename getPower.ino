void getPower() {
  int power = 1;
  float k = 90.78;//коэффициент трансформации
  float valV, valI, valP;
  
  valV = analogRead(A0)*(5/1024.0)*k;    //показания напряжения
  valI = sensorCurrent.readCurrentAC();//показания с датчика тока
  valP = valI*valV;
  bluetooth.println(valP);         //вывод показаний мощности
  formJsonObject(power, valP);
}
