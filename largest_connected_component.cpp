#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (ll i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))

vector<ll>store;

void dfs_visit(vector<ll>g[], ll v, char color[], ll u, ll *count)
{
    *count+=1;
    color[u] = 'g';
    f(i,0,g[u].size())
    {
        if(color[g[u][i]]=='w') dfs_visit(g,v,color,g[u][i],count);
    }
    color[u] = 'b';
    store.pb(u);
}

void dfs_visit_C(vector<ll>g[], ll v, char color[], ll u, ll *count)
{
    *count+=1;
    color[u] = 'g';
    f(i,0,g[u].size())
    {
        if(color[g[u][i]]=='w') dfs_visit(g,v,color,g[u][i],count);
    }
    color[u] = 'b';
}

void dfs(vector<ll>g[], ll v)
{
    ll trash;
    char color[v];memset(color,'w',sizeof(color));
    f(i,0,v)
    {
        if(color[i]=='w') dfs_visit(g,v,color,i,&trash);
    }
}


int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
      store.clear();
      ll v,e,a,b;scanf("%lld%lld",&v,&e);
      vector<ll> g[v];vector<ll> g_r[v];
      f(i,0,e)
      {
          scanf("%lld%lld",&a,&b);
          g[a].pb(b);g_r[b].pb(a);
      }
      
      dfs(g_r,v);
      reverse(store.begin(),store.end());
      ll max_count=-1;
      char color[v];memset(color,'w',sizeof(color));
      
      f(i,0,v)
      {
          ll x;ll *count=&x;*count=0;
          if(color[store[i]]=='w'){dfs_visit_C(g,v,color,store[i],&x); max_count = max(max_count, x);}
      }
      cout<<max_count<<endl;
  }
  return 0;
}