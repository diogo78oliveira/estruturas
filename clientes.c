#include <stdlib.h>
#include <string.h>
#include "clientes.h"

// Inser??o de um novo registo
Cliente* inserirCliente(Cliente * inicio, int NIFc, char passc[], char nomec[],char moradac[], char emailc[], float saldoc){
 if (!existeCliente(inicio, NIFc)) {
        Cliente* novo = malloc(sizeof(struct registoClientes));
        if (novo != NULL) {
        	novo->NIF_cliente= NIFc;
        	strcpy(novo->password_cliente, passc);
        	strcpy(novo->nome_cliente, nomec);
            strcpy(novo->morada_cliente, moradac);
            strcpy(novo->email_cliente, emailc);
			novo->saldo_cliente= saldoc;	
   			novo->seguinte = inicio;

            FILE* fp;
            fp = fopen("dadosClientes.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "%d;%s;%s;%s;%s;%f\n", novo->NIF_cliente,novo->password_cliente, novo->nome_cliente, novo->morada_cliente, novo->email_cliente, novo->saldo_cliente);
                fclose(fp);
            } else {
                printf("Erro\n");
            }
            return novo;
        }
    } else {
        return inicio;
    }
}

// listar na consola o conte?do da lista ligada
void listarClientes(Cliente * inicio)
{while (inicio != NULL)
 {printf("%d %s %s %s %.2f\n",inicio->NIF_cliente,inicio->nome_cliente, 
		             inicio->morada_cliente, inicio->email_cliente, inicio->saldo_cliente);
  inicio = inicio->seguinte;
 }
}
// Determinar exist?ncia do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contr?rio
int existeCliente(Cliente* inicio, int NIFc)
{while(inicio!=NULL)
  {if (inicio->NIF_cliente == NIFc) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

<<<<<<< HEAD
Cliente* encontrar_cliente(Cliente* inicio, int NIFc) {
    // Cria um ponteiro chamado "meio" e inicializa com o ponteiro para o inï¿½cio da lista.
    Cliente* cliente = inicio;
    // Loop enquanto "meio" nï¿½o ï¿½ nulo (ou seja, ainda hï¿½ elementos na lista).
    while (cliente != NULL) {
        // Verifica se o cï¿½digo do elemento atual ï¿½ igual ao cï¿½digo buscado.
        if (cliente->NIF_cliente == NIFc) {
            // Se for igual, retorna o ponteiro para o elemento atual.
            return cliente;
        }
        // Se o cï¿½digo nï¿½o for igual, avanï¿½a para o prï¿½ximo elemento da lista.
        cliente = cliente->seguinte;
    }
    // Se nï¿½o encontrar um elemento com o cï¿½digo buscado, retorna nulo.
    return NULL;


}

=======
>>>>>>> parent of ac16e1a (dsadsa)
void consultarSaldo(Cliente * inicio)
{	
	int NIFc;
    FILE *arquivo;

    // abre o arquivo para leitura e escrita
    arquivo = fopen("dadosClientes.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // procura o cliente com o NIF informado no arquivo
    printf("Insira o seu NIF : ");
    scanf("%d", &NIFc);
    int encontrado = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        char *token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            
            token = strtok(NULL, ";"); //ignora NIF
            token = strtok(NULL, ";"); // ignora  senha
            token = strtok(NULL, ";"); // ignora  nome
            token = strtok(NULL, ";"); // ignora  morada
            token = strtok(NULL, ";"); // ignora email
            float saldoc = atof(token);
            printf("Saldo atual: %.2f\n", saldoc);	
            // verifica se o cliente foi encontrado
    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }


    // fecha o arquivo
    fclose(arquivo);	
} 
}
}
					
void adicionarSaldo(Cliente *inicio, int NIFc) {
    FILE *arquivo;

    // abre o arquivo para leitura e escrita
    arquivo = fopen("dadosClientes.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

<<<<<<< HEAD
    // Encontra o cliente com o NIF informado
    Cliente* cliente = encontrar_cliente(inicio, NIFc);
    if (cliente != NULL) {
        // Exibe o saldo atual
        printf("Saldo atual: %.2f\n", cliente->saldo_cliente);

        // Solicita ao usuÃ¡rio o valor a ser adicionado
        float novoSaldo;
        printf("Insira quanto saldo quer inserir : ");
        scanf("%f", &novoSaldo);
=======
    // procura o cliente com o NIF informado no arquivo
    printf("Insira o seu NIF : ");
    scanf("%d", &NIFc);
    int encontrado = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        char *token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            // lê o saldo atual e atualiza no arquivo
            token = strtok(NULL, ";"); //ignora NIF
            token = strtok(NULL, ";"); // ignora  senha
            token = strtok(NULL, ";"); // ignora  nome
            token = strtok(NULL, ";"); // ignora  morada
            token = strtok(NULL, ";"); // ignora email
            float saldoc = atof(token);
            printf("Saldo atual: %.2f\n", saldoc);

            // pede ao usuário o valor a ser adicionado
            float novoSaldo;
            printf("Insira quanto saldo quer inserir : ");
            scanf("%f", &novoSaldo);
>>>>>>> parent of ac16e1a (dsadsa)

        // Atualiza o saldo do cliente
        cliente->saldo_cliente += novoSaldo;

        // Volta para o inÃ­cio do arquivo
        rewind(arquivo);

        // Atualiza o valor do saldo no arquivo
        char linha[100];
        while (fgets(linha, 100, arquivo) != NULL) {
            char *token = strtok(linha, ";");
            if (atoi(token) == NIFc) {
                fseek(arquivo, -strlen(token) - 1, SEEK_CUR);
                fprintf(arquivo, "%d;%s;%s;%s;%s;%.2f\n", cliente->NIF_cliente, cliente->password_cliente,
                        cliente->nome_cliente, cliente->morada_cliente, cliente->email_cliente, cliente->saldo_cliente);
                break;
            }
        }

        printf("Saldo atualizado com sucesso\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }

    // fecha o arquivo
    fclose(arquivo);
}

void alterarDados(Cliente *inicio) {
    int NIFc;
    char passc[50], nomec[50], moradac[50], emailc[50];
    float saldoc;
    FILE *arquivo;

    // abre o arquivo para leitura e escrita
    arquivo = fopen("dadosClientes.txt", "r+");

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
            
            printf("Password atual: %s\n", passc);
            printf("Nome atual: %s\n", nomec);
            printf("Morada atual: %s\n", moradac);
            printf("Email atual: %s\n", emailc); 
			saldoc = atof(token); 
			printf("Saldo atual: %.2f\n", saldoc); 
            char novaPass[50], novoNome[50], novaMorada[50], novoEmail[50];

            printf("Insira a nova password:\n");
            scanf("%s", novaPass);
            printf("Insira o novo nome:\n");
            scanf("%s", novoNome);
            printf("Insira a nova morada:\n");
            scanf("%s", novaMorada);
            printf("Insira o novo email:\n");
            scanf("%s", novoEmail);

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

         	rewind(arquivo);
			long int offset = ftell(arquivo) - strlen(linha) - 1;
			fseek(arquivo, offset, SEEK_SET);
			fprintf(arquivo, "%d;%s;%s;%s;%s;%.2f\n", NIFc, passc, nomec, moradac, emailc, saldoc);
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







