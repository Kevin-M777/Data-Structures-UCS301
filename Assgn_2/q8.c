#include <stdio.h>

int unique(char *ptr,int s);
char * delete(char *ptr,int s,int idx);
//counting unique characters 
int main(){
    char str[]="abcdeabcdea";
    char size=sizeof(str)/sizeof(char);
    int u= unique(str,size);
    printf("Number of unique characters:%d",u);
    return 0;
}

int unique(char *ptr,int s){
	int size=s,i=0,j;int idx;
    char e;
	char *p=ptr;char *temp;
	for(i=0;i<size;i++){
		e=*(p+i);
		for(j=i+1;j<size;j++){
			if(*(p+j)==e){
				temp=delete(p,size,j);
				p=temp;
				size=size-1;
                j--;//so that in the next iteration of for loop it starts from the same index as before in order to handle adjacent repetitions
			}
		}
	}
    int final_size=size;
	return final_size;
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
