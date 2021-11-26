//Para leer varios caracteres    

int out1 = 9;  // Senal PWM de control
int vel;
int velocidad;

void setup(){
  Serial.begin(9600);
  pinMode(out1,OUTPUT);
  vel = 0;
  velocidad = 130;
  analogWrite(out1, velocidad);  // Velocidad 0
  Serial.print("Velocidad = ");
  Serial.println(velocidad);
  }


void loop(){
 while(Serial.available()>0){
   vel = Serial.parseInt();
   if(vel!=0){
     velocidad = vel;
     datoVel(vel);
    }
  }
  
 if(!(Serial.available())){
  analogWrite(out1,velocidad);
 }  
}


void datoVel(int velocidad){
  velocidad = constrain(velocidad,1, 254);   //Validacion de Datos
  if (velocidad >= 1 && velocidad <= 254){
    analogWrite(out1, velocidad);
    Serial.print("Velocidad = ");
    Serial.println(velocidad);
    }
  delay(15);
}
