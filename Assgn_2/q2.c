#include <stdio.h>
//Bubble sort implementation
int main(){
    int a[]={64,34,25,12,22,11,90};
    int i,j,n=sizeof(a)/sizeof(int);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}