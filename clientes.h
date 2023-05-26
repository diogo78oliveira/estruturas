	#include <stdio.h>
	
	typedef struct registoClientes
	{int NIF_cliente;
	char password_cliente[50];
	char nome_cliente[50]; 
	char morada_cliente[50];
	char email_cliente[50];
	float saldo_cliente;
	char localizacaoC[50];
	struct registo* seguinte;
	} Cliente;


	Cliente* inserirCliente(Cliente* inicio, int NIFc, char passc[], char nomec[], char moradac[], char emailc[], float saldoc, char locCliente); 
	void alterarDados(Cliente* inicio);	
	void listarClientes(Cliente* inicio); 	
	int existeCliente(Cliente* inicio, int NIF_cliente); 	
	Cliente* removerCliente(Cliente* inicio, int NIFc);
	void consultarSaldo(Cliente* inicio);
	Cliente* lerClientes();
	int guardarClientes(Cliente* inicio);
	void adicionarSaldo(Cliente* inicio);
	Cliente* inserirLocCliente(Cliente * inicio, int NIFc, char locCliente[50]);


