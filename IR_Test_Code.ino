int QRE1113_Pin = 7; 

void setup()
{
Serial.begin(9600);
}

void loop()
{
int QRE_Value = digitalRead(QRE1113_Pin);
Serial.println(QRE_Value);
delay(1000);
}