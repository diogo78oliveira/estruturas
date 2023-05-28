	#include <stdio.h>
	
	typedef struct registo
	{int codigo; // código do meio de mobilidade elétrica
	 char tipo[50];
	 float bateria;
	 float autonomia;
	 float preco;
	 int disponivel;
	 char geocodigo[3][30];
	 int localizacao;
	 char loalizacaoMeio[50];
	 struct registo* seguinte;
	} Meio;


	Meio* inserirMeio(Meio* inicio, int cod, float bat, float aut, char tipo[], float prec, char geo[][30], int locM); // Inserção de um novo registo
	void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
	int existeMeio(Meio* inicio, int codigo); // Determinar existência do 'codigo' na lista ligada 'inicio'
	Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu código
	int converterLocalizacaoMeio(char localizacaoMeio[])
	int guardarMeios(Meio* inicio);
	Meio* lerMeios();
	void listarMeiosPorAutonomiaDecrescente(Meio* inicio);
	Meio* encontrar_meio(Meio* inicio, int codigo);
	float alugarMeio(Meio* inicio, int codigo, float saldoc);
	void devolverMeio(Meio* inicio, int codigo);
	void listar_meios_por_geocodigo(Meio* inicio);

