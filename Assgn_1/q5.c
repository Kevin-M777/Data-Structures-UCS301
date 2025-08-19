#include<stdio.h>
#include<stdlib.h>

void matrix_input(int *p,int r,int c);
void matrix_display(int *p,int r,int c);

int main(){
    int r,c,i,j,sum;
    printf("Enter rows and columns:");
    scanf("%d%d",&r,&c);
    int *A=(int *)malloc((r*c)*sizeof(int));
    matrix_input(A,r,c);
    matrix_display(A,r,c);
    int *sum_r=(int *)malloc(r*sizeof(int));
    int *sum_c=(int *)malloc(c*sizeof(int));
    for(i=0;i<r;i++){
        sum=0;
        for(j=0;j<c;j++) sum=sum + *(A+i*c+j);
        *(sum_r+i)=sum;
    }
    for(j=0;j<c;j++){
        sum=0;
        for(i=0;i<r;i++) sum=sum + *(A+i*c+j);
        *(sum_c+j)=sum;
    }
    printf("Row sums:");
    for(i=0;i<r;i++) printf("%d ",*(sum_r+i));
    printf("\n");
    printf("Column sums:");
    for(j=0;j<c;j++) printf("%d ",*(sum_c+j));
    return 0;
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