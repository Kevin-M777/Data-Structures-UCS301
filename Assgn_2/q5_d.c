#include<stdio.h>
#include<stdlib.h>
//upper triangular  matrix
int main(){
    int r,i,j,dump,count=0;
    printf("Enter order of square matrix:");
    scanf("%d",&r);
    int total= (r*(r+1))/2;
    int *d=(int *)malloc(total*sizeof(int)); 
    printf("%s","Enter the elements of the matrix:");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(i<=j) {scanf("%d",(d+count));count++;}
            else scanf("%d",&dump);
        }
    }
    //display elements of upper triangle:
    printf("%s","All elements in upper triangle:\n");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(i<=j){
            int idx=((i*(2*r-i+1))/2)+(j-i);
            printf("%d  ",*(d+idx));
            
            }
            else printf("%d ",0);
        }
        printf("\n");
    }
    free(d);
    return 0;
}
