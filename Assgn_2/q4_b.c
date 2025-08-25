#include <stdio.h>
//reversing a string
int main(){
    char str[]="!dlroW olleH";
    int size= sizeof(str)/sizeof(char);
    int i,j;char temp;
    for(i=0,j=size-2;i<=j;i++,j--){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    printf("%s",str);
    return 0;
}