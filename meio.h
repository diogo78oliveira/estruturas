	#include <stdio.h>
	
	typedef struct registo
	{int codigo; // c�digo do meio de mobilidade el�trica
	 char tipo[50];
	 float bateria;
	 float autonomia;
	 float preco;
	 int disponivel;
	 char geocodigo[3][30];
	 char localizacao[50];
	 struct registo* seguinte;
	} Meio;


	Meio* inserirMeio(Meio* inicio, int cod, float bat, float aut, char tipo[], float prec, char geo[][30], char locMeio[50]); // Inser��o de um novo registo
	void listarMeios(Meio* inicio); // listar na consola o conte�do da lista ligada
	int existeMeio(Meio* inicio, int codigo); // Determinar exist�ncia do 'codigo' na lista ligada 'inicio'
	Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu c�digo

	int guardarMeios(Meio* inicio);
	Meio* lerMeios();
	void listarMeiosPorAutonomiaDecrescente(Meio* inicio);
	Meio* encontrar_meio(Meio* inicio, int codigo);
	float alugarMeio(Meio* inicio, int codigo);
	void devolverMeio(Meio* inicio, int codigo);
	void listar_meios_por_geocodigo(Meio* inicio);

