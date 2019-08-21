#include <bits/stdc++.h>
using namespace std;

int max_mid_sum(int A[], int p, int q,int r)
{
    int cross_sum = 0;
    int l_sum = INT_MIN; int r_sum = INT_MIN;int sum=0;
    for(int i=q;i>=p;i--)
    {
        sum += A[i];
        l_sum = max(l_sum,sum);
    }sum = 0;
    for(int i=q+1;i<=r;i++)
    {
        sum += A[i];
        r_sum = max(r_sum,sum);
    }
    cross_sum = l_sum + r_sum;
    return cross_sum;
}

int max_subarray_sum(int A[], int p, int r)
{
    if(p<r){
        int q = (p+r)/2;
        int l_sum = max_subarray_sum(A,p,q);
        int r_sum = max_subarray_sum(A,q+1,r);
        int cross_sum = max_mid_sum(A,p,q,r);
        return max(max(l_sum,r_sum),cross_sum);
    }
    else return A[p];
}

int main() {
	int A[] = {-1,4,3,-5,7,-3,-2,-4};
	cout<<max_subarray_sum(A,0,7);
	return 0;
}