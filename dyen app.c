
#include <stdio.h>
#include <string.h>

typedef struct {
    int identifiant;
    char nom[50];
    int prix;
} plat;

plat menu[100];
int nbplat = 0;

// 1. Ajouter un plat
void ajoutermenu() {
    if (nbplat >= 100) {
        printf("\nLe menu de Dyen App est complet!\n");
        return;
    }
    printf("\n--- Ajouter un nouveau plat --- \n");
    menu[nbplat].identifiant = nbplat + 1;
    
    printf("Nom du plat : ");
    scanf("%s", menu[nbplat].nom);
    
    printf("Prix du plat : ");
    scanf("%d", &menu[nbplat].prix);

    nbplat++;
    printf("Plat ajoute avec succes! Total: %d\n", nbplat);
}

// 2. Afficher le menu
void affichermenu() {
    printf("\n--- Liste du menu Dyen App ---\n");
    if (nbplat == 0) {
        printf("Le menu est vide.\n");
    } else {
        for (int i = 0; i < nbplat; i++) {
            printf("ID: %d | Nom: %s | Prix: %d DT\n", 
                   menu[i].identifiant, menu[i].nom, menu[i].prix);
        }
    }
}

// 3. Rechercher un plat
void rechercherplat() {
    char nomRecherche[50];
    int trouve = 0;

    printf("\nEntrez le nom du plat a chercher : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < nbplat; i++) {
        if (strcmp(menu[i].nom, nomRecherche) == 0) {
            printf("Plat trouve! ID: %d | Prix: %d DT\n", 
                   menu[i].identifiant, menu[i].prix);
            trouve = 1;
            break; 
        }
    }
    if (trouve == 0) printf("Plat non trouve.\n");
}

// 4. Supprimer un plat 
void supprimerplat() {
    int idRecherche, trouve = 0;
    if (nbplat == 0) {
        printf("\nLe menu est deja vide.\n");
        return;
    }
    printf("\nEntrez l'ID du plat a supprimer : ");
    scanf("%d", &idRecherche);

    for (int i = 0; i < nbplat; i++) {
        if (menu[i].identifiant == idRecherche) {
            trouve = 1;
            // Décalage des éléments vers la gauche pour boucher le vide
            for (int j = i; j < nbplat - 1; j++) {
                menu[j] = menu[j + 1];
            }
            nbplat--;
            printf("Plat ID %d supprime avec succes!\n", idRecherche);
            break;
        }
    }
    if (!trouve) printf("ID %d non trouve dans le menu.\n", idRecherche);
}

// 5. Fonction principale
int main() {
    int choix;
    do {
        printf("\n=== DYEN APP MENU ===\n");
        printf("1. Ajouter un plat\n");
        printf("2. Afficher le menu\n");
        printf("3. Rechercher un plat\n");
        printf("4. Supprimer un plat\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajoutermenu(); break;
            case 2: affichermenu(); break;
            case 3: rechercherplat(); break;
            case 4: supprimerplat(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide!\n");
        }
    } while (choix != 0);

    return 0;
}
  
