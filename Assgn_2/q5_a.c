#include<stdio.h>
#include<stdlib.h>
//diagonal matrix efficient storage
int main(){
    int r,i,j,count=0,dump;
    printf("Enter order of square matrix:");
    scanf("%d",&r);
    int *d=(int *)malloc(r*sizeof(int));
    printf("%s","Enter the elements of the matrix:");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if (i==j){
                scanf("%d",(d+i));
                count++;
            }
            else scanf("%d",&dump);
        }
    }
    //display
    for(i=0;i<r;i++)
        printf("%d ",*(d+i));
    return 0;
}