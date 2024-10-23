# LiteScript (LS)

**LiteScript (LS)** é uma linguagem de programação simples e amigável, com uma sintaxe inspirada no Python, mas adaptada para português, tornando-a fácil de aprender para iniciantes. O objetivo do LiteScript é permitir que novos programadores entrem no mundo da programação de maneira simples e eficiente.

## Sumário

- [Características](#características)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como Usar](#como-usar)
- [Exemplo de Código](#exemplo-de-código)
- [Adicionar LiteScript ao PATH](#adicionar-litescript-ao-path)
- [Contribuindo](#contribuindo)
- [Licença](#licença)

## Características

- **Sintaxe Simples**: Escrita em português e projetada para ser fácil de entender.
- **Operações Básicas**: Suporta variáveis de tipos `int`, `bool` e `string`, além de funções matemáticas simples.
- **Estruturas Condicionais**: Suporte para `se`, `senao` e `enquanto`, facilitando a execução condicional e laços de repetição.
- **Funções**: Permite criar e executar funções personalizadas.
- **Multiplataforma**: Suporte para Windows, Linux e macOS.
- **Compatível com C**: Estruturado para ser compatível com funcionalidades do C, facilitando o aprendizado de ambas as linguagens.

## Estrutura do Projeto

Aqui está a estrutura básica do projeto LiteScript:

```plaintext
LiteScript/        
├── assets/        # Imagens e etc...
├── bin/           # Arquivos binários gerados após compilação
├── src/           # Código-fonte do interpretador LiteScript
└── examples/      # Exemplos de código em LiteScript (.lspt)
```

## Como Usar

Depois de instalar o LiteScript, você pode rodar scripts `.lspt` diretamente no terminal.

### Executar um arquivo:

```bash
litescript meu_script.lspt
```

Se você quiser entrar no **modo interativo**, basta executar o interpretador sem fornecer um arquivo:

```bash
litescript
```

No modo interativo, você pode digitar comandos diretamente e obter os resultados instantaneamente.

### Exemplo de Código

Aqui está um exemplo básico de código LiteScript:

```lspt
definir x = 10
mostre "O valor de x e:"
mostre x
```

**Saída esperada**:

```plaintext
O valor de x e:
10
```

## Adicionar LiteScript ao PATH

Para facilitar o uso do LiteScript a partir de qualquer pasta no seu terminal, você pode adicionar o LiteScript ao seu **PATH**:

### No Windows:

1. Abra o **Painel de Controle** > **Sistema** > **Configurações Avançadas do Sistema**.
2. Clique em **Variáveis de Ambiente**.
3. Encontre a variável **Path**, clique em **Editar**.
4. Adicione o caminho completo do diretório onde o executável LiteScript está localizado e coloque para cima, como `E:\LiteScript\bin\`.

### No Linux/macOS:

1. Abra o terminal e edite seu arquivo `.bashrc` ou `.zshrc`:
   ```bash
   nano ~/.bashrc
   ```
   ou
   ```bash
   nano ~/.zshrc
   ```

2. Adicione a seguinte linha ao final do arquivo:
   ```bash
   export PATH="$PATH:/caminho/para/litescript/bin"
   ```

3. Salve o arquivo e recarregue as configurações:
   ```bash
   source ~/.bashrc
   ```

Agora, você poderá executar o LiteScript de qualquer lugar do terminal!

## Contribuindo

Quer contribuir para o LiteScript? Todas as contribuições são bem-vindas!

### Como Contribuir:

1. **Faça um fork** do repositório.
2. Crie uma **branch** para a nova funcionalidade ou correção de bug:
   ```bash
   git checkout -b minha-feature
   ```
3. **Commit suas mudanças**:
   ```bash
   git commit -m "Descrição das mudanças"
   ```
4. **Envie um Pull Request**.

Se você encontrar algum bug ou tiver sugestões, sinta-se à vontade para abrir uma **issue** no GitHub.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE.md para mais detalhes.

---

**Criado por SoloDev** – Criador do LiteScript
