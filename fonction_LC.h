#ifndef FONCTION_LC_H
#define FONCTION_LC_H

typedef struct Monome{
    double coefficient;
    int degre;
    struct Monome * suivant;
}monome;

typedef struct Polynome{
    struct Monome * monomes;
    int n;
}polynome;

int initialisation_LC(polynome** p);
/// La fonction initialise un polynome dans lequel le seul monome est nul.
/// Elle alloue de la mémoire au pointeur polynome.
/// Elle a en paramètre un double pointeur polynome dans le but de modifier le pointeur p polynome sans avoir à le retourner.
/// Elle retoune 0 si le polynome n'a pas été initialiser et retourne 1 si le polynome a bien été initialisé.

polynome* saisir_LC(polynome* p, double coeff, int degre);
/// Fonction principal du projet, elle rajoute les valeurs du monomes renseigné en paramètre dans la liste chainée du monome.
/// Si le polynome est nul, elle l'initialise avant d'ajouter quoi que ce sois.
/// Elle range les monomes dans l'ordre décroissant selon les degrés
/// Si le degré renseigné est supérieur au premier degré, elle rajoute le monomes en en-tête
/// Si le degré renseigné est inférieur à un monome de la liste et que le noeud suivant est nul, elle rajoute le monome au noeud suivant.
/// Si le degré renseigné est inférieur à un monome de la liste et qu'en même temps il est supérieur au monome suivant, alors elle rajoute le monome entre les deux noeuds.
/// Si le degré est égale au degré d'un monome de la liste, elle additione les deux coefficients sans rajouter de nouveau noeud.
/// Ensuite elle retourne le polynome une fois sa liste chainée de monomes modifié.

void afficher_LC(const polynome* p);
/// Affiche le polynome mis en paramètre via une copie de la liste chainée de monomes
/// Cette copie rentre dans une boucle, permettant d'afficher le coefficient puis le dégrés de chaque monomes.
/// Elle affiche de cette manière : (coefficient, degrés) ...

polynome* somme_LC(polynome* p1, polynome* p2);
/// La fonction somme utilise la fonction Saisir.
/// Elle créée un nouveau polynome somme puis avec la fonction Saisir elle ajoute chacun des monomes de p1 puis de p2
/// Pour ce faire elle copie la liste chainée de p1 puis la rajoute dans le polynome somme via la fonction saisir ensuite elle fait de même pour p2.
/// Puisque la somme des monomes de même degrés est déjà faite par la fonction saisir il n'y a pas besoin de faire quoi que ce sois d'autre.
/// Enfin elle retourne le polynome somme.

polynome* produit_LC(polynome* p1, polynome* p2);
/// La fonction somme utilise la fonction Saisir.
/// Elle créée un nouveau polynome produit puis avec la fonction Saisir, elle copie la liste chainée de p1 et de p2 puis elle réduit le polynome qui résulte du produit de p1 et p2 et le met dans le polynome produit.
/// Pour ce faire elle utilise une double boucle, si p1 contient plus de monomes que p2 alors elle multiplie le premier monome de p1 avec tout les monomes de p2 puis fait la meme chose avec les monomes suivant de p1.
/// Sinon elle refait la même double boucle mais en inversant le rôle de p1 avec celui de p2.
/// Enfin elle retourne le polynome produit.

double calcul_LC(polynome* p, double x);
/// Créée une nouvelle variable résultat qui, par une boucle allant jusqu'au nombre total de monome via une copie, multiplie le coefficient et x, mis en paramètre, élevé à la puissance dégré du monome.
/// Elle retourne le resultat.

polynome* derive_LC(polynome* p);
/// La fonction derive utilise la fonction Saisir.
/// Elle créée un nouveau polynome derive qui passe dans une boucle permettant d'avancer dans la liste chainée de monomes via une copie.
/// Elle fait la dérivé de chacun des monomes du polynome mis en parametre et les range dans le polynome derive.
/// Puis elle retourne derive

polynome* deriveSomme_LC(polynome* p1, polynome* p2);
/// Créée un nouveau polynome derive somme
/// La fonction fait la dérivé de p1 puis de p2
/// Puis elle retourne la somme, par la fonction somme, des deux dérivés

polynome* deriveProduit_LC(polynome* p1, polynome* p2);
/// Créée un nouveau polynome derive produit
/// La fonction fait la dérivé de p1 puis de p2
/// Puis elle retourne le produit, par la fonction produit, des deux dérivés

double calculHorner_LC(polynome* p, double x);
/// Elle créée une nouvelle variable r initialisée à la valeur du coefficient du monomes de plus haut degré,
/// Ensuite par une boucle, elle multiplie cette variable r par la veleur de x puis l'additionne avec le coefficient du monome de degré inférieur.
/// Puis elle retourne le resultat.

polynome* primitive_LC(polynome* p);
/// La fonction primitive utilise la fonction Saisir.
/// Elle créée un nouveau polynome primitive qui passe dans une boucle permettant d'avancer dans lea liste chainée de monomes.
/// Elle fait la primitive de chacun des monomes du polynome mis en parametre et les range dans le polynome primitive.
/// Puis elle retourne primitive

#endif //FONCTION_LC_H
