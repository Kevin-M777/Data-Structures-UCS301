#include<iostream>
using namespace std;
//Combined Source file for full Assignment 9
class Heap{
   public:
   int *arr;
   int heap_size;int length;//length stores the length of the net array whereas heap_szie stores how many elements are there in the heap
   //The above distinction is absolutely necessary in Heapsort
   Heap(int num){this->heap_size=num;this->length=num;arr=(int *)malloc(num*sizeof(int));}//number of elements in heap
   void input(); //this internally also calls build_max_heap()
   void display_array();
   int left(int idx){return (2*idx +1);}//converts parent index to left child index
   int right(int idx){return (2*idx +2);}//converts parent index to right child index
   int parent(int idx){return ((idx-1)/2);}//converts child index to parent index
   int leaf_start(){return heap_size/2;}//returns starting index of leaves in array
   void max_heapify(int idx);
   void build_max_heap();
   void heapsort();
   void increment_array_size(){arr = (int *)realloc(arr,(length + 1)*sizeof(int));length++;}
   //below are the priority queue member functions
   int heap_max(){return arr[0];}
   int heap_extract_max();
   void heap_increase_key(int idx,int key);
   void max_heap_insert(int key);
};

void Heap::input()
{
    cout<<"Enter array values:"<<endl;int i;
    for(i=0;i<heap_size;i++){cin>>arr[i];}
    build_max_heap(); //so we finaally have an actual heap
}

 void Heap::display_array()
 {
   int i;
   for(i=0;i<length;i++){cout<<arr[i]<<" ";}
   cout<<endl;
 }

 void Heap::max_heapify(int idx)
 {
    int l_idx=left(idx);
    int r_idx=right(idx);
    int largest_idx;
    //the <heap_size condition ensures that we are acessing an existing left/right child, we dont want to access a child which doesnt exist!
    if (l_idx < heap_size && arr[l_idx] > arr[idx]) largest_idx = l_idx;
    else largest_idx = idx;
    if (r_idx < heap_size && arr[r_idx] > arr[largest_idx]) largest_idx = r_idx; //observe that we compare with arr[largest_idx] here and not idx!

    if (largest_idx != idx) //ie if max heap property is not satisfied
    {
        //swap arr[idx] and arr[largest_idx]
        int temp = arr[largest_idx];
        arr[largest_idx] = arr[idx];
        arr[idx] = temp;
        max_heapify(largest_idx);
    }
    return;
 }

 void Heap::build_max_heap()
 {
    int i;//go from last non-leaf node all the way back to root and apply max_heapify()
    for(i=leaf_start()-1;i>=0;i--) max_heapify(i);
 }

 void Heap::heapsort()
 {
    int i;
    build_max_heap(); //dont forget this! ensure that max element is on top
    for(i=length-1;i>=1;i--) //last left over node will be displayed separately
    {
        //swap last node with present root
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heap_size = heap_size - 1; //truncate size of heap 
        cout<<arr[i]<<" ";
        max_heapify(0); //now get the heap back into order
    }
    cout<<arr[0]<<endl;
 }

int Heap::heap_extract_max(){//am assuming that build_max_heap() was already called when array was initialized
   if (heap_size >= 1) 
   {
      int max = arr[0];
      arr[0] = arr[heap_size -1];
      heap_size = heap_size - 1;
      max_heapify(0);
      return max;
   }
   else cout<<"Heap Underflow, nothing to extract!"<<endl;
   return -1; //case of underflow
}

void Heap::heap_increase_key(int idx,int key) //this works upwards, do not confuse it with build_max_heap() (works downwards) though this is also trying to restore order
{
   if (key > arr[idx]) //important condition
   {
      arr[idx] = key;
      while (idx >=1 && arr[parent(idx)] < arr[idx]) //can perform a swap from first child onwards only (level 0 is root only) hence idx>=1
      {
         int temp = arr[parent(idx)];
         arr[parent(idx)] = arr[idx];
         arr[idx] = temp;
         idx = parent(idx);
      }
   }
   else cout<<"Key is less than or equal to existing key\n"<<endl;
}

void Heap::max_heap_insert(int key)
{
   if (heap_size == length) increment_array_size();//incase array is full

   heap_size = heap_size + 1;
   arr[heap_size - 1] = -10000; //some very small value so that the key that you insert(update internally)here is surely greater than it
   heap_increase_key(heap_size-1,key);
}

int main(){
   int num;
   cout<<"Enter size of heap:";
   cin>>num;
   Heap ob(num);
   ob.input();
   cout<<ob.heap_extract_max()<<endl;
   cout<<ob.heap_extract_max()<<endl;
   ob.heap_increase_key(2,200);
   ob.display_array();
   ob.max_heap_insert(120);
   ob.max_heap_insert(140);
   ob.max_heap_insert(100);
   ob.display_array();
   
   return 0;
 }


