#include <stdlib.h>
#include <string.h>
#include "gestores.h"


int guardarGestores(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestoresDados.txt","a");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%s;%s\n",aux->ID_gestor, aux->password, 
	                      aux->nome, aux->morada);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}


Gestor* lerGestores()
{FILE* fp;
 int ID;
 char passg[50], nomeg[50], moradag[50];
 Gestor* aux=NULL;
 fp = fopen("gestoresDados.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%s;%s;%s\n", &ID, &passg, &nomeg, &moradag);
    aux = inserirGestor(aux, ID, passg, nomeg, moradag);
  }
  fclose(fp);
 }
 return(aux);
}

// Inser�ao de um novo gestor
Gestor* inserirGestor(Gestor * inicio, int ID, char passg[], char nomeg[], char moradag[])

{
 if (!existeGestor(inicio, ID)) //verifica se existe um meio com esse c�digo
 
 {Gestor * novo = malloc(sizeof(struct registoGestores));
  
  if (novo != NULL)
  {novo->ID_gestor = ID;				//copiar strings para o novo meio
   strcpy(novo->password,passg);
   strcpy(novo->nome,nomeg);
   strcpy(novo->morada,moradag);
   novo->seguinte = inicio;
   return(novo); //retorna o novo meio
  }
 } else return(inicio);
}


// listar na consola o conteudo da lista ligada
void listarGestores(Gestor* inicio)
	{while (inicio != NULL)
 {printf("%d %s %s %s\n",inicio->ID_gestor,inicio->password, 
		             inicio->nome, inicio->morada);
  inicio = inicio->seguinte;
 }
}

// Determinar existencia do 'username' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contr?rio
int existeGestor(Gestor* inicio, int ID)
{while(inicio!=NULL)
  {if (inicio->ID_gestor == ID) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}


Gestor* removerGestor(Gestor* inicio, int ID) 
{
    Gestor *anterior = NULL;
    Gestor *atual = inicio;

    if (atual == NULL) {
        return NULL;
    }
    else if (atual->ID_gestor == ID) {
        inicio = atual->seguinte;
        free(atual);
        return inicio;
    }
    else {
        while (atual != NULL && atual->ID_gestor != ID) {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL) {
            return inicio;
        }
        else {
            anterior->seguinte = atual->seguinte;
            free(atual);
            return inicio;
        }
    }
}


void alterar_dados(Gestor* inicio) {
	int ID;
    char passg[50];
    char nomeg[50];
    char moradag[50];
    FILE *arquivo;

    // abre o arquivo para leitura e escrita
    arquivo = fopen("gestoresDados.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    printf("Insira o ID : ");
    scanf("%d", &ID);
    int encontrado = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        char *token = strtok(linha, ";");
        if (atoi(token) == ID) {
            encontrado = 1;
            token = strtok(NULL, ";"); //ignora ID       
   	        strcpy(passg, token);
            token = strtok(NULL, ";");
            strcpy(nomeg, token);
            token = strtok(NULL, ";");
            strcpy(moradag, token);
            token = strtok(NULL, ";");
			
			system("cls");
            printf("ID: %d\n", ID);
            printf("Password atual: %s\n", passg);
            printf("Nome atual: %s\n", nomeg);
            printf("Morada atual: %s\n", moradag);
            

            char novaPassg[50], novoNomeg[50], novaMoradag[50];
            
            printf("Insira a nova password:\n");
            scanf("%s", novaPassg);
            printf("Insira o novo nome:\n");
            scanf("%s", novoNomeg);
            printf("Insira a nova morada: \n");
            scanf("%s", novaMoradag);
						
            if (strlen(novaPassg) > 0) {
                strcpy(passg, novaPassg);
                memset(novaPassg, 0, sizeof(novaPassg)); // apaga a nova pass da mem�ria
            }
            if (strlen(novoNomeg) > 0) {
                strcpy(nomeg, novoNomeg);
            }
            if (strlen(novaMoradag) > 0) {
                strcpy(moradag, novaMoradag);
            }

         	rewind(arquivo);
			long int offset = ftell(arquivo) - strlen(linha) - 1;
			fseek(arquivo, offset, SEEK_SET);
			fprintf(arquivo, "%d;%s;%s;%s\n", ID, passg, nomeg, moradag);
			
			printf("Dados atualizados com sucesso");
			break;
		}
}
    // verifica se o cliente foi encontrado
    if (!encontrado) {
        printf("Gestor nao encontrado.\n");
    }

    // fecha o arquivo
    fclose(arquivo);
}






