#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clientesDados.h"

dadosCliente* inserirdadosCliente(dadosCliente* inicio, int NIFc, char passc[], char nomec[], char moradac[], char emailc[], int locC) {
    if (!existedadosCliente(inicio, NIFc)) {
        dadosCliente* novo = malloc(sizeof(struct InserirdadosClientes));
        if (novo != NULL) {
            novo->NIF_cliente = NIFc;
            strcpy(novo->password_cliente, passc);
            strcpy(novo->nome_cliente, nomec);
            strcpy(novo->morada_cliente, moradac);
            strcpy(novo->email_cliente, emailc);
            novo->localizacao_cliente = locC;
            novo->seguinte = inicio;

            return novo;
        }
    } else {
        return inicio;
    }
}

int converterLocalizacao(char localizacaoCliente[]) {
    // Mapear o texto da localização para um número aleatório entre 1 e 100
    srand(time(NULL));  // Inicializar a semente para geração de números aleatórios
    int numLocalizacao = (rand() % 100) + 1;
    return numLocalizacao;
}

int guardardadosClientes(dadosCliente* inicio) {
    FILE* fp;
    fp = fopen("ClientesDados.txt", "a");
    if (fp != NULL) {
        dadosCliente* aux = inicio;
        while (aux != NULL) {
            fprintf(fp, "%d;%s;%s;%s;%s;%d\n", aux->NIF_cliente, aux->password_cliente,
                aux->nome_cliente, aux->morada_cliente, aux->email_cliente, aux->localizacao_cliente);
            aux = aux->seguinte;
        }
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

dadosCliente* lerdadosClientes() {
    FILE* fp;
    int NIFc;
    char passc[50];
    char nomec[50];
    char moradac[50];
    char emailc[50];
    int locC;

    dadosCliente* aux = NULL;
    fp = fopen("ClientesDados.txt", "r");
    if (fp != NULL) {
        while (!feof(fp)) {
            fscanf(fp, "%d;%s;%s;%s;%s;%d\n", &NIFc, passc, nomec, moradac, emailc, &locC);
            aux = inserirdadosCliente(aux, NIFc, passc, nomec, moradac, emailc, locC);
        }
        fclose(fp);
    }
    return aux;
}

int existedadosCliente(dadosCliente* inicio, int NIFc) {
    while (inicio != NULL) {
        if (inicio->NIF_cliente == NIFc) {
            return 1;
        }
        inicio = inicio->seguinte;
    }
    return 0;
}

void listardadosClientes(dadosCliente* inicio) {
    while (inicio != NULL) {
        printf("%d %s %s %s %s %d\n", inicio->NIF_cliente, inicio->password_cliente,
            inicio->nome_cliente, inicio->morada_cliente, inicio->email_cliente, inicio->localizacao_cliente);
        inicio = inicio->seguinte;
    }
}

void alterarDados(dadosCliente* inicio) {
    int NIFc;
    char passc[50], nomec[50], moradac[50], emailc[50];
    int locC;
    FILE* arquivo;

    // Abre o arquivo para leitura e escrita
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
        char* token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            token = strtok(NULL, ";"); // Ignora NIF
            strcpy(passc, token);
            token = strtok(NULL, ";");
            strcpy(nomec, token);
            token = strtok(NULL, ";");
            strcpy(moradac, token);
            token = strtok(NULL, ";");
            strcpy(emailc, token);
            token = strtok(NULL, ";");
            locC = atoi(token);

            printf("Password atual: %s\n", passc);
            printf("Nome atual: %s\n", nomec);
            printf("Morada atual: %s\n", moradac);
            printf("Email atual: %s\n", emailc);
            printf("Localizacao atual: %d\n", locC);

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
                locC = atoi(novaLoc);
            }

            fseek(arquivo, -(strlen(linha)), SEEK_CUR);
            fprintf(arquivo, "%d;%s;%s;%s;%s;%d\n", NIFc, passc, nomec, moradac, emailc, locC);
            printf("Dados alterados com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("NIF não encontrado.\n");
    }

    fclose(arquivo);
}

void verdadosCliente(dadosCliente* inicio) {
    int NIFc;
    char passc[50], nomec[50], moradac[50], emailc[50];
    int locC;
    FILE* arquivo;

    // Abre o arquivo para leitura e escrita
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
        char* token = strtok(linha, ";");
        if (atoi(token) == NIFc) {
            encontrado = 1;
            token = strtok(NULL, ";"); // Ignora NIF
            strcpy(passc, token);
            token = strtok(NULL, ";");
            strcpy(nomec, token);
            token = strtok(NULL, ";");
            strcpy(moradac, token);
            token = strtok(NULL, ";");
            strcpy(emailc, token);
            token = strtok(NULL, ";");
            locC = atoi(token);

            printf("NIF: %d\n", NIFc);
            printf("Password: %s\n", passc);
            printf("Nome: %s\n", nomec);
            printf("Morada: %s\n", moradac);
            printf("Email: %s\n", emailc);
            printf("Localizacao: %d\n", locC);

            break;
        }
    }

    if (!encontrado) {
        printf("NIF não encontrado.\n");
    }

    fclose(arquivo);
}

