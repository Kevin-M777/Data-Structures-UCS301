#include <stdio.h>
#include <stdlib.h>
//multiplication of sparse matrices
int * input(int row,int col,int *c);
void display(int *ptr,int *c);
void invert(int *ptr,int *c);
void sort(int *ptr,int *c,int row);
int * multiplication(int *ptr1,int *ptr2,int r1,int c1,int r2,int c2,int count1,int count2,int *ct3);
void push(int **ptr,int idx,int r,int c,int v);


int main(){
    int row1,col1;int count1,count2;
    int row2,col2;
    printf("Enter number of rows for 1st matrix:");
    scanf("%d",&row1);
    printf("Enter number of columns for 1st matrix:");
    scanf("%d",&col1);
    printf("Enter number of rows for 2nd matrix:");
    scanf("%d",&row2);
    printf("Enter number of columns for 2nd matrix:");
    scanf("%d",&col2);
    int *ptr1=input(row1,col1,&count1);
    int *ptr2=input(row2,col2,&count2);
    if(ptr1!=NULL&&ptr2!=NULL){ 
        display(ptr1,&count1);
        display(ptr2,&count2);
    }
    else exit(1);
    //taking transpose of second matrix
    invert(ptr2,&count2); 
    sort(ptr2,&count2,row2);

    int temp=row2;
    row2=col2;
    col2=temp;
    int count3=0;
    int *pr=multiplication(ptr1,ptr2,row1,col1,row2,col2,count1,count2,&count3);
    if(pr!=NULL) display(pr,&count3);
    else printf("Memory Allocation Failed\n");

    free(ptr1);free(ptr2);free(pr);
    return 0;
}

int * input(int row,int col,int *c){
    int i,j,count=0,num;
    int *ptr=(int *)malloc(3*sizeof(int));
    //setting the header row
    *(ptr)=row;*(ptr+1)=col;
    printf("Enter elements in flattened form:");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&num);
            if(num!=0){
                count ++;
                int *temp=(int *)realloc(ptr,(3*(count +1))*sizeof(int));
                if(temp!=NULL)ptr=temp;
                else {printf("Memory Allocation Failed!\n");return NULL;}
                int e_base=(count*3);//base index of the row belonging to the present element
                *(ptr+(e_base))=i;
                *(ptr+(e_base)+1)=j;
                *(ptr+(e_base)+2)=num;
            }
        }
    }
    *(ptr+2)=count;
    *c=count;
    return ptr;
}

void display(int *ptr,int *c){
    int i,j;
    for(i=0;i<((*c)+1);i++){
        for(j=0;j<3;j++){
            printf("%d ",*(ptr+i*3+j));
        }
        printf("\n");
    }
    printf("\n");
}

void invert(int *ptr,int *c){
    int i,j,temp;
    for(i=1;i<((*c)+1);i++){
        temp=*(ptr+i*3);
        *(ptr+i*3)=*(ptr+i*3+1);
        *(ptr+i*3+1)=temp;
    }
    return;
}

void sort(int *ptr, int *c,int row){
    int i,j; 
    for(i=0;i<((*c)-1);i++){
        for(j=1;j<(*c)-i;j++){
            if((*(ptr+j*3))>(*(ptr+j*3+3))){
                int temp1=*(ptr+j*3);
                *(ptr+j*3)=*(ptr+j*3+3);
                *(ptr+j*3+3)=temp1;
                int temp2=*(ptr+j*3+1);
                *(ptr+j*3+1)=*(ptr+j*3+3+1);
                *(ptr+j*3+3+1)=temp2;
                int temp3=*(ptr+j*3+2);
                *(ptr+j*3+2)=*(ptr+j*3+3+2);
                *(ptr+j*3+3+2)=temp3;
            }
        }
    }
    return;
}

int * multiplication(int *ptr1,int *ptr2,int r1,int c1,int r2,int c2,int count1,int count2,int *ct3){
    if(c1!=r2)printf("Multiplication fo these two matrices is invalid!\n");
    else{
        int *pr=(int *)malloc(3*sizeof(int));
        *(pr)=r1;*(pr+1)=c2;
        int i,j,sum;int r,c,c3=0;
        for(i=1;i<=count1;i++){
            r=ptr1[3*i];
            for(j=1;j<=count2;j++){
                c=ptr2[3*j];sum=0;
                int t1=i,t2=j;
                while(t1<=count1&&t2<=count2&&ptr1[3*t1]==r&&ptr2[3*t2]==c){
                    if(ptr1[3*t1+1]<ptr2[3*t2+1])t1++;
                    else if (ptr1[3*t1+1]>ptr2[3*t2+1])t2++;
                    else {sum=sum+((ptr1[3*t1+2])*(ptr2[3*t2+2]));t1++;t2++;}
                }
                if(sum!=0) {
                    int k=1;int flag=0;
                    for(k=1;k<=c3;k++){
                        if(pr[3*k]==r&&pr[3*k+1]==c){flag=1;break;};
                    }
                    if(flag==0)push(&pr,++c3,r,c,sum);
                }
            }
        }
        *(pr+2)=c3;
        *ct3=c3;
        return pr;
    }
    
    return NULL;
}

void push(int **ptr,int idx,int r,int c,int v){
    //here idx is element number
    int *temp=(int *)realloc(*ptr,(3*(idx+1))*sizeof(int));
    if(temp!=NULL) *ptr=temp;
    else{printf("Memory Allocation Failed");exit(1);}
    *(*ptr+idx*3)=r;*(*ptr+(idx*3)+1)=c;*(*ptr+(idx*3)+2)=v;
    
}
