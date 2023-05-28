#include <stdio.h>
#include "meio.h"
#include "clientes.h"
#include "gestores.h"
#include <stdlib.h>
#include <string.h>
#include "clientesDados.h"

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
			 //char nomec[50];
			 //char moradac[50];
			 //char emailc[50];
			 float saldoc;
			printf("NIF?\n");
            scanf("%d",&NIFc);
            scanf("%c");
            printf("Password?\n");
            scanf("%s",&passc);
            /*printf("Nome?\n");
	   		scanf("%s",&nomec);
	   		printf("Morada?\n");
	   		scanf("%s",&moradac);
	   		printf("Email?\n");
	   		scanf("%s",&emailc);
	   		*/
           	clientes = inserirCliente(clientes,NIFc,passc,saldoc);
           	printf("Cliente Registado com sucesso\n");
           	
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
    arquivo = fopen("loginClientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de Clientes!\n");
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
            printf("1 - Inserir Dados\n");
            printf("2 - Ler Dados\n");
            printf("3 - Guardar Dados\n");
            printf("4 - Alterar Dados\n");
            printf("5 - Ver Dados\n");
            printf("6 - Adicionar saldo\n");
            printf("7 - Consultar saldo\n");
            printf("8 - Ver meios disponiveis\n");
            printf("9 - Alugar um meio\n");
            printf("10 - Devolver meio\n");
            printf("0 - Sair\n");
            
            {Cliente* clientes = NULL;
            dadosCliente* dadosclientes = NULL;
            dadosCliente* inicio = NULL;
            //Cliente* inicio=NULL;
            Meio* meios = NULL;
            int opcao,NIFc;
            int saldoc;
            char nomec[50];
            char passc[50];
			char moradac[50];
			char emailc[50];
			int locC;
	
			int cod,codigo;
			float bat, aut;
			char tipo[50], localizacaoCliente[50];
			int locM;
            do {
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                	case 1:
                    	printf("NIF?\n");
                        scanf("%d",&NIFc);
                        scanf("%c");
	   					printf("Password?\n");
	   					scanf("%s",&passc);
	   					printf("Nome\n");
	   					scanf("%s",&nomec);
	   					printf("Morada?\n");											
	   					scanf("%s",&moradac);
	   					printf("Email\n");
	   					scanf("%s",&emailc);
	   					printf("Localizacao?\n");
			            scanf("%s", localizacaoCliente);
			            int locC = converterLocalizacao(localizacaoCliente);
			            dadosclientes = inserirdadosCliente(dadosclientes, NIFc, passc, nomec, moradac, emailc, locC);
			            break;
                        
                    case 2:
                    	dadosclientes = lerdadosClientes(); break;
					case 3:
                    	 guardardadosClientes(dadosclientes); break;  
                    case 4:
                        alterarDados(dadosclientes);
                        break;
                    case 5:
                        verdadosCliente(dadosclientes);
                        break;    
                    case 6:
                        adicionarSaldo(clientes);
                        break;
                    case 7:
                        consultarSaldo(clientes);
						break;            
					case 8:
						meios = lerMeios();
						listarMeios(meios);
						break;
					case 9:
					    printf("Insira o codigo do meio de mobilidade eletrica que deseja alugar: ");
                    	scanf("%d", &codigo);
                       	alugarMeio(meios, codigo);break;
					case 10:
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
            printf("=====================================\n");
            printf("=======    MEIOS  ===============\n");
        	printf("1 - Inserir Meio\n");
        	printf("2 - Listar Meios\n");
        	printf("3 - Remover Meio\n");
        	printf("4 - Guardar Meios\n");
        	printf("5 - Ler Meios\n");
        	printf("6 - Listar Meios por ordem de autonomia decrescente\n");
        	printf("7 - Listar Meios por Geocodigo\n");
        	printf("=====================================\n");
        	printf("=======    Gestores  ===============\n");
        	printf("8 - Inserir novo Gestor\n");
        	printf("9 - Listar Gestores\n");
        	printf("10 - Remover um gestor\n");  
			printf("11 - Alterar dados\n");
			printf("12 - Guardar\n");
            printf("13 - Ler gestores\n");
            printf("=====================================\n");
            printf("=======    Clientes  ===============\n");
            printf("14 - Ler clientes\n");
            printf("15 - Listar Clientes\n");
            printf("=====================================\n");
            printf("=======    Grafos  ===============\n");
            printf("16 - Iniciar grafo\n");
            printf("17 - Ver grafo\n");
            printf("18 - libertar grafo\n");
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
			 char localizacaoMeio[50];
             int locM;
             dadosCliente* dadosclientes = NULL;
            dadosCliente* inicio = NULL;
            int NIFc;
            char passc;
            char nomec;
            char moradac;
            char emailc;
            char locC;
            Grafo* grafo = NULL;
            
            /*No* nos = NULL;
            Aresta* arestas = NULL;
            Grafo* grafos = NULL;
            char nome[50];
            int peso;
            const char* localizacao;
            */
            
            
   
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
	   					printf("Insira o preco do meio\n");
	   					scanf("%f",&prec);
	   					printf("Primeiro nome do geocodigo\n");
                        scanf("%s",&geo[0]);
                        printf("Segundo nome do geocodigo\n");
                        scanf("%s",&geo[1]);
                        printf("terceiro nome do geocodigo\n");
                        scanf("%s",&geo[2]);
                        printf("Localizacao?\n");
			            scanf("%s", localizacaoMeio);
			            int locM = converterLocalizacaoMeio(localizacaoMeio);
           				meios = inserirMeio(meios,cod,bat,aut,tipo,prec,geo,locM);
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
					case 14:
						dadosclientes = lerdadosClientes(); break;
					case 15:
						listardadosClientes(dadosclientes);
						break;
						
					case 16:	
						Grafo grafo = lerMeios();
					    // Adicionar arestas entre os meios
					    adicionarAresta(&grafo, 1, 2);
					    adicionarAresta(&grafo, 2, 3);
					    adicionarAresta(&grafo, 3, 4);
					    adicionarAresta(&grafo, 4, 1);
					
					    // Calcular distância entre um meio e um cliente
					    int codigoMeio = 2;
					    int codigoCliente = 1;
					    int distancia = calcularDistancia(&grafo, codigoMeio, codigoCliente);
					    if (distancia != -1) {
					        printf("A distância entre o meio %d e o cliente %d é %d.\n", codigoMeio, codigoCliente, distancia);
					    } else {
					        printf("Meio ou cliente não encontrado.\n");
					    }
					
					    return 0;
}
						 break;
					case 17:
							imprimirGrafo(grafos);break;	
					case 18:
							liberarGrafo(grafos);break;				
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

    printf("Codigo ou pass invalidos!\n");
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











