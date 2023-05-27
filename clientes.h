	#include <stdio.h>
	
	typedef struct registoClientes
	{int NIF_cliente;
	char password_cliente[50];
	char nome_cliente[50]; 
	float saldo_cliente;
	struct registo* seguinte;
	} Cliente;


	Cliente* inserirCliente(Cliente* inicio, int NIFc, char passc[], float saldoc); 
	//void alterarDados(Cliente* inicio);	
	void listarClientes(Cliente* inicio); 	
	int existeCliente(Cliente* inicio, int NIF_cliente); 	
	Cliente* removerCliente(Cliente* inicio, int NIFc);
	void consultarSaldo(Cliente* inicio);
	Cliente* lerClientes();
	int guardarClientes(Cliente* inicio);
	void adicionarSaldo(Cliente* inicio);


