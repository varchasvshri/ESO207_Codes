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

struct node{
    ll val;
    struct node *next;
};
typedef struct node node;

struct queu{
    ll a[100000];
    ll head=0;
    ll tail=0;
};
typedef struct queu queu;
queu q;

void push_in(queu *q, ll x)
{
    q->a[q->tail] = x;
    q->tail++;
}

void pop_out(queu *q)
{
    q->head++;
}

ll front(queu *q)
{
    return q->a[q->head];
}

int isempty(queu *q)
{
    return q->head == q->tail;
}

ll timer = 0,source=0;

void dfs(graph *g, ll v, ll parent[] , char is_visited[], ll tin[], ll low[])
{
    is_visited[v] = 'b';
    tin[v] = ++timer; low[v] = timer;
    
    for(node *ptr = g->head[v]; ptr!=NULL; ptr = ptr->next)
    {
        if(v==parent[ptr->val]) continue;
        else if (is_visited[ptr->val]=='w')
        {
            parent[ptr->val] = v;
            dfs(g,ptr->val,parent,is_visited,tin,low);
            low[v] = min(low[v],low[ptr->val]);
            
            if(low[ptr->val]>tin[v]){source = ptr->val;}
        }
        else if((ptr->val)!=parent[v])
        {
            low[v] = min(low[v],tin[ptr->val]);
        }
        
    }
}

void bfs(graph *g, ll v, ll parent[], ll distance[])
{
    char is_visited[v];memset(is_visited,'w',sizeof(is_visited));
    push_in(&q,source);is_visited[source] = 'b';
    while(!isempty(&q))
    {
        ll u = front(&q);
        pop_out(&q);
        node *ptr = g->head[u];
        for(node *ptr = g->head[u]; ptr!=NULL; ptr = ptr->next)
        {
            if(is_visited[ptr->val]=='w')
            {
                distance[ptr->val] = distance[u] + 1;
                parent[ptr->val] = u;
                is_visited[ptr->val] = 'b';
                push_in(&q,ptr->val);
            }
        }
    }
}

int main()
{
    ll v,e,qp,a,b;scanf("%lld%lld%lld",&v,&e,&qp);
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
    
    char is_visited[v];memset(is_visited,'w',sizeof(is_visited));
    ll parent[v];memset(parent,-1,sizeof(parent));
    ll tin[v],low[v];fill(tin);fill(low);
      
    dfs(g,0,parent,is_visited,tin,low);
    
    memset(parent,-1,sizeof(parent));
    ll distance[v];fill(distance);
    bfs(g,v,parent,distance);
    
    while(qp--)
    {
        cin>>a>>b;
        cout<<distance[a] + distance[b]<<endl;
    }
  return 0;
}