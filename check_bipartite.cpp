#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))

int main()
{
  int t,n;scanf("%d",&t);
  while(t--)
    {
        ll v,e,a,b;scanf("%lld%lld",&v,&e);
        vector<vector<ll>> adj(v);
        queue<ll> q;
        f(i,0,e)
        {
            scanf("%lld%lld",&a,&b);
            if(a==b)adj[a-1].pb(a-1);
            else
            {
                adj[a-1].pb(b-1);
                adj[b-1].pb(a-1);
            }
        }
    
    int is_bi = 1;
    char color[v];int nature[v];fill(nature);memset(color,'w',sizeof(color));
    
    f(alp,0,v){
        if(color[alp]=='g')continue;
        q.push(alp);color[alp]='g';
        nature[alp]=1;
        
        while(!q.empty()&&is_bi)
        {
            ll t = q.front();
            q.pop();
            f(i,0,adj[t].size())
            {
                if(color[adj[t][i]]=='w')
                {
                    color[adj[t][i]] ='g';
                    q.push(adj[t][i]);
                    nature[adj[t][i]] = nature[t]*-1;
                }
                else if(nature[adj[t][i]] == nature[t]) {is_bi=0;break;}
            }
        }    
    }
     
     if(is_bi) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
        
    }
  return 0;
}
