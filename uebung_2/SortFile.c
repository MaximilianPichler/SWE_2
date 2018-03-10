#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *array, int length)
{
   int i, j,tmp;

   for (i = 0; i < length ; i++) 
   {
      for (j = i; j < length ; j++) 
      {
          if (array[i] > array[j]) 
          {
              tmp = array[i];
              array[i] = array[j];
              array[j] = tmp;
          }
      }
   }
}

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
    fclose(fp);

    bubblesort(&buffer[0], count);

    fp = fopen("zahlen.txt", "w+");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%i\n", buffer[i]);
    }

    fclose(fp);
    return 0;
}