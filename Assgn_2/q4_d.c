#include <stdio.h>
//sorting characters in alphabetic order
int main(){
    char str[]="Hello World";
    int size=sizeof(str)/sizeof(char);
    int i,j;
    for(i=0;i<size-2;i++){
        for(j=0;j<size-i-2;j++){
            if (str[j]>str[j+1]){
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    printf("%s",str);
    return 0;
}