	#include <stdio.h>
	
	typedef struct InserirdadosClientes
	{int NIF_cliente;
	char password_cliente[50];
	char nome_cliente[50]; 
	char morada_cliente[50];
	char email_cliente[50];
	char localizacao_cliente[50];
	struct registo* seguinte;
	} dadosCliente;


	dadosCliente* inserirdadosCliente(dadosCliente* inicio, int NIFc, char passc[], char nomec[], char moradac[], char emailc[], char locC[]); 
	void alterarDados(dadosCliente* inicio);	
	int existedadosCliente(dadosCliente* inicio, int NIF_cliente); 	
	dadosCliente* removerdadosCliente(dadosCliente* inicio, int NIFc);
	dadosCliente* lerdadosClientes();
	int guardardadosClientes(dadosCliente* inicio);
	void verdadosCliente(dadosCliente* inicio);

