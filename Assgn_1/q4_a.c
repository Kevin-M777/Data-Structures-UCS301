#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=0,temp,j;
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    j=size-1;
    int *A=(int *)malloc(size*(sizeof(int)));
    printf("Enter the %d elements:",size);
    for(i=0;i<size;i++){
        scanf("%d",A+i);
    }
    i=0;
    while(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        j--;i++;
    }
    printf("The contents of the reversed array are:");
    for(i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    return 0;
}