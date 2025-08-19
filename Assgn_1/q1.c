#include<stdio.h>
#include<stdlib.h>

int * create(int s);
void display(int *p,int s);
int * insert(int *ptr,int s,int idx,int e);
int * delete(int *ptr,int s,int idx);
int lin_search(int *ptr,int s,int e);

int main(){
    printf("MENU\n");
    printf("1.Create\t2.Dsiplay\t3.Insert\t4.Delete\t5.Linear Search\n");
    int ch=100,size,*ptr;
    while(ch!=6){
        printf("Enter option:");
        scanf("%d",&ch);
        if(ch==1){
            int s;
            printf("Enter size of array:");
            scanf("%d",&s);
            int *p= create(s);
            size=s;ptr=p;
        }
        else if(ch==2) display(ptr,size);
        else if(ch==3){
            int id,el,*p;
            printf("Enter idx and element for insertion:");
            scanf("%d%d",&id,&el);
            p=insert(ptr,size,id,el);
            if(p!=NULL){
                ptr=p;
                size=size+1;
            }
            else printf("Invalid index of Array\n");
        }
        else if(ch==4){
            int id,*p;
            printf("Enter idx for deletion:");
            scanf("%d",&id);
            p=delete(ptr,size,id);
            if(p!=NULL){
                ptr=p;
                size=size-1;
            }
            else printf("Invalid index of Array\n");
        }
        else if(ch==5){
            int el,r;
            printf("Enter element for linear search:");
            scanf("%d",&el);
            r=lin_search(ptr,size,el);
            if(r!=-1) printf("Element %d found at index %d\n",el,r);
            else printf("Element not found in array\n");
        }
        else if(ch==6) printf("EXITED\n");
        else printf("Invalid Option, please try again\n");
    }
    return 0;
}

int * create(int s){
    int *ptr= (int *)malloc(s*sizeof(int));
    printf("Please enter the %d elements:",s);
    int i;
    for(i=0;i<s;i++){
        scanf("%d",ptr+i);
    }
    return ptr;
}

void display(int *p,int s){
    printf("The contents of the array are:\n");
    int i;
    for(i=0;i<s;i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
}

int * insert(int *ptr,int s,int idx,int e){
    if(idx<0||idx>s-1) return NULL;
    else{
        int *temp=(int *)realloc(ptr,(s+1)*sizeof(int));
        ptr=temp;
        int i=s;
        while(1){
            if(i==idx){
                *(ptr+i)=e;
                break;
            }
            else *(ptr+i)=*(ptr+(i-1));
            i--;
        }
        return ptr;
    }
}

int * delete(int *ptr,int s,int idx){
    if(idx<0||idx>s-1) return NULL;
    else{
        int i=idx;
        while(1){
            if(i!=(s-1)) *(ptr+i)=*(ptr+i+1);
            else break;
            i++;
        }
        return ptr;
        int *temp=(int *)realloc(ptr,(s-1)*sizeof(int));
        ptr=temp;
        return ptr;
    }
}

int lin_search(int *ptr,int s,int e){
    int i=0,flag=0;
    for(i;i<s;i++){
        if(*(ptr+i)==e){
            flag=1;
            break;
        }
    }
    if(flag==1) return i;
    else return -1; //case of no element found
}