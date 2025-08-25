#include <stdio.h>
#include <stdlib.h>
//string concatenation
int main(){
    char str1[]="hello";
    char str2[]=" world!";
    int size1= sizeof(str1)/sizeof(char); //includes null operator
    int size2= sizeof(str2)/sizeof(char); int l;
    l=size1+size2-1;int i;
    char * str3=(char *)malloc(l*sizeof(char));
    int idx=0;
    for(i=0;i<l-1;i++){
        if(i<size1-1){
            str3[i]=str1[i];
        }
        else{
            str3[i]=str2[idx];
            idx++;
        }
    }
    str3[l-1]='\0';
    printf("%s",str3);
    return 0;
}