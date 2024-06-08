#include "function.h"
#include "menu.h"




// Protótipos


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
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\tTemperatura" RESET "                 ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf(RED "\t\t\t\t!Atenção!\n");
                printf("\tNa escala Kelvin, teoricamente não existem  \n");
                printf("\tvalores negativos, entretanto a fins de \n");
                printf("\tcuriosidade, as conversões para esses valores\n");
                printf("\tainda serão feitas." RESET "\n\n");
                printf("\t\t1 - Celsius para Fahrenheits\n");
                printf("\t\t2 - Celsius para Kelvin\n");
                printf("\t\t3 - Fahrenheits para Celsius\n");
                printf("\t\t4 - Fahrenheits para Kelvin\n");
                printf("\t\t5 - Kelvin para Celsius\n");
                printf("\t\t6 - Kelvin para Fahrenheits\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                aux = capturarInteiro(); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de temperatura se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                aux2 = capturarDouble(); // Captura o valor a ser convertido
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                    break;
                }
                break;

            case OP_MASSA:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tMassa" RESET "                   ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Libras para quilogramas\n");
                printf("\t\t2 - Quilogramas para libras\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                aux = capturarInteiro(); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de massa se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                aux2 = capturarDouble(); // Captura o valor a ser convertido
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                menuConversao(novo); // Realiza a conversão
                break;

            case OP_COMPRIMENTO:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tDistâncias" RESET "              ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Centímetros para Metros\n");
                printf("\t\t2 - Centímetros para Quilômetros\n");
                printf("\t\t3 - Metros para Centímetros\n");
                printf("\t\t4 - Metros para Quilômetros\n");
                printf("\t\t5 - Quilômetros para Centímetros\n");
                printf("\t\t6 - Quilômetros para Metros\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                aux = capturarInteiro(); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de comprimento se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                aux2 = capturarDouble(); // Captura o valor a ser convertido
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                }
                break;

            case OP_TEMPO:
                printf("\n");
                printf("==============================================");
                printf("\n||" BMAGENTA "\t\t\t\t\tTempo" RESET "                   ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
                printf("\t\t1 - Dias para Horas\n");
                printf("\t\t2 - Dias para Minutos\n");
                printf("\t\t3 - Horas para Dias\n");
                printf("\t\t4 - Horas para Minutos\n");
                printf("\t\t5 - Minutos para Dias\n");
                printf("\t\t6 - Minutos para Horas\n");
                printf("\t\t0 - Sair\n\n");
                printf(BOLD "\t\tOpção:" RESET " ");
                aux = capturarInteiro(); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de tempo se 0 for selecionado
                }
                printf(BOLD "\t\tDigite o valor a ser convertido:" RESET " ");
                aux2 = capturarDouble(); // Captura o valor a ser convertido
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                if (!menuConversao(novo)) { // Realiza a conversão e verifica erros
                    printf(BG_RED "\t\tErro na conversão!" RESET "\n");
                }
                break;

            case OP_RELATORIO:
                mostrarHistorico(nomeArquivo);
                break;

            case OP_SAIR:
                break; // Sai do programa

            default:
                printf("\n" BG_RED "\t\t\tOpção inválida!" RESET "\n\n");
        }
    }

    return EXIT_SUCCESS;
}

