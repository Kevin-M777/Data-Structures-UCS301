#include <stdio.h>
//counting number of inversions
int main(){
    int a[]={1,2,3,4,5,6,22,8,9};
    int size=sizeof(a)/sizeof(int);
    int count=0,i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(i<j && (a[i]>a[j])) count++;
        }
    }
    printf("Number of inversions is:%d",count);
    return 0;
}