#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonction_LC.h"

int initialisation_LC(polynome** p)
{
    *p = (polynome*) malloc(sizeof(polynome));

    (*p)->monomes = (monome*) malloc(sizeof(monome));

    if(*p == NULL && (*p)->monomes == NULL)
    {return 0;}

    (*p)->monomes->suivant = NULL;
    (*p)->monomes->coefficient = 0;
    (*p)->monomes->degre = 0;
    (*p)->n = 1;

    return 1;
}

polynome* saisir_LC(polynome* p, double coeff, int degre)
{
    if(p == NULL)
    {initialisation_LC(&p);}


    monome* nouveau = NULL;
    monome* copie = NULL;

    copie = p->monomes;

    if(degre > copie->degre)
    {
        nouveau = (monome*) malloc(sizeof(monome));

        nouveau->suivant = copie;

        nouveau->coefficient = coeff;
        nouveau->degre = degre;

        copie = nouveau;

        p->monomes = copie;
        p->n += 1;

        return p;
    }else
    {
        while (copie != NULL)
        {

            if(copie->degre > degre && copie->suivant == NULL)
            {
                copie->suivant->degre = degre;
                copie->suivant->coefficient = coeff;

                p->n += 1;

                return p;
            }else
            {
                if (copie->degre == degre)
                {
                    copie->coefficient += coeff;

                    return p;
                }else
                {
                    if(copie->degre > degre && degre > copie->suivant->degre)
                    {
                        nouveau = (monome*) malloc(sizeof(monome));

                        nouveau->degre = degre;
                        nouveau->coefficient = coeff;

                        nouveau->suivant = copie->suivant;

                        copie->suivant = nouveau;

                        p->n += 1;

                        return p;
                    }else
                    {
                        copie = copie->suivant;
                    }
                }
            }
        }
    }
}

void afficher_LC(const polynome* p)
{
    monome* courant = NULL;

    courant = p->monomes;

    while (courant != NULL)
    {
        printf("(%0.1f,%d) ", courant->coefficient, courant->degre);
        courant = courant->suivant;
    }
    printf ("\n\n");
}

polynome* somme_LC(polynome* p1, polynome* p2)
{
    polynome* somme = NULL;
    monome* copie = NULL;

    copie = p1->monomes;

    while(copie != NULL)
    {
        somme = saisir_LC(somme, copie->coefficient, copie->degre);
        copie = copie->suivant;
    }

    copie = p2->monomes;

    while(copie != NULL)
    {
        somme = saisir_LC(somme, copie->coefficient, copie->degre);
        copie = copie->suivant;
    }

    return somme;
}

polynome* produit_LC(polynome* p1, polynome* p2)
{
    polynome* produit = NULL;
    monome* copie_1 = NULL;
    monome* copie_2 = NULL;

    copie_1 = p1->monomes; copie_2 = p2->monomes;

    while (copie_1 != NULL)
    {
        while(copie_2 != NULL)
        {
            produit = saisir_LC(produit, copie_1->coefficient * copie_2->coefficient, copie_1->degre + copie_2->degre);
            copie_2 = copie_2->suivant;
        }
        copie_2 = p2->monomes;
        copie_1 = copie_1->suivant;
    }

    return produit;
}

double calcul_LC(polynome* p, double x)
{
    double resultat = 0;

    monome* copie = NULL;
    copie = p->monomes;

    while(copie != NULL)
    {
        resultat += copie->coefficient * pow(x, copie->degre);
        copie = copie->suivant;
    }

    return resultat;
}

polynome* derive_LC(polynome* p)
{
    polynome* derive = NULL;

    monome* copie = NULL;
    copie = p->monomes;

    while(copie != NULL)
    {
        if(copie->degre == 0)
        {
            derive = saisir_LC(derive, 0, 0);
        }else
        {
            derive = saisir_LC(derive, copie->coefficient * copie->degre, copie->degre - 1);
        }

        copie = copie->suivant;
    }

    return derive;
}

polynome* deriveSomme_LC(polynome* p1, polynome* p2)
{
    polynome* deriveSomme = NULL;

    p1 = derive_LC(p1); p2 = derive_LC(p2);
    deriveSomme = somme_LC(p1, p2);

    return deriveSomme;
}

polynome* deriveProduit_LC(polynome* p1, polynome* p2)
{
    polynome* deriveProduit = NULL;

    polynome* p1d = NULL;
    p1d = derive_LC(p1);

    polynome* p2d = NULL;
    p2d = derive_LC(p2);

    deriveProduit = somme_LC(produit_LC(p1d, p2), produit_LC(p1, p2d));

    return deriveProduit;
}

double calculHorner_LC(polynome* p, double x)
{
    monome* copie = NULL;
    copie = p->monomes;

    double r = copie->coefficient;

    while(copie->suivant != NULL)
    {
        r = r*x + copie->suivant->coefficient;
        copie = copie->suivant;
    }

    return r;
}

polynome* primitive_LC(polynome* p)
{
    polynome* primitive = NULL;

    monome* copie = NULL;
    copie = p->monomes;

    while(copie != NULL)
    {
        {
            primitive = saisir_LC(primitive, (copie->coefficient / (copie->degre + 1)), copie->degre + 1);
        }

        copie = copie->suivant;
    }

    return primitive;
}