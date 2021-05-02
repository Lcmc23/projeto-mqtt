# Projeto MQTT - Sprint 8

## Objetivo
O objetivo desse projeto é utilizar o Arduino Uno juntamente com um Sensor Magnético para o monitoramento da porta de um Rack de rede, fazendo a seguinte verificação: **RACK ABERTO** ou **RACK FECHADO**. Após esta análise, a informação será enviada via internet utilizando o protocolo MQTT (_Message Queuing Telemetry Transport_) para um servidor MQTT hospedado na _Amazon Web Service_ (AWS) e assim, exibida em um cliente MQTT.

![exemplo](https://camo.githubusercontent.com/7beef2d4780d87a603d7de49b2da0467c8537dff96575b628a04bd4010ebb1cc/68747470733a2f2f692e696d6775722e636f6d2f4d576870586b562e706e67)

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
![circuito](https://camo.githubusercontent.com/ad1da211b35b60b23fb095a64e76dc6504d0c3229e853bd82a69a4d5d27bbb88/68747470733a2f2f692e696d6775722e636f6d2f594947477453472e706e67)

[![Linkedin Badge](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white&link=mailto:lucascabralmendes.correa@gmail.com)](mailto:lucascabralmendes.correa@gmail.com)

[![Linkedin Badge](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&link=https://www.linkedin.com/in/lucas-cabral-42121b206/)](https://www.linkedin.com/in/lucas-cabral-42121b206/)


![AUTOR](https://img.shields.io/badge/AUTOR-Lucas%20Cabral-important) 
