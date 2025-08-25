#include<stdio.h>
//deleting vowels from a sentence by overwriting, more efficient approach

int vowel(char c);
int main(){
    char str[]="C is a cool language";
    int size= sizeof(str)/sizeof(char);//includes null operator
    int i,count=0;
    for(i=0;i<size-1;i++){
        if(!vowel(str[i])){
            str[count]=str[i];
            count++;
        }
    }
    str[count]='\0';
    printf("%s",str);
    return 0;
}
int vowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return 1;
    else return 0;
}