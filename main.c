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
                printf("==============================================");
                printf("\n||\t\t\t\tTemperatura                 ||\n");
                printf("||\t\tEscolha uma opção de conversão:     ||\n");
                printf("==============================================\n\n");
              //Deixar o aviso ou não?
                printf("\t\t\t\t!Atenção!\n");
                printf("\tNa escala Kelvin, teoricamente não existem  \n");
                printf("\tvalores negativos, entretanto a fins de \n");
                printf("\tcuriosidade, as conversões para esses valores\n");
                printf("\tainda serão feitas.\n\n");
              //^^^^^^
                printf("\t\t1 - Celsius para Fahrenheits\n");
                printf("\t\t2 - Celsius para Kelvin\n");
                printf("\t\t3 - Fahrenheits para Celsius\n");
                printf("\t\t4 - Fahrenheits para Kelvin\n");
                printf("\t\t5 - Kelvin para Celsius\n");
                printf("\t\t6 - Kelvin para Fahrenheits\n");
                printf("\t\t0 - Sair\n\n");
                printf("\t\tOpção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de temperatura se 0 for selecionado
                }
                printf("\t\tDigite o valor a ser convertido: ");
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
              printf("==============================================");
              printf("\n||\t\t\t\t\tMassa                   ||\n");
              printf("||\t\tEscolha uma opção de conversão:     ||\n");
              printf("==============================================\n\n");
                printf("\t\t1 - Libras para quilogramas\n");
                printf("\t\t2 - Quilogramas para libras\n");
                printf("\t\t0 - Sair\n\n");
                printf("\t\tOpção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de massa se 0 for selecionado
                }
                printf("\t\tDigite o valor a ser convertido: ");
                scanf("%lf", &aux2); // Captura o valor a ser convertido
                limparBuffer(); // Limpa o buffer do teclado
                novo.tipoUnidade = opcao;
                novo.nomeUnidade = aux;
                novo.valorConversao = aux2;
                menuConversao(novo); // Realiza a conversão
                break;

            case OP_COMPRIMENTO:
              printf("==============================================");
              printf("\n||\t\t\t\t\tDistâncias              ||\n");
              printf("||\t\tEscolha uma opção de conversão:     ||\n");
              printf("==============================================\n\n");
                printf("\t\t1 - Centímetros para Metros\n");
                printf("\t\t2 - Centímetros para Quilômetros\n");
                printf("\t\t3 - Metros para Centímetros\n");
                printf("\t\t4 - Metros para Quilômetros\n");
                printf("\t\t5 - Quilômetros para Centímetros\n");
                printf("\t\t6 - Quilômetros para Metros\n");
                printf("\t\t0 - Sair\n\n");
                printf("\t\tOpção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de comprimento se 0 for selecionado
                }
                printf("\t\tDigite o valor a ser convertido: ");
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
              printf("==============================================");
              printf("\n||\t\t\t\t\tTempo                   ||\n");
              printf("||\t\tEscolha uma opção de conversão:     ||\n");
              printf("==============================================\n\n");
                printf("\t\t1 - Dias para Horas\n");
                printf("\t\t2 - Dias para Minutos\n");
                printf("\t\t3 - Horas para Dias\n");
                printf("\t\t4 - Horas para Minutos\n");
                printf("\t\t5 - Minutos para Dias\n");
                printf("\t\t6 - Minutos para Horas\n");
                printf("\t\t0 - Sair\n\n");
                printf("\t\tOpção: ");
                scanf("%d", &aux); // Captura a sub-opção
                if (aux == 0) {
                    break; // Sai do caso de tempo se 0 for selecionado
                }
                printf("\t\tDigite o valor a ser convertido: ");
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
  
  printf("\t\t===========================\n");
  printf("\t\t||Bem vindo ao ConverSir!||\n");
  printf("\t\t===========================\n\n");
  printf("==============================================\n");
  printf("||Converta grandezas de maneira simples.    ||\n");
  printf("||Selecione a grandeza que deseja converter:||\n");
  printf("==============================================\n\n");
  printf("\t\t\t\t*** Menu ***\n\n");
  printf("\t\t\t %d - Temperatura\n", OP_TEMPERATURA);
  printf("\t\t\t %d - Massa\n", OP_MASSA);
  printf("\t\t\t %d - Distância\n ", OP_COMPRIMENTO);
  printf("\t\t\t %d - Tempo\n", OP_TEMPO);
  printf("\t\t\t %d - Gerar Relatório\n", OP_RELATORIO);
  printf("\t\t\t %d - Sair\n\n", OP_SAIR);
  printf("\t\t\tDigite sua opção: ");
    scanf("%d", &op); // Captura a opção do menu principal
    scanf("%*c"); // Limpa o buffer

    return op; // Retorna a opção selecionada
}