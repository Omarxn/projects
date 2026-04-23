#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <myconio.h>

int main()
{

    int   choix;
    float money = 0;
    float rendu;
    int   cptCafe = 0, cptThe = 0, cptChoco = 0, cptCapp = 0;
    float ca = 0;
    

    FILE *f;
    FILE *caFile;
    FILE *cptFile;


    caFile = fopen("ca.dat", "r");
    if (caFile != NULL)
    {
        fscanf(caFile, "%f", &ca);
        fclose(caFile);
    }


    cptFile = fopen("cpt.dat", "r");
    if (cptFile != NULL)
    {
        fscanf(cptFile, "%d %d %d %d", &cptCafe, &cptThe, &cptChoco, &cptCapp);
        fclose(cptFile);
    }


    f = fopen("vente.dat", "a");
    if (f == NULL)
    {
        printf("Erreur ouverture fichier vente.dat");
        return 1;
    }


    do
    {

        // le menu client
        system("cls");

        textcolor(9);
        for (int i = 0; i <= 55; i++) printf("*");
        printf("\n\n* ");
        textcolor(WHITE);
        printf("   BIENVENUE AU DISTRIBUTEUR AUTOMATIQUE   ");
        textcolor(9);
        printf(" *\n\n");
        for (int i = 0; i <= 55; i++) printf("*");

        printf("\n\n");
        textcolor(WHITE);
        printf("* *\n\n");

        printf("* ");
        textcolor(YELLOW);
        printf("1. ");
        textcolor(WHITE);
        printf("Cafe Court");
        for (int i = 0; i <= 20; i++) printf(".");
        textcolor(GREEN);
        printf(" 4.00 DH");
        textcolor(WHITE);
        printf("  *\n\n");

        printf("* ");
        textcolor(YELLOW);
        printf("2. ");
        textcolor(WHITE);
        printf("The a la Menthe");
        for (int i = 0; i <= 15; i++) printf(".");
        textcolor(GREEN);
        printf(" 5.00 DH");
        textcolor(WHITE);
        printf("  *\n\n");

        printf("* ");
        textcolor(YELLOW);
        printf("3. ");
        textcolor(WHITE);
        printf("Chocolat Chaud");
        for (int i = 0; i <= 16; i++) printf(".");
        textcolor(GREEN);
        printf(" 6.00 DH");
        textcolor(WHITE);
        printf("  *\n\n");

        printf("* ");
        textcolor(YELLOW);
        printf("4. ");
        textcolor(WHITE);
        printf("Cappuccino");
        for (int i = 0; i <= 20; i++) printf(".");
        textcolor(GREEN);
        printf(" 8.00 DH");
        textcolor(WHITE);
        printf("  *\n\n");

        printf("* *\n\n");
        printf("* ");
        textcolor(7);
        printf("0. Quitter le programme                     *\n\n");
        printf("* ");
        textcolor(RED);
        printf("999. ESPACE ADMINISTRATION                  *\n\n");
        textcolor(WHITE);
        printf("* *\n\n");

        textcolor(9);
        for (int i = 0; i <= 55; i++) printf("*");
        textcolor(WHITE);
        printf("\n\nSaisissez votre choix : ");
        textcolor(YELLOW);
        scanf("%d", &choix);
        textcolor(WHITE);


        if (choix == 1)
        {
            money = 0;
            printf("\n");
            do
            {
                printf("Inserez une piece (1 / 2 / 5 / 10 / 20 DH) : ");
                float piece;
                
                scanf("%f", &piece);
                

                if (piece != 1 && piece != 2 && piece != 5 && piece != 10 && piece != 20)
                {
                    textcolor(RED);
                    printf("Piece invalide !\n");
                    textcolor(WHITE);
                }
                else
                {
                    money += piece;
                    textcolor(YELLOW);
                    printf("Montant insere : %.2f DH\n", money);
                    textcolor(WHITE);
                    
                    if (money < 4.00)
                    {
                        textcolor(RED);
                        printf("Il vous reste %.2f DH a payer\n", 4.00f - money);
                        textcolor(WHITE);
                    }
                    else
                    {
                        textcolor(GREEN);
                        printf("Montant suffisant atteint !\n");
                        textcolor(WHITE);
                    }
                }
            }
            while (money < 4.00);

            rendu = money - 4.00f;
            cptCafe++;
            ca += 4.00f;
            fprintf(f, "Produit: Cafe Court | Prix: 4.00 DH | Monnaie: %.2f DH | Rendu: %.2f DH\n", money, rendu);

            printf("\nPreparation en cours");
            for (int i = 0; i < 5; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n\nRendu : ");
            textcolor(GREEN);
            printf("%.2f DH\n", rendu);
            textcolor(WHITE);
            system("pause");
        }


        if (choix == 2)
        {
            money = 0;
            printf("\n");
            do
            {
                printf("Inserez une piece (1 / 2 / 5 / 10 / 20 DH) : ");
                float piece;
                scanf("%f", &piece);
                

                if (piece != 1 && piece != 2 && piece != 5 && piece != 10 && piece != 20)
                {
                    textcolor(RED);
                    printf("Piece invalide !\n");
                    textcolor(WHITE);
                }
                else
                {
                    money += piece;
                    textcolor(YELLOW);
                    printf("Montant insere : %.2f DH\n", money);
                    textcolor(WHITE);
                    
                    if (money < 5.00)
                    {
                        textcolor(RED);
                        printf("Il vous reste %.2f DH a payer\n", 5.00f - money);
                        textcolor(WHITE);
                    }
                    else
                    {
                        textcolor(GREEN);
                        printf("Montant suffisant atteint !\n");
                        textcolor(WHITE);
                    }
                }
            }
            while (money < 5.00);

            rendu = money - 5.00f;
            cptThe++;
            ca += 5.00f;
            fprintf(f, "Produit: The a la Menthe | Prix: 5.00 DH | Monnaie: %.2f DH | Rendu: %.2f DH\n", money, rendu);

            printf("\nPreparation en cours");
            for (int i = 0; i < 5; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n\nRendu : ");
            textcolor(GREEN);
            printf("%.2f DH\n", rendu);
            textcolor(WHITE);
            system("pause");
        }


        if (choix == 3)
        {
            money = 0;
            printf("\n");
            do
            {
                printf("Inserez une piece (1 / 2 / 5 / 10 / 20 DH) : ");
                float piece;
                scanf("%f", &piece);
            

                if (piece != 1 && piece != 2 && piece != 5 && piece != 10 && piece != 20)
                {
                    textcolor(RED);
                    printf("Piece invalide !\n");
                    textcolor(WHITE);
                }
                else
                {
                    money += piece;
                    textcolor(YELLOW);
                    printf("Montant insere : %.2f DH\n", money);
                    textcolor(WHITE);
                    
                    if (money < 6.00)
                    {
                        textcolor(RED);
                        printf("Il vous reste %.2f DH a payer\n", 6.00f - money);
                        textcolor(WHITE);
                    }
                    else
                    {
                        textcolor(GREEN);
                        printf("Montant suffisant atteint !\n");
                        textcolor(WHITE);
                    }
                }
            }
            while (money < 6.00);

            rendu = money - 6.00f;
            cptChoco++;
            ca += 6.00f;
            fprintf(f, "Produit: Chocolat Chaud | Prix: 6.00 DH | Monnaie: %.2f DH | Rendu: %.2f DH\n", money, rendu);

            printf("\nPreparation en cours");
            for (int i = 0; i < 5; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n\nRendu : ");
            textcolor(GREEN);
            printf("%.2f DH\n", rendu);
            textcolor(WHITE);
            system("pause");
        }


        if (choix == 4)
        {
            money = 0;
            printf("\n");
            do
            {
                printf("Inserez une piece (1 / 2 / 5 / 10 / 20 DH) : ");
                float piece;
                scanf("%f", &piece);
                

                if (piece != 1 && piece != 2 && piece != 5 && piece != 10 && piece != 20)
                {
                    textcolor(RED);
                    printf("Piece invalide !\n");
                    textcolor(WHITE);
                }
                else
                {
                    money += piece;
                    textcolor(YELLOW);
                    printf("Montant insere : %.2f DH\n", money);
                    textcolor(WHITE);
                    
                    if (money < 8.00)
                    {
                        textcolor(RED);
                        printf("Il vous reste %.2f DH a payer\n", 8.00f - money);
                        textcolor(WHITE);
                    }
                    else
                    {
                        textcolor(GREEN);
                        printf("Montant suffisant atteint !\n");
                        textcolor(WHITE);
                    }
                }
            }
            while (money < 8.00);

            rendu = money - 8.00f;
            cptCapp++;
            ca += 8.00f;
            fprintf(f, "Produit: Cappuccino | Prix: 8.00 DH | Monnaie: %.2f DH | Rendu: %.2f DH\n", money, rendu);

            printf("\nPreparation en cours");
            for (int i = 0; i < 5; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n\nRendu : ");
            textcolor(GREEN);
            printf("%.2f DH\n", rendu);
            textcolor(WHITE);
            system("pause");
        }


        if (choix == 0)
        {
            printf("\n\nFermeture");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n");
        }


        caFile = fopen("ca.dat", "w");
        if (caFile != NULL)
        {
            fprintf(caFile, "%.2f", ca);
            fclose(caFile);
        }

        cptFile = fopen("cpt.dat", "w");
        if (cptFile != NULL)
        {
            fprintf(cptFile, "%d %d %d %d", cptCafe, cptThe, cptChoco, cptCapp);
            fclose(cptFile);
        }


        if (choix == 999)
        {
            system("cls");

            FILE *fa;
            char user[50], pass[50];
            char fileUser[50], filePass[50];
            int choixadmin;

            fa = fopen("auth.txt", "r");


            if (fa == NULL)
            {
                printf("=== CREATION DU COMPTE ADMINISTRATEUR ===\n\n");
                fa = fopen("auth.txt", "w");
                printf("Entrez le nom d'utilisateur : ");
                scanf("%s", user);
                printf("Entrez le mot de passe      : ");
                scanf("%s", pass);
                fprintf(fa, "%s\n%s\n", user, pass);
                fclose(fa);
                textcolor(GREEN);
                printf("\nCompte cree avec succes!\n");
                textcolor(WHITE);
                system("pause");
            }


            else
            {
                fscanf(fa, "%s %s", fileUser, filePass);
                fclose(fa);

                printf("=== AUTHENTIFICATION ===\n\n");
                printf("Nom d'utilisateur : ");
                scanf("%s", user);
                printf("Mot de passe      : ");
                scanf("%s", pass);

                if (strcmp(user, fileUser) == 0 && strcmp(pass, filePass) == 0)
                {
                    textcolor(GREEN);
                    printf("\nBonjour %s!\n", user);
                    textcolor(WHITE);

                    // menu admin:
                    do
                    {
                        system("cls");
                        textcolor(RED);
                        for (int i = 0; i < 10; i++) printf("-");
                        textcolor(WHITE);
                        printf(" MENU ADMINISTRATION ");
                        textcolor(RED);
                        for (int i = 0; i < 10; i++) printf("-");
                        printf("\n\n");

                        textcolor(YELLOW);
                        printf("1. ");
                        textcolor(WHITE);
                        printf("Etat de la caisse    ");
                        textcolor(7);
                        printf("(Chiffre d'affaires)\n\n");
                        textcolor(YELLOW);
                        printf("2. ");
                        textcolor(WHITE);
                        printf("Rapport des ventes   ");
                        textcolor(7);
                        printf("(Quantites vendues)\n\n");
                        textcolor(YELLOW);
                        printf("3. ");
                        textcolor(WHITE);
                        printf("Gestion du compte    ");
                        textcolor(7);
                        printf("(Changer le mot de passe)\n\n");
                        textcolor(RED);
                        printf("4. ");
                        textcolor(WHITE);
                        printf("Reinitialiser        ");
                        textcolor(7);
                        printf("(Caisse et ventes)\n\n");
                        textcolor(9);
                        printf("0. ");
                        textcolor(WHITE);
                        printf("Retour au menu client\n\n");
                        textcolor(RED);
                        for (int i = 0; i < 40; i++) printf("-");
                        textcolor(WHITE);
                        printf("\n\nSaisissez votre choix : ");
                        scanf("%d", &choixadmin);


                        if (choixadmin == 1)
                        {
                            printf("\n=== ETAT DE LA CAISSE ===\n");
                            textcolor(GREEN);
                            printf("Chiffre d'affaires total : %.2f DH\n", ca);
                            textcolor(WHITE);
                            system("pause");
                        }


                        if (choixadmin == 2)
                        {
                            printf("\n=== RAPPORT DES VENTES ===\n");
                            printf("Cafe Court        : %d vendu(s)\n", cptCafe);
                            printf("The a la Menthe   : %d vendu(s)\n", cptThe);
                            printf("Chocolat Chaud    : %d vendu(s)\n", cptChoco);
                            printf("Cappuccino        : %d vendu(s)\n", cptCapp);
                            system("pause");
                        }


                        if (choixadmin == 3)
                        {
                            char ancien[50], nouveau[50], confirm[50];
                            printf("\n=== CHANGEMENT DE MOT DE PASSE ===\n");
                            printf("Ancien mot de passe  : ");
                            scanf("%s", ancien);

                            if (strcmp(ancien, filePass) != 0)
                            {
                                textcolor(RED);
                                printf("Mot de passe incorrect!\n");
                                textcolor(WHITE);
                            }
                            else
                            {
                                printf("Nouveau mot de passe : ");
                                scanf("%s", nouveau);
                                printf("Confirmer            : ");
                                scanf("%s", confirm);

                                if (strcmp(nouveau, confirm) != 0)
                                {
                                    textcolor(RED);
                                    printf("Les mots de passe ne correspondent pas!\n");
                                    textcolor(WHITE);
                                }
                                else
                                {
                                    strcpy(filePass, nouveau);
                                    fa = fopen("auth.txt", "w");
                                    fprintf(fa, "%s\n%s\n", fileUser, nouveau);
                                    fclose(fa);
                                    textcolor(GREEN);
                                    printf("Mot de passe mis a jour!\n");
                                    textcolor(WHITE);
                                }
                            }
                            system("pause");
                        }


                        if (choixadmin == 4)
                        {
                            char conf[10];
                            printf("\nEtes-vous sur ? (oui/non) : ");
                            scanf("%s", conf);

                            if (strcmp(conf, "oui") == 0)
                            {
                                ca = 0;
                                cptCafe = 0;
                                cptThe = 0;
                                cptChoco = 0;
                                cptCapp = 0;

                                caFile  = fopen("ca.dat",  "w");
                                fprintf(caFile,  "0.00");
                                fclose(caFile);
                                cptFile = fopen("cpt.dat", "w");
                                fprintf(cptFile, "0 0 0 0");
                                fclose(cptFile);
                                FILE *fv = fopen("vente.dat", "w");
                                fclose(fv);

                                textcolor(GREEN);
                                printf("Machine reinitialisee!\n");
                                textcolor(WHITE);
                            }
                            else
                            {
                                printf("Reinitialisation annulee.\n");
                            }
                            system("pause");
                        }


                        if (choixadmin == 0)
                        {
                            printf("\nRetour au menu principal...\n");
                            Sleep(800);
                        }

                    }
                    while (choixadmin != 0);
                }
                else
                {
                    textcolor(RED);
                    printf("Nom d'utilisateur ou mot de passe incorrect!\n");
                    textcolor(WHITE);
                    system("pause");
                }
            }
        }

    }
    while (choix != 0);

    fclose(f);
    printf("\n\n");
    system("pause");
    return 0;
}
