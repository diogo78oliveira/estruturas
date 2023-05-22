	#include <stdio.h>

	typedef struct registoGestores
	{int ID_gestor;
	char password[50];
	char nome[50];
	char morada[50];
	struct registo* seguinte;
	} Gestor;


	Gestor* inserirGestor(Gestor* inicio, int ID, char passg[], char nomeg[], char moradag[]); // Inser��o de um novo registo
	int existeGestor(Gestor* inicio, int ID_gestor); // Determinar exist�ncia do 'codigo' na lista ligada 'inicio'
	Gestor* removerGestor(Gestor* inicio, int ID); // Remover um gestor a partir do seu c�digo
	void alterar_dados(Gestor* inicio);
	Gestor* lerGestores();
	int guardarGestores(Gestor* inicio);

