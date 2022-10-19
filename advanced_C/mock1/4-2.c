#include <stdio.h>
#include <string.h>

int main(){
    char A[100][251], B[100][101], tmp[251] = "";

    gets(A[0]);
    gets(B[0]);

    int i1 = 1, j1 = 0;
    for(char *p = A[0]; *p; p++){
        if(*p == ' '){
            A[i1++][j1] = '\0';
            j1 = 0;
        }else{
            A[i1][j1++] = *p;
        }
    }
    A[i1++][j1] = '\0';

    int i2 = 1, j2 = 0;
    for(char *p = B[0]; *p; p++){
        if(*p == ' '){
            B[i2++][j2] = '\0';
            j2 = 0;
        }else{
            B[i2][j2++] = *p;
        }
    }
    B[i2++][j2] = '\0';

    int i = 1;
    for(int x = 1; x < i1; x++){
        for(int y = 1; y < x; y++){
            if(!strcmp(A[x], A[y])){
                strcpy(A[x], B[i++]);
            }
        }
    }

    for(int x = 1; x < i1; x++){
        strcat(tmp, A[x]);
        strcat(tmp, " ");
    }

    printf("%s\n", tmp);

    return 0;
}