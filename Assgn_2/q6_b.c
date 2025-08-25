#include <stdio.h>
#include <stdlib.h>
//addition of sparse matrices
int * input(int row,int col,int *c);
void display(int *ptr,int *c);
int * add(int *ptr1,int *ptr2,int c1,int c2,int row,int col,int *ct3);
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
    if(row1!=row2||col1!=col2){
        printf("Addition to these two matrices is invalid!\n");
        exit(1);
    }
    int count3=0;
    int *ptr3=add(ptr1,ptr2,count1,count2,row1,col1,&count3);
    display(ptr3,&count3);
    free(ptr1);free(ptr2);free(ptr3);
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

int * add(int *ptr1,int *ptr2,int count1,int count2,int row,int col,int *ct3){
    int i=1,j=1;int r1,c1,r2,c2;int v1,v2;
    int c3=0;
    int *sum=(int *)malloc(3*sizeof(int));
    *(sum)=row;*(sum+1)=col;
    while(i<=count1&&j<=count2){
        r1=*(ptr1+(i*3));c1=*(ptr1+(i*3)+1);v1=*(ptr1+(i*3)+2);
        r2=*(ptr2+(j*3));c2=*(ptr2+(j*3)+1);v2=*(ptr2+(j*3)+2);
        if(r1>r2||r1==r2&&c1>c2){
            push(&sum,++c3,r2,c2,v2);
            j++;
        }
        else if(r1<r2||r1==r2&&c1<c2){
            push(&sum,++c3,r1,c1,v1);i++;
        }
        else{
            if(v1+v2!=0){
                 push(&sum,++c3,r1,c1,v1+v2);
                 i++;j++;
            }
        }
    }
    while(i<=count1){
        push(&sum,++c3,ptr1[i*3],ptr1[i*3+1],ptr1[i*3+2]);i++;
    }
    while(j<=count2){
        push(&sum,++c3,ptr2[j*3],ptr2[j*3+1],ptr2[j*3+2]);j++;
    }
    *(sum+2)=c3;
    *ct3=c3;
    return sum;
}

void push(int **ptr,int idx,int r,int c,int v){
    //here idx is element number
    int *temp=(int *)realloc(*ptr,(3*(idx+1))*sizeof(int));
    if(temp!=NULL) *ptr=temp;
    else{printf("Memory Allocation Failed");exit(1);}
    *(*ptr+idx*3)=r;*(*ptr+(idx*3)+1)=c;*(*ptr+(idx*3)+2)=v;
    
}