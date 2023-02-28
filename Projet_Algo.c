#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include "Projet_Algo.h"

int main(int argc, char *argv[])
{
    printf("le chemin contiene les possibilités suivants pour chaque minutes : 'A' ou 'B' ou 'miger' \n  ");
    printf("Un test sur les tableaux de l'énoncé : \n  ");
    printf("---------------------------------------------------------- \n ");
    printf("le premier exemple :");
    uint32_t A1[5]={40,40,10,30,30};
    uint32_t B1[5]={20,20,60,20,20};
    foncttion_principal(5,A1,B1);
    printf("---------------------------------------------------------- \n ");

    printf("le deuxieme exemple :");
    uint32_t A2[5]={50,10,10,30,30};
    uint32_t B2[5]={10,20,50,20,40};
    foncttion_principal(5,A2,B2);
    printf("---------------------------------------------------------- \n ");

    printf("le troixieme exemple :");
    uint32_t A3[5]={40,40,10,10,60};
    uint32_t B3[5]={20,30,60,60,10};
    foncttion_principal(5,A3,B3);
    printf("---------------------------------------------------------- \n ");


    printf("le quatrième exemple :");
    uint32_t A4[10]={10,10,10,60,10,10,10,50,40,10};
    uint32_t B4[10]={20,40,20,10,10,60,20,10,10,60};
    foncttion_principal(10,A4,B4);


    return 0;
} 