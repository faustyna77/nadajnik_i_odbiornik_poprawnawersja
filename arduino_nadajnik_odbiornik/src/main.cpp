#include <VirtualWire.h>
#include <SPI.h>


/*uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
const char *on2 = "a";
const char *off2 = "b";
int button = 8;
void setup()
{
  vw_set_ptt_inverted(true); // Required for RF Link modules
  vw_setup(300); // set data speed
  vw_set_tx_pin(12);
  pinMode(button, INPUT);
}
void loop()
{
  if (digitalRead(button)==HIGH)
  {
    vw_send((uint8_t *)on2, strlen(on2)); // send the data out to the world
    vw_wait_tx(); // wait a moment
    delay(200);
  }
  if (digitalRead(button)==LOW)
  {
    vw_send((uint8_t *)off2, strlen(off2));
    vw_wait_tx();
    delay(200);
  }
}

*/


//receiver
/*
#include <VirtualWire.h>
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
int ledpin = 2;
void setup()
{
  vw_set_ptt_inverted(true); // Required for RF link modules
  vw_setup(300);
  vw_set_rx_pin(11);
  vw_rx_start();
  pinMode(ledpin, OUTPUT);
}
void loop()
{
  if (vw_get_message(buf, &buflen))
  {
    switch(buf[0])
    {
    case 'a':
      digitalWrite(ledpin, HIGH);
      break;
    case 'b':
      digitalWrite(ledpin, LOW);
      break;
    }
  }
}
*/

#include <Servo.h>

Servo ESC;     // tworzymy obiekt serwo do sterowania ESC

const int pwmValue = 1500;  // Stała wartość PWM (dostosuj według potrzeb)
// Dla większości ESC, wartość PWM 1500 oznacza zatrzymanie silnika,
// a wartości poniżej 1500 odpowiadają obrotowi wstecznemu, natomiast wartości powyżej 1500 odpowiadają obrotowi do przodu.

void setup() {
  // Podłączamy ESC do pinu 9
  ESC.attach(9, 1000, 2000); // (pin, minimalna szerokość impulsu, maksymalna szerokość impulsu w mikrosekundach)
}

void loop() {
  // Ustawiamy stałą wartość PWM do sterowania silnikiem BLDC
  ESC.writeMicroseconds(pwmValue);

  // Jeśli potrzebujesz, możesz dodać opóźnienie tutaj, aby płynniej kontrolować prędkość lub kierunek silnika
  // Na przykład delay(1000) spowoduje pauzę na 1 sekundę przed ustawieniem nowej wartości PWM.
}