#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

#define MAX_LINHA 256
#define MAX_VARIAVEIS 100
#define MAX_FUNCOES 50

// Declaracao antecipada
void interpretar_codigo(const char* codigo);

// Tipos de variaveis
typedef enum { LS_INT, LS_STR, LS_BOOL } TipoVariavel;

// Estrutura de Variaveis
typedef struct {
    char nome[50];
    TipoVariavel tipo;
    union {
        int i;
        char str[256];
        bool b;
    } valor;
} Variavel;

// Estrutura de Funcoes
typedef struct {
    char nome[50];
    char codigo[1024];  // Codigo da funcao armazenado como string
} Funcao;

// Arrays de Variaveis e Funcoes
Variavel variaveis[MAX_VARIAVEIS];
int cont_variaveis = 0;

Funcao funcoes[MAX_FUNCOES];
int cont_funcoes = 0;

// Funcao para buscar variavel pelo nome
Variavel* buscar_variavel(char* nome) {
    for (int i = 0; i < cont_variaveis; i++) {
        if (strcmp(variaveis[i].nome, nome) == 0) {
            return &variaveis[i];
        }
    }
    return NULL;
}

// Funcao para definir variavel
void definir_variavel(char* nome, TipoVariavel tipo, void* valor) {
    Variavel* var = buscar_variavel(nome);
    if (!var) {
        strcpy(variaveis[cont_variaveis].nome, nome);
        var = &variaveis[cont_variaveis++];
    }
    var->tipo = tipo;
    if (tipo == LS_INT) {
        var->valor.i = *(int*)valor;
    } else if (tipo == LS_STR) {
        strcpy(var->valor.str, (char*)valor);
    } else if (tipo == LS_BOOL) {
        var->valor.b = *(bool*)valor;
    }
}

// Funcao para exibir uma variavel ou string
void mostrar(char* valor, bool is_literal) {
    if (is_literal) {
        printf("%s\n", valor);  // Exibe a string literal
    } else {
        Variavel* var = buscar_variavel(valor);
        if (var) {
            if (var->tipo == LS_INT) {
                printf("%d\n", var->valor.i);  // Exibe o valor inteiro
            } else if (var->tipo == LS_STR) {
                printf("%s\n", var->valor.str);  // Exibe a string
            } else if (var->tipo == LS_BOOL) {
                printf(var->valor.b ? "verdadeiro\n" : "falso\n");  // Exibe booleano
            }
        } else {
            printf("Erro: Variavel %s nao encontrada\n", valor);
        }
    }
}

// Funcao para definir uma funcao
void definir_funcao(char* nome, char* codigo) {
    strcpy(funcoes[cont_funcoes].nome, nome);
    strcpy(funcoes[cont_funcoes].codigo, codigo);
    cont_funcoes++;
}

// Funcoes matemáticas básicas

// Funcao para somar dois números
int soma(int a, int b) {
    return a + b;
}

// Funcao para subtrair dois números
int subtrai(int a, int b) {
    return a - b;
}

// Funcao para multiplicar dois números
int multiplica(int a, int b) {
    return a * b;
}

// Funcao para dividir dois números
int divide(int a, int b) {
    if (b == 0) {
        printf("Erro: Divisao por zero!\n");
        return 0;
    }
    return a / b;
}

