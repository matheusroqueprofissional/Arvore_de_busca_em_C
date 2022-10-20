#include <stdio.h>
#include <stdlib.h>

struct tree{
struct stree *leftptr;
int data;
struct stree *rightptr;
};

typedef struct tree TREENODE;
typedef TREENODE *TREENODEPTR;

void inserir(TREENODEPTR *, int);
void inorder(TREENODEPTR);
void search(TREENODEPTR ,int);

int main()
{
TREENODEPTR TNP = NULL;
int i;

i = 1;
int valorabuscar;
int valor_arvore;
printf("insira valor da arvore:");
scanf("%d",&valor_arvore);
printf("insira valor que deseja buscar de 0 a %d",valor_arvore);
scanf("%d",&valorabuscar);
while (i<=valor_arvore)
{

inserir(&TNP,i);
inorder(TNP);
printf("\n");
i++;
}
printf("\n\nARVORE RESULTADO INORDER\n[");
inorder(TNP);
printf("  ]");
printf("\n\n\n");
search(TNP,valorabuscar);
printf("\n\n\n");
}



void inserir(TREENODEPTR *treenodeptr, int valor)
{
 if(*treenodeptr == NULL)
 {
    *treenodeptr = malloc(sizeof(TREENODE));
    if(*treenodeptr != NULL)
    {
        (*treenodeptr)->data = valor;
        (*treenodeptr)->leftptr = NULL;
        (*treenodeptr)->rightptr = NULL;

    }
    else
        printf("sem memoria no aparelho");

 }
 else{
    if(valor<(*treenodeptr)->data)
    {
        inserir(&((*treenodeptr)->leftptr),valor);
    }
    else{
        if(valor>(*treenodeptr)->data)
        {
            inserir(&((*treenodeptr)->rightptr),valor);
        }
        else{
            printf("menor");
            }
        }
    }
}


void inorder(TREENODEPTR treenodeptr)
{
    if(treenodeptr != NULL)
    {
        inorder((treenodeptr)->leftptr);
        printf("%3d",(treenodeptr)->data);
        inorder((treenodeptr)->rightptr);
    }
}
void search(TREENODEPTR treenodeptr, int inserido)
{

    if(treenodeptr == NULL)
        return;
    if(treenodeptr<inserido)
    {   search((treenodeptr)->leftptr,inserido);

    }
    else{
        if(treenodeptr>inserido)
        {
            search((treenodeptr)->rightptr,inserido);

        }
    }
    if(treenodeptr->data == inserido)
    {
        printf("valor inserido:%d",treenodeptr->data);
    }

}
