#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "test.h"

void testInitialisation(polynome** p)
{
    initialisation(p);
    if(initialisation(p) == 0)
    {
        printf("L'initialisation a echoue ");
    }
}

void testSaisir(polynome** p1, polynome** p2)
{
    saisir(p1, 5, 3);
    saisir(p1, 3, 2);
    saisir(p1, 1, 1);
    printf("Le polynome p1 est :"); afficher(*p1);

    saisir(p2, 2, 2);
    saisir(p2, 3, 1);
    printf("Le polynome p2 est :"); afficher(*p2);
}

void testSomme(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = somme(p1, p2);
    printf("La somme des polynomes p1 et p2 est :");
    afficher(p3);
}

void testProduit(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = produit(p1, p2);
    printf("Le produit des polynomes p1 et p2 est :");
    afficher(p3);
}

void testDerive(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = derive(p1);
    printf("la derivee de p1 est :");
    afficher(p3);

    p3 = derive(p2);
    printf("la derivee de p2 est :");
    afficher(p3);

}

void testPrimitive(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = primitive(p1);
    printf("la primitive de p1 est :");
    afficher(p3);

    p3 = primitive(p2);
    printf("la primitive de p2 est :");
    afficher(p3);
}


void testDeriveSommme(polynome* p1, polynome* p2)
{
    polynome* p3;
    p3 = deriveSomme(p1, p2);
    printf("La derivee de la somme de p1 et p2 est :");
    afficher(p3);
}


void testDeriveProduit(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = deriveProduit(p1, p2);
    printf("La derivee du produit de p1 et p2 est :");
    afficher(p3);
}

void testCalcul(polynome* p, double x)
{
    double resultat;

    resultat = calcul(p, x);
    printf("Le resultat est %0.1f\n\n",resultat);
}

void testCalculHorner(polynome* p, double x)
{
    double resultat;

    resultat = calculHorner(p, x);
    printf("Le resultat est %0.1f\n\n",resultat);
}


void test()
{
    polynome* p1 = NULL;
    polynome* p2 = NULL;
    polynome* p3 = NULL;

    testInitialisation(&p1);
    testInitialisation(&p2);
    testInitialisation(&p3);

    testSaisir(&p1, &p2);

    int choix;
    printf("Choix possibles :\n");
    printf("    0- Arreter\n");
    printf("    1- Somme des deux polynomes\n");
    printf("    2- Produit des deux polynomes\n");
    printf("    3- Derivee des polynome p1 et p2\n");
    printf("    4- Derivee de la somme des deux polynomes\n");
    printf("    5- Derivee du produit des deux polynomes\n");
    printf("    6- Calcul du polynome p1 pour x = 1\n");
    printf("    7- Calcul du polynome p1 pour x = 1 avec la methode d'Horner\n");
    printf("    8- Primitive des deux polynomes p1 et p2\n");
    printf("Votre choix : "); scanf("%d",&choix); printf("\n");

    while(choix != 0)
    {
        switch(choix)
        {
            case 1: testSomme(p1, p2); break;

            case 2: testProduit(p1, p2); break;

            case 3: testDerive(p1, p2); break;

            case 4: testDeriveSommme(p1, p2); break;

            case 5: testDeriveProduit(p1, p2); break;

            case 6: testCalcul(p1, 1); break;

            case 7: testCalculHorner(p1, 1); break;

            case 8: testPrimitive(p1, p2); break;

            default: printf("Probleme de saisie\n"); break;

        }

        printf("Choix possibles :\n");
        printf("    0- Arreter\n");
        printf("    1- Somme des deux polynomes\n");
        printf("    2- Produit des deux polynomes\n");
        printf("    3- Derivee des polynome p1 et p2\n");
        printf("    4- Derivee de la somme des deux polynomes\n");
        printf("    5- Derivee du produit des deux polynomes\n");
        printf("    6- Calcul du polynome p1 pour x = 1\n");
        printf("    7- Calcul du polynome p1 pour x = 1 avec la methode d'Horner\n");
        printf("    8- Primitive des deux polynomes p1 et p2\n");
        printf("Votre choix : "); scanf("%d",&choix); printf("\n");
    }

    printf("Arret du programme\n");

    free(p1->monomes); free(p2->monomes); free(p3->monomes);
    free(p1); free(p2); free(p3);

}

