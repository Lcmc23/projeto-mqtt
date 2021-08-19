# Projeto MQTT - Sprint 8

## Objetivo
O objetivo desse projeto é utilizar o Arduino Uno juntamente com um Sensor Magnético para o monitoramento da porta de um Rack de rede, fazendo a seguinte verificação: **RACK ABERTO** ou **RACK FECHADO**. Após esta análise, a informação será enviada via internet utilizando o protocolo MQTT (_Message Queuing Telemetry Transport_) para um servidor MQTT hospedado na _Amazon Web Service_ (AWS) e assim, exibida em um cliente MQTT.

<h1>
    <h1 align="center">
    <img src="https://i.ibb.co/yhcL9y8/img1.png">
</h1>

Aplicativo onde as informações serão exibidas:

Plataforma | Aplicativo
--- | ---------
Android | [MQTT Dash](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR&gl=US)
IOS | [MQTTool](https://apps.apple.com/us/app/mqttool/id1085976398)

Bibliotecas utilizadas:
- [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet) (Conexão do ENC28J60 com o Arduino)
- [PubSubClient](https://github.com/knolleary/pubsubclient) (Cliente MQTT para o Arduino)

## Materiais utilizados

* Arduino Uno;
* Módulo Ethernet (ENC28J60);
* Sensor Magnético (MC-38);
* Jumpers.

## Circuito
  
<h1>
    <h1 align="center">
    <img src="https://i.ibb.co/7RrjXhk/img2.png">
</h1>

[![Linkedin Badge](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white&link=mailto:lucascabralmendes.correa@gmail.com)](mailto:lucascabralmendes.correa@gmail.com)

[![Linkedin Badge](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&link=https://www.linkedin.com/in/lucas-cabral-42121b206/)](https://www.linkedin.com/in/lucas-cabral-42121b206/)


![AUTOR](https://img.shields.io/badge/AUTOR-Lucas%20Cabral-important) 
