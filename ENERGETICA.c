#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print3DText(const char *text) {
    // Print each character with a slight offset for a 3D effect
    for (const char *c = text; *c != '\0'; ++c) {
        putchar(*c);
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    printf("  W   W  EEEEE  L      CCCCC  OOO   M     M  EEEEE  \n");
    printf("  W   W  E      L     C      O   O  MM   MM  E      \n");
    printf("  W W W  EEEE   L     C      O   O  M M M M  EEEE   \n");
    printf("  W W W  E      L     C      O   O  M  M  M  E      \n");
    printf("   W W   EEEEE  LLLLL  CCCCC  OOO   M     M  EEEEE  \n");

    printf("\n");

    printf("  TTTTT  OOO   \n");
    printf("    T   O   O  \n");
    printf("    T   O   O  \n");
    printf("    T   O   O  \n");
    printf("    T    OOO   \n");

    printf("\n");

    printf("  EEEEE  N     N  EEEEE  RRRR   GGG   EEEEE  TTTTT  III  CCCCC  AAAAA \n");
    printf("  E      NN    N  E      R   R G   G  E        T     I   C      A   A \n");
    printf("  EEEE   N N   N  EEEE   RRRR  G      EEEE     T     I   C      AAAAA \n");
    printf("  E      N  N  N  E      R  R  G   G  E        T     I   C      A   A \n");
    printf("  EEEEE  N   N N  EEEEE  R   R  GGG   EEEEE    T    III  CCCCC  A   A \n");

    return 0;
}


