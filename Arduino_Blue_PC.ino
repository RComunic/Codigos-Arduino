
int led = 13; 
char c;

void setup(){

Serial.begin(9600);
pinMode(led, OUTPUT);                        // Led como salida
}

void loop() {  
   if (Serial.available()>0){

     c=Serial.read();

     if (c== 'a'){
        digitalWrite(led, HIGH); //Si el valor de input es 1, se enciende el led
        Serial.println( c );    // Imprimir lectura en el monitor serial
        Serial.println( "LED ON" );
        
     }

     if ( c == 'b'){
        digitalWrite(led, LOW); //Si el valor de input es diferente de 1, se apaga el LED
        Serial.println( c );                // Imprimir en el monitor serial
        Serial.println( "LED OFF" );
     }
     delay(100);
   }
}
