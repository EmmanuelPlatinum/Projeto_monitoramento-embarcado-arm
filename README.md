# 🌡️ Projeto: Monitoramento Embarcado ARM

Sistema end-to-end (Hardware + Software) desenvolvido para telemetria térmica em tempo real, utilizando programação embarcada em C e uma interface web de supervisão.

## 🔗 Links e Entregáveis do Projeto

* 🎥 **Vídeo Demonstrativo:** [Assistir no YouTube](https://youtu.be/dvDMxREVWmM)
* 🌐 **Dashboard Web (Live):** [Acessar Painel Interativo](https://plat-temp-dash.lovable.app)
* 💻 **Repositório do Frontend (React):** [Acessar Código Fonte do Site](https://github.com/EmmanuelPlatinum/plat-temp-dash.git)
* ⚙️ **Simulação do Hardware:** O arquivo da simulação no Wokwi está disponível neste repositório no arquivo `Prova sistemas distribuidos.zip`.

## 🚀 Visão Geral da Arquitetura
Este projeto foi desenvolvido como aplicação prática de microcontroladores e arquitetura ARM. Ele consiste em duas camadas principais que operam de forma desacoplada, integrando-se via troca de pacotes de dados:

1. **Edge Computing (Hardware/Firmware):** - Arquivo principal: `Código.c`
   - O microcontrolador processa dados do sensor analógico localmente.
   - Aplica lógica de tomada de decisão (IA introdutória via árvore de decisão) baseada em limiares térmicos pré-definidos (Normal, Aviso, Crítico).
   - Aciona os atuadores físicos (LEDs) e estrutura a telemetria em formato JSON (`Dados.json`) transmitido via UART.

2. **Supervisório Web (Software/Interface):** - Desenvolvido em React e hospedado na nuvem.
   - Atua como o painel de monitoramento capaz de ler o padrão JSON gerado pelo hardware, plotando gráficos de 24h em tempo real e emitindo alertas visuais na tela.

## 🛠️ Tecnologias Utilizadas
- **Firmware/Sistemas Embarcados:** Linguagem C/C++, Arduino Uno, Simulador Wokwi.
- **Frontend/Dashboard Web:** React 18, TypeScript, TailwindCSS.
- **Protocolo de Integração:** UART Serial (formatação JSON).

---
*Projeto acadêmico desenvolvido para a disciplina de Sistemas digitais e Microcontroladores (Prof. Felipe Douglas).*
