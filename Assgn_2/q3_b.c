#include<stdio.h>
//Find missing number from n-1 integers sorted from 1 to n-1
//Always when we exit the while condition , l will be greater than u and A[l]-1 will be the missing element except when
//the missing element is n itself, in that case the missing element will be A[u]+1 as in that case the loop will exit with u having the 
//last index of the array.
int main(){
    int A[]={1,2,3,4,6,7,8,9,10};
    int size=sizeof(A)/sizeof(int);
    int l=0,u=size-1,mid;
    while(l<=u){
        printf("%d %d\n",l,u);
        mid=(l+u)/2;
        if(A[mid]-mid!=1) u=mid-1;
        else l=mid+1;    
    }
    int miss;
    if(l<size) miss= A[l]-1;
    else miss=A[u]+1;
    printf("Missing number is:%d",miss);
    return 0;
}
