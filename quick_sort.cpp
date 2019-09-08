#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int p,int r)
{
    int pivot = a[r];
    int q,i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[r]);
    return i;
}

void quick_sort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

int main() {
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}