#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main () {
    int index = 0;

    for (int i = 0; i < 20; i++) {
        FILE *command = popen("vcgencmd measure_temp", "r");
        char *commBuffer = (char *)malloc(255);

        if ( command == NULL) {
            perror("Error");
        }

        fscanf(command, "%s", commBuffer);
        fclose(command);

        char *val = (char *)malloc(5);
        strncpy(val, commBuffer + 5, 4);
        val[4] = '\0';

        char buffer[255];
        snprintf(buffer, sizeof(buffer), "curl -X POST -d '{\"value\": \"%s\", \"time\": \"%i\"}' 'https://swe2-projekt.firebaseio.com/data.json'", val, index);
        printf("%s   %i", val, index);
        
        system(buffer);
        sleep(0.5);
        index++;
    }
    return 0;
}