// Função para executar operações matemáticas no LiteScript
void executar_funcao(char* nome) {
    int a, b, resultado;

    if (strcmp(nome, "soma") == 0) {
        printf("Digite o primeiro número: ");
        scanf("%d", &a);
        printf("Digite o segundo número: ");
        scanf("%d", &b);
        resultado = soma(a, b);
        printf("Resultado da soma: %d\n", resultado);
        return;
    } else if (strcmp(nome, "subtrai") == 0) {
        printf("Digite o primeiro número: ");
        scanf("%d", &a);
        printf("Digite o segundo número: ");
        scanf("%d", &b);
        resultado = subtrai(a, b);
        printf("Resultado da subtracao: %d\n", resultado);
        return;
    } else if (strcmp(nome, "multiplica") == 0) {
        printf("Digite o primeiro número: ");
        scanf("%d", &a);
        printf("Digite o segundo número: ");
        scanf("%d", &b);
        resultado = multiplica(a, b);
        printf("Resultado da multiplicacao: %d\n", resultado);
        return;
    } else if (strcmp(nome, "divide") == 0) {
        printf("Digite o primeiro número: ");
        scanf("%d", &a);
        printf("Digite o segundo número: ");
        scanf("%d", &b);
        resultado = divide(a, b);
        if (b != 0) {
            printf("Resultado da divisao: %d\n", resultado);
        }
        return;
    }

    for (int i = 0; i < cont_funcoes; i++) {
        if (strcmp(funcoes[i].nome, nome) == 0) {
            interpretar_codigo(funcoes[i].codigo);  // Executa a funcao armazenada
            return;
        }
    }

    printf("Erro: Funcao %s nao encontrada\n", nome);
}

void interpretar_se(char* condicao, char* bloco_true, char* bloco_false) {
    Variavel* var = buscar_variavel(condicao);
    bool condicao_verdadeira = false;

    if (var) {
        if (var->tipo == LS_INT) {
            // Comparação manual para maior ou igual
            if (var->valor.i >= 18) {
                condicao_verdadeira = true;
            }
        } else if (var->tipo == LS_BOOL) {
            condicao_verdadeira = var->valor.b;
        }
    } else {
        // Tentar interpretar a condicao como um valor literal
        if (strcmp(condicao, "verdadeiro") == 0) {
            condicao_verdadeira = true;
        } else if (strcmp(condicao, "falso") == 0) {
            condicao_verdadeira = false;
        } else {
            printf("Erro: Condicao '%s' invalida\n", condicao);
            return;
        }
    }

    if (condicao_verdadeira) {
        interpretar_codigo(bloco_true);  // Bloco verdadeiro
    } else {
        interpretar_codigo(bloco_false);  // Bloco falso (senao)
    }
}

