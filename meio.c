#include <stdlib.h>
#include <string.h>
#include "meio.h"

int guardarMeios(Meio* inicio)
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%f;%f;%s;%f;%s\n", aux->codigo, aux->bateria, 
	                      aux->autonomia, aux->tipo, aux->preco, aux->geocodigo);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Meio* lerMeios()
{FILE* fp;
 int cod;
 float bat, aut, prec;
 char tipo[50];
 char geo[3][30];
 Meio* aux=NULL;
 fp = fopen("meios.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%f;%f;%s;%f;%s\n", &cod, &bat, &aut, &tipo, &prec, &geo);
    aux = inserirMeio(aux, cod, bat, aut, tipo, prec, geo);
  }
  fclose(fp);
 }
 return(aux);
}

// Inser??o de um novo registo
Meio* inserirMeio(Meio * inicio, int cod, float bat, float aut, char tipo[], float prec, char geo[][30])

{
 if (!existeMeio(inicio, cod)) //verifica se existe um meio com esse código
 
 {Meio * novo = malloc(sizeof(struct registo));
  
  if (novo != NULL)
  {novo->codigo = cod;				//copiar strings para o novo meio
   novo->bateria = bat;
   novo->autonomia = aut;
   strcpy(novo->tipo,tipo);
   novo->preco = prec;
   strcpy(novo->geocodigo[0],geo[0]);
   strcpy(novo->geocodigo[1],geo[1]);
   strcpy(novo->geocodigo[2],geo[2]);
   novo->seguinte = inicio;
   return(novo); //retorna o novo meio
  }
 } else return(inicio);
}

// listar na consola o conte?do da lista ligada
void listarMeios(Meio * inicio)
{while (inicio != NULL)
 {printf("%d %.2f %.2f %s %.2f %s\n",inicio->codigo,  inicio->bateria, 
 								inicio->autonomia, inicio->tipo, inicio->preco, inicio->geocodigo);
  inicio = inicio->seguinte;
 }
}


// Determinar exist?ncia do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contr?rio
int existeMeio(Meio* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codigo == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}
Meio* removerMeio(Meio* inicio, int cod) 
{ Meio *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codigo == cod) // remo??o do 1? registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=cod)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}
void listarMeiosPorAutonomiaDecrescente(Meio* inicio) {
    // Count the number of meios in the linked list
    int num_meios = 0;
    Meio* aux = inicio;
    while (aux != NULL) {
        num_meios++;
        aux = aux->seguinte;
    }

    // Create an array with the same number of meios as the linked list
    Meio** vetor_meios = malloc(sizeof(Meio*) * num_meios);

    // Fill the array with the meios from the linked list
    int i;
    for (i = 0, aux = inicio; aux != NULL; i++, aux = aux->seguinte) {
        vetor_meios[i] = aux;
    }

    // Sort the array in descending order of autonomy
    int x, y;
    for (x = 0; x < num_meios - 1; x++) {
        for (y = x + 1; y < num_meios; y++) {
            if (vetor_meios[x]->autonomia < vetor_meios[y]->autonomia) {
                Meio* temp = vetor_meios[x];
                vetor_meios[x] = vetor_meios[y];
                vetor_meios[y] = temp;
            }
        }
    }

    // List the meios from the sorted array
    for (i = 0; i < num_meios; i++) {
        printf("%d %.2f %.2f %s %.2f\n", vetor_meios[i]->codigo, vetor_meios[i]->bateria, vetor_meios[i]->autonomia, vetor_meios[i]->tipo, vetor_meios[i]->preco);
    }

    // Free the memory allocated for the array
    free(vetor_meios);
}


Meio* encontrar_meio(Meio* inicio, int codigo) {
    // Cria um ponteiro chamado "meio" e inicializa com o ponteiro para o início da lista.
    Meio* meio = inicio;
    // Loop enquanto "meio" não é nulo (ou seja, ainda há elementos na lista).
    while (meio != NULL) {
        // Verifica se o código do elemento atual é igual ao código buscado.
        if (meio->codigo == codigo) {
            // Se for igual, retorna o ponteiro para o elemento atual.
            return meio;
        }
        // Se o código não for igual, avança para o próximo elemento da lista.
        meio = meio->seguinte;
    }
    // Se não encontrar um elemento com o código buscado, retorna nulo.
    return NULL;
}




void devolverMeio(Meio* inicio, int codigo) {
	
    // Procura meio com o código 
    Meio* meio = encontrar_meio(inicio, codigo);
    // Verifica se o meio foi encontrado
    if (meio == NULL) {
        printf("Meio de mobilidade eletrica nao encontrado.\n");
        return;
    }
    // Verifica se o meio está disponível
    if (meio->disponivel == 1) {
        printf("Meio de mobilidade eletrica ja esta disponivel.\n");
        return;
    }
    // Marca o meio como disponível
    meio->disponivel = 1;
    printf("Meio de mobilidade eletrica devolvido com sucesso.\n");
}

void listar_meios_por_geocodigo(Meio* inicio) {
    int encontrou = 0;
    char geocodigo[3][30]; 
    Meio* meio_atual = inicio;

    
    printf("Primeiro nome do geocodigo\n");
    scanf("%s",&geocodigo[0]);
    printf("Segundo nome do geocodigo\n");
    scanf("%s",&geocodigo[1]);
    printf("Terceiro nome do geocodigo\n");
    scanf("%s",&geocodigo[2]);

    // Percorre a lista de meios  á procura daqueles com o geocodigo especificado
    printf("Meios  para o geocodigo %s.%s.%s:\n", geocodigo[0],geocodigo[1],geocodigo[2]);
    while (meio_atual != NULL && encontrou==0) {
        if (strcmp(meio_atual->geocodigo[0], geocodigo[0]) == 0 && strcmp(meio_atual->geocodigo[1], geocodigo[1]) == 0 && strcmp(meio_atual->geocodigo[2], geocodigo[2]) == 0){ 
            printf("- Codigo: %d ; Tipo: %s ; Bateria: %.2f ; Autonomia: %.2f ; Preco: %.2f\n",
                   meio_atual->codigo, meio_atual->tipo, meio_atual->bateria, meio_atual->autonomia, meio_atual->preco);
            encontrou = 1;
        } else {

        meio_atual = meio_atual->seguinte;
        }

        if (!encontrou) {
            printf("Nao foi encontrado nenhum meio para o geocodigo %s.%s.%s:\n", geocodigo[0],geocodigo[1],geocodigo[2]);
        }
    }
}








