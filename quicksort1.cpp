#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// swap function create swap function always with pass by rference to work lol!
void swap(int * &array,int a,int b){
    int temp  = array[a];
    array[a]  = array[b];
    array[b]  = temp;
}

// partioning function
int loumutoPartition(int *arr, int low , int high){
    // selcting pivot element basically that element which divide partition
    // [ less tha pivot element | pivot element | greater than pivot element ] ----> array after loumuto partition
    int pivot=arr[high];
    int i= low-1;
    for (int j = low; j <= (high-1); j++)
    {
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
   
    return i+1;
    
}
int partitionrandom(int* &array,int start,int end){
    srand(time(NULL));
    int randompivot = start+ rand() % (start - end);
    swap(array,randompivot,end);
    return loumutoPartition(array, start, end);
}
// quick sort function
void quickSort(int* arr , int low , int high){
    if(low<high){
        // int p=loumutoPartition(arr,low,high);
        int p=partitionrandom(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
// selecting random pivot  or median pivot
// void selectRandomPivot(int * arr , int n){
//     srand(time(0));
//     int j=rand()%n;
//     int k=rand()%n;
//     int l=rand()%n;
//     cout<<"\nj : "<<j<<": "<<arr[j]<<" k : "<<k<<" : "<<arr[k]<<" l :"<<l<<" : "<<arr[l]<<endl;
//     int pivotIndex;
//      // Checking for b
//     if ((arr[j] < arr[k] && arr[k] < arr[l]) || (arr[l] < arr[k] && arr[k] < arr[j])){

//         pivotIndex=k;
//     }
//     // Checking for a
//     else if ((arr[k] < arr[j] && arr[j] < arr[l]) || (arr[l] < arr[j] && arr[j] < arr[k])){

//         pivotIndex=j;
//     }
//     else{

//         pivotIndex=l;
//     }

//     cout<<"\n  index : "<<pivotIndex<<endl;
//     // int pivot=arr[pivotIndex];
//     swap(arr[pivotIndex],arr[n-1]);

// }


int main(){
    int A[]={10,80,30,90,40,50,70};
    // int A[]={5,3,8,4,2,7,1,10};
    int h=6;
    int l=0;
    // loumutoPartition(A,0,6);
    // naivePartition(A,0,6,4);
    // hoarePartition(A,0,7);
    cout<<"Raw Array : ";
    for (int i = 0; i < 7; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Array after Quick Sort : ";
    quickSort(A,l,h);
    for (int i = 0; i < 7; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}

// int main()
// {
//     //creating stream for file 
//     // fstream file;

//     int iter=0;

//     // using srand function for reducing the probability of generating same random integer
//     srand(time(0));

    
//     // loop for iterating mergesort for 100 times
//     while (iter!=3)
//     {
       

//         cout<<"\nITERATION : "<<iter+1<<endl;
        
//         // input_size variable which holds the random value generated by rand() function <=1000
//         // act as a input size for array , and changes after each iteration
//         int input_size=rand()%30; 

//         // Arr[input_size] array of random size <=1000;
//         int *Arr=new int[input_size];

//         cout<<"SIZE OF ARRAY : "<<input_size<<endl;

//         // loop for filling array with random integers;
//         for (int i = 0; i < input_size; i++)
//         {
//             int x = rand()%30;
//             Arr[i]=x;
//         }
       
//         //counting execution time using time library
//         cout<<"\nRAW ARRAY : ";
//         for (int i = 0; i < input_size; i++)
//         {
//             cout<<Arr[i]<<" ";
//         }
//         selectRandomPivot(Arr,input_size);    
//         cout<<"\nAfter pivot selection ARRAY : ";
//         for (int i = 0; i < input_size; i++)
//         {
//             cout<<Arr[i]<<" ";
//         }
//         auto start = high_resolution_clock::now();
//         quickSort(Arr,0,(input_size-1));
//         auto stop = high_resolution_clock::now();
//         auto duration = duration_cast<microseconds>(stop - start);
//         cout<<"\n After Quick Sort ARRAY : ";
//         for (int i = 0; i < input_size; i++)
//         {
//             cout<<Arr[i]<<" ";
//         }
       
       
        
//         iter++;   
//         free(Arr); 
//     }
    
// }