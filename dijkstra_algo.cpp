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
    double weight;
    struct node *next;
};
typedef struct node node;


int main() {
    ll v,e,a,b,w,s,t;scanf("%lld%lld",&v,&e);
    graph *g = (graph*)malloc(sizeof(graph));
    f(i,0,v) g->head[i] = NULL;
    
    f(i,0,e)
    {
        scanf("%lld%lld%lld",&a,&b,&w);
        node* newNode1 = (node*)malloc(sizeof(node));
        newNode1->val = b;
        newNode1->weight = w;
        newNode1->next = g->head[a];
        g->head[a] = newNode1;
    }
    scanf("%lld%lld",&s,&t);
    
    ll distance[v], count = v, is_visited[v];memset(is_visited,0,sizeof(is_visited));
    f(i,0,v) {distance[i] = 900000000;}
    distance[s] = 0;
 
    while(count--)
    {
        ll store = -1;
        ll min = LONG_MAX;
        f(i,0,v){
            if(distance[i]<=min && !is_visited[i]) {min = distance[i];store=i;}
        }
        is_visited[s] = 1;
        if(store==-1) break;
        is_visited[store] = 1;
        
        for(node* ptr = g->head[store]; ptr!=NULL; ptr=ptr->next)
        {
            if(distance[ptr->val] > distance[store] + ptr->weight && !is_visited[ptr->val])
            {
                distance[ptr->val] = distance[store] + ptr->weight;
            }
        }
    }
    
    cout<<distance[t];
    return 0;
}