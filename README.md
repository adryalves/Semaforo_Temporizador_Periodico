# 🚦 Atividade 1: Temporizador Periódico

Este projeto implementa um **semáforo** utilizando o **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` do **Pico SDK**. O sistema controla **três LEDs** (vermelho, amarelo e verde) com uma temporização de **3 segundos** para cada mudança de estado.

## 📌 Link do vídeo mostrando o funcionamento
https://drive.google.com/file/d/11IEivA0x-sKl_k8oPXnazyTU2YlnMGEC/view?usp=sharing

## 🛠 Componentes Utilizados
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde)
- 3 Resistores de 330 Ω

## 🔄 Funcionamento
1. O semáforo inicia na cor **vermelha**.
2. Após **3 segundos**, muda para **amarelo**.
3. Após mais **3 segundos**, muda para **verde**.
4. O ciclo se repete continuamente.

## 📌 Requisitos de Implementação
✔ O temporizador é configurado para um atraso de **3 segundos (3.000ms)**.  
✔ A mudança de estado dos LEDs é realizada na **função de call-back do temporizador** (`repeating_timer_callback()`).  
✔ A **função principal (loop while)** deve imprime a mensagem "Semaforo operando" a cada **1 segundo (1.000ms)**.  

## 🚀 Execução - Caso seja no simulador
1. Após baixar o projeto, clique em compilar para poder criar a pasta build.
2. Entre no arquivo diagram.json.
3. Clique no botão de executar no diagram.json e assista ao funcionamento.

