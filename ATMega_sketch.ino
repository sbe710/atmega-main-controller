#include <TroykaCurrent.h>
#include <TroykaDHT11.h>
#include <SoftwareSerial.h>

ACS712 sensorCurrent(A1);//объект для работы с датчиком тока
DHT11 dht(11);//объект для работы с датчиком температуры
SoftwareSerial bluetooth(2, 3);//RX TX
SoftwareSerial wifi(12, 13);

int relayPin = 8;//номер пина управляющего сигнала реле
int voltagePin = 0;
int com;//управление командами
int check;//мониторинг ошибок

void setup()
{
  Serial.begin(9600);// открываем последовательный порт
  Serial.println("Ready");
  bluetooth.begin(9600);
  bluetooth.println("BT is ready");
  wifi.begin(9600);
  wifi.println("Wi-Fi is ready to setup");
  dht.begin();//датчик температуры
  pinMode(voltagePin, INPUT);//пин для измерения напряжения
  pinMode(relayPin, OUTPUT);//реле
  relayON();
}

void loop()
{
  getPower();
  getTemp();
  getRelayState();
  delay(5000);
  

    String card = wifi.readString();
    Serial.println(card);
    if (card == "xxx") { 
      com = 11; Serial.println(com);} 
      else if (card == "yyy") {
       com = 10; Serial.println(com); }
 
    switch(com) {                      
      case 10://команда ВЫКЛЮЧЕНИЯ реле
        relayOFF();                   
        break;
      case 11://команда ВКЛЮЧЕНИЯ пеле
        relayON();
        break;
 
      case 22://получение данных о температуре 
        getTemp();
        break;
    } 
 }
