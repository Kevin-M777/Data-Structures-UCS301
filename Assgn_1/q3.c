#include<stdio.h>

int main()
{
int i;
int arr[5] = {1};
for (i = 0; i < 5; i++)
printf("%d",arr[i]);
return 0;
}

//Ans: Output will be 10000 as by default the uninitilaized values of the array are set to zero
