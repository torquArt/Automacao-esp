#include "WiFi.h"
void setup() {
// Inicializa a comunicação serial
Serial.begin(115200);
// Configura o modo Wi-Fi para estação (client)
WiFi.mode(WIFI_STA);
WiFi.disconnect(); // Desconecta de qualquer rede Wi-Fi anterior
delay(100);
Serial.println("Iniciando escaneamento de redes Wi-Fi...");
}
void loop() {
// Escaneia as redes Wi-Fi disponíveis
int numberOfNetworks = WiFi.scanNetworks();
Serial.println("Escaneamento concluído!");
if (numberOfNetworks == 0) {
Serial.println("Nenhuma rede encontrada");
} else {
Serial.print(numberOfNetworks);
Serial.println(" redes encontradas:");
for (int i = 0; i < numberOfNetworks; ++i) {
// Imprime o SSID e a intensidade do sinal (RSSI) de cada rede
Serial.print(i + 1);
Serial.print(": ");
Serial.print(WiFi.SSID(i));
Serial.print(" (");
Serial.print(WiFi.RSSI(i));
Serial.print(" dBm)");
Serial.print(" ");
Serial.print((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Aberta" :
"Fechada");
Serial.println();
}
}
Serial.println("");
// Aguarda 5 segundos antes de escanear novamente
delay(5000);
}