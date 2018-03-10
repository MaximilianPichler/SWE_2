#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));

    FILE *fp = NULL;
    fp = fopen("zahlen.txt", "w+");

    if (fp == NULL) {
        perror("Fileerror");
    }

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%i\n", rand() % 100 + 1);
    }

    fclose(fp);
}