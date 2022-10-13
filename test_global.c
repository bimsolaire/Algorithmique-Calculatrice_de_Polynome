#include "test.h"
#include "test_LC.h"
#include <stdio.h>

void test_global()
{
    int choix;
    printf("Choix possibles :\n");
    printf("    1- Liste chainee\n");
    printf("    2- Tableau de structures\n");
    printf("Votre choix :"); scanf("%d",&choix);


    switch(choix)
    {
        case 1: test_LC();break;

        case 2: test(); break;

        default: printf("Probleme de saisie\n"); break;
    }
}