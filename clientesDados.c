#include <stdlib.h>
#include <string.h>
#include "clientesDados.h"

int guardardadosClientes(dadosCliente* inicio)
{FILE* fp;
 fp = fopen("ClientesDados.txt","w");
 if (fp!=NULL)
 {
 dadosCliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%s;%s;%s;%s\n", aux->NIF_cliente, aux->password_cliente, 
	                      aux->nome_cliente, aux->morada_cliente, aux->email_cliente, aux->localizacao_cliente);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

// Inser??o de um novo registo
dadosCliente* inserirdadosCliente(dadosCliente * inicio, int NIFc, char passc[], char nomec[], char moradac[], char emailc[], char locC[]){
 if (!existedadosCliente(inicio, NIFc)) {
        dadosCliente* novo = malloc(sizeof(struct InserirdadosClientes));
        if (novo != NULL) {
        	novo->NIF_cliente= NIFc;
        	strcpy(novo->password_cliente, passc);
			strcpy(novo->nome_cliente, nomec);
			strcpy(novo->morada_cliente, moradac);
			strcpy(novo->email_cliente, emailc);
			strcpy(novo->localizacao_cliente, locC);
   			novo->seguinte = inicio;
   return(novo); //retorna o novo meio
  }
 } else return(inicio);
}


dadosCliente* lerdadosClientes()
{FILE* fp;
 int NIFc;
 char passc[50];
 char nomec[50];
 char moradac[50];
 char emailc[50];
 char locC[50];
 
 dadosCliente* aux=NULL;
 fp = fopen("ClientesDados.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%s;%s;%s;%s;%s\n", &NIFc, &passc, &nomec, &moradac, &emailc, &locC);
    aux = inserirdadosCliente(aux, NIFc, passc, nomec, moradac, emailc, locC);
  }
  fclose(fp);
 }
 return(aux);
}

int existedadosCliente(dadosCliente* inicio, int NIFc)
{while(inicio!=NULL)
  {if (inicio->NIF_cliente == NIFc) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

void alterarDados(dadosCliente *inicio) {
    int NIFc;
    char passc[50], nomec[50], moradac[50], emailc[50], locC[50];
    FILE *arquivo;

    // abre o arquivo para leitura e escrita
    arquivo = fopen("ClientesDados.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    printf("Insira o seu NIF : ");
    scanf("%d", &NIFc);
    int encontrado = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        char *token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            token = strtok(NULL, ";"); //ignora NIF
   	        strcpy(passc, token);
            token = strtok(NULL, ";");
            strcpy(nomec, token);
            token = strtok(NULL, ";");
            strcpy(moradac, token);
            token = strtok(NULL, ";");
            strcpy(emailc, token);
            token = strtok(NULL, ";");
            strcpy(locC, token);
            token = strtok(NULL, ";");
            
            printf("Password atual: %s\n", passc);
            printf("Nome atual: %s\n", nomec);
            printf("Morada atual: %s\n", moradac);
            printf("Email atual: %s\n", emailc);
			printf("Localizacao atual: %s\n", locC);  
			
            char novaPass[50], novoNome[50], novaMorada[50], novoEmail[50], novaLoc[50];

            printf("Insira a nova password:\n");
            scanf("%s", novaPass);
            printf("Insira o novo nome:\n");
            scanf("%s", novoNome);
            printf("Insira a nova morada:\n");
            scanf("%s", novaMorada);
            printf("Insira o novo email:\n");
            scanf("%s", novoEmail);
            printf("Insira a nova Localizacao:\n");
            scanf("%s", novaLoc);

            if (strlen(novaPass) > 0) {
                strcpy(passc, novaPass);
            }
            if (strlen(novoNome) > 0) {
                strcpy(nomec, novoNome);
            }
            if (strlen(novaMorada) > 0) {
                strcpy(moradac, novaMorada);
            }
            if (strlen(novoEmail) > 0) {
                strcpy(emailc, novoEmail);
            }
             if (strlen(novaLoc) > 0) {
                strcpy(locC, novaLoc);
            }

         	rewind(arquivo);
			long int offset = ftell(arquivo) - strlen(linha) - 1;
			fseek(arquivo, offset, SEEK_SET);
			fprintf(arquivo, "%d;%s;%s;%s;%s;%s\n", NIFc, passc, nomec, moradac, emailc, locC);
			memset(passc, 0, sizeof(passc));
			printf("Dados atualizados com sucesso\n");
			break;
		}
}
    // verifica se o cliente foi encontrado
    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    // fecha o arquivo
    fclose(arquivo);
}


void verdadosCliente(dadosCliente* inicio) {
    int NIFc;
    printf("Insira o NIF: ");
    scanf("%d", &NIFc);

    // Abre o arquivo para leitura
    FILE* arquivo = fopen("ClientesDados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int encontrado = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        char *token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            token = strtok(NULL, ";"); // Ignora NIF
            char passc[50], nomec[50], moradac[50], emailc[50], locC[50];
            strcpy(passc, token);
            token = strtok(NULL, ";");
            strcpy(nomec, token);
            token = strtok(NULL, ";");
            strcpy(moradac, token);
            token = strtok(NULL, ";");
            strcpy(emailc, token);
            token = strtok(NULL, ";");
            strcpy(locC, token);
            token = strtok(NULL, ";");

            printf("Dados, NIF %d:\n", NIFc);
            printf("Password: %s\n", passc);
            printf("Nome: %s\n", nomec);
            printf("Morada: %s\n", moradac);
            printf("Email: %s\n", emailc);
            printf("Localizacao: %s\n", locC);
            break;
        }
    }

    // Verifica se o cliente foi encontrado
    if (!encontrado) {
        printf("Cliente com NIF %d nao encontrado.\n", NIFc);
    }

    // Fecha o arquivo
    fclose(arquivo);
}



