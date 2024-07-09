# Astronauta-LP1
## Funcionalidades

- Cadastro de Astronautas: Inclui dados como CPF, nome e idade dos astronautas.
- Cadastro de Voos: Inclui o código do voo.
- Adicionar e Remover Astronautas de Voo (por CPF): Permite adicionar ou remover astronautas de um voo específico usando o CPF como referência, desde que o voo esteja em planejamento.
- Lançamento de Voos: A função para lançar um voo garante que pelo menos um astronauta esteja presente e disponível. Após o lançamento, os astronautas envolvidos ficam indisponíveis.
- Finalizar Voos (com ou sem sucesso): Permite a finalização de um voo, retornando os astronautas ao estado disponível ou marcando-os como mortos, dependendo do resultado do voo.
- Listar Voos: Lista todos os voos (planejados, em curso ou finalizados) com seus astronautas. 
- Listar Astronautas e Voos feitos por eles: Exibe os astronautas e os voos em que participaram.
- Listar Mortos: Exibir uma lista de astronautas mortos.


## Configuração e execução no Linux

**Baixe todos os arquivos (Exceto o READ.me)**:


**Navegue até diretório do projeto e abra o terminal**:


**Instale as ferramentas essenciais para C++**:

Primeiramente, atualize os repositórios de pacotes:
```bash
  sudo apt update
```

Em seguida, instale o pacote `build-essential` que inclui o compilador `g++` e outras ferramentas:
```bash
  sudo apt install build-essential
```

**Compilar o código**:
Usando o `Makefile`
```bash
  make
```
**Executar o programa**:
```bash
  ./sistemaGestao
```
**Caso alternativo**:
```bash
  Pesquisar no navegador o GDB Online, colocar na versão C++ 17 ou maior, e fazer o upload dos arquivos, copiar a main.cpp que tem o código para o main inicial da páginae excluir um dos main's, o GDB pode compilar "sozinho".
```
