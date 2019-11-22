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
// Função para inserir nó no final
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
void add(int chave, int codigo, node *tabela_hash) {
  bool n;
  if (tabela_hash)
  {
    n = true;
  }
  else
    n = false;
  if(n == true) {
    insere_no_final(tabela_hash, codigo);

  }
  else {
    tabela_hash = (node *)malloc(sizeof(node));
    tabela_hash->valor = codigo;
    tabela_hash->proximo = NULL;
  }

}
int main(void)
{
  int tamanho_da_tabela_hash = 10;
  node *tabela_hash[tamanho_da_tabela_hash];
  for (int i = 0; i < tamanho_da_tabela_hash; i++)
  {
    tabela_hash[i] = NULL;
  }

  // criando o primeiro nodo na tabela hash
  int codigo1 = 100112375;
  int chave1 = hash(codigo1);

  // criando o primeiro nodo na tabela hash
  if(tabela_hash[chave1] == NULL) {
    tabela_hash[chave1] = (node *)malloc(sizeof(node));
    tabela_hash[chave1]->valor = codigo1;
    tabela_hash[chave1]->proximo = NULL;
  }
  else
    insere_no_final(tabela_hash[chave1], codigo1);

    // // Informações para o segundo nodo
     int codigo2 = 100112345;
     int chave2 = hash(codigo2);
     add(chave2, codigo2, tabela_hash[chave2]);

     int codigo3 = 100112344;
     int chave3 = hash(codigo3);
     if(tabela_hash[chave3] == NULL) {
       tabela_hash[chave3] = (node *)malloc(sizeof(node));
       tabela_hash[chave3]->valor = codigo3;
       tabela_hash[chave3]->proximo = NULL;
     }
     else
       insere_no_final(tabela_hash[chave3], codigo3);
    int codigo4 = 100113804;
    int chave4 = hash(codigo4);
       if(tabela_hash[chave4] == NULL) {
         tabela_hash[chave4] = (node *)malloc(sizeof(node));
         tabela_hash[chave4]->valor = codigo4;
         tabela_hash[chave4]->proximo = NULL;
       }
       else
         insere_no_final(tabela_hash[chave4], codigo4);
    //
    // // criando o primeiro nodo na tabela hash
    // if(tabela_hash[chave1] == NULL) {
    //   tabela_hash[chave1] = (node *)malloc(sizeof(node));
    //   tabela_hash[chave1]->valor = codigo1;
    //   tabela_hash[chave1]->proximo = NULL;
    // }
    // else
    //   insere_no_final(tabela_hash[chave1], codigo1);

  // imprimindo toda a estrutura
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

  return 0;
}
