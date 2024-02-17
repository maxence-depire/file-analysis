#include <stdio.h>
#include <string.h>

int main() {
    int nombre = 192;
    char nombreEnString[20]; // Définir une taille suffisamment grande pour contenir l'entier converti en chaîne de caractères

    // Convertir l'entier en chaîne de caractères
    sprintf(nombreEnString, "%d", nombre);

    // Déterminer la taille de la chaîne obtenue
    size_t taille = strlen(nombreEnString);

    printf("Le nombre %d a une taille de %zu caractères.\n", nombre, taille);

    return 0;
}
