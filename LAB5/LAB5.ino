//Electronica Digital 2
//Seccion 10
//Mario Estrada - 18123
//Laboratorio 5


#include <SPI.h>
#include <SD.h>

File myFile;
int opc=0;
void setup()
{
    Serial.begin(115200);
    SPI.setModule(0);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    Serial.print("Initializing SD card...");
    pinMode(PA_3, OUTPUT);

    if (!SD.begin(PA_3))
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
    myFile = SD.open("/"); //abrir archivos

    //Funcion que imprime los archivos guardados en la memoria SD
    printDirectory(myFile, 0); //funcion que muestra archivos dentro de SD
    Serial.print("Ingrese el numero del fichero que desea abrir:");
    

    }   
    

void loop()
{    
      //Esto permite la lectura del dato que se esta enviando desde el monitor serial para la seleccion del fichero indicado
        if (Serial.available() > 0) {
      opc = Serial.read();
      }
      
//Opcion que lee el fichero mario
    if(opc== '3'){
      myFile = SD.open("mario.txt");
        Serial.println("mario.txt:");

        // read from the file until there's nothing else in it:
        while (myFile.available())
        {
            Serial.write(myFile.read());
        }
        // close the file:
        myFile.close();

    }
//opcion que lee el fichero space
    if(opc=='2'){
      myFile = SD.open("space.txt");
        Serial.println("space.txt:");

        // read from the file until there's nothing else in it:
        while (myFile.available())
        {
            Serial.write(myFile.read());
        }
        // close the file:
        myFile.close();

    }
//Opcion que lee el fichero triforce
     if(opc=='1'){
       myFile = SD.open("triforce.txt");
        Serial.println("triforce.txt:");

        // read from the file until there's nothing else in it:
        while (myFile.available())
        {
            Serial.write(myFile.read());
        // close the file:
        }
        myFile.close();

     }
        
        else{
        }
}


    void printDirectory(File dir, int NTabs) {
   while(true) {
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<NTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, NTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
  Serial.println("");

}
