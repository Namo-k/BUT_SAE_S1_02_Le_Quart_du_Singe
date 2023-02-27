#pragma once

#ifndef _FONCTIONS_
#define _FONCTIONS_

/**
 * @file fonctions.h
 * @brief Entête du composant de fonctions
 */

 /**
 * @brief Les constantes
 */
enum {
	MIN_JOUEURS = 2,
	MAX = 28,
};

/**
* @brief Structure de données de type Dico
*/
struct Dico {
	char** mots;
	unsigned int nbMot;
};
/**
* @brief Structure de données de type Joueur
*/
struct Joueur {
	char type; // H ou R
	int score;
};
/**
* @brief Structure de données de type Partie
*/
struct Partie {
	Joueur* joueurs;
	unsigned int nbJoueurs;
	char* motTap; // Lettres annoncées pendant la partie
	unsigned int tailleMot;
	unsigned int posLettre; // Position où on doit insérer la lettre dans le mot
	unsigned int tourActuel; // Indice du joueur dans le tableau joueurs
	char* motTapVerif;
	Dico d;
};

/**
* @brief Verification du nombre de joueur
* @param[in] argv : L'argument utilisé pour compter le nombre de joueur
* @return retourne un booléan
* @pre argv valide
*/
bool verifNbJoueur(const char* argv[]);
/**
* @brief Vérifie le type de joueur
* @param[in] argv : L'argument utilisé pour vérifier le type de joueur
* @return Retourne un booléen
* @pre argv doit être valide
*/
bool verifJoueur(const char* argv[]);
/**
* @brief Charge le dictionnaire de mots
* @param[in,out] p: La partie à laquelle le dictionnaire est associé
* @pre p est valide
*/
void initialiserDico(Partie& p);
/**
* @brief Initialise une partie
* @param[in,out] p: La partie à initialiser
* @param[in] argv : Les arguments de la commande utilisés pour initialiser la partie
* @pre argv doit être valide
* @see initialiserDico
*/
void initialiserPartie(Partie& p, const char* argv[]);
/**
* @brief Vérifie si le mot tapé par le joueur est vide
* @param[in] p: La partie en cours
* @return Vrai si le mot tapé est vide, faux sinon
*/
bool estZeroLettre(Partie& p);
/**
* @brief Vérifie si le mot tapé par le joueur n'a qu'une seule lettre
* @param[in] p: La partie en cours
* @return Vrai si le mot tapé n'a qu'une seule lettre, faux sinon
*/
bool estPremiereLettre(Partie& p);
/**
* @brief Vérifie si le mot tapé par le joueur n'a que deux lettres ou qu'une lettre suivie d'un '?'
* @param[in] p: La partie en cours
* @return Vrai si le mot tapé n'a que deux lettres ou qu'une lettre suivie d'un '?', faux sinon
*/
bool estDeuxLettre(Partie& p);
/**
* @brief Vérifie si un mot est valide (si il est présent dans le dictionnaire de la partie)
* @param[in] p: La partie en cours
* @param[in] mot: Le mot à vérifier
* @return Vrai si le mot est valide, faux sinon
*/
bool estMotValide(Partie& p, char* mot);
/**
* @brief Agrandi la taille de la chaîne de caractère du mot tapé
* @param[in,out] p: La partie en cours
*/
void agrandir(Partie& p);
/**
* @brief Ajoute une lettre au mot tapé par le joueur
* @param[in,out] p: La partie en cours
* @param[in] c: La lettre à ajouter
*/
void ajoutLettre(Partie& p, char c);
/**
* @brief Demande à l'utilisateur de saisir une lettre et l'ajoute au mot tapé par le joueur
* @param[in,out] p: La partie en cours
*/
void saisiHumain(Partie& p);
/**
* @brief Vérifie si un caractère est une voyelle
* @param[in] c: Le caractère à vérifier
* @return Vrai si c est une voyelle, faux sinon
*/
bool estVoyelle(const char c);
/**
* @brief Vérifie si un caractère est une consonne
* @param[in] c: Le caractère à vérifier
* @return Vrai si c est une consonne, faux sinon
* @see estVoyelle
*/
bool estConsonne(const char c);
/**
* @brief Vérifie si le dernier caractère tapé par le joueur est un point d'interrogation
* @param[in,out] p: La partie en cours
* @return Vrai si le dernier caractère est un point d'interrogation, faux sinon
*/
bool ptInterrogation(Partie& p);
/**
* @brief Le robot tape un mot dans le cas où l'humain a tapé un point d'interrogation
* @param[in,out] p: La partie en cours
*/
void casPtInterroR(Partie& p);
/**
* @brief Cas du robot où il tape une lettre
* @param[in,out] p: La partie en cours
*/
void casNormalSaisiR(Partie& p);
/**
* @brief Génère une lettre aléatoire pour le robot
* @param[in,out] p: La partie en cours
*/
void saisiRobot(Partie& p);
/**
* @brief Fait jouer le joueur en cours
* @param[in,out] p: La partie en cours
*/
void jouer(Partie& p);
/**
* @brief Affiche le mot tapé par le joueur courant dans la partie en cours
* @param[in] p: La partie en cours
*/
void motSaisi(Partie& p);
/**
* @brief Affiche l'état de la partie en cours
* @param[in,out] p: La partie en cours
*/
void afficher(Partie& p);
/**
* @brief Fonction permettant de mettre à jour le score d'un joueur
* @param[in] p: La partie en cours
* @param[in] i: L'indice du joueur dont on veut mettre à jour le score
*/
void score(Partie& p, unsigned int i);
/**
* @brief Affiche les scores des joueurs
* @param[in] p: La partie en cours
*/
void afficheScore(Partie& p);
/**
* @brief Ajoute un point au score du joueur en cours
* @param[in,out] p: La partie en cours
*/
void ajouteScore(Partie& p);
/**
* @brief Réinitialiser la manche en cours
* @param[in,out] p : La partie en cours
*/
void resetManche(Partie& p);
/**
* @brief Message si le mot tapé par le joueur existe dans le dictionnaire
* @param[in,out] p : La partie en cours
*/
void motExiste(Partie& p);
/**
* @brief Message si le mot tapé par le joueur n'est pas le même que le mot tapé
* @param[in,out] p : La partie en cours
*/
void lettresDifferentes(Partie& p);
/**
* @brief Message si le mot tapé par le joueur existe
* @param[in,out] p : La partie en cours
*/
void motExisteVerif(Partie& p);
/**
* @brief Message si le mot tapé par le joueur n'existe pas
* @param[in,out] p : La partie en cours
*/
void motExistePas(Partie& p);
/**
* @brief Saisir un mot pour verifier s'il existe
* @param[in,out] p : La partie en cours
*/
void saisirMotTapVerif(Partie& p);
/**
* @brief Message si le joueur tape un point d'exclamation
* @param[in,out] p : La partie en cours
*/
void exclamation(Partie& p);
/**
* @brief Verifie si le caractère tapé est un point d'exclamation
* @param[in] p : La partie en cours
* @return Vrai si le dernier caractère est un point d'exclamation, faux sinon
*/
bool ptExclamation(Partie& p);
/**
* @brief Verifie si les caractère tapé sont les mêmes que le mot tapé
* @param[in] p : La partie en cours
* @return retourne un booléen
*/
bool verifLettres(Partie& p);
/**
* @brief Cas où c'est un point d'interrogation, on fais les vérifications
* @param[in,out] p : La partie en cours
*/
void verifInterrogation(Partie& p);
/**
* @brief Cas où c'est un point d'exclamation, on fait les vérifications
* @param[in,out] p : La partie en cours
*/
void verifExclamation(Partie& p);
/**
* @brief Cas normal, on regarde si le mot existe
* @param[in,out] p : La partie en cours
*/
void verifNormal(Partie& p);
/**
* @brief Fonction reunissant toutes les verifications
* @param[in,out] p : La partie en cours
*/
void verification(Partie& p);
/**
* @brief Le jeu
* @param[in, out] p : La partie en cours
*/
void jouerPartie(Partie& p);
/**
* @brief Détruit une partie et libère les ressources associées
* @param[in,out] p: La partie à détruire
*/
void detruirePartie(Partie& p);


#endif // !_FONCTIONS_