#include "function.h"

// Constantes

// Variáveis
double valorConversao;

// Funções


// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void salvarHistorico(const char* tipo, double valorOriginal, double valorConvertido, const char* unidadeOriginal, const char* unidadeConvertida) {
    FILE *file = fopen("historico.txt", "a");
    if (file == NULL) {
        perror(BG_RED "\n\t\tErro ao abrir o arquivo" RESET "\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "[%02d-%02d-%04d %02d:%02d:%02d] %s: %.2lf %s -> %.2lf %s\n",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            tipo, valorOriginal, unidadeOriginal, valorConvertido, unidadeConvertida);

    fclose(file);

}

void mostrarHistorico(const char *nomeArquivo) {
    FILE *arquivo;
    char linha[100]; // Tamanho máximo de uma linha no arquivo

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf(BG_RED "\t\tErro ao abrir o arquivo." RESET "\n\n");
        return;
    } else {
        printf("\t\t\nAqui está o relatório de conversões: \n\n");
    }

    // Lê e imprime cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s\n", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);
}


bool menuConversao(struct unidade inicio) {
    int opcao = inicio.tipoUnidade;
    int nome = inicio.nomeUnidade;
    double valor = inicio.valorConversao;

    switch (opcao) {
        case OP_TEMPERATURA:
            valor = round(valor);

            if (!temperatura(nome, valor)) {
                return false;
            }
            printf(BG_GREEN "\t\tA temperatura convertida equivale a: %.2lf°" RESET "\n\n", valorConversao);
            break;

        case OP_MASSA:
            if (!massa(nome, valor)) {
                return false;
            }
            printf(BG_GREEN "\t\tO valor convertido equivale a: %.2lf" RESET "\n\n", valorConversao);
            break;

        case OP_COMPRIMENTO:
            if (!comprimento(nome, valor)) {
                return false;
            }
            printf(BG_GREEN "\t\tO valor convertido equivale a: %.2lf" RESET "\n\n", valorConversao);
            break;

        case OP_TEMPO:
            if (!tempo(nome, valor)) {
                return false;
            }
            printf(BG_GREEN "\t\tO valor convertido equivale a: %.2lf" RESET "\n\n", valorConversao);
            break;

        case OP_SAIR:
            break;

        default:
            printf(BG_RED "\n\t\tOpção inválida!" RESET "\n\n");
    }
    return true;
}

// Código da função temperatura
bool temperatura(int opcao, double valor) {
    double valorOriginal = valor;

    switch (opcao) {
        case 1:
            valorConversao = Celsius_Fahrenheits(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Celsius", "Fahrenheits");
            break;
        case 2:
            valorConversao = Celsius_Kelvin(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Celsius", "Kelvin");
            break;
        case 3:
            valorConversao = Fahrenheits_Celsius(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Fahrenheits", "Celsius");
            break;
        case 4:
            valorConversao = Fahrenheits_Kelvin(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Fahrenheits", "Kelvin");
            break;
        case 5:
            valorConversao = Kelvin_Celsius(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Kelvin", "Celsius");
            break;
        case 6:
            valorConversao = Kelvin_Fahrenheits(valor);
            salvarHistorico("Temperatura", valorOriginal, valorConversao, "Kelvin", "Fahrenheits");
            break;

        default:
            printf(BG_RED "\t\tOpção inválida!" RESET "\n\n");
            return false;
    }
    return true;
}

// Outras funções

double Celsius_Fahrenheits(double valor) {
    return ((9 * valor + 160) / 5);
}

double Celsius_Kelvin(double valor) {
    return (valor + 273);
}

double Fahrenheits_Celsius(double valor) {
    return ((5 * (valor - 32)) / 9);
}

double Fahrenheits_Kelvin(double valor) {
    return ((5 * valor + 2297) / 9);
}

double Kelvin_Celsius(double valor) {
    return (valor - 273);
}

double Kelvin_Fahrenheits(double valor) {
    return ((9 * valor - 2297) / 5);
}

// Código da função massa
bool massa(int opcao, double valor) {
    double valorOriginal = valor;

    switch (opcao) {
        case 1:
            valorConversao = Libras_para_Quilogramas(valor);
            salvarHistorico("Massa", valorOriginal, valorConversao, "Libras", "Quilogramas");
            break;
        case 2:
            valorConversao = Quilogramas_para_Libras(valor);
            salvarHistorico("Massa", valorOriginal, valorConversao, "Quilogramas", "Libras");
            break;
        default:
            printf(BG_RED "\t\tOpção inválida!" RESET "\n\n");
            return false;
    }
    return true;
}

double Libras_para_Quilogramas(double libras) {
    return libras * 0.453592;
}

double Quilogramas_para_Libras(double quilogramas) {
    return quilogramas / 0.453592;
}

// Código da função comprimento
bool comprimento(int opcao, double valor) {
    double valorOriginal = valor;

    switch (opcao) {
        case 1:
            valorConversao = Centimetros_para_Metros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Centímetros", "Metros");
            break;
        case 2:
            valorConversao = Centimetros_para_Quilometros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Centímetros", "Quilômetros");
            break;
        case 3:
            valorConversao = Metros_para_Centimetros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Metros", "Centímetros");
            break;
        case 4:
            valorConversao = Metros_para_Quilometros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Metros", "Quilômetros");
            break;
        case 5:
            valorConversao = Quilometros_para_Centimetros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Quilômetros", "Centímetros");
            break;
        case 6:
            valorConversao = Quilometros_para_Metros(valor);
            salvarHistorico("Comprimento", valorOriginal, valorConversao, "Quilômetros", "Metros");
            break;
        default:
            printf(BG_RED "\t\tOpção inválida!" RESET "\n\n");
            return false;
    }
    return true;
}

double Centimetros_para_Metros(double cm) {
    return cm / 100.0;
}

double Centimetros_para_Quilometros(double cm) {
    return cm / 100000.0;
}

double Metros_para_Centimetros(double metros) {
    return metros * 100.0;
}

double Metros_para_Quilometros(double metros) {
    return metros / 1000.0;
}

double Quilometros_para_Centimetros(double km) {
    return km * 100000.0;
}

double Quilometros_para_Metros(double km) {
    return km * 1000.0;
}

// Código da função tempo

double Dias_para_Horas(double dias) {
    return dias * 24.0;
}

double Dias_para_Minutos(double dias) {
    return dias * 1440.0;
}

double Horas_para_Dias(double horas) {
    return horas / 24.0;
}

double Horas_para_Minutos(double horas) {
    return horas * 60.0;
}

double Minutos_para_Dias(double minutos) {
    return minutos / 1440.0;
}

double Minutos_para_Horas(double minutos) {
    return minutos / 60.0;
}


bool tempo(int opcao, double valor) {
    double valorOriginal = valor;

    switch (opcao) {
        case 1:
            valorConversao = Dias_para_Horas(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Dias", "Horas");
            break;
        case 2:
            valorConversao = Dias_para_Minutos(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Dias", "Minutos");
            break;
        case 3:
            valorConversao = Horas_para_Dias(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Horas", "Dias");
            break;
        case 4:
            valorConversao = Horas_para_Minutos(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Horas", "Minutos");
            break;
        case 5:
            valorConversao = Minutos_para_Dias(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Minutos", "Dias");
            break;
        case 6:
            valorConversao = Minutos_para_Horas(valor);
            salvarHistorico("Tempo", valorOriginal, valorConversao, "Minutos", "Horas");
            break;
        default:
            printf(BG_RED "\t\tOpção inválida!" RESET "\n\n");
            return false;
    }
    return true;
}