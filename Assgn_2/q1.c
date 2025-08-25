//Binary search VS Linear Search
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,i,num;
    //assuming user enters elements in sorted manner
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int *p=(int *)malloc(size*sizeof(int));
    printf("Enter the %d elements:",size);
    for(i=0;i<size;i++)
        scanf("%d",(p+i));
    printf("Enter element for search:");
    scanf("%d",&num);
    int flag=0,idx;

    //Linear Search
    
    for(i=0;i<size;i++)
        if(*(p+i)==num){flag=1;idx=i;break;}
    if (flag==1)printf("Element %d found at index %d\n",num,idx);
    else printf("Element %d not found\n.",num);
   

    //Binary Search
   
    flag=0;
    int l=0,r=size-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(num==p[mid]){idx=mid;flag=1;break;}
        else if (num>p[mid]) l= mid+1;
        else r=mid-1;
    }
    if (flag==1)printf("Element %d found at index %d\n",num,idx);
    else printf("Element %d not found\n.",num);


    return 0;
}