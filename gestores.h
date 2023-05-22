	#include <stdio.h>

	typedef struct registoGestores
	{int ID_gestor;
	char password[50];
	char nome[50];
	char morada[50];
	struct registo* seguinte;
	} Gestor;


	Gestor* inserirGestor(Gestor* inicio, int ID, char passg[], char nomeg[], char moradag[]); // Inserção de um novo registo
	int existeGestor(Gestor* inicio, int ID_gestor); // Determinar existência do 'codigo' na lista ligada 'inicio'
	Gestor* removerGestor(Gestor* inicio, int ID); // Remover um gestor a partir do seu código
	void alterar_dados(Gestor* inicio);
	Gestor* lerGestores();

