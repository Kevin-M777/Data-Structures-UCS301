#include<iostream>

void selection_sort(int *A,int num)
{
    int i,j;int min_idx;int temp;
    for(i=0;i<num-1;i++){	
	    min_idx=i;
	    for(j=i+1;j<num;j++){
		    if(A[j]<A[min_idx])min_idx=j;
	    }
	if(min_idx!=i){temp=A[i];A[i]=A[min_idx];A[min_idx]=temp;}
	//min_idx==i means there was no one smaller than the leftmost unsorted element which means that that leftmost element is actually
	//sorted and in its correct place already
    }
}

void improved_selection_sort(int *A,int n)
{
    int i,j;int min_idx,max_idx;int temp;
	for(i=0;i<n/2;i++){	
		min_idx=i;max_idx=n-i-1;
		for(j=i;j<=n-i-1;j++){
			if(A[j]<A[min_idx])min_idx=j;
			if(A[j]>A[max_idx])max_idx=j;
		}
		if(min_idx==max_idx+1){ 
			if(min_idx!=i){temp=A[i];A[i]=A[min_idx];A[min_idx]=temp;}
			//this condition handles the case where in the last section like 1 2 [4 3] 5 7 if the elements are not already ordered
			//then if we do follow the usual swapping we will end up swapping it twice which will get us back to the same unsorted state
			//so in this case we do only one of the swaps, could be any one of them, doesnt make a difference.
		}
		else{
			if(min_idx!=i){temp=A[i];A[i]=A[min_idx];A[min_idx]=temp;}
			if(max_idx!=n-i-1){temp=A[n-i-1];A[n-i-1]=A[max_idx];A[max_idx]=temp;}
		}
	}
}

void bubble_sort(int *a,int n)
{
    int i,j;int flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                flag=1; //atleast a single swap occurred in this pass
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==0)break; //no more passes needed
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void insertionSort(int *A, int n) {
    for (int i=1;i<n; i++) {
        int el = A[i];
        int j = i-1;
        while (j>=0 && A[j]>el) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=el;
    }
}

void merge(int *A, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L=(int *)malloc(n1*sizeof(int));
    int *R=(int *)malloc(n2*sizeof(int));
    int i;
    for (i=0;i<n1;i++){L[i] = A[l+i];}
    for (i=0;i<n2;i++){R[i] = A[m+1+i];}
    int i=0,j=0,k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i<n1){A[k++] = L[i++];}
    while (j<n2){A[k++] = R[j++];}
}

void mergeSort(int *A, int l, int r){
    if (l>=r) return;
    int m = (l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m+1,r);
    merge(A,l,m,r);
}

int partition(int A[], int l, int r) {
    int pivot = A[r];int temp;
    int i=l-1;int j;
    for (j=l; j<r;j++) {
        if (A[j]<=pivot) {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

void quickSort(int *A, int l, int r){
    if (l>=r) return;
    int p=partition(A,l,r);
    quickSort(A,l,p-1);
    quickSort(A,p+1,r);
}

int main()
{
    int A[]={2,1,4,5,3};
    int size = sizeof(A)/sizeof(int);
    bubble_sort(A,size);

    return 0;
}

