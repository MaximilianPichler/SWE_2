#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    while(1) {
        FILE *fp = fopen("data.log", "a");
        FILE *command = popen("/opt/vc/bin/vcgencmd measure_temp", "r");
        char *commBuffer[255];

        if (fp == NULL || command == NULL) {
            perror("Error");
        }

        fscanf(command, "%s", commBuffer);
        fclose(command);
        fprintf(fp, "%s\n", commBuffer);
        fclose(fp);

        sleep(60 * 60);
    }
}