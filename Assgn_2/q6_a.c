#include <stdio.h>
#include <stdlib.h>
//transpose of sparse matrix
int * input(int row,int col,int *c);
void display(int *ptr,int *c);
void invert(int *ptr,int *c);
void sort(int *ptr,int *c,int row);

int main(){
    int row,col;int count;//count its number of non zero elements
    printf("Enter number of rows:");
    scanf("%d",&row);
    printf("Enter number of columns:");
    scanf("%d",&col);
    int *ptr=input(row,col,&count);
    if(ptr!=NULL) display(ptr,&count);
    else exit(1);
    printf("------\n");
    //converting to column major form
    invert(ptr,&count); 
    printf("Transpose:\n");
    sort(ptr,&count,row);
    display(ptr,&count);
    return 0;
}

int * input(int row,int col,int *c){
    int i,j,count=0,num;//count stores the number of non zero elements
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
}

void invert(int *ptr,int *c){
    //This function interchanges the row and column of each non zero element
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
    //this function sets the elements in row major order after the rows and columns have been inverted
    //by arranging the elements in increasing order of row number, column numbers are already sorted
    //Have used bubble sort for sorting row numbers
    for(i=0;i<((*c)-1);i++){
        for(j=1;j<(*c)-i;j++){
            //Here the index of the actual elements start from 1 thus the upper limit of j  will be till <(*c)-i and not <(*c)-i-1  
            if((*(ptr+j*3))>(*(ptr+j*3+3))){
                //swap r, c, value
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