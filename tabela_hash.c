#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Estrutura base do nó->
struct Node
{
  int valor;
  struct Node *proximo;
};

typedef struct Node node;

// funcao que retorna o ultimo digito do numero como chave de hash
int hash(int codigo)
{
  int chave = codigo;
  while (chave >= 10)
  {
    chave = chave % 10;
  }
  return chave;
}
//Função pra printar o nó na tela.
void displayLL2(node *p)
{
    p = p->proximo;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf(" %d", p->valor);
            p = p->proximo;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
}
// imprime a lista na posicao da chave hash
void displayLL(int chave, node *p)
{
  int i;
  printf("\nposicao %d:", chave);
  if (p)
  {
    do
    {
      printf(" %d ", p->valor);
      p = p->proximo;
    } while (p);
  }
  else
    printf("nodo vazio.");
}
// Função PARA INSERIR NÓS NA SEQUENCIA DE ELEMENTOS NA TABELA HASH CASO HAJA COLISÃO
void insere_no_final(node *tabela, int info){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    while(tabela->proximo != NULL) {
        tabela = tabela->proximo;
    }
    novo->valor = info;
    novo->proximo = NULL;
    tabela->proximo = novo;
}
 // FUNÇÃO QUE ADICIONA AS PRIMEIRAS POSIÇÕES DA TABELA HASH
node* add(node *tabela, int info){
      tabela = (node *)malloc(sizeof(node));
      tabela->valor = info;
      tabela->proximo = NULL;
      return tabela;
}

// Função para remover nó no final
void remove_no_final(node *tabela)
{ 
    if(tabela->proximo == NULL){
      free(tabela);
    }
    node *p = tabela;
    node *anterior = tabela;
    while(p->proximo){
        anterior = p;
        p = p->proximo;
    }
    anterior->proximo = p->proximo;
    p->proximo = NULL;
    free(p);
}

int main(void)
{
  int tamanho_da_tabela_hash = 10;
  node *tabela_hash[tamanho_da_tabela_hash];
  for (int i = 0; i < tamanho_da_tabela_hash; i++)
  {
    tabela_hash[i] = NULL;
  }
  int codigo = 0;
  int chave = 0;
  int menu = 0;
  while(true) { 
    printf("Digite o Codigo correspondente ao Menu abaixo: \n");
    printf("1 ---------------Para adicionar um elemento na tabela hash \n");
    printf("2 ---------------Para remover o ultimo elemento de uma colisão hash \n");
    printf("3 ---------------Para Sair \n");
    scanf("%d", &menu);
    if(menu == 1){
        printf("\n Digite o código de matricula: ");
        scanf("%d", &codigo);
        chave = hash(codigo);
        if(tabela_hash[chave] == NULL)
          tabela_hash[chave] = add(tabela_hash[chave], codigo);
        else  
          insere_no_final(tabela_hash[chave], codigo);
        for (int i = 0; i < 10; i++)
      {
        if (tabela_hash[i])
        {
          displayLL(i, tabela_hash[i]);
        }
        else
        {
          printf("\nposicao %d, nodo vazio ", i);
        }
      }
    }
    printf("\n \n");
    if(menu == 2){
      printf("\n Digite o codigo ou a chave correspondente que deseja remover: \n");
      scanf("%d", &codigo);
      chave = hash(codigo);
      remove_no_final(tabela_hash[chave]);
      for (int i = 0; i < 10; i++)
      {
        if (tabela_hash[i])
        {
          displayLL(i, tabela_hash[i]);
        }
        else
        {
          printf("\nposicao %d, nodo vazio ", i);
        }
      }
    }
    if(menu == 3)
      break;
  }
}
