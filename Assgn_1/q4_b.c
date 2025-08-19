#include<stdio.h>

int main() {
	int r1,c1,r2,c2;
	int i,j,k,l;
	printf("Enter number of rows and columns:");
	scanf("%d%d",&r1,&c1);
	//matrix 1
	int m1[r1][c1];
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("enter %d,%d:",i,j);
			scanf("%d",&m1[i][j]);
		}	
	}
	//matrix 2
	printf("Enter number of rows and columns:");
	scanf("%d%d",&r2,&c2);
	int m2[r2][c2];
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			printf("enter %d,%d:",i,j);
			scanf("%d",&m2[i][j]);
		}	
	}
	//c1 has to be =r2
	int sum,p;
	int m3[r1][c2];
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			sum=0;
			for(k=0;k<c1;k++){
				p=m1[i][k]*m2[k][j];
				sum=sum+p;	
			}
			m3[i][j]=sum;	
		}
	}
	//displaying the product
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d ",m3[i][j]);	
		}
		printf("\n");	
	}
	return 0;
}

