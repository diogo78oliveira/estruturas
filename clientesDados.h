#include <stdio.h>
#ifndef DADOSCLIENTES_H
#define DADOSCLIENTES_H

typedef struct InserirdadosClientes {
    int NIF_cliente;
    char password_cliente[50];
    char nome_cliente[50];
    char morada_cliente[50];
    char email_cliente[50];
    int localizacao_cliente;
	char localizacaoCliente[50]; 
    struct InserirdadosClientes* seguinte;
} dadosCliente;

dadosCliente* inserirdadosCliente(dadosCliente* inicio, int NIFc, char passc[], char nomec[], char moradac[], char emailc[], int locC);
int converterLocalizacao(char localizacaoCliente[]);
int guardardadosClientes(dadosCliente* inicio);
dadosCliente* lerdadosClientes();

int existedadosCliente(dadosCliente* inicio, int NIFc);
void listardadosClientes(dadosCliente* inicio);
void alterarDados(dadosCliente* inicio);
void verdadosCliente(dadosCliente* inicio);

#endif /* DADOSCLIENTES_H */

