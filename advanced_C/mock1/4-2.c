#include <stdio.h>
#include <string.h>

int main(){
    char A[100][251], B[100][101], tmp[251] = "";

    int i1 = 0;
    while(1){
        scanf("%s", A[i1++]);
        if(getchar() == '\n') break;
    }

    int i2 = 0;
    while(1){
        scanf("%s", B[i2++]);
        if(getchar() == '\n') break;
    }

    int i = 0;
    for(int x = 0; x < i1; x++){
        for(int y = 0; y < x; y++){
            if(!strcmp(A[x], A[y])){
                strcpy(A[x], B[i++]);
            }
        }
    }

    for(int x = 0; x < i1; x++){
        strcat(tmp, A[x]);
        strcat(tmp, " ");
    }

    printf("%s\n", tmp);

    return 0;
}