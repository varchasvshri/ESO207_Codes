#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

void span_range(ll a[], int n, ll span[])
{
    stack<ll>st;
    ll h[n];
    // for(int i=0;i<n;i++)
    // {
    //     stack<ll> st;
         st.push(0); 
         span[0] = 1; 
  
    for (int i = 1; i < n; i++) { 
        while (!st.empty() && a[i]>=a[st.top()]) st.pop(); 
        if(st.empty()) span[i]=i+1;
        else span[i] = i - st.top();
        st.push(i); 
        } 
    //}
}

int main() {
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;cin>>n;
        ll a[n];ll span[n];
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        span_range(a,n,span);
        for(int i=0;i<n;i++)printf("%lld\n",span[i]);
    }
    return 0;
}