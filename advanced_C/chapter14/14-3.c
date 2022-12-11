#include <stdio.h>

int main() {

    FILE *fp;

    fp = fopen("example.txt", "w");

    while (1) {
        char c = fgetc(stdin);
        if (c == 'x') {
            break;
        }
        fputc(c, fp);
    }

    fclose(fp);

    FILE *fp1 = fopen("example.txt", "r");

    

    return 0;
}