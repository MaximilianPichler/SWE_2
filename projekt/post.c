#include <stdio.h>
#include <stdlib.h>

int main () {
    system("curl -X POST -d '{\"user_id\" : \"test\", \"text\" : \"Test1\"}' 'https://swe2-projekt.firebaseio.com/data.json'");
    return 0;
}