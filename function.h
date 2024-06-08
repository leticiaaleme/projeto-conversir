#ifndef FUNCTION_FUNCTION_H
#define FUNCTION_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Estrutura de dados para representar a unidade de conversão
struct unidade {
    int tipoUnidade;    // Tipo de unidade (temperatura, massa, etc.)
    int nomeUnidade;    // Nome específico da unidade (ex. Celsius, Fahrenheits, etc.)
    double valorConversao; // Valor a ser convertido
};

// Constantes para representar as opções do menu
enum {
    OP_NAO_SELECIONADA = 0,
    OP_TEMPERATURA,
    OP_MASSA,
    OP_COMPRIMENTO,
    OP_TEMPO,
    OP_RELATORIO,
    OP_SAIR,
};

// Variável global para armazenar o valor convertido
extern double valorConversao;

// Protótipos das funções
void limparBuffer(); // Função para limpar o buffer do teclado

bool menuConversao(struct unidade inicio); // Função para realizar a conversão com base no tipo de unidade

// Funções de conversão de temperatura
bool temperatura(int opcao, double valor);

double Celsius_Fahrenheits(double valor);

double Celsius_Kelvin(double valor);

double Fahrenheits_Celsius(double valor);

double Fahrenheits_Kelvin(double valor);

double Kelvin_Celsius(double valor);

double Kelvin_Fahrenheits(double valor);

// Funções de conversão de massa
bool massa(int opcao, double valor);

double Libras_para_Quilogramas(double libras);

double Quilogramas_para_Libras(double quilogramas);

// Funções de conversão de comprimento
double Centimetros_para_Metros(double cm);

double Centimetros_para_Quilometros(double cm);

double Metros_para_Centimetros(double metros);

double Metros_para_Quilometros(double metros);

double Quilometros_para_Centimetros(double km);

double Quilometros_para_Metros(double km);

bool comprimento(int opcao, double valor);

// Funções de conversão de tempo
double Dias_para_Horas(double dias);

double Dias_para_Minutos(double dias);

double Horas_para_Dias(double horas);

double Horas_para_Minutos(double horas);

double Minutos_para_Dias(double minutos);

double Minutos_para_Horas(double minutos);

bool tempo(int opcao, double valor);

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Opções de menu
#define OP_NAO_SELECIONADA -1
#define OP_TEMPERATURA 1
#define OP_MASSA 2
#define OP_COMPRIMENTO 3
#define OP_TEMPO 4
#define OP_RELATORIO 5
#define OP_SAIR 0


// Funções de conversão
bool menuConversao(struct unidade novo);
void mostrarHistorico(const char *nomeArquivo);

#endif


#endif // FUNCTION_FUNCTION_H
