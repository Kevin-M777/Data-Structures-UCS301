#include <stdio.h>
#include <stdlib.h>
//deleting vowels from a sentence using a normal delete function
char * delete(char *ptr,int s,int idx);
int check(char c);

int main(){
    char str[]="Hello C is fun!";
    int size=sizeof(str)/sizeof(char);
    //store indices where vowels are present
    int *id=(int *)malloc(sizeof(int)),i;
    for(i=0;i<size-1;i++)
        if(check(str[i])) delete(str,size,i);
    printf("%s",str);
    
    return 0;
}

char * delete(char *ptr,int s,int idx){
    if(idx<0||idx>s-1) return NULL;
    else{
        int i=idx;
        while(1){
            if(i!=(s-1)) *(ptr+i)=*(ptr+i+1);
            else break;
            i++;
        }
        return ptr;
    }
}

int check(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return 1;
    else return 0;
}