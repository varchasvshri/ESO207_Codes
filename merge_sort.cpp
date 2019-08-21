#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r -q;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++)L[i]=A[p+i]; 
    for(int i=0;i<n2;i++)R[i]=A[q+i+1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i=0;int j=0;int k;
    for(k=0;k<r-p+1;k++)
    {
        if(L[i]>=R[j]){
            A[p+k] = R[j];
            j++;
        }
        else{
            A[p+k] = L[i];
            i++;
        }
    }
}

void merge_sort(int A[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main() {
	int A[] = {12,11,23,54,12,17,34,13,6,5,7};
	merge_sort(A,0,10);
	for(int i=0;i<11;i++) cout<<A[i]<<" ";
	return 0;
}