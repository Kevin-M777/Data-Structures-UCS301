#include<stdio.h>
#include<stdlib.h>

void transpose(int *A,int r,int c);
void matrix_input(int *p,int r,int c);
void matrix_display(int *p,int r,int c);

int main(){
    int r,c;
    printf("Enter rows and columns:");
    scanf("%d%d",&r,&c);
    int *A=(int *)malloc((r*c)*sizeof(int));
    matrix_input(A,r,c);
    transpose(A,r,c);
    matrix_display(A,r,c);
    return 0;
}

void transpose(int *A,int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=i;j<c;j++){
			int temp=*(A+i*c+j);
			*(A+i*c+j)=*(A+j*c+i);
			*(A+j*c+i)=temp;
		}
    }
}

void matrix_input(int *p,int r,int c){
    int i,j;
    printf("Enter all %d elements:",r*c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",(p+i*c+j));
        }
    }
}

void matrix_display(int *p,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",*(p+i*c+j));
        }
        printf("\n");
    }
}