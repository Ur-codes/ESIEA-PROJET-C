# include <stdio.h>

int main()
{

    int nb_allumettes;
    int nb_allumettes_prises;
    int joueur = 1;
    int fin = 0;
    int regle ;
    int nb_joueur;
    int rejouer = 1;
    int Config_garder;

    printf("\n============================================\n");
    printf("Bienvenue dans le jeu des allumettes !\n");
    printf("============================================\n\n");
    printf("La partie va commencer, voulez vous un rappel des regles ?\n");
    printf("1. Oui\n");
    printf("2. Non\n");
    printf("Votre choix : ");
    scanf("%d", &regle);

    printf("Hello World");

        while (regle != 1 || regle != 2)
        {
            printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
            printf("Votre saisi : ");
            scanf("%d", &regle);
        }
        if (regle == 1)
        {
            printf("Le jeu se joue a deux joueurs ou contre un ordinateur.\n");
            printf("Au debut de la partie, il y a un nombre allumettes que vous aller choisir.\n");
            printf("A tour de role, les joueurs enlèvent 1, 2 ou 3 allumettes.\n");
            printf("Celui qui prend la derniere allumette a perdu.\n\n");
        }
        if(Config_garder ==1 )
        {
            printf("Vous avez choisi de garder les regles par defaut.\n\n");
        }
        else
        {
            printf("Avant de commencer la partie nous allons configurer les différents paramètres.\n");
            printf("Combien de joueur vont jouer cette partie ?\n");
            printf("Saisir le nombre de joueur : \n");
            scanf("%d", &nb_joueur);
            while (nb_joueur != 1 || nb_joueur != 2)
            {
                printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
                printf("Saisir le nombre de joueur : \n");
                scanf("%d", &nb_joueur);
            }
            printf("Maintenant, combien d'allumettes voulez vous mettre au debut de la partie ?\n");
            printf("Votre choix doit etre compris entre 10 et 100 \n");
            printf("Saisir le nombre d'allumettes : \n");
            scanf("%d", &nb_allumettes);
            while (nb_allumettes < 10 || nb_allumettes > 100)
            {
                printf("Vous avez saisi un nombre d'allumettes inferieur a 10 ou superieur a 100.\n");
                printf("Veuillez resaisir le nombre d'allumettes : \n");
                scanf("%d", &nb_allumettes);
            }
            printf("Vous avez choisi de jouer a %d joueur(s) et de mettre %d allumettes au debut de la partie.\n", nb_joueur, nb_allumettes);
        }
    }

    while (rejouer == 1)
    {
        while (fin == 0)
        {
            while (nb_allumettes > 0)
            {
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
        printf("Voulez vous rejouer ?\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        printf("Votre choix : ");
        scanf("%d", &rejouer);
        if (rejouer != 1 || rejouer != 2)
        {
            while (rejouer != 1 && rejouer != 2)
            {
                printf("Vous avez saisi autre chose que 1 ou 2 donc veillez resaissir votre choix\n");
                scanf("%d", &rejouer);
            }
            if (rejouer == 1)
            {
                printf("Vous avez choisi de rejouer.\n\n");
                printf("Voulez vous conserver les meme parametre que la derniere partie ?\n");
                printf("1. Oui\n");
                printf("2. Non\n");
                printf("Votre choix : ");
                scanf("%d", &Config_garder);
                printf("Voter choix a bien ete pris en compte.\n\n");
            }
            if (rejouer == 2)
            {
                printf("Au revoir et a bientot !\n");

            }
        }
    }

    return 0;
}