// Funcao para interpretar uma linha de codigo
void interpretar_linha(char* linha) {
    // Remover quebra de linha no final da linha
    linha[strcspn(linha, "\n")] = '\0';

    if (strncmp(linha, "mostre", 6) == 0) {
        char* resto = linha + 6;
        while (isspace(*resto)) resto++;  // Remove espacos em branco

        if (*resto == '"') {
            // String literal
            char* inicio = resto + 1;
            char* fim = strchr(inicio, '"');
            if (fim) {
                *fim = '\0';
                mostrar(inicio, true);
            } else {
                printf("Erro: String literal nao fechada\n");
            }
        } else {
            // Nome de variavel
            char* nome_var = resto;
            mostrar(nome_var, false);
        }
    } else if (strncmp(linha, "definir", 7) == 0) {
        char* resto = linha + 7;
        while (isspace(*resto)) resto++;  // Remove espacos em branco

        char* nome = strtok(resto, " =");
        if (nome) {
            while (isspace(*nome)) nome++;  // Remove espacos em branco
            char* valor = strtok(NULL, "\n");
            if (valor) {
                while (*valor == ' ' || *valor == '=') valor++;  // Remove espacos e '='
                while (isspace(*valor)) valor++;  // Remove espacos em branco

                if (*valor == '"') {
                    // Valor é uma string literal
                    valor++;  // Pula o primeiro "
                    char* fim = strchr(valor, '"');
                    if (fim) {
                        *fim = '\0';  // Remove o ultimo "
                    }
                    definir_variavel(nome, LS_STR, valor);
                } else if (isdigit(*valor) || (*valor == '-' && isdigit(*(valor + 1)))) {
                    int val = atoi(valor);
                    definir_variavel(nome, LS_INT, &val);
                } else if (strcmp(valor, "verdadeiro") == 0 || strcmp(valor, "falso") == 0) {
                    bool val = strcmp(valor, "verdadeiro") == 0;
                    definir_variavel(nome, LS_BOOL, &val);
                } else {
                    // Valor é outra variavel
                    Variavel* var = buscar_variavel(valor);
                    if (var) {
                        definir_variavel(nome, var->tipo, &var->valor);
                    } else {
                        printf("Erro: Variavel %s nao encontrada\n", valor);
                    }
                }
            } else {
                printf("Erro: Valor nao especificado para a variavel %s\n", nome);
            }
        } else {
            printf("Erro: Nome da variavel nao especificado\n");
        }
    } else if (strncmp(linha, "funcao", 6) == 0) {
        char* resto = linha + 6;
        while (isspace(*resto)) resto++;  // Remove espacos em branco

        char* nome_funcao = strtok(resto, " \n");
        if (nome_funcao && *nome_funcao != '\0') {
            char codigo_funcao[1024] = {0};
            char buffer[MAX_LINHA];
            while (fgets(buffer, MAX_LINHA, stdin)) {
                if (strncmp(buffer, "fimfuncao", 9) == 0) {
                    break;
                }
                strcat(codigo_funcao, buffer);
            }
            definir_funcao(nome_funcao, codigo_funcao);
        } else {
            printf("Erro: Nome da funcao nao especificado\n");
        }
    } else if (strncmp(linha, "se", 2) == 0) {
        // Interpretacao de um bloco "se"
        char* resto = linha + 2;
        while (isspace(*resto)) resto++;  // Remove espacos em branco

        char* condicao = strtok(resto, " \n");
        if (condicao && *condicao != '\0') {
            char bloco_true[1024] = {0};
            char bloco_false[1024] = {0};
            char buffer[MAX_LINHA];
            bool no_senao = false;

            // Lendo o bloco de codigo "se"
            while (fgets(buffer, MAX_LINHA, stdin)) {
                if (strncmp(buffer, "fimse", 5) == 0) break;
                if (strncmp(buffer, "senao", 5) == 0) {
                    no_senao = true;
                    continue;
                }
                if (no_senao) {
                    strcat(bloco_false, buffer);
                } else {
                    strcat(bloco_true, buffer);
                }
            }

            interpretar_se(condicao, bloco_true, bloco_false);
        } else {
            printf("Erro: Condicao nao especificada no bloco 'se'\n");
        }
    } else if (*linha != '\0') {
        // Tenta executar como uma funcao
        executar_funcao(linha);  // Executa a funcao se nao for um comando conhecido
    }
}

// Funcao para interpretar o codigo completo
void interpretar_codigo(const char* codigo) {
    char codigo_copia[strlen(codigo) + 1];
    strcpy(codigo_copia, codigo);

    char* linha = strtok(codigo_copia, "\n");
    while (linha != NULL) {
        interpretar_linha(linha);
        linha = strtok(NULL, "\n");
    }
}

// Modificacao no main para manter o interpretador em loop
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");  // Configura a codificacao local
    SetConsoleOutputCP(CP_UTF8);  // Força UTF-8 para a saída no console
    SetConsoleCP(CP_UTF8);        // Força UTF-8 para a entrada

    // Verificar se o arquivo foi passado como argumento
    if (argc >= 2) {
        FILE* arquivo = fopen(argv[1], "r");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo '%s'.\n", argv[1]);
            return 1;
        }

        char linha[MAX_LINHA];
        while (fgets(linha, MAX_LINHA, arquivo)) {
            interpretar_linha(linha);
        }

        fclose(arquivo);
        return 0;  // Saímos após rodar o arquivo
    }

    // Se nenhum arquivo foi passado, entrar no modo interativo
    char comando[MAX_LINHA];  // Armazena o comando do usuário

    printf("Bem-vindo ao interpretador LiteScript.\n");
    printf("Digite 'sair' para encerrar o programa.\n\n");

    while (1) {  // Loop principal para manter o interpretador rodando
        printf("LiteScript> ");
        if (!fgets(comando, MAX_LINHA, stdin)) {
            break;  // Sai do loop se não puder ler o comando
        }

        // Remover o '\n' do final do comando
        comando[strcspn(comando, "\n")] = '\0';

        if (strcmp(comando, "sair") == 0) {
            printf("Encerrando o LiteScript...\n");
            break;
        }

        interpretar_linha(comando);  // Interpretar a linha de comando do usuário
    }

    return 0;
}
