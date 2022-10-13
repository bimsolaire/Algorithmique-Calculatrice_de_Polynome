#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"


int initialisation(polynome** p)
{
    *p = malloc(sizeof(polynome));

    (*p)->n = 1;
    (*p)->monomes = malloc((*p)->n*sizeof(monome));

    if(*p == NULL || (*p)->monomes == NULL)
    {
        return 0;
    }

    (*p)->monomes[0].degre = 0;
    (*p)->monomes[0].coefficient = 0;

    (*p)->degre = 0;

    return 1;
}

void saisir(polynome** p, double coeff, int degre)
{
    if(*p == NULL)
    {initialisation(p);}

    int test = 0;
    for (int i=0; i < (*p)->n; i++)
    {
        if ((*p)->monomes[i].degre == degre)
        {
            (*p)->monomes[i].coefficient += coeff;
            test = 1;
        }
    }

    if(test == 0)
    {
        (*p)->n += 1;
        monome* tp = NULL;
        tp = realloc((*p)->monomes, (*p)->n*sizeof(monome));
        (*p)->monomes = tp;

        if((*p)->monomes == NULL)
        {exit(EXIT_FAILURE);}
        else
        {
            (*p)->monomes[(*p)->n - 1].degre = degre;
            (*p)->monomes[(*p)->n - 1].coefficient = coeff;
        }
    }

    double temp;
    int temp2;

    for (int i = 0; i < (*p)->n; i++)
    {
        for (int j = i+1; j < (*p)->n; j++)
        {
            if((*p)->monomes[i].degre < (*p)->monomes[j].degre)
            {
                temp2 = (*p)->monomes[i].degre;
                (*p)->monomes[i].degre = (*p)->monomes[j].degre;
                (*p)->monomes[j].degre = temp2;

                temp = (*p)->monomes[i].coefficient;
                (*p)->monomes[i].coefficient = (*p)->monomes[j].coefficient;
                (*p)->monomes[j].coefficient = temp;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < (*p)->n; i++)
    {
        if((*p)->monomes[i].degre > max)
        {
            max = (*p)->monomes[i].degre;
        }
    }
    (*p)->degre = max;
}

void afficher(polynome* p)
{
    for(int i = 0; i < p->n; i++)
    {
        printf("(%0.1f, ",p->monomes[i].coefficient);

        printf("%d) ",p->monomes[i].degre);
    }
    printf("\n\n");
}

polynome* somme(polynome* p1, polynome* p2)
{
    polynome* somme = NULL;

    for(int i = 0; i < p1->n; i++)
    {
        saisir(&somme, p1->monomes[i].coefficient, p1->monomes[i].degre);
    }
    for(int i = 0; i < p2->n; i++)
    {
        saisir(&somme, p2->monomes[i].coefficient, p2->monomes[i].degre);
    }

    return somme;
}

polynome* produit(polynome* p1, polynome* p2)
{
    polynome* produit = NULL;

    for(int i= 0; i < p1->n; i++)
    {
        for(int j = 0; j < p2->n; j++)
        {
            saisir(&produit, p1->monomes[i].coefficient * p2->monomes[j].coefficient, p1->monomes[i].degre + p2->monomes[j].degre);
        }
    }

    return produit;
}

double calcul(polynome* p, double x)
{
    double resultat = 0;

    for (int i =0; i < p->n; i++)
    {
        resultat += p->monomes[i].coefficient * pow(x, p->monomes[i].degre);
    }

    return resultat;
}

polynome* derive(polynome* p)
{
    polynome* derive = NULL;

    for (int i =0; i < p->n; i++)
    {
        if(p->monomes[i].degre == 0)
        {
            saisir(&derive, 0, 0);
        }else
        {
            saisir(&derive, p->monomes[i].coefficient * p->monomes[i].degre, p->monomes[i].degre - 1);
        }
    }

    return derive;
}

polynome* deriveSomme(polynome* p1, polynome* p2)
{
    polynome* deriveSomme = NULL;

    p1 = derive(p1); p2 = derive(p2);
    deriveSomme = somme(p1, p2);

    return deriveSomme;
}

polynome* deriveProduit(polynome* p1, polynome* p2)
{
    polynome* deriveProduit = NULL;

    polynome* p1d = NULL;
    p1d = derive(p1);

    polynome* p2d = NULL;
    p2d = derive(p2);

    deriveProduit = somme(produit(p1d, p2), produit(p1, p2d));

    return deriveProduit;
}

double calculHorner(polynome* p, double x)
{
    double r = p->monomes[0].coefficient;

    for(int i = 1; i < p->n; i++)
    {
        r = r*x + p->monomes[i].coefficient;
    }

    return r;
}

polynome* primitive(polynome* p)
{
    polynome* primitive = NULL;

    for (int i =0; i < p->n; i++)
    {
            saisir(&primitive, (p->monomes[i].coefficient / ((p)->monomes[i].degre + 1)), p->monomes[i].degre + 1);
    }

    return primitive;
}
