#include <ESP8266WiFi.h>
#include "time.h"
#include <FS.h>   //Include File System Headers

const char* filename = "/archivodepruebas1.txt";
// Sustituir con datos de vuestra red
const char* ssid     = "WIFIID";
const char* password = "WIFIPASSWORD";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 7200;   //Replace with your GMT offset (seconds)
const int   daylightOffset_sec = 0;  //Replace with your daylight offset (seconds)
int dia = 0;
int hora = 0;
int minuto = 0;

byte bd1;
byte bd2;
byte bd3;
byte bd4;
byte bd5;
byte bh1;
byte bh2;
byte bh3;
byte bh4;
byte bh5;
byte bm1;
byte bm2;
byte bm3;
byte bm4;
byte bm5;
char c1;
char c2;
char c3;
char c4;
char c5;


//const int  entero;
//const char caracter;

void setup()
{
  Serial.begin(115200);
  delay(10);
   delay(1000);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.print("Conectando a:\t");
  Serial.println(ssid); 

  // Esperar a que nos conectemos
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
   Serial.print('.');
  }

  // Mostrar mensaje de exito y dirección IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID()); 
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());


   //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
   delay(1000);
  Serial.begin(115200);
  Serial.println();

  //Initialize File System
  if(SPIFFS.begin())
  {
    Serial.println("SPIFFS Initialize....ok");
  }
  else
  {
    Serial.println("SPIFFS Initialization...failed");
  }
  //Format File System
  if(SPIFFS.format())
  {
    Serial.println("File System Formated");
  }
  else
  {
    Serial.println("File System Formatting Error");
  }

  //Create New File And Write Data to It
  //w=Write Open file for writing
  File f = SPIFFS.open(filename, "w");
    ///////////////////////////////////////////
  dia = 15;
  hora = 03;
  minuto = 15;
  bd1 = dia;
  bh1 = hora;
  bm1 = minuto;
    ///////////////////////////////////////////
  dia = 3;
  hora = 06;
  minuto = 45;
  bd2 = dia;
  bh2 = hora;
  bm2 = minuto;
    ///////////////////////////////////////////
  dia = 95;
  hora = 22;
  minuto = 0;
  bd3 = dia;
  bh3 = hora;
  bm3 = minuto;
    ///////////////////////////////////////////
  dia = 7;
  hora = 12;
  minuto = 20;
  bd4 = dia;
  bh4 = hora;
  bm4 = minuto;
    ///////////////////////////////////////////
  dia = 127;
  hora = 18;
  minuto = 30;
  bd5 = dia;
  bh5 = hora;
  bm5 = minuto;
    ///////////////////////////////////////////
  if (!f) {
    Serial.println("file open failed");
  }
  else
  {
      //Write data to file
      Serial.println("Data read");
      f.print (String(int(bd1)));
      f.print(String(int(bh1)));
      f.println(String(int(bm1)));
      f.print (String(int(bd2)));
      f.print(String(int(bh2)));
      f.println(String(int(bm2)));
      f.print (String(int(bd3)));
      f.print(String(int(bh3)));
      f.println(String(int(bm3)));
      f.print (String(int(bd4)));
      f.print(String(int(bh4)));
      f.println(String(int(bm4)));
      f.print (String(int(bd5)));
      f.print(String(int(bh5)));
      f.println(String(int(bm5)));
      f.close();  //Close file
  }
}

void loop() 
{
  delay(1000);
  printLocalTime();
}

void printLocalTime()
{
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  Serial.println(asctime(timeinfo));
  delay(1000);

  int i;
  
  //Read File data
  File f = SPIFFS.open(filename, "r");
  
  if (!f) {
    Serial.println("file open failed");
  }
  else
  {
      Serial.println("Reading Data from File:");
      //Data from file
      for(i=0;i<f.size();i++) //Read upto complete file size
      {
        Serial.print((char)f.read());
      f.print (String(int(bd1)));
      f.print(String(int(bh1)));
      f.println(String(int(bm1)));
      f.print (String(int(bd2)));
      f.print(String(int(bh2)));
      f.println(String(int(bm2)));
      f.print (String(int(bd3)));
      f.print(String(int(bh3)));
      f.println(String(int(bm3)));
      f.print (String(int(bd4)));
      f.print(String(int(bh4)));
      f.println(String(int(bm4)));
      f.print (String(int(bd5)));
      f.print(String(int(bh5)));
      f.println(String(int(bm5)));
        
      }
      Serial.println();
      f.close();  //Close file
      Serial.println("File Closed");
  }

  delay(5000);
  

}
