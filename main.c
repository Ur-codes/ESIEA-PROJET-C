# include <stdio.h>

int main()
{
    //****************************************************************************************************
    // déclaration des différentes variables
    //****************************************************************************************************

    int nb_allumettes, save_nb_allumettes;
    int nb_allumettes_prises;
    int joueur = 1;
    int fin = 0;
    int regle = 0 , save_regle;
    int nb_joueur, save_nb_joueur;
    int rejouer = 1;
    int config_garder = 0;
    char nom_joueur[20];

    //****************************************************************************************************
    // introduction du jeu
    //****************************************************************************************************

    printf("\n============================================\n");
    printf("Bienvenue dans le jeu des allumettes !\n");
    printf("============================================\n\n");

    printf("Entrer votre prénom: ");
    scanf("%s", &nom_joueur);
    printf("Bonjour %s !\n", nom_joueur);

    printf("La partie va commencer, voulez vous un rappel des regles ? \n");
    printf("1. Oui\n");
    printf("2. Non\n");
    printf("Votre choix : ");
    scanf("%d", &regle);

    //****************************************************************************************************
    // vérification de la saisie de l'utilisateur pour les règles
    //****************************************************************************************************

    while (regle != 1 && regle != 2)
    {
        printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
        printf("Votre saisi : ");
        scanf("%d", &regle);
    }

    //****************************************************************************************************
    // affichage des règles si demander par l'utilisateur
    //****************************************************************************************************

    if (regle == 1)
    {
        printf("Le jeu se joue a deux joueurs ou contre un ordinateur.\n");
        printf("Au debut de la partie, il y a un nombre allumettes que vous aller choisir.\n");
        printf("A tour de role, les joueurs enlevent 1, 2 ou 3 allumettes.\n");
        printf("Celui qui prend la derniere allumette a perdu.\n\n");
    }

    //************************************************************************************************
    // configuration des paramètres de la partie (intervient au d"but et pour rejouer une partie)
    //************************************************************************************************

    if(config_garder != 1 )
    {
        printf("Avant de commencer la partie nous allons configurer les differents parametres.\n");
        printf("Combien de joueur vont jouer cette partie ?\n");
        printf("Saisir le nombre de joueur : \n");
        scanf("%d", &nb_joueur);

        //****************************************************************************************************
        // vérification de la saisie de l'utilisateur pour le nombre de joueur
        //****************************************************************************************************

        while (nb_joueur != 1 && nb_joueur != 2)
        {
            printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
            printf("Saisir le nombre de joueur : \n");
            scanf("%d", &nb_joueur);
        }
        printf("Maintenant, combien d'allumettes voulez vous mettre au debut de la partie ?\n");
        printf("Votre choix doit etre compris entre 10 et 100 \n");
        printf("Saisir le nombre d'allumettes : \n");
        scanf("%d", &nb_allumettes);

        //****************************************************************************************************
        // vérification de la saisie de l'utilisateur du nombre d'allumettes
        //****************************************************************************************************

        while (nb_allumettes <= 9 || nb_allumettes >=101)
        {
            printf("Vous avez saisi un nombre d'allumettes inferieur a 10 ou superieur a 100.\n");
            printf("Veuillez resaisir le nombre d'allumettes : \n");
            scanf("%d", &nb_allumettes);
        }
        printf("Vous avez choisi de jouer a %d joueur(s) et de mettre %d allumettes au debut de la partie.\n", nb_joueur, nb_allumettes);
    }

//****************************************************************************************************
// début de la partie
//****************************************************************************************************

    while (rejouer == 1) // variable a 1 quand une partie ce lance
    {
        //****************************************************************************************************
        // save des paramètres de la partie
        //****************************************************************************************************

        save_nb_allumettes = nb_allumettes;
        save_nb_joueur = nb_joueur;
        save_regle = regle;

        while (fin == 0) // temps que la parti n'est pas fini
        {
            while (nb_allumettes > 0) // temps qu'il reste des allumettes a retirer
            {
                //****************************************************************************************************
                // affichage des information de la partie
                //****************************************************************************************************
                printf("Il reste %d allumettes.\n", nb_allumettes);
                printf("Joueur %d, combien d'allumettes voulez-vous enlever ? ", joueur);
                scanf("%d", &nb_allumettes_prises);


                if (nb_allumettes_prises > 3 || nb_allumettes_prises < 1)
                {
                    printf("Vous ne pouvez pas enlever plus de 3 allumettes ou moins d'une allumette.\n");
                }
                else
                {
                    nb_allumettes = nb_allumettes - nb_allumettes_prises;
                    //****************************************************************************************************
                    // changement de joueur
                    //****************************************************************************************************
                    if (joueur == 1)
                    {
                        joueur = 2;
                    }
                    else
                    {
                        joueur = 1;
                    }
                }
            }
            printf("Le joueur %d gagne !\n", joueur);
            fin = 1;
        }


//****************************************************************************************************
// demande de rejouer une partie
// ****************************************************************************************************

        printf("Voulez vous rejouer ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        printf("Votre choix : ");
        scanf("%d", &rejouer);

        //****************************************************************************************************
        // vérification de la saisie de l'utilisateur pour rejouer une partie
        //****************************************************************************************************

        while  (rejouer != 1 && rejouer != 2)
        {
            printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
            printf("Votre choix : ");
            scanf("%d", &rejouer);
        }

        if (rejouer == 1)
        {
            printf("Vous avez choisi de rejouer.\n\n");
            fin = 0;
            nb_allumettes = save_nb_allumettes;
            nb_joueur = save_nb_joueur;
            regle = save_regle;


            printf("Voulez vous conserver les meme parametre que la derniere partie ?\n");
            printf("1. Oui\n");
            printf("2. Non\n");
            printf("Votre choix : ");
            scanf("%d", &config_garder);

            while (config_garder != 1 && config_garder != 2)
            {
                printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
                printf("Votre saisi : ");
                scanf("%d", &config_garder);
            }
            if (config_garder == 1)
            {
                printf("Vous avez choisi de conserver les meme parametre que la derniere partie.\n\n");
                printf("Voter choix a bien ete pris en compte.\n\n");
            }
            else
            {
                printf("Vous avez choisi de changer les parametre de la partie.\n\n");
                printf("Saisir le nombre de joueur : \n");
                scanf("%d", &nb_joueur);
                printf("Saisir le nombre d'allumettes : \n");
                scanf("%d", &nb_allumettes);
            }
        }
        else
        {
            printf("Vous avez choisi de ne pas rejouer.\n\n");
            printf("Merci d'avoir jouer et a bientot.\n\n");
        }
    }

    return 0;
}

