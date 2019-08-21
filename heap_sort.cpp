#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int A[], int heap_size, int node)//make heap from which node
{
    int left = 2*node + 1; 
    int right = 2*node + 2;
    int max_index = node;
    if(left<heap_size && A[left]>A[node]) //compare left child and root
        max_index = left;
    
    if(right<heap_size && A[right]>A[max_index]) //compare right child to both left child and parent
        max_index = right;
        
    if(max_index!=node) //checking if root itself is greater than its children
    {
        swap(A[node],A[max_index]); //following the property of max-heap
        heapify(A,heap_size,max_index); //recursively build the heap
    }
}

void heap_sort(int A[], int heap_size)
{
    int n = heap_size;
    for(int i = n/2 ;i>=0;i--) //notice i starts when all the leaves end from below and goes up to the first element
        heapify(A,n,i); //after completion of each iteration the subtrees rooted at all index above i satisfy max heap property
    
    for(int i=n-1;i>=0;i--)
    {
        swap(A[0],A[i]); //getting the largest element A[0] to the bottom of array
        n--; // removing last elemnt from the tree/heap
        heapify(A,n,0); //after swapping heap condition is lost for first node, so again build the heap for first node only
    }
}

int main() {
    int n;cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    heap_sort(A,n);
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    return 0;
}