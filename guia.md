# Guia de Programação em LiteScript

Bem-vindo ao **LiteScript**! Este guia foi criado para ajudá-lo a aprender a programar nesta linguagem simples e intuitiva. O LiteScript é projetado para ser fácil de aprender, especialmente para iniciantes, com uma sintaxe em português que torna o processo de codificação mais natural.

## Sumário

- [O que é LiteScript?](#o-que-é-litescript)
- [Instalação](#instalação)
- [Seu Primeiro Programa](#seu-primeiro-programa)
- [Comentários](#comentários)
- [Variáveis e Tipos de Dados](#variáveis-e-tipos-de-dados)
- [Operadores](#operadores)
- [Entrada e Saída](#entrada-e-saída)
- [Estruturas de Controle](#estruturas-de-controle)
  - [Condicionais (`se`, `senao`)](#condicionais-se-senao)
  - [Laços de Repetição (`enquanto`)](#laços-de-repetição-enquanto)
- [Funções](#funções)
- [Exemplos Práticos](#exemplos-práticos)
- [Dicas e Boas Práticas](#dicas-e-boas-práticas)
- [Conclusão](#conclusão)

---

## O que é LiteScript?

**LiteScript (LS)** é uma linguagem de programação simples, escrita em português, inspirada na sintaxe do Python. Foi criada para facilitar o aprendizado de programação, permitindo que novos programadores entendam conceitos fundamentais sem a barreira adicional de uma sintaxe complexa ou em outro idioma.

### Características Principais

- **Sintaxe Simples**: Facilita a leitura e escrita de código.
- **Tipos de Dados Básicos**: Suporta `int` (inteiro), `string` (texto) e `bool` (booleano).
- **Estruturas de Controle**: Instruções como `se`, `senao` e `enquanto`.
- **Funções**: Possibilidade de criar e chamar funções personalizadas.
- **Operações Matemáticas**: Suporte a operações aritméticas básicas.

---

## Instalação

Antes de começar a programar em LiteScript, você precisa instalar o interpretador.

### Passos para Instalação

1. **Baixe o LiteScript**: Obtenha o interpretador a partir do repositório oficial ou do site do projeto.

2. **Compilação (Opcional)**: Se você baixou o código-fonte, compile-o usando um compilador C compatível.

3. **Configuração do Ambiente**: Adicione o diretório do LiteScript ao seu PATH para facilitar a execução a partir do terminal.

   - **Windows**:
     - Abra as **Configurações do Sistema** > **Variáveis de Ambiente**.
     - Edite a variável `Path` e adicione o caminho para o executável do LiteScript.

   - **Linux/macOS**:
     - Edite o arquivo `~/.bashrc` ou `~/.zshrc` e adicione:
       ```bash
       export PATH="$PATH:/caminho/para/litescript/bin"
       ```
     - Salve o arquivo e execute `source ~/.bashrc` ou `source ~/.zshrc`.

4. **Verificação**: No terminal, digite `litescript` e pressione Enter. Se o interpretador iniciar, a instalação foi bem-sucedida.

---

## Seu Primeiro Programa

Vamos começar com um programa clássico: **"Olá, mundo!"**

Crie um arquivo chamado `ola_mundo.lspt` com o seguinte conteúdo:

```lspt
mostre "Olá, mundo!"
```

Para executar o programa, abra o terminal e digite:

```bash
litescript ola_mundo.lspt
```

**Saída esperada:**

```plaintext
Olá, mundo!
```

---

## Comentários

Comentários são trechos de código ignorados pelo interpretador, usados para explicar partes do código.

- **Linha Única**: Use `#` no início da linha.

  ```lspt
  # Este é um comentário de linha única
  ```

- **Múltiplas Linhas**: Atualmente, o LiteScript não suporta comentários de múltiplas linhas. Utilize `#` em cada linha.

  ```lspt
  # Comentário linha 1
  # Comentário linha 2
  ```

---

## Variáveis e Tipos de Dados

Variáveis são usadas para armazenar dados que podem ser utilizados posteriormente.

### Declarando Variáveis

Use a palavra-chave `definir` para declarar uma variável.

#### Inteiros (`int`)

```lspt
definir idade = 25
```

#### Strings (`string`)

```lspt
definir nome = "Alice"
```

#### Booleanos (`bool`)

```lspt
definir ativo = verdadeiro
```

### Regras para Nomes de Variáveis

- Devem começar com uma letra.
- Podem conter letras, números e underscores (`_`).
- Sensíveis a maiúsculas e minúsculas (`nome` é diferente de `Nome`).

---

## Operadores

Operadores são usados para realizar operações em variáveis e valores.

### Operadores Aritméticos

- **Adição**: `+`
- **Subtração**: `-`
- **Multiplicação**: `*`
- **Divisão**: `/`

```lspt
definir soma = 10 + 5      # soma recebe 15
definir produto = 4 * 2    # produto recebe 8
```

### Operadores de Comparação

- **Igual a**: `==`
- **Diferente de**: `!=`
- **Maior que**: `>`
- **Menor que**: `<`
- **Maior ou igual a**: `>=`
- **Menor ou igual a**: `<=`

```lspt
se idade >= 18
    mostre "Maior de idade"
senao
    mostre "Menor de idade"
fimse
```

---

## Entrada e Saída

### Saída de Dados

Use `mostre` para exibir informações.

```lspt
mostre "Bem-vindo ao LiteScript!"
mostre nome
```

### Entrada de Dados

Atualmente, o LiteScript não suporta diretamente a entrada de dados do usuário via `input`. Você pode modificar o interpretador para adicionar essa funcionalidade ou usar variáveis pré-definidas.

---

## Estruturas de Controle

### Condicionais (`se`, `senao`)

Permitem executar blocos de código com base em condições.

```lspt
definir nota = 7

se nota >= 7
    mostre "Aprovado"
senao
    mostre "Reprovado"
fimse
```

### Laços de Repetição (`enquanto`)

> **Nota:** Com base no código fornecido, não há implementação de laços `enquanto`. Se o interpretador não suporta essa funcionalidade, você precisará estender o interpretador ou omitir esta seção.

---

## Funções

Funções são blocos de código que executam tarefas específicas e podem ser reutilizados.

### Definindo Funções

Use a palavra-chave `funcao` para definir uma função.

```lspt
funcao saudacao
    mostre "Olá!"
fimfuncao
```

### Chamando Funções

Basta escrever o nome da função.

```lspt
saudacao
```

### Funções com Operações Matemáticas

O LiteScript vem com funções matemáticas básicas:

- `soma`
- `subtrai`
- `multiplica`
- `divide`

#### Exemplo

```lspt
soma
```

**Após chamar `soma`, o interpretador solicitará os números:**

```plaintext
Digite o primeiro número: 5
Digite o segundo número: 3
Resultado da soma: 8
```

---

## Exemplos Práticos

### Exemplo 1: Verificar se um número é par ou ímpar

```lspt
definir numero = 4

se numero % 2 == 0
    mostre "O número é par"
senao
    mostre "O número é ímpar"
fimse
```

**Nota:** Se o operador `%` (módulo) não for suportado, este exemplo não funcionará sem modificar o interpretador.

### Exemplo 2: Saudação Personalizada

```lspt
funcao saudacao_personalizada
    definir nome = "Carlos"
    mostre "Olá, " + nome + "!"
fimfuncao

saudacao_personalizada
```

**Saída:**

```plaintext
Olá, Carlos!
```

---

## Dicas e Boas Práticas

- **Consistência**: Mantenha um padrão de nomenclatura para suas variáveis e funções.
- **Comentários**: Utilize comentários para explicar partes complexas do código.
- **Testes**: Teste seu código frequentemente para identificar e corrigir erros cedo.
- **Organização**: Separe seu código em funções para melhorar a legibilidade e reutilização.

---

## Conclusão

O LiteScript é uma ótima ferramenta para iniciar sua jornada na programação. Sua sintaxe simples e orientada ao português facilita o aprendizado dos conceitos básicos que são fundamentais em qualquer linguagem de programação.

Sinta-se à vontade para explorar e modificar o interpretador, adicionando novas funcionalidades e aprendendo mais sobre como linguagens de programação funcionam internamente.

---

**Criado por SoloDev** – Criador do LiteScript
