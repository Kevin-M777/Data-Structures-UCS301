#include<stdio.h>
#include<stdlib.h>
//tri-diagonal matrix
int main(){
    int r,i,j,dump;
    printf("Enter order of square matrix:");
    scanf("%d",&r);
    int *ud=(int *)malloc((r-1)*sizeof(int));
    int *d=(int *)malloc(r*sizeof(int));
    int *ld=(int *)malloc((r-1)*sizeof(int));
    int cu=0,cd=0,cl=0;
    printf("%s","Enter the elements of the matrix:");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if (j-i==1){
                scanf("%d",(ud+cu));
                cu++;
            }
            else if(i-j==1){
                scanf("%d",(ld+cl));
                cl++;
            }
            else if(i==j){
                scanf("%d",(d+cd));
                cd++;
            }
            else scanf("%d",&dump);
        }
    }
    //display elements of each of the diagonals
    printf("%s","Upper diagonal elements:");
    for(i=0;i<r-1;i++) printf("%d ",*(ud+i));
    printf("\n");
    printf("%s","Diagonal elements:");
    for(i=0;i<r;i++) printf("%d ",*(d+i));
    printf("\n");
    printf("%s","Lower diagonal elements:");
    for(i=0;i<r-1;i++) printf("%d ",*(ld+i));
    return 0;
}