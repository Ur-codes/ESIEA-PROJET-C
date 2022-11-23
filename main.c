#include <stdio.h>
#include <stdlib.h>


char nom_joueur2[20];


void verification_utilisateur(int regle) {

    switch (regle) {

        case 1:

            printf("\n");
            printf("Le jeu se joue a deux joueurs ou contre un ordinateur.\n");
            printf("Au debut de la partie, il y a un nombre allumettes que vous aller choisir.\n");
            printf("A tour de role, les joueurs enlevent 1, 2 ou 3 allumettes.\n");
            printf("Celui qui prend la derniere allumette a perdu.\n\n");
            break;

        case 2:

            break;

        default:

            printf("\n");
            printf("Erreur ! Vous n'avez pas choisi une option valide !\n");
            printf("Voulez vous un rappel des regles ? \n");
            printf("1. OUI\n");
            printf("2. NON\n");
            printf("Votre choix : ");
            scanf("%*[^0-9]%d", &regle);
            verification_utilisateur(regle);
    }
}

void verification_joueur(int nb_joueur) {

    switch (nb_joueur) {

        case 1:

            printf("\n");
            printf("Vous avez choisi de jouer contre l'ordinateur.\n");
            break;

        case 2:

            printf("\n");
            printf("Vous avez choisi de jouer a deux joueurs.\n");
            printf("Veuillez entrer le nom du joueur 2 : ");
            scanf("%s", &nom_joueur2);
            printf("\n");
            printf("Bonjour %s !\n", nom_joueur2);
            break;

        default:

            printf("\n");
            printf("Erreur ! Vous n'avez pas choisi une option valide !\n");
            printf("\n");
            printf("Combien de joueurs vont jouer cette partie 1 ou 2 ?\n");
            printf("Saisir le nombre de joueur : \n");
            scanf("%*[^1-2]%d", &nb_joueur);
            verification_joueur(nb_joueur);
    }
}

void verification_mode_jeu(int mode_jeu) {

    switch (mode_jeu) {

        case 1:
            printf("\n");
            printf("Vous avez choisi le mode Classique !\n");
            break;

        case 2:

            printf("\n");
            printf("Vous avez choisi le mode Custom !\n");
            break;

        default:

            printf("\n");
            printf("Erreur ! Vous n'avez pas choisi une option valide ! \n");
            printf("1. Mode Classique : 30 allumettes\n");
            printf("2. Mode Custom : 10 a 100 allumettes\n");
            printf("Votre choix : ");
            scanf("%*[^0-9]%d", &mode_jeu);
            verification_mode_jeu(mode_jeu);
    }
}

void verification_difficulte(int difficulte) {

    switch (difficulte) {

        case 1:

            printf("\n");
            printf("Vous avez choisi le mode Facile !\n");
            break;

        case 2:

            printf("\n");
            printf("Vous avez choisi le mode Difficile !\n");
            break;

        default:

            printf("\n");
            printf("Erreur ! Vous n'avez pas choisi une option valide !\n");
            printf("1. Facile \n");
            printf("2. Difficile\n");
            printf("Votre choix : ");
            scanf("%*[^0-9]%d", &difficulte);
            verification_difficulte(difficulte);
    }
}

void verification_allumette(int nb_allumettes) {

    switch (nb_allumettes) {

        case 10 ... 100:
            printf("Vous avez choisi de jouer avec %d allumettes !\n", nb_allumettes);
            break;
        default:

            printf("\n");
            printf("Erreur ! Vous n'avez pas choisi une option valide !\n");
            nb_allumettes = 0;
            printf("Veuillez saisir un nombre d'allumettes entre 10 et 100 : ");
            scanf("%*[^0-9]%d", &nb_allumettes);
            verification_allumette(nb_allumettes);


    }
}


