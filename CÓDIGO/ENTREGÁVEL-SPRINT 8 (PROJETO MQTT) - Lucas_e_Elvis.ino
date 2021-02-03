#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0xBE, 0xF0, 0x4F, 0x95, 0x3B, 0xFC};

boolean mensagem;
int pino2 = 2; 
bool estado_sensor;

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient (client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer ("54.144.190.205",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    pinMode(pino2,INPUT_PULLUP);

    //Exibe uma linha em branco
    Serial.println("");

}

void loop() {
  mqttClient.connect ("lucaselvis");
  
  Serial.println (mensagem);

  mqttClient.loop();

  // Verifica qual o estado atual do sensor
  estado_sensor = digitalRead(pino2); 

  // Verifica se o estado da chave está em 1
  if (estado_sensor == 1) {
    Serial.println("RACK ABERTO");
    mensagem = mqttClient.publish ("lucaselvis-s","ABERTO!");
    
  }          

  // Verifica se o estado da chave é diferente de 1 ou seja 0
    if (estado_sensor == 0) {
    Serial.println ("RACK FECHADO");
    mensagem = mqttClient.publish ("lucaselvis-s","FECHADO!");
    
  }
  
    
}