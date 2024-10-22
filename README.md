# LiteScript (LS)

**LiteScript (LS)** é uma linguagem de programação simples e intuitiva, inspirada em Python, mas com sintaxe em português. Projetada para iniciantes, LiteScript facilita o aprendizado de programação ao permitir que conceitos básicos sejam explorados de forma acessível. 

Este projeto inclui um **interpretador em C** que executa arquivos `.lspt` e suporta variáveis, funções, e estruturas de controle como condicionais.

## Funcionalidades

- **Tipos de variáveis**: Suporte para variáveis inteiras, booleanas e strings.
- **Definição de Funções**: Funções podem ser criadas e chamadas diretamente no código LiteScript.
- **Controle Condicional**: Suporte para blocos condicionais `se` e `senao`.
- **Exibição de Valores**: Função `mostre` para exibir variáveis ou strings diretamente no console.

## Exemplo de Código

Aqui está um exemplo básico de código LiteScript:

```lspt
definir x = 10
se x
    mostre "X é verdadeiro"
senao
    mostre "X é falso"
fimse
```

### Saída Esperada

```
X é verdadeiro
```

## Como Usar

1. **Compilar o interpretador**:
   Para compilar o interpretador, utilize um compilador C. Por exemplo, usando o GCC no terminal:

   ```bash
   gcc -o litescript_interpreter litescript_interpreter.c
   ```

2. **Executar um arquivo LiteScript (.lspt)**:
   Para executar um arquivo `.lspt`, basta fornecer o caminho do arquivo como argumento ao executável.

   ```bash
   ./litescript_interpreter caminho/do/arquivo.lspt
   ```

## Estrutura do Código

- **Tipos Suportados**:
  - `int` (inteiros)
  - `bool` (booleanos, com valores `verdadeiro` e `falso`)
  - `string` (cadeias de caracteres)

- **Definição de Funções**:
  Funções são definidas com a palavra-chave `funcao`, e o código da função é armazenado como uma string. A execução é feita ao chamar o nome da função.

- **Condicionais**:
  Blocos de código podem ser executados condicionalmente com o comando `se`, seguido de um bloco opcional `senao` para cenários alternativos.

## Exemplo de Definição de Função

```lspt
funcao saudacao
    mostre "Olá, Mundo!"
fimfuncao

saudacao
```

### Saída:

```
Olá, Mundo!
```

## Contribuindo

Contribuições são bem-vindas! Se encontrar bugs, ou tiver sugestões de novas funcionalidades, sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.

---

**SoloDev** – Criador do LiteScript
