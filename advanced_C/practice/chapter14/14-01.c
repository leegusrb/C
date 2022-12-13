#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w");

    while(1) {
        int n;
        fscanf(stdin, "%d", &n);
        if (n == -1) break;
        fprintf(fp, "%d\n", n);
    }

    fclose(fp);

    fp = fopen("data.txt", "r");

    int cnt = 0, sum = 0;
    while (!feof(fp)) {
        int n;
        fscanf(fp, "%d\n", &n);
        cnt++;
        sum += n;
    }

    fprintf(stdout, "%d\n%d\n%.2lf\n", cnt, sum, (double)sum / cnt);

    fclose(fp);
    
    return 0;
}