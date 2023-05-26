#include <stdio.h>
#include "meio.h"
#include "clientes.h"
#include "gestores.h"
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MAX_LINHA_LEN 20

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Clientes;

void registar_cliente() {
	{Cliente* clientes = NULL;
			 int NIFc;
			 char passc[50];
			 char nomec[50];
			 char moradac[50];
			 char emailc[50];
			 float saldoc;
			printf("NIF?\n");
            scanf("%d",&NIFc);
            scanf("%c");
            printf("Password?\n");
            scanf("%s",&passc);
            printf("Nome?\n");
	   		scanf("%s",&nomec);
	   		printf("Morada?\n");
	   		scanf("%s",&moradac);
	   		printf("Email?\n");
	   		scanf("%s",&emailc);
           	clientes = inserirCliente(clientes,NIFc,passc,nomec,moradac,emailc,saldoc);
           	printf("Cliente Registado com sucesso");
           	
           }
       }
       
void login_cliente() {
    int NIFc[MAX_USERNAME_LEN], passc[MAX_PASSWORD_LEN];
    printf("=== Login de Cliente ===\n");
    printf("Insira o seu NIF: ");
    scanf("%s", NIFc);
    printf("Insira a senha: ");
    scanf("%s", passc);

    FILE* arquivo;
    arquivo = fopen("dadosClientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de gestores!\n");
    }
    char linha[MAX_LINHA_LEN];
    while (fgets(linha, MAX_LINHA_LEN, arquivo) != NULL) {
        char* token = strtok(linha, ";");
        char* NIF_cliente = token;
        token = strtok(NULL, ";");
        char* password_cliente = token;
        if (strcmp(NIF_cliente, NIFc) == 0 && strcmp(password_cliente, passc) == 0) {
        	
            printf("Login realizado com sucesso!\n");
            system("cls");
            printf("========== MENU DO CLIENTE ==========\n");
            printf("1 - Alterar Dados\n");
            printf("2 - Adicionar saldo\n");
            printf("3 - Consultar saldo\n");
            printf("4 - Ver meios disponiveis\n");
            printf("5 - Alugar um meio\n");
            printf("6 - Devolver meio\n");
            printf("0 - Sair\n");
            
            {Cliente* clientes = NULL;
            Cliente * inicio = NULL;
            Meio* meios = NULL;
            int opcao,NIFc;
            int saldoc;
            char nomec[50];
			char moradac[50];
			char emailc[50];
			int cod,codigo;
			float bat, aut;
			char tipo[50];
            do {
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                    	system("cls");
                        alterarDados(clientes);
                        break;
                    case 2:
                        adicionarSaldo(clientes);
                        break;
                    case 3:
                        consultarSaldo(clientes);
						break;            
					case 4:
						meios = lerMeios();
						listarMeios(meios);
						break;
					case 5:
					    printf("Insira o codigo do meio de mobilidade eletrica que deseja alugar: ");
                    	scanf("%d", &codigo);
                       	alugarMeio(meios, codigo);break;
					case 6:
						devolverMeio(meios, codigo);break;						
                    case 0:
                        printf("Logout realizado com sucesso!\n");
                        system("cls");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
		 }
            }  while (opcao != 0);
         
 			fclose(arquivo);
            return;
        }
		}
	}	
    printf("Username ou senha invalidos!\n");
    fclose(arquivo);
    
}
void login_gestor(){
	int ID[MAX_USERNAME_LEN], passg[MAX_PASSWORD_LEN];
    printf("=== Login de Gestor ===\n");
    printf("Insira o ID: ");
    scanf("%s", ID);
    printf("Insira a senha: ");
    scanf("%s", passg);

    FILE* arquivo;
    arquivo = fopen("GestoresDados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de gestores!\n");
    }

    char linha[MAX_LINHA_LEN];
    while (fgets(linha, MAX_LINHA_LEN, arquivo) != NULL) {
        char* token = strtok(linha, ";");
        char* ID_gestor = token;
        token = strtok(NULL, ";");
        char* password = token;
        if (strcmp(ID_gestor, ID) == 0 && strcmp(password, passg) == 0) {
        	
            printf("Login realizado com sucesso!\n");
            system("cls");
            printf("======= MENU GESTORES =======\n");
        	printf("1 - Inserir Meio\n");
        	printf("2 - Listar Meios\n");
        	printf("3 - Remover Meio\n");
        	printf("4 - Guardar Meios\n");
        	printf("5 - Ler Meios\n");
        	printf("6 - Listar Meios por ordem de autonomia decrescente\n");
        	printf("7 - Listar Meios por Geoc�digo\n");
        	printf("=====================================\n");
        	printf("8 - Inserir novo Gestor\n");
        	printf("9 - Listar Gestores\n");
        	printf("10 - Remover um gestor\n");  
			printf("11 - Alterar dados\n");
			printf("12 - Guardar\n");
            printf("13 - Ler gestores\n");
        	printf("0 - Sair\n");
        	
             {Meio* meios = NULL;
			 int opcao;
			 int cod;
			 float bat, aut, prec;
			 char tipo[50];
			 Gestor* gestores = NULL;
			 int ID;
			 char nomeg[50];
			 char moradag[50];
			 char passg[50];
			 char geo[3][30];
             
            do {
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Codigo?\n");
                        scanf("%d",&cod);
                        scanf("%c");
	   					printf("Nivel da bateria?\n");
	   					scanf("%f",&bat);
	   					printf("Autonomia\n");
	   					scanf("%f",&aut);
	   					printf("Tipo?\n");
	   					scanf("%s",&tipo);
	   					printf("Insira o pre�o do meio\n");
	   					scanf("%f",&prec);
	   					printf("Primeiro nome do geocodigo\n");
                        scanf("%s",&geo[0]);
                        printf("Segundo nome do geocodigo\n");
                        scanf("%s",&geo[1]);
                        printf("terceiro nome do geocodigo\n");
                        scanf("%s",&geo[2]);
           				meios = inserirMeio(meios,cod,bat,aut,tipo,prec,geo);
                        break;
                    case 2:
                       listarMeios(meios); 
                        break;
                    case 3:
                        printf("Codigo do meio de mobilidade a remover?\n");
	   					scanf("%d",&cod);
	   					meios = removerMeio(meios, cod);
	   					break;
	   				case 4:
					   	guardarMeios(meios); break;
					case 5:
						meios = lerMeios(); break;
					case 6:
						listarMeiosPorAutonomiaDecrescente(meios);
						break;
					case 7:
						listar_meios_por_geocodigo(meios);
						break;	
					case 8:
						printf("\n");
						printf("ID?\n");
						scanf("%d",&ID);
                        scanf("%c");
                        printf("Password?\n");
	   					scanf("%s",&passg);
	   					printf("Nome?\n");
	   					scanf("%s",&nomeg);
	   					printf("Morada?\n");
	   					scanf("%s",&moradag);
           				gestores = inserirGestor(gestores,ID,passg,nomeg,moradag);          				
                        break;
					case 9:
						listarGestores(gestores);
						break;
					case 10:
						printf("ID do gestor que deseja remover?\n");
	   					scanf("%d",&ID);
	   					gestores = removerGestor(gestores, ID);break;
					case 11:					
						alterar_dados(gestores);break;	
					case 12:
						guardarGestores(gestores); break;
					case 13:
						gestores = lerGestores(); break;				   		   	
                    case 0:
                        printf("Logout realizado com sucesso!\n");
                        system("cls");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
       }
   		
            } while (opcao != 0);

}	
            fclose(arquivo);
            return;
        }
    }

    printf("Usu�rio ou senha inv�lidos!\n");
    fclose(arquivo);
}

int main() {
    
	int opcao;
    do {
        printf("===== MENU PRINCIPAL ==========\n");
        printf("1 - Registar cliente\n");
        printf("2 - Login de cliente\n");
        printf("3 - Login de gestor\n");
        printf("0 - Cancelar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registar_cliente();
                break;
            case 2:
                login_cliente();
                break;
            case 3:
		   		login_gestor();
            break;
        case 0:
            printf("A Cancelar...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

} while (opcao != 0);

return 0;
}











