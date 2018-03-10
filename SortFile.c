#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));
    int buffer[50];

    FILE *fp = NULL;
    fp = fopen("zahlen.txt", "r");

    if (fp == NULL) {
        perror("Fileerror");
    }

    int count = 0;

    while (fscanf(fp, "%d", &buffer[count]) == 1) {
        count++;
    }

    printf("%i\n", count);

    for (int i = 0; i < count; i++) {
        printf("%i\n", buffer[i]);
    }


    fclose(fp);
    return 0;
}