#include "function.h"

// Protótipos
int menu();

int main(void) {
    // Variáveis
    int aux = 0;
    double aux2 = 0;
    int opcao = OP_NAO_SELECIONADA;
    struct unidade novo;
    const char *nomeArquivo = "historico.txt";

    // Início do menu
    while(opcao != OP_SAIR) { // Até o usuário querer sair
        opcao = menu(); // Exibe o menu e captura a opção do usuário

        switch (opcao) {
            case OP_TEMPERATURA:
                printf("Temperatura\n");
                printf("Escolha uma opção:\n");
                printf("1 - Celsius para Fahrenheits\n");
                printf("2 - Celsius para Kelvin\n");
                printf("3 - Fahrenheits para Celsius\n");
                printf("4 - Fahrenheits para Kelvin\n");
                printf("5 - Kelvin para Celsius\n");
                printf("6 - Kelvin para Fahrenheits\n");
                printf("0 - Sair\n");
                printf("Opção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de temperatura se 0 for selecionado
                }
                printf("Digite o valor: \n");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf("Erro na conversão!\n");
                    break;
                }
                break;

            case OP_MASSA:
                printf("Massa\n");
                printf("1 - Libras para quilogramas\n");
                printf("2 - Quilogramas para libras\n");
                printf("0 - Sair\n");
                printf("Opção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de massa se 0 for selecionado
                }
                printf("Digite o valor: \n");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                menuConversao(novo); // Realiza a conversão
                break;

            case OP_COMPRIMENTO:
                printf("Comprimento\n");
                printf("1 - Centímetros para Metros\n");
                printf("2 - Centímetros para Quilômetros\n");
                printf("3 - Metros para Centímetros\n");
                printf("4 - Metros para Quilômetros\n");
                printf("5 - Quilômetros para Centímetros\n");
                printf("6 - Quilômetros para Metros\n");
                printf("0 - Sair\n");
                printf("Opção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de comprimento se 0 for selecionado
                }
                printf("Digite o valor: \n");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf("Erro na conversão!\n");
                }
                break;

            case OP_TEMPO:
                printf("Tempo\n");
                printf("1 - Dias para Horas\n");
                printf("2 - Dias para Minutos\n");
                printf("3 - Horas para Dias\n");
                printf("4 - Horas para Minutos\n");
                printf("5 - Minutos para Dias\n");
                printf("6 - Minutos para Horas\n");
                printf("0 - Sair\n");
                printf("Opção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de tempo se 0 for selecionado
                }
                printf("Digite o valor: \n");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf("Erro na conversão!\n");
                }
                break;
          
            case OP_RELATORIO:
                mostrarHistorico(nomeArquivo);
                break;

            case OP_SAIR:
                break; // Sai do programa

            default:
                printf("Opção inválida!\n");
        }
    }

    return EXIT_SUCCESS;
}

// Menu de opções
int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("Menu\n");
    printf("%d - Temperatura\n", OP_TEMPERATURA);
    printf("%d - Massa\n", OP_MASSA);
    printf("%d - Comprimento\n", OP_COMPRIMENTO);
    printf("%d - Tempo\n", OP_TEMPO);
    printf("%d - Relatório\n", OP_RELATORIO);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opção: ");
    scanf("%d", &op); // Captura a opção do menu principal
    scanf("%*c"); // Limpa o buffer

    return op; // Retorna a opção selecionada
}
