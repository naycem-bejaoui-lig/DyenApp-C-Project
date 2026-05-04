
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure du plat
typedef struct Plat {
    int id;
    char nom[50];
    int prix;
    struct Plat* suivant;
} Plat;

Plat* tete = NULL;

// Ajouter un plat
void ajouterPlat() {
    Plat* nouveau = (Plat*)malloc(sizeof(Plat));

    printf("Nom du plat: ");
    scanf("%s", nouveau->nom);

    printf("Prix: ");
    scanf("%d", &nouveau->prix);

    nouveau->id = (tete == NULL) ? 1 : tete->id + 1;
    nouveau->suivant = tete;
    tete = nouveau;

    printf("Plat ajouté avec succès!\n");
}

// Afficher les plats
void afficherMenu() {
    Plat* temp = tete;

    if (temp == NULL) {
        printf("Menu vide.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d | Nom: %s | Prix: %d DT\n", 
               temp->id, temp->nom, temp->prix);
        temp = temp->suivant;
    }
}

// Recherche
void rechercherPlat() {
    char nom[50];
    printf("Nom à chercher: ");
    scanf("%s", nom);

    Plat* temp = tete;
    while (temp != NULL) {
        if (strcmp(temp->nom, nom) == 0) {
            printf("Trouvé: ID %d | Prix %d\n", temp->id, temp->prix);
            return;
        }
        temp = temp->suivant;
    }

    printf("Plat non trouvé.\n");
}

// Suppression
void supprimerPlat() {
    int id;
    printf("ID à supprimer: ");
    scanf("%d", &id);

    Plat *temp = tete, *precedent = NULL;

    while (temp != NULL && temp->id != id) {
        precedent = temp;
        temp = temp->suivant;
    }

    if (temp == NULL) {
        printf("Non trouvé.\n");
        return;
    }

    if (precedent == NULL)
        tete = temp->suivant;
    else
        precedent->suivant = temp->suivant;

    free(temp);
    printf("Supprimé.\n");
}

// Sauvegarde
void sauvegarder() {
    FILE* f = fopen("menu.txt", "w");
    Plat* temp = tete;

    while (temp != NULL) {
        fprintf(f, "%d %s %d\n", temp->id, temp->nom, temp->prix);
        temp = temp->suivant;
    }

    fclose(f);
    printf("Données sauvegardées.\n");
}

// Chargement
void charger() {
    FILE* f = fopen("menu.txt", "r");
    if (!f) return;

    Plat* nouveau;

    while (!feof(f)) {
        nouveau = (Plat*)malloc(sizeof(Plat));
        if (fscanf(f, "%d %s %d", &nouveau->id, nouveau->nom, &nouveau->prix) != 3)
            break;

        nouveau->suivant = tete;
        tete = nouveau;
    }

    fclose(f);
}

// MAIN
int main() {
    int choix;

    charger();

    do {
        printf("\n1. Ajouter\n2. Afficher\n3. Rechercher\n4. Supprimer\n5. Sauvegarder\n0. Quitter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterPlat(); break;
            case 2: afficherMenu(); break;
            case 3: rechercherPlat(); break;
            case 4: supprimerPlat(); break;
            case 5: sauvegarder(); break;
        }

    } while (choix != 0);

    sauvegarder();
    return 0;
}
