#include <stdio.h>
#include <stdlib.h>

int final_size;
int * create(int s);
void display(int *p,int s);
int * delete(int *ptr,int s,int idx);
int * unique(int *ptr,int s);

int main(){
	int size,*ptr,*u_ptr;
	printf("Enter size of array:");
	scanf("%d",&size);
	ptr= create(size);
	display(ptr,size);
    u_ptr= unique(ptr,size);
    display(u_ptr,final_size);
	return 0;
}

int * create(int s){
    int *ptr= (int *)malloc(s*sizeof(int));
    printf("Please enter the %d elements:",s);
    int i;
    for(i=0;i<s;i++){
        scanf("%d",ptr+i);
    }
    return ptr;
}

void display(int *p,int s){
    printf("The contents of the array are:\n");
    int i;
    for(i=0;i<s;i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
}

int * delete(int *ptr,int s,int idx){
    if(idx<0||idx>s-1) return NULL;
    else{
        int i=idx;
        while(1){
            if(i!=(s-1)) *(ptr+i)=*(ptr+i+1);
            else break;
            i++;
        }
        return ptr;
        int *temp=(int *)realloc(ptr,(s-1)*sizeof(int));
        ptr=temp;
        return ptr;
    }
}

int * unique(int *ptr,int s){
	int size=s,i=0,e,j;int idx;
	int *p=ptr;int *temp;
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
    final_size=size;
	return p;
}