#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct Monome {
    double coefficient;
    int degre;
} monome;

typedef struct Polynome{
    monome* monomes;
    int n;
    int degre;
} polynome;

int initialisation(polynome** p);
/// La fonction initialise un polynome dans lequel le seul monome est nul.
/// Elle alloue de la mémoire au pointeur et au tableau de monomes.
/// Elle a en paramètre un double pointeur polynome dans le but de modifier le pointeur p polynome sans avoir à le retourner.
/// Elle retoune 0 si le polynome n'a pas été initialiser et retourne 1 si le polynome a bien été initialisé.

void saisir(polynome** p, double coeff, int degre);
/// Fonction principal du projet,  elle rajoute les valeurs du monomes renseigné en paramètre dans le polynome.
/// Si le polynome est nul, elle l'initialise avant d'ajouter quoi que ce sois.
/// Si dans le polynome il y a un degré égal au degré renseigné elle additionne juste les coefficient dans le but d'avoir un polynome réduit.
/// Sinon elle réalloue la taille du tableau de monomes et lui rajoute le nouveau monome.
/// Ensuite elle trie chacun des monomes dans l'orde décroissant selon leurs degrés.
/// Pour finir elle détermine le degré le plus haut du polynome.

void afficher(polynome* p);
/// Affiche le polynome mis en paramètre par une boucle, en affichant le coefficient puis le dégrés de chaque monomes.
/// Elle affiche de cette manière : (coefficient, degrés) ...


polynome* somme(polynome* p1, polynome* p2);
/// La fonction somme utilise la fonction Saisir.
/// Elle créée un nouveau polynome somme puis avec la fonction Saisir elle ajoute chacun des monomes de p1 puis de p2 via une boucle.
/// Puisque la somme des monomes de même degrés est déjà faite par la fonction saisir il n'y a pas besoin de faire quoi que ce sois d'autre.
/// Enfin elle retourne le polynome somme.

polynome* produit(polynome* p1, polynome* p2);
/// La fonction somme utilise la fonction Saisir.
/// Elle créée un nouveau polynome produit puis avec la fonction Saisir, elle réduit le polynome qui résulte du produit de p1 et p2 et le met dans le polynome produit.
/// Pour ce faire elle utilise une double boucle, si p1 contient plus de monomes que p2 alors elle multiplie le premier monome de p1 avec tout les monomes de p2 puis fait la meme chose avec les monomes suivant de p1.
/// Sinon elle refait la même double boucle mais en inversant le rôle de p1 avec celui de p2.
/// Enfin elle retourne le polynome produit.

double calcul(polynome* p, double x);
/// Créée une nouvelle variable résultat qui, par une boucle allant jusqu'au nombre total de monome, multiplie le coefficient et x, mis en paramètre, élevé à la puissance dégré du monome.
/// Elle retourne le resultat.

polynome* derive(polynome* p);
/// La fonction derive utilise la fonction Saisir.
/// Elle créée un nouveau polynome derive qui passe dans une boucle permettant d'avancer dans le tableau de monome.
/// Elle fait la dérivé de chacun des monomes du polynome mis en parametre et les range dans le polynome derive.
/// Puis elle retourne derive


polynome* deriveSomme(polynome* p1, polynome* p2);
/// Créée un nouveau polynome derive somme
/// La fonction fait la dérivé de p1 puis de p2
/// Puis elle retourne la somme, par la fonction somme, des deux dérivés

polynome* deriveProduit(polynome* p1, polynome* p2);
/// Créée un nouveau polynome derive produit
/// La fonction fait la dérivé de p1 puis de p2
/// Puis elle retourne le produit, par la fonction produit, des deux dérivés

double calculHorner(polynome* p, double x);
/// Elle créée une nouvelle variable r initialisée à la valeur du coefficient du monomes de plus haut degré,
/// Ensuite par une boucle, elle multiplie cette variable r par la veleur de x puis l'additionne avec le coefficient du monome de degré inférieur.
/// Puis elle retourne le resultat.

polynome* primitive(polynome* p);
/// La fonction primitive utilise la fonction Saisir.
/// Elle créée un nouveau polynome primitive qui passe dans une boucle permettant d'avancer dans le tableau de monome.
/// Elle fait la primitive de chacun des monomes du polynome mis en parametre et les range dans le polynome primitive.
/// Puis elle retourne primitive

#endif //FONCTIONS_H