void main() {

    //****************************************************************************************************
    // déclaration des différentes variables
    //****************************************************************************************************

    int nb_allumettes;
    int nb_allumettes_prises;
    int fin = 0;
    int regle = 0;
    int mode_jeu = 0;
    char nom_joueur[20];
    int difficulte = 0;
    int nb_joueur = 0;

    //****************************************************************************************************
    // introduction du jeu
    //****************************************************************************************************

    printf("\n============================================\n");
    printf("Bienvenue dans le jeu des allumettes !\n");
    printf("============================================\n\n");
    printf("La partie va commencer, voulez vous un rappel des regles ? \n");
    printf("1. Oui\n");
    printf("2. Non\n");
    printf("Votre choix : ");
    scanf("%*[^1-2]%d", &regle);

    //****************************************************************************************************
    // vérification de la saisie de l'utilisateur pour les règles
    //****************************************************************************************************

    verification_utilisateur(regle);

    //****************************************************************************************************
    // affichage du prenom du joueur
    //****************************************************************************************************

    printf("\n");
    printf("Entrer votre nom : ");
    scanf("%s", &nom_joueur);
    printf("\n");
    printf("Bonjour %s !\n", nom_joueur);

    //****************************************************************************************************
    // demande et vérification de la saisie de l'utilisateur pour le nombre de joueur
    //****************************************************************************************************

    printf("\n");
    printf("Avant de commencer la partie nous allons configurer les differents parametres.\n");
    printf("Combien de joueur vont jouer cette partie 1 ou 2 ?\n");
    printf("Saisir le nombre de joueur : ");
    scanf("%*[^1-2]%d", &nb_joueur);
    verification_joueur(nb_joueur);

    //****************************************************************************************************
    // demande et vérification de la saisie de l'utilisateur pour le mode de jeu
    //****************************************************************************************************

    printf("\n");
    printf("Bien, maintenant veuillez selectionner le mode de jeu.\n");
    printf("1. Mode Classique : 30 allumettes\n");
    printf("2. Mode Custom : 10 a 100 allumettes\n");
    printf("Votre choix : ");
    scanf("%*[^0-9]%d", &mode_jeu);

    verification_mode_jeu(mode_jeu);

    //****************************************************************************************************
    // attribution des allumettes en fonction du mode de jeu
    //****************************************************************************************************

    if (mode_jeu == 1) {
        nb_allumettes = 30;
    }
    else {

        printf("Maintenant, combien d'allumettes voulez vous mettre au debut de la partie ?\n");
        printf("Votre choix doit etre compris entre 10 et 100 \n");
        printf("Saisir le nombre d'allumettes : ");
        scanf("%*[^0-9]%d", &nb_allumettes);
        verification_allumette(nb_allumettes);
    }

    //****************************************************************************************************
    // confirmation a l'utilisateur pour le nombre de joueur
    //****************************************************************************************************

    if (nb_joueur == 1) {
        printf("\n");
        printf("Vous avez choisi de jouer contre l'ordinateur.\n");
        printf("Veuillez choisir la difficulte de l'ordinateur.\n");
        printf("1. Facile\n");
        printf("2. Difficile\n");
        printf("Votre choix : ");
        scanf("%*[^0-9]%d", &difficulte);
        verification_difficulte(difficulte);
    } else {
        printf("\n");
        printf("Vous avez choisi de jouer contre un autre joueur.\n");
    }




//****************************************************************************************************
// début de la partie
//****************************************************************************************************


    while (fin == 0)
    {
        printf("\n");
        printf("Il reste %d allumettes.\n", nb_allumettes);
        for (int i = 0; i < nb_allumettes; i++) {
            printf("|");
        }
        printf("\n");
        while (nb_allumettes > 0) // temps qu'il reste des allumettes a retirer
        {
            //****************************************************************************************************
            // affichage des information de la partie
            //****************************************************************************************************


            if (nb_joueur == 1) {

                //****************************************************************************************************
                // tour du joueur en mode contre l'ordinateur
                //****************************************************************************************************

                printf("\n");
                printf("Tour du joueur %s\n", nom_joueur);
                printf("\n" "Joueur %s, combien d'allumettes voulez-vous enlever ? ", nom_joueur);
                scanf("%*[^0-9]%d", &nb_allumettes_prises);
                if (nb_allumettes_prises > 3 || nb_allumettes_prises < 1) {
                    printf("Vous ne pouvez pas enlever plus de 3 allumettes ou moins d'une allumette.\n");
                }
                else {
                    if (nb_allumettes_prises > nb_allumettes) {
                        printf("Vous ne pouvez pas enlever plus d'allumettes que ce qu'il y a sur le plateau.\n");
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");

                        }
                        printf("\n");
                    }
                    else {
                        nb_allumettes = nb_allumettes - nb_allumettes_prises;
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");
                        }
                        printf("\n");

                    }
                }
                if (nb_allumettes == 0) {
                    printf("L'ordinateur a gagne !\n");
                    fin = 1;

                }

                    //********************************************************************************************
                    // comportement de l'ordinateur en mode facile
                    //********************************************************************************************

                else {
                    if (difficulte == 1) {
                        printf("\n");
                        printf("Tour de l'ordinateur\n");
                        if (nb_allumettes == 1 || nb_allumettes == 2 || nb_allumettes == 3) {
                            nb_allumettes_prises = 1;
                        }
                        else {
                            nb_allumettes_prises = 1 + rand() % 3;
                        }
                        printf("L'ordinateur a enleve %d allumettes.\n", nb_allumettes_prises);
                        nb_allumettes = nb_allumettes - nb_allumettes_prises;
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");
                        }
                        printf("\n");
                        if (nb_allumettes == 0) {
                            printf("Le joueur %s a gagne !\n", nom_joueur);
                            fin = 1;

                        }
                    }

                        //****************************************************************************************
                        // comportement de l'ordinateur en mode difficile
                        //****************************************************************************************

                    else {
                        printf("Tour de l'ordinateur\n");
                        if (nb_allumettes == 1 ) {
                            nb_allumettes_prises = 1;
                        }
                        else if (nb_allumettes == 2 ) {
                            nb_allumettes_prises = 1;
                        }
                        else if (nb_allumettes == 3 ) {
                            nb_allumettes_prises = 2;
                        }
                        else if (nb_allumettes == 4 ) {
                            nb_allumettes_prises = 3;
                        }
                        else{
                            nb_allumettes_prises = (nb_allumettes - 1) % 4;
                        }
                        printf("L'ordinateur a enleve %d allumettes.\n", nb_allumettes_prises);
                        nb_allumettes = nb_allumettes - nb_allumettes_prises;
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");
                        }
                        printf("\n");
                        if (nb_allumettes == 0) {
                            printf("Le joueur %s a gagne !\n", nom_joueur);
                            fin = 1;
                        }

                    }
                }
            }

                //****************************************************************************************************
                // tour du joueur 1 en mode contre un autre joueur
                //****************************************************************************************************

            else{
                printf("\n");
                printf("Tour du joueur %s\n", nom_joueur);
                printf("\n" "Joueur %s, combien d'allumettes voulez-vous enlever ? ", nom_joueur);
                scanf("%*[^0-9]%d", &nb_allumettes_prises);
                if (nb_allumettes_prises > 3 || nb_allumettes_prises < 1) {
                    printf("Vous ne pouvez pas enlever plus de 3 allumettes ou moins d'une allumette.\n");
                }
                else {
                    if (nb_allumettes_prises > nb_allumettes) {
                        printf("Vous ne pouvez pas enlever plus d'allumettes que ce qu'il y a sur le plateau.\n");
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");
                        }
                        printf("\n");
                    }
                    else {
                        nb_allumettes = nb_allumettes - nb_allumettes_prises;
                        printf("Il reste %d allumettes.\n", nb_allumettes);
                        for (int i = 0; i < nb_allumettes; i++) {
                            printf("|");
                        }
                        printf("\n");
                    }
                    if (nb_allumettes == 0) {
                        printf("Le joueur %s a gagne !\n", nom_joueur2);
                        fin = 1;
                    }
                        //****************************************************************************************************
                        // tour du joueur 2 en mode contre un autre joueur
                        //****************************************************************************************************

                    else {
                        printf("\n");
                        printf("Tour du joueur %s\n", nom_joueur2);
                        printf("\n" "Joueur %s, combien d'allumettes voulez-vous enlever ? ", nom_joueur2);
                        scanf("%*[^0-9]%d", &nb_allumettes_prises);
                        if (nb_allumettes_prises > 3 || nb_allumettes_prises < 1) {
                            printf("Vous ne pouvez pas enlever plus de 3 allumettes ou moins d'une allumette.\n");
                        }
                        else {
                            if (nb_allumettes_prises > nb_allumettes) {
                                printf("Vous ne pouvez pas enlever plus d'allumettes que ce qu'il y a sur le plateau.\n");
                                printf("Il reste %d allumettes.\n", nb_allumettes);
                                for (int i = 0; i < nb_allumettes; i++) {
                                    printf("|");
                                }
                                printf("\n");
                            }
                            else {
                                nb_allumettes = nb_allumettes - nb_allumettes_prises;
                                printf("Il reste %d allumettes.\n", nb_allumettes);
                                for (int i = 0; i < nb_allumettes; i++) {
                                    printf("|");
                                }
                                printf("\n");
                            }
                            if (nb_allumettes == 0) {
                                printf("Le joueur %s a gagne !\n", nom_joueur);
                                fin = 1;
                            }
                        }
                    }

                }
            }
        }
    }
    printf("Fin du jeu.\n");
    printf("Merci d'avoir joue !\n");
}


//PROJET C ESIEA 2022-2023
