# LiteScript (LS)

**LiteScript (LS)** é uma linguagem de programação simples e intuitiva, com uma sintaxe inspirada no Python e adaptada para português. Ideal para iniciantes, LiteScript torna o aprendizado de programação acessível a todos.

## Estrutura do Projeto

O LiteScript já vem pronto para uso, com a seguinte estrutura de pastas:

- **assets/**: Arquivos de suporte, como imagens ou outros recursos.
- **bin/**: Contém o executável (`LiteScript.exe`) e outros arquivos binários.
- **src/**: Código-fonte do LiteScript, caso queira explorar ou modificar o interpretador.

## Funcionalidades Principais

- **Variáveis**: Suporte para `int`, `bool` e `string`.
- **Funções**: Defina e chame suas próprias funções.
- **Estruturas Condicionais**: Suporte para `se` e `senao` para controlar o fluxo do programa.
- **Exibição de Mensagens**: Use `mostre` para imprimir texto ou valores no console.

---

## Guia Completo de Uso

### 1. Como Executar o LiteScript

O LiteScript já vem com um **executável** que permite rodar seus scripts rapidamente. Siga as etapas abaixo para começar a usar:

1. **Navegue até o diretório `bin/`.**
2. **Localize o arquivo `LiteScript.exe`.**
3. **Crie um arquivo `.lspt`** com o código LiteScript que deseja executar. Você pode usar qualquer editor de texto, como o Bloco de Notas, VS Code, ou Sublime Text.

### 2. Criando seu Primeiro Script LiteScript

Crie um arquivo com a extensão `.lspt`. Abaixo está um exemplo simples de script LiteScript:

```lspt
definir nome = "LiteScript"
mostre nome

se nome
    mostre "Nome está definido!"
senao
    mostre "Nome não foi encontrado."
fimse
```

Salve este arquivo com um nome de sua escolha, por exemplo: `meu_primeiro_script.lspt`.

### 3. Executando seu Script

Agora, execute o script que você criou. Aqui está como fazer:

1. **Arraste o arquivo `.lspt`** para cima do `LiteScript.exe` ou execute via linha de comando da seguinte forma:

    - Abra o **Prompt de Comando** (no Windows).
    - Navegue até o diretório `bin/`, onde está o `LiteScript.exe`:

      ```bash
      cd caminho/para/bin
      ```

    - Execute o interpretador passando o caminho do arquivo `.lspt`:

      ```bash
      LiteScript.exe caminho/para/seu_script.lspt
      ```

    - Por exemplo:

      ```bash
      LiteScript.exe C:\Users\SeuUsuario\Documentos\meu_primeiro_script.lspt
      ```

2. O LiteScript vai rodar o script e exibir a saída no console.

### 4. Explorando Mais Funções

Aqui estão mais exemplos de como usar variáveis, funções e condicionais no LiteScript.

#### Definindo Variáveis

```lspt
definir idade = 25
definir nome = "João"
definir ativo = verdadeiro

mostre idade
mostre nome
mostre ativo
```

#### Funções Simples

Você pode definir funções e chamá-las assim:

```lspt
funcao saudacao
    mostre "Olá, bem-vindo ao LiteScript!"
fimfuncao

saudacao
```

#### Controle Condicional

Use condicionais para tomar decisões no seu programa:

```lspt
definir idade = 18

se idade >= 18
    mostre "Você é maior de idade."
senao
    mostre "Você é menor de idade."
fimse
```

### 5. Dicas Adicionais

- **Erros Comuns**:
  - **Variável não encontrada**: Verifique a ortografia e se a variável foi definida antes de ser usada.
  - **Erro de sintaxe**: Certifique-se de que a sintaxe, como a indentação, está correta.

- **Melhorando Scripts**:
  - Organize seu código com funções para facilitar a leitura.
  - Use comentários (`// comentário aqui`) para documentar seu código.

---

## Contribuições

Contribuições são **bem-vindas**! Se você encontrar algum problema, ou tiver ideias para novas funcionalidades, fique à vontade para abrir um pull request ou issue no GitHub.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.

---

**SoloDev** – Criador do LiteScript

---

### Resumo das Alterações:

1. **Remoção de Instruções de Compilação**: Como o LiteScript será distribuído como um executável, eliminei as instruções sobre compilação.
2. **Guia Simples de Execução**: Agora o foco é executar o `.exe` com arquivos `.lspt`, seja arrastando o arquivo ou usando o terminal/linha de comando.
3. **Exemplos Práticos**: Incluí exemplos simples para mostrar como criar variáveis, funções, e usar condicionais no LiteScript.
