#include <bits/stdc++.h>
using namespace std;

int merge_count_inv(int A[],int p, int q , int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];int R[n2+1];
    for(int i=0;i<n1;i++){L[i] = A[p+i];}
    for(int i=0;i<n2;i++){R[i] = A[q+1+i];}
    L[n1]=INT_MAX;R[n2]=INT_MAX;
    int p1=0;int p2=0;int inv_count=0;
    for(int i=0;i<r-p+1;i++)
    {
        if(R[p2]>=L[p1]){
            A[p+i] = L[p1];
            p1++;
        }
        else{
            A[p+i] = R[p2];
            p2++;
            inv_count += q-p-p1+1;//Assuming array is sorted from p to q and q+1 to r
        }
    }
    return inv_count;
}

int merge_sort_count_inv(int A[], int p, int r)
{
    if(p<r){
        int q = (p+r)/2;
        int l_count_inv = merge_sort_count_inv(A,p,q);
        int r_count_inv = merge_sort_count_inv(A,q+1,r);
        int cross_inv = merge_count_inv(A,p,q,r);
        return l_count_inv+r_count_inv+cross_inv;
    }
    else return 0;//single element has no inversions
}

int main() {
    //counting number of inversions as well as sorting the array
	int A[] = {1, 20, 6, 4, 5 };
	cout<<merge_sort_count_inv(A,0,4)<<"\n";
	for(int i=0;i<5;i++) cout<<A[i]<<" ";
	return 0;
}
