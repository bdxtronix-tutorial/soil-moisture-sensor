int analogValue;
int soilHumid; 	
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT); // Positif terminal LED ke pin D13 sebagai input
}
void loop()
{
  analogValue = analogRead(A0);  //mengambil bacaan analog
  soilHumid = map(analogValue,0,1023,0,100); //menukar bacaan 10-bit ke peratusan
  Serial.print("Kelembapan Tanah: ");
  Serial.print(soilHumid);
  Serial.print("%");                 //memaparkan kelembapan tanah dalam unit %
  Serial.println(" ");
  delay(2000);
  if (soilHumid<50){
   digitalWrite(13,LOW);
   Serial.println("tanah lembab..");  	// output yang akan dipaparkan di serial monitor
   Serial.println(" ");
  }
  else
  {
   digitalWrite(13,HIGH);                       //LED dalam menyala
   Serial.println("tanah kering..");   	// output yang akan dipaparkan di serial monitor
	Serial.println(" ");
	}
}

