/*
Nome do desenvolvedor: Lucas Cabral
Versão: 0.1
Data de criação: 02/01/2021
Última manutenção: 03/01/2021

Objetivo desse projeto: utilizar o Arduino Uno juntamente com um Sensor Magnético para o monitoramento da porta de um Rack de rede, fazendo 
a seguinte verificação: RACK ABERTO ou RACK FECHADO. Após esta análise, a informação será enviada via internet utilizando o protocolo MQTT 
(Message Queuing Telemetry Transport) para um servidor MQTT hospedado na Amazon Web Service (AWS) e assim, exibida em um cliente MQTT.
*/ 

//Adicionar as Bibliotecas
#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <SPI.h>

//Define o endereço MAC que será utilizado
byte mac [] = {0xBE, 0xF0, 0x4F, 0x95, 0x3B, 0xFC};

//Inicia o cliente Ethernet
EthernetClient client;

//Inicia o cliente MQTT
PubSubClient mqttClient(client);

//Variável utilizada para enviar as mensagens utilizando o cliente MQTT
boolean mensagem;

//Variáveis utilizadas para definir o pino do sensor magnético (int) e seu estado (bool)
int pino2 = 2; 
bool estado_sensor;

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o Monitor Serial
    Serial.begin (9600);

    //Define o IP e Porta TCP do Broker MQTT que vamos utilizar
    mqttClient.setServer("",);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print ("O IP do arduino e:");
    Serial.println (Ethernet.localIP());
    
    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do arduino e:");
    Serial.println(Ethernet.subnetMask());
    
    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print ("O Gateway do arduino e:");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println(" ");
    
    //Variável "pino2" como entrada, variando em 1 (ligado) ou 0 (desligado)
    pinMode(pino2, INPUT_PULLUP);

    //Aguarde 5seg antes de ir para a função void loop()
    delay(5000);
}

void loop() {
  
  //Define o nome do cliente MQTT e efetua a conexão com o servidor
  mqttClient.connect("lucascabral");

  //Variável que envia a mensagem e armazena o valor de '1' (caso a mensagem seja enviada com sucesso) e '0' (caso o envio falhe)
  mensagem = mqttClient.publish("sensor_magnetico, LIGADO");

  //Verificar a conexão entre o Cliente e o Broker
  mqttClient.loop();

  //Aguarde 0,5seg
  delay(500);

  // Verifica qual o estado atual da chave
  estado_sensor = digitalRead(pino2); 

  // Verifica se o estado da chave está em 1
  if (estado_sensor == 1) {
    Serial.println("RACK ABERTO");
    delay(1000);
  }

  // Verifica se o estado da chave é diferente de 1 ou seja 0
  else {
    Serial.println ("RACK FECHADO");
    delay (1000);
  }
  

}