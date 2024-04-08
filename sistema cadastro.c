// sistema para cadastro de players.
// cadastrar player, excluir, ordenar (a-z) e motrar todos os players cadastrados.

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define NAME 50
#define TF 100

typedef struct
{
    int codigo;
    char nome[NAME];
}Player;

void limpar ()
{
    system("cls");
}

void pausar ()
{
    system("pause\n");
}

int cadastro_vazio (int *tl)
{
    if(*tl==0)
        return 1;
    else
        return 0;
}

void cadastro (Player play[], int *tl)
{
    int cod;
    printf("\nCodigo: ");
    scanf("%d", &cod);

    while(cod!=0)
    {
        if(*tl==0)
        {
            printf("Nome: "); fflush(stdin);
            gets(play[*tl].nome);
            play[*tl].codigo=cod;
            (*tl)++;
            printf("Player cadastrado com sucesso!\n");
            printf("------------------------------\n");
        }
        else
        {
            int achou, i;
            achou=0;
            for(i=0;i<*tl;i++)
            {
                if(play[i].codigo==cod)
                    achou=1;
            }
            if(achou==1)
            {
                printf("Player ja cadastrado no banco de dados!\n");
                printf("------------------------------\n");
            }
            else
            {
                printf("Nome: "); fflush(stdin);
                gets(play[*tl].nome);
                play[*tl].codigo=cod;
                (*tl)++;
                printf("Player cadastrado com sucesso!\n");
                printf("------------------------------\n");
            }
        }

        printf("Codigo: ");
        scanf("%d", &cod);
    }
}

void excluir (Player play[], int *tl)
{
    int cod, i, achou;
        achou=0;
        if(!cadastro_vazio(tl))
        {
            printf("\nCodigo para excluir: ");
            scanf("%d", &cod);

            while(cod!=0)
            {
                for(i=0;i<*tl;i++)
                {
                    if(play[i].codigo==cod)
                        achou=1;
                }
                if(achou==1)
                {
                    int pos=0;
                    char nome[50];
                    while(play[pos].codigo!=cod && pos<TF)
                        pos++;
                    if(pos<TF)
                    {
                        for(i=pos;i<*tl;i++)
                        {
                            strcpy(nome,play[i].nome);
                            play[i].codigo=play[i+1].codigo;
                            strcpy(play[i].nome,play[i+1].nome);
                        }
                        (*tl)--;
                        printf("%s excluido com sucesso!\n", nome);
                        printf("------------------------------\n");
                    }
                }
                else
                {
                    printf("Codigo nao encontado!\n");
                    printf("------------------------------\n");
                }

                printf("\nCodigo para excluir: ");
                scanf("%d", &cod);
            }
        }
        else
        {
            printf("\nNenhum player cadastrado!\n");
            printf("------------------------------\n");
            pausar();
        }
}

void ordenar (Player play[], int *tl)
{
    char aux[50];
    int i, j;

    if(!cadastro_vazio(tl))
    {
        for(i=0;i<*tl;i++)
        {
            for(j=i+1;j<*tl;j++)
            {
                int r;
                r=strcmp(play[i].nome,play[j].nome);
                if(r>0)
                {
                    strcpy(aux,play[i].nome);
                    strcpy(play[i].nome,play[j].nome);
                    strcpy(play[j].nome,aux);
                }
            }
        }
        printf("\nOrdenacao feita com sucesso!\n");
        printf("------------------------------\n");
    }
    else
    {
        printf("\nNenhum player cadastrado!\n");
        printf("------------------------------\n");
    }
    pausar();
}

void relatorio (Player play[], int *tl)
{
    if(!cadastro_vazio(tl))
    {
        printf("------------------------------\n");
        int i;
        for(i=0;i<*tl;i++)
        {
            printf("Codigo: %d\n", play[i].codigo);
            printf("Nome: %s\n", play[i].nome);
            printf("------------------------------\n");
        }
    }
    else
    {
        printf("\nNenhum player cadastrado!\n");
        printf("------------------------------\n");
    }
    pausar();
}

char menu ()
{
    char m; 
    limpar();
    printf(" [A]  Cadastrar\n");
    printf(" [B]  Excluir\n");
    printf(" [C]  Ordenar (a-z)\n");
    printf(" [D]  Relatorio\n");
    printf("[ESC] Encerrar\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    return m;
}


int main ()
{
    Player play[TF];

    int TL=0;
    char m;

    m=menu();
    while(m!=27)
    {
        switch(m)
        {
            case 'A':
                cadastro(play, &TL);
            break;

            case 'B':
                excluir(play, &TL);
            break;

            case 'C':
                ordenar(play, &TL);
            break;

            case 'D':
                relatorio(play, &TL);
            break;
        }
        m=menu();
    }
}