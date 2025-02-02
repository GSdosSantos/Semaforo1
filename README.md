CEPeDI - Embarcateh - Moodle

Autor

Este código foi desenvolvido por Gabriel Santos dos Santos.
Matrícula: tic370101356

# Projeto Semáforo com LEDs RGB (Raspberry Pi Pico)

Este projeto implementa um semáforo simples utilizando três LEDs RGB conectados aos pinos GPIO 11, 12 e 13 de um Raspberry Pi Pico. O código alterna entre os estados de "vermelho", "amarelo" e "verde", simulando um semáforo típico. O código foi desenvolvido em C utilizando a biblioteca do Raspberry Pi Pico e pode ser testado de forma simulada utilizando a extensão Wokwi para o VS Code.

## Requisitos

- Raspberry Pi Pico ou qualquer placa compatível com o Raspberry Pi.
- Visual Studio Code instalado.
- Extensão **Wokwi** instalada no VS Code para simulação de circuitos.
- Biblioteca `pico/stdlib.h` para controlar o hardware do Raspberry Pi Pico.

## Componentes Utilizados

- **3 LEDs RGB**:
  - LED vermelho conectado ao pino GPIO 11.
  - LED amarelo conectado ao pino GPIO 12.
  - LED verde conectado ao pino GPIO 13.

## Funcionamento do Código

O código alterna entre três estados, acendendo um LED de cada vez para representar os três estágios de um semáforo:

1. **Estado 0**: LED vermelho aceso.
2. **Estado 1**: LED amarelo aceso.
3. **Estado 2**: LED verde aceso.

Após um intervalo de 3 segundos, o sistema muda de estado de forma cíclica, reiniciando após o estado verde.

## Como Rodar

### No VS Code com Extensão Wokwi:

1. Abra o VS Code e instale a extensão **Wokwi** para simulação de circuitos.
2. Clone ou crie um novo arquivo `.c` com o código fornecido.
3. Conecte os LEDs aos pinos GPIO 11, 12 e 13 no simulador Wokwi.
4. Compile o código e inicie a simulação no Wokwi para observar o comportamento do semáforo.
   
### Compilação e Execução no Raspberry Pi Pico:

1. Compile o código com o compilador GCC para ARM.
2. Carregue o binário gerado para o Raspberry Pi Pico.
3. Observe os LEDs alternando entre os estados de semáforo.

## Explicação do Código

O código define três pinos GPIO para os LEDs (vermelho, amarelo e verde). Um temporizador repetido é configurado para alternar entre os estados a cada 3 segundos. O estado atual do semáforo é impresso no terminal a cada segundo.

- **Estado 0**: Acende o LED vermelho.
- **Estado 1**: Acende o LED amarelo.
- **Estado 2**: Acende o LED verde.

A alternância entre os estados é realizada com o auxílio da função `repeating_timer_callback`, que é chamada a cada 3 segundos.

### Funções:

- `gpio_init()`: Inicializa os pinos GPIO.
- `gpio_set_dir()`: Configura a direção dos pinos como saída.
- `gpio_put()`: Acende ou apaga os LEDs de acordo com o estado atual.
- `add_repeating_timer_ms()`: Configura o temporizador repetido que alterna os LEDs a cada 3 segundos.
- `stdio_init_all()`: Inicializa a comunicação serial para imprimir o estado atual no terminal.


