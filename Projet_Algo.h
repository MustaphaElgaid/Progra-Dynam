#ifndef __Projet_Algo_H__
#define __Projet_Algo_H__


#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include <string.h>

// structur de donnée utilise pour determiner f(n,x) et le chemin correspondant 
typedef struct machine
{
    uint32_t value; // temps max  f(t,A) ou f(t,B)
    char* chemin;   // le chemin suivi
}machine;

// fonction pour determiner le MAX
uint32_t entier_Max(uint32_t m,uint32_t n)
{
    if(m>n)
        return m;
    return n;
}

_Bool  machine_valeur_max(uint32_t machine_A,uint32_t machine_B)
{
    if(machine_A>machine_B)
        return 0;
    return 1;
}

// fonction de Algo dynmique
void foncttion_principal(uint32_t n , uint32_t *A,uint32_t *B)
{

    machine tab[2][n]; // initialisation 
   
    tab[0][0].value = A[0];   tab[1][0].value = B[0];  // f(1,A)  f(1,B)
    tab[0][0].chemin = "A";   tab[1][0].chemin = "B";   
    tab[0][1].value = A[0]+A[1];   tab[1][1].value = B[0]+B[1];   // f(2,A)  f(2,B)
    tab[0][1].chemin = "A-->A";   tab[1][1].chemin = "B-->B";


    for(int t=2; t<n;t++)
    {
        tab[0][t].value = entier_Max(tab[0][t-1].value,tab[1][t-2].value) + A[t]; // f(t,A)
        tab[1][t].value = entier_Max(tab[1][t-1].value,tab[0][t-2].value) + B[t]; // f(t,B)

        // allocation des chaines de caracteres pour determiner le chemin 
        tab[0][t].chemin = malloc(sizeof(char)*300);   // la chaine de caractere du chemin
        tab[1][t].chemin = malloc(sizeof(char)*300);    // la chaine de caractere du chemin

        // le chemin pour arrive à la machine 'A' dans la minute t 
        if(machine_valeur_max(tab[0][t-1].value,tab[1][t-2].value)==0){  
            strcpy(tab[0][t].chemin,tab[0][t-1].chemin);
            strcat(tab[0][t].chemin,"-->A"); 
        } 
        else
        {  
            strcpy(tab[0][t].chemin,tab[1][t-2].chemin);
            strcat(tab[0][t].chemin,"-->migrer_B_vers_A-->A"); 
        } 
          // le chemin pour arrive à la machine 'B' dans la minute t
        if(machine_valeur_max(tab[0][t-2].value,tab[1][t-1].value)==0)
        {  
            strcpy(tab[1][t].chemin,tab[0][t-2].chemin);
            strcat(tab[1][t].chemin,"-->migrer_A_vers_B-->B");
        }  
        else
       {    
            strcpy(tab[1][t].chemin,tab[1][t-1].chemin);
            strcat(tab[1][t].chemin,"-->B"); 
       } 
    }
    // max(f(n,A), f(n,B))
    uint32_t resultat = machine_valeur_max(tab[0][n-1].value,tab[1][n-1].value); 
    
    printf("le temps maximal dans la minute n est : %d \n  ",tab[resultat][n-1].value);
    printf("le chemin est : %s \n  ",tab[resultat][n-1].chemin);

}

#endif
