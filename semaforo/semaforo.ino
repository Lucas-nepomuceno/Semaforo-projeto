#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Inicializa os LEDs
int led_vermelho = 8;
int led_amarelo = 9;
int led_verde = 10;

// Cria o ponteiro para o LED verde
int* pverde = &led_verde;

// Inicializa a biblioteca LCD com o endereço I2C e dimensões (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

  lcd.init();
}

void loop() {
  // LED vermelho aceso - não atravesse
  digitalWrite(led_vermelho, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Aguarde...");
  lcd.noBacklight();
  delay(6000);
  digitalWrite(led_vermelho, LOW);

  // LED amarelo aceso - prepare-se
  digitalWrite(led_amarelo, HIGH);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Prepare-se...");
  delay(2000);
  digitalWrite(led_amarelo, LOW);

  // LED verde aceso - atravesse
  digitalWrite(*pverde, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Atravesse!");
  delay(4000);
  digitalWrite(*pverde, LOW);

  // LED amarelo piscando - termine a travessia
  digitalWrite(led_amarelo, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Termine a");
  lcd.setCursor(0, 1);
  lcd.print("travessia");
  delay(2000);
  digitalWrite(led_amarelo, LOW);

  // Limpa o display ao final do ciclo
  lcd.clear();
}
