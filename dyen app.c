#include <stdio.h>
#include <string.h> 

typedef struct
{
    int identifiant;
    char nom[50];
    int prix;
} plat;

plat menu[100];
int nbplat = 0;

void ajoutermenu()
{
    if (nbplat >= 100) {
        printf("\nle menu de dyen app est complet\n");
        return;
    }
    printf("\najouter un nouveau plat dyen app\n");
    menu[nbplat].identifiant = nbplat + 1;
    
    printf("entrer le nom de plat : ");
    scanf("%s", menu[nbplat].nom);
    
    printf("entrer le prix de plat : ");
    scanf("%d", &menu[nbplat].prix);
    
    nbplat++;
    printf("le plat a ete ajoute au menu de dyen app\n");
    printf("le nombre total de plat est : %d\n", nbplat);
}

void affichermenu()
{
    printf("\nliste de menu dyen app\n");
    if (nbplat == 0) {
        printf("nombre de plat est vide\n");
    }
    else {
        for (int i = 0; i < nbplat; i++) {
            printf("ID: %d, Nom: %s, Prix: %d\n", menu[i].identifiant, menu[i].nom, menu[i].prix);
        }
    }
}

void rechercherplat() {
    char nomRecherche[50];
    int trouve = 0;

    printf("\nEntrez le nom du plat a chercher : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < nbplat; i++) {
        if (strcmp(menu[i].nom, nomRecherche) == 0) {
            printf("Plat trouve ! identifiant: %d, Prix: %d\n", menu[i].identifiant, menu[i].prix);
            trouve = 1;
            break;
        }
    }
    if (trouve == 0) printf("Plat non trouve.\n");
}

int main()
{
    int choix;
    do {
        printf("\n--- menu dyen app ---\n");
        printf("1.ajouter un plat\n");
        printf("2.afficher le menu\n");
        printf("3.rechercher un plat\n");
        printf("0.Quitter\n");
        printf("votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajoutermenu(); break;
            case 2: affichermenu(); break;
            case 3: rechercherplat(); break; 
            case 0: printf(" au revoir\n"); break;
            default: printf(" choix invalide\n");
        }

    } while (choix != 0);

    return 0;
}
