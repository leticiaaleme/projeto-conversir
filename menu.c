#include "menu.h"


// Menu de opções
int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("\n");
    printf(BCYAN BOLD"\t\t===========================\n");
    printf("\t\t||" BWHITE BOLD "Bem vindo ao ConverSir!" RESET BCYAN BOLD "||\n");
    printf("\t\t===========================\n\n" RESET);
    printf(BCYAN BOLD "==============================================\n");
    printf("||" BWHITE BOLD "Converta grandezas de maneira simples." RESET BCYAN BOLD "\t||\n");
    printf("||" BWHITE "Selecione a grandeza que deseja converter:" RESET BCYAN BOLD "||\n");
    printf("==============================================" RESET "\n\n");
    printf("\t1 - Temperatura\n");
    printf("\t2 - Massa\n");
    printf("\t3 - Comprimento\n");
    printf("\t4 - Tempo\n");
    printf("\t5 - Relatório\n");
    printf("\t0 - Sair\n\n");
    printf(BOLD "\tOpção:" RESET " ");
    op = capturarInteiro(); // Captura a opção

    return op;
}

// Função para validar se a entrada é um número inteiro
bool validarEntradaInt(const char *entrada) {
    int i = 0;
    // Se o primeiro caractere é um sinal, ignorar
    if (entrada[0] == '-' || entrada[0] == '+') {
        i = 1;
    }
    // Checar se os demais caracteres são dígitos
    for (; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return false;
        }
    }
    return true;
}
// Função para validar se a entrada é um número double
bool validarEntradaDouble(const char *entrada) {
    int i = 0;
    bool pontoEncontrado = false;
    // Se o primeiro caractere é um sinal, ignorar
    if (entrada[0] == '-' || entrada[0] == '+') {
        i = 1;
    }
    // Checar se os demais caracteres são dígitos ou ponto
    for (; entrada[i] != '\0'; i++) {
        if (entrada[i] == '.') {
            if (pontoEncontrado) {
                return false; // Mais de um ponto
            }
            pontoEncontrado = true;
        } else if (!isdigit(entrada[i])) {
            return false;
        }
    }
    return true;
}

// Função para capturar e validar um número inteiro
int capturarInteiro() {
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o newline
        if (validarEntradaInt(buffer)) {
            return atoi(buffer);
        }
        printf(RED "Entrada inválida! Por favor, digite um número inteiro: " RESET);
    }
}
// Função para capturar e validar um número double
double capturarDouble() {
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o newline
        if (validarEntradaDouble(buffer)) {
            return atof(buffer);
        }
        printf(RED "Entrada inválida! Por favor, digite um número: " RESET);
    }
}