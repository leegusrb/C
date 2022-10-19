#include <stdio.h>
#include <string.h>

int main(){
    char A[251], B[11], C[11], tmp[251];

    gets(A);
    scanf("%s", B);
    scanf("%s", C);

    for(char *p = A; *p; p++){
        if(!strncmp(p, B, strlen(B))){
            strcpy(tmp, p + strlen(B));
            strcpy(p, C);
            strcpy(p + strlen(C), tmp);
        }
    }

    printf("%s\n", A);

    return 0;
}