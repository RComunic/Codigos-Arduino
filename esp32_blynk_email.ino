/******************************************************************************************************************************
 * TITULO: ESP32 BLYNK + EMAIL
 * DESCRIPCION: En este código leemos una lectura analogica de un puerto adc de nuestro esp32 y ademas se configura una alarma para enviar un correo electronico de aviso

 *******************************************************************************************************************************/
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxxxxxxxx";
char pass[] = "xxxxxxxxxxxx";

WidgetLED led(V1);
BlynkTimer timer;

const byte pot = 33; //gpio33  adc1_5
const int alarma = 2900;
int lectura;
bool correoEnviado = false;

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"


// V1 LED Widget is blinking
void checkSensor()
{
    lectura = analogRead(pot);
    Blynk.virtualWrite(V2, lectura);
    Serial.println(lectura);

    if (lectura >= 4095){
        led.setColor(BLYNK_RED);
        Serial.println("Alarma critica, sensor muy alta");
        if (!correoEnviado){
            String body = String("La lectura del sensor es ") + lectura + " superando la Alarma critica del sistema. Atender cuanto antes!.";
            Blynk.email("jadsa_corp@hotmail.com", "Subject: Sensor Analógico Blynk App", body);
            correoEnviado = true;
        }
    }
    else if (lectura >= alarma)
    {
        led.setColor(BLYNK_YELLOW);
        Serial.print("Alarma, lectura del sensor alta: ");
    }
    else
    {
        led.setColor(BLYNK_GREEN);
    }
}

void setup()
{
    // Debug console
    Serial.begin(9600);

    Blynk.begin(auth, ssid, pass);

    // Turn LED on, so colors are visible
    led.on();
    led.setColor(BLYNK_GREEN);
    // Setup periodic color change
    timer.setInterval(1000L, checkSensor);
}

void loop()
{
    Blynk.run();
    timer.run();
}
