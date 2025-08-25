#include<stdio.h>
#include<stdlib.h>
//symmetric  matrix
int main(){
    int r,i,j,dump,count=0;
    printf("Enter order of square matrix:");
    scanf("%d",&r);
    int total= (r*(r+1))/2;
    int *d=(int *)malloc(total*sizeof(int)); 
    printf("%s","Enter the elements of the matrix:");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(j<=i) {scanf("%d",(d+count));count++;}
            else scanf("%d",&dump);
        }
    }
    //display entire matrix by only using either the upper or lower diagonal elements
    int idx;
    printf("%s","Symmetric matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(j<=i){
            idx=(i*(i+1)/2)+(j);
            printf("%d  ",*(d+idx));
            }
            else{
                idx=(j*(j+1)/2)+(i);
                printf("%d  ",*(d+idx));
            }
        }
        printf("\n");
    }
    free(d);
    return 0;  
}