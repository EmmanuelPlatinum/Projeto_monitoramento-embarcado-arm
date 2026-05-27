/**
 * Disciplina: Programação de Microprocessadores e Microcontroladores
 * Professor: Felipe Douglas
 * Projeto: Sistema Inteligente de Monitoramento Térmico
 */

#include <Arduino.h>

// Pinos dos LEDs
const int LED_VERDE = 6;    // Estado Normal
const int LED_LARANJA = 4;  // Estado de Aviso
const int LED_VERMELHO = 2; // Estado Crítico

// Limites de temperatura
const float LIMITE_AVISO = 35.0;
const float LIMITE_CRITICO = 42.0;

float temperaturaAtual = 25.0;

const char* processarTomadaDecisao(float temp) {
    if (temp >= LIMITE_CRITICO) {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_LARANJA, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
        return "CRITICO";
    } else if (temp >= LIMITE_AVISO) {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_LARANJA, HIGH);
        digitalWrite(LED_VERMELHO, LOW);
        return "AVISO";
    } else {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_LARANJA, LOW);
        digitalWrite(LED_VERMELHO, LOW);
        return "NORMAL";
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_LARANJA, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
    int leituraAnalogica = analogRead(A0);
    
    // CORREÇÃO AQUI: O mapeamento foi invertido (50, 20) para casar com a ligação física do interruptor.
    // Agora: Posição Baixa = Verde (20°C), Média = Laranja, Alta = Vermelho (50°C).
    temperaturaAtual = map(leituraAnalogica, 0, 1023, 50, 20);

    const char* statusSistema = processarTomadaDecisao(temperaturaAtual);

    Serial.print("{");
    Serial.print("\"timestamp\": "); Serial.print(millis());
    Serial.print(", \"temperature\": "); Serial.print(temperaturaAtual, 1);
    Serial.print(", \"status\": \""); Serial.print(statusSistema); Serial.print("\"");
    Serial.println("}");

    delay(3000);
}
