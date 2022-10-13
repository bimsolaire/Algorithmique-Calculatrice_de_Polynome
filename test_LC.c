#include <stdio.h>
#include <stdlib.h>
#include "fonction_LC.h"


void testInitialisation_LC(polynome** p)
{
    initialisation_LC(p);
    if(initialisation_LC(p) == 0)
    {
        printf("L'initialisation a echoue ");
    }
}

void testSaisir_LC(polynome** p1, polynome** p2)
{
    *p1 = saisir_LC(*p1, 5, 3);
    *p1 = saisir_LC(*p1, 3, 2);
    *p1 = saisir_LC(*p1, 1, 1);
    printf("Le polynome p1 est :"); afficher_LC(*p1);

    *p2 = saisir_LC(*p2, 2, 2);
    *p2 = saisir_LC(*p2, 3, 1);
    printf("Le polynome p2 est :"); afficher_LC(*p2);
}

void testSomme_LC(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = somme_LC(p1, p2);
    printf("La somme des polynomes p1 et p2 est :");
    afficher_LC(p3);
}

void testProduit_LC(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = produit_LC(p1, p2);
    printf("Le produit des polynomes p1 et p2 est :");
    afficher_LC(p3);
}

void testDerive_LC(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = derive_LC(p1);
    printf("la derivee de p1 est :");
    afficher_LC(p3);

    p3 = derive_LC(p2);
    printf("la derivee de p2 est :");
    afficher_LC(p3);

}

void testPrimitive_LC(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = primitive_LC(p1);
    printf("la primitive de p1 est :");
    afficher_LC(p3);

    p3 = primitive_LC(p2);
    printf("la primitive de p2 est :");
    afficher_LC(p3);
}


void testDeriveSommme_LC(polynome* p1, polynome* p2)
{
    polynome* p3;
    p3 = deriveSomme_LC(p1, p2);
    printf("La derivee de la somme de p1 et p2 est :");
    afficher_LC(p3);
}


void testDeriveProduit_LC(polynome* p1, polynome* p2)
{
    polynome* p3;

    p3 = deriveProduit_LC(p1, p2);
    printf("La derivee du produit de p1 et p2 est :");
    afficher_LC(p3);
}

void testCalcul_LC(polynome* p, double x)
{
    double resultat;

    resultat = calcul_LC(p, x);
    printf("Le resultat est %0.1f\n\n",resultat);
}

void testCalculHorner_LC(polynome* p, double x)
{
    double resultat;

    resultat = calculHorner_LC(p, x);
    printf("Le resultat est %0.1f\n\n",resultat);
}

void liberer(monome* liste)
{
    monome * m = NULL;
    while(liste != NULL)
    {
        m = liste->suivant;
        free(liste);
        liste = m;
    }
}

void test_LC()
{
    polynome* p1 = NULL;
    polynome* p2 = NULL;
    polynome* p3 = NULL;

    testInitialisation_LC(&p1);
    testInitialisation_LC(&p2);
    testInitialisation_LC(&p3);

    testSaisir_LC(&p1, &p2);

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
            case 1: testSomme_LC(p1, p2); break;

            case 2: testProduit_LC(p1, p2); break;

            case 3: testDerive_LC(p1, p2); break;

            case 4: testDeriveSommme_LC(p1, p2); break;

            case 5: testDeriveProduit_LC(p1, p2); break;

            case 6: testCalcul_LC(p1, 1); break;

            case 7: testCalculHorner_LC(p1, 1); break;

            case 8: testPrimitive_LC(p1, p2); break;

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

    liberer(p1->monomes); liberer(p2->monomes); liberer(p3->monomes);
    free(p1); free(p2); free(p3);
}

