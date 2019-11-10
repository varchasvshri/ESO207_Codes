#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))

struct node{
    ll src = -1;
    ll dest = -1;
    ll weight = -1;
};
typedef node node;

bool comp(node a, node b)
{
    return a.weight<b.weight;
}

struct makeset{
    ll key = -1;
    ll rank = 0;
};
typedef makeset makset;

ll find(ll x, ll parent[])
{
    ll y = x;
    while(y!=parent[y]){
        y = parent[y];
    }
    return y;
}

void un_ion(ll rank[], ll x, ll y, ll parent[])
{
    ll rx = find(x, parent);
    ll ry = find(y, parent);
    if(rx == ry) return;
    if(rank[rx] > rank[ry]) parent[ry] = rx;
    else if(rank[rx] < rank[ry]) parent[rx] = ry;
    else{
        parent[ry] = rx;
        rank[rx] = rank[rx] + 1;
    }
}


int main() {
    ll v,e,q,c=0;scanf("%lld%lld%lld",&v,&e,&q);
    node edges[e+q]; ll sum = 0;
    f(i,0,e+q) {
        scanf("%lld%lld%lld",&edges[i].src,&edges[i].dest,&edges[i].weight);
        ll t = c;
        if(c<=e-1){
        while(t>0&&edges[t].weight<edges[t-1].weight){swap(edges[t],edges[t-1]);t--;}}
        c++;
    }
        
    ll rank[v];
    ll parent[v];
    
    f(k,0,q+1){
        ll sum = 0;fill(rank);
        f(i,0,v) parent[i]=i;
        f(i,0,e+k)
        {
            ll temp1 = edges[i].src; ll temp2 = edges[i].dest;
            if(find(temp1, parent)!=find(temp2, parent))
            {
                un_ion(rank, temp1, temp2, parent);
                sum += edges[i].weight;
            }
        }
        printf("%d\n",sum);
        ll t = e+k;
        if(t<e+q){
        while(t>0&&edges[t].weight<edges[t-1].weight){swap(edges[t],edges[t-1]);t--;}}
    }
    return 0;
}
