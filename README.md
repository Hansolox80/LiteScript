# LiteScript (LS)

**LiteScript (LS)** é uma linguagem de programação simples e amigável, com uma sintaxe inspirada no Python, mas adaptada para português, tornando-a fácil de aprender para iniciantes. O objetivo do LiteScript é permitir que novos programadores entrem no mundo da programação de maneira simples e eficiente.

## Estrutura do Projeto

O LiteScript segue a estrutura abaixo:

- **assets/**: Arquivos de suporte, como imagens ou outros recursos.
- **bin/**: Arquivos executáveis gerados depois de compilar o projeto.
- **src/**: Código-fonte do LiteScript, onde está o interpretador.
- **LiteScript**: Atalho para o interpretador ou arquivo principal do projeto.

### Diretórios:

- **assets/**: Contém arquivos auxiliares que podem ser usados no projeto (ex: imagens, ícones, etc.).
- **bin/**: Diretório onde ficam os arquivos binários, ou seja, os executáveis gerados após a compilação.
- **src/**: Onde o código-fonte principal do LiteScript é mantido, incluindo o interpretador e outros componentes do núcleo da linguagem.

## Funcionalidades Principais

- **Variáveis**: Suporta variáveis de tipos `int`, `bool`, e `string`.
- **Funções**: Funções podem ser definidas e chamadas no código LiteScript.
- **Controle Condicional**: Suporte para `se` e `senao`, facilitando a execução condicional de blocos de código.
- **Exibição de Mensagens**: O comando `mostre` permite exibir variáveis e strings diretamente no console.

## Exemplo de Código

Este é um exemplo básico de como usar o LiteScript:

```lspt
definir nome = "LiteScript"
mostre nome

se nome
    mostre "Nome está definido!"
senao
    mostre "Nome não foi encontrado."
fimse

Saída Esperada:

LiteScript
Nome está definido!

Como Compilar e Executar

1. Compilar o Interpretador: Para compilar o interpretador, você pode utilizar um compilador C. No Windows, por exemplo, com o MinGW, você pode usar o seguinte comando no terminal:

gcc -o litescript_interpreter src/litescript_interpreter.c


2. Executar um Arquivo .lspt: Após a compilação, você pode executar arquivos .lspt como argumento:

./litescript_interpreter caminho/do/arquivo.lspt



Contribuições

Contribuições são bem-vindas! Se você encontrar algum problema, ou tiver ideias para novas funcionalidades, fique à vontade para abrir um pull request ou issue no GitHub.

# Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para mais detalhes.



SoloDev – Criador do LiteScript
