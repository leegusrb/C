#include <stdio.h>

int main()
{
    int sum = 0;
    double avg;
    int cntLow = 0;
    int min = 100;

    for (int i = 0; i < 5; i++)
    {
        int score;
        scanf("%d", &score);
        sum += score;
        if (score < 0 || score > 100)
        {
            printf("Invalid\n");
            return 0;
        }
        if (score < 40)
            cntLow++;
        if (score < min)
            min = score;
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
    printf("avg=%.2lf min=%d\n", avg, min);

    return (0);
}