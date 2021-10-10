
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dico.h"

int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();

int main(int argc, char *argv[])
{
    char lettre = 0;
    char motSecret[100] = {0};
    int *lettreTrouvee = NULL;
    long coupsRestants = 10;
    long i = 0;
    long tailleMot = 0;

    printf("Bienvenue dans le Pendu !\n\n");

    if (!piocherMot(motSecret))
        exit(0);

    tailleMot = strlen(motSecret);

    lettreTrouvee = malloc(tailleMot * sizeof(int));
    if (lettreTrouvee == NULL)
        exit(0);

    for (i = 0; i < tailleMot; i++)
        lettreTrouvee[i] = 0;

    
    while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        for (i = 0; i < tailleMot; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        rechercheLettre(lettre, motSecret, lettreTrouvee);
        coupsRestants--;
        // printf("%c",lettre );
    }

    if (gagne(lettreTrouvee, tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s\n", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s\n", motSecret);

    free(lettreTrouvee);

    return 0;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n')
        ;

    return caractere;
}

int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0; i < tailleMot; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;

    for (i = 0; motSecret[i] != '\0'; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return bonneLettre;
}
