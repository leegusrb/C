#include <stdio.h>
#include <string.h>

void StringAdd(char *arr, char ch, int index);
int Convertor(char x);

int main(){
    char num[16];

    scanf("%s", num);

    for(char *p = num + 1; *p; p++){
        if(Convertor(*(p - 1)) % 2 == 1 && Convertor(*p) % 2 == 1){
            StringAdd(num, '+', p - num);
            p++;
        }if(Convertor(*(p - 1)) % 2 == 0 && Convertor(*p) % 2 == 0){
            StringAdd(num, '*', p - num);
            p++;
        }
    }

    printf("%s\n", num);

    return 0;
}

void StringAdd(char *arr, char ch, int index){
    char tmp[16];
    strcpy(tmp, arr + index);
    arr[index] = ch;
    strcpy(arr + index + 1, tmp);
}

int Convertor(char x){
    return x - '0';
}