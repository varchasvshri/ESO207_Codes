#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))

struct Graph {
    struct node* head[100000];
};
typedef struct Graph graph;

struct store {
    ll a[100000];
    ll b[100000];
    ll top = -1;
}cool;


struct node{
    ll val;
    struct node *next;
};
typedef struct node node;

ll max(ll a, ll b)
{
    if(a>b) return a;
    return b;
}

ll min(ll a, ll b)
{
    if(a>b) return b;
    return a;
}

ll timer = 0,flag=1;

void dfs(graph *g, ll v, ll parent[] , ll is_visited[], ll entry[], ll low_val[])
{
    is_visited[v] = 1;
    entry[v] = ++timer; low_val[v] = timer;
    for(node *ptr = g->head[v]; ptr!=NULL; ptr = ptr->next)
    {
        if(v==parent[ptr->val]) continue;
        if (!is_visited[ptr->val])
        {
            parent[ptr->val] = v;
            dfs(g,ptr->val,parent,is_visited,entry,low_val);
            low_val[v] = min(low_val[v],low_val[ptr->val]);
            
            if(low_val[ptr->val]>entry[v]){
                flag=0;
                cool.a[++cool.top] = min(ptr->val,v);
                cool.b[cool.top] = max(ptr->val,v);
                ll ele = cool.top ;
                while(ele>=1 && cool.a[ele]==cool.a[ele-1] && cool.b[ele]<cool.b[ele-1])
                {
                    swap(cool.b[ele],cool.b[ele-1]);
                }
            }
        }
        else if(ptr->val!=parent[v])
        {
            low_val[v] = min(low_val[v],entry[ptr->val]);
        }
    }
}

int main()
{
    ll v,e,a,b;scanf("%lld%lld",&v,&e);
    graph *g = (graph*)malloc(sizeof(graph));
    f(i,0,v) g->head[i] = NULL;
    
    f(i,0,e)
    {
        scanf("%d%d",&a,&b);
        node* newNode1 = (node*)malloc(sizeof(node));
        newNode1->val = b;
        newNode1->next = g->head[a];
        g->head[a] = newNode1;
        node* newNode2 = (node*)malloc(sizeof(node));
        newNode2->val = a;
        newNode2->next = g->head[b];
        g->head[b] = newNode2;
    }
    
    ll is_visited[v],parent[v];fill(is_visited);memset(parent,-1,sizeof(parent));
    ll entry[v],low_val[v];fill(entry);fill(low_val);
    
    for(int i=v-1;i>=0;i--)
    {
        if(!is_visited[i]) dfs(g,i,parent,is_visited,entry,low_val);
    }
    
    if(flag) cout<<"No";
    else{
        f(i,0,cool.top+1) cout<<cool.a[i]<<" "<<cool.b[i]<<endl;
    }
  return 0;
}