#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// long long find_pivot(long long a[],long long p, long long r)
// {
//     if(p>r) return p;
//     long long q = (p+r)/2;
//     if(q<r && a[q]>a[q+1]) return q;
//     if(q>p&&a[q]<a[q-1]) return q-1;
//     if(a[q]>a[p])return find_pivot(a,q+1,r);
//     return find_pivot(a,p,q);
// }

// long long binary_search(long long a[],long long p, long long r, long long k)
// {
//     if(p>r) return -1;
//     long long q = (p+r)/2;
//     if(a[q]==k)return q;
//     else if(a[q]>k) return binary_search(a,p,q-1,k);
//     else return binary_search(a,q+1,r,k);
// }

long long find_index(long long a[],int p, int r, long long k)
{
    if(p>r) return -1;
    int q = (p+r)/2;
    if(a[q]==k) return q;
    if(a[q]>a[p])
    {
        if(k<=a[q]&&k>=a[p]) return find_index(a,p,q-1,k);
        return find_index(a,q+1,r,k);
    }
    if(k>=a[q]&&k<=a[r]) return find_index(a,q+1,r,k);
    
    return find_index(a,p,q-1,k);
}

int main() {
    long long t,k,n;cin>>t;
    while(t--)
    {
        cin>>n;long long a[n];
        for(long long i=0;i<n;i++)cin>>a[i];
        cin>>k;
        // long long pivot = find_pivot(a,0,n-1);
        // if(a[pivot]==k) cout<<pivot;
        // else if(a[0]<k) cout<<binary_search(a,0,pivot-1,k)<<endl;
        // else cout<<binary_search(a,pivot+1,n-1,k)<<endl;
        cout<<find_index(a,0,n-1,k)<<endl;
    }
    return 0;
}