#include <stdio.h>
//Finding missing number using linear search
int main(){
    int a[]={2,3,4,5,6,7,8},i;
    int s=sizeof(a)/sizeof(int);
    int flag=0,m;
    for(i=0;i<s-1;i++){
        if (a[0]!=1){flag=1;m=1;break;}
        if(a[i+1]-a[i]==2){
            flag=1;
            m=a[i]+1;
        }
    }
    if(flag==1) printf("Missing number is :%d",m );
    else printf("Missing number is: %d",a[s-1]+1);
    return 0;
}