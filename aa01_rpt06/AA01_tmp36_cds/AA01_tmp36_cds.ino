//
// AA00, TMP36 sensor
//

#define TEMP_INPUT 0
#define CDS_INPUT 1
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(TEMP_INPUT);
  float voltage = value * 5.0 * 1000.0/1023.0;
  float temperatureC = (voltage - 500) / 10 ;   
  Serial.print(temperatureC);
  Serial.print(',');

  int value2 = analogRead(CDS_INPUT);
  Serial.println(int(Iuminosity(value2)));
  delay(1000);
}

double Iuminosity (int RawADC0){
double Vout=RawADC0*5.0/1023.0;
int lux=(2500/Vout-500)/10;
return lux;
}