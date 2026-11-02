# Sincronização do Metrô (Implementação 4)

Implementação em C, com pthreads, das funções de sincronização para o embarque de passageiros nos vagões da METROREC. Disciplina de Infraestrutura de Software, CESAR School.

## Sistema operacional

Desenvolvido e testado no **Windows 11**, compilando e executando no **WSL** (Ubuntu 26.04.1 LTS), com `gcc` e `make` (pacote `build-essential`).

## Arquivos

| Arquivo | Descrição |
|---|---|
| `include/sync_car.h` | Definição da `struct station` (1 mutex, 2 variáveis de condição e 3 contadores) e protótipos das funções. |
| `src/sync_car.c` | Implementação de `station_init`, `station_load_car`, `station_wait_for_car` e `station_on_board`. |
| `src/sync_car-runner.c` | Teste fornecido pelo professor, sem alterações. Simula 100 passageiros e vários carros com quantidades aleatórias de assentos. |
| `src/test_invalid.c` | Teste adicional de entrada inválida: `station_load_car` com `count` negativo, com a estação vazia e com passageiros esperando. |
| `Makefile` | Compilação dos executáveis e limpeza. |

## Como compilar

Na pasta do projeto (onde está o `Makefile`):

```bash
make clean
make
```

O `make` gera dois executáveis:

- `sync_car`: o runner do professor com a implementação;
- `test_invalid`: o teste de entrada inválida.

Para compilar só um deles: `make sync_car` ou `make test_invalid`.

O único warning esperado na compilação é `unused parameter 'foo'`, que vem do `sync_car-runner.c` fornecido.

## Como executar e testar

Teste principal (deve terminar com `Looks good!`):

```bash
./sync_car
```

Teste de entrada inválida (deve imprimir `OK` nos dois cenários):

```bash
./test_invalid
```

Execução repetida, para detectar falhas intermitentes de concorrência (não imprime nada se todas passarem):

```bash
for i in $(seq 100); do ./sync_car > /dev/null || echo "falhou na execução $i"; done
```

## Como limpar

```bash
make clean
```

Remove os executáveis `sync_car` e `test_invalid`.