#include <stdio.h>

int main()
{
    int sum = 0;
    double avg;
    int cntLow = 0;

    for (int i = 0; i < 5; i++)
    {
        int score;
        scanf("%d", &score);
        sum += score;
        if (score < 40)
            cntLow++;
    }

    avg = (double) sum / 5;
    if (avg < 50 || cntLow >= 3)
        printf("F\n");
    else if (avg >= 90)
        printf("A+\n");
    else if (avg >= 75)
        printf("A\n");
    else if (avg >= 65)
        printf("B+\n");
    else if (avg >= 50)
        printf("B\n");
    printf("%.2lf\n", avg);

    return (0);
}