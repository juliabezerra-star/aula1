// Lab 1 — LED de status: pulso de 200 ms a cada 2 s

const int PINO_LED = 8;   // LED com resistor de 220 Ω em série

// Tempos em milissegundos; o ciclo total é TEMPO_ACESO + TEMPO_APAGADO
const unsigned long TEMPO_ACESO   = 200;
const unsigned long TEMPO_APAGADO = 1800;

void setup() {
  pinMode(PINO_LED, OUTPUT);   // roda uma vez, ao ligar
}

void loop() {                  // repete para sempre
  digitalWrite(PINO_LED, HIGH);
  delay(TEMPO_ACESO);
  digitalWrite(PINO_LED, LOW);
  delay(TEMPO_APAGADO);
}