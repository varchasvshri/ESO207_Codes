#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))
const ll mod = 1e9+7;

ll MATRIX_CHAIN(ll* arr, ll n)
{
    ll **m = (ll**)malloc(n*sizeof(ll*));
    f(i,0,n) m[i] = (ll*)malloc(n*sizeof(ll));
    f(i,0,n) m[i][i] = 0; //all diagonal elements to be 0
    for(ll l = 2; l<n; l++)
    {
        for(ll i = 1; i<=n-l; i++)
        {
            ll j = i + l - 1;
            m[i][j] = LONG_MAX;
            for(ll k=i;k<=j-1;k++)
            {
                ll q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(m[i][j]>q){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    ll n;scanf("%lld",&n);
    ll arr[n+1];
    f(i,0,n+1) cin>>arr[i];
    cout<<MATRIX_CHAIN(arr,n+1)<<endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,a,n) for (int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define fill(a)  memset(a, 0, sizeof (a))
const ll mod = 1e9+7;

int main()
{
  ll t;scanf("%lld",&t);
  while(t--)
  {
      int m,n;scanf("%d%d\n",&m,&n);
      char one[m+1],two[n+1];
      scanf("%s",&one);scanf("%s",&two);
      int **mat = (int**)malloc((m+1)*sizeof(int*));
      f(i,0,m+1) mat[i] = (int*)malloc((n+1)*sizeof(int));
      f(i,0,m+1)
        {
            f(j,0,n+1)
            {
                if(!i||!j) {mat[i][j] = 0;}
                else if(one[i-1]==two[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
                else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
      printf("%d\n",mat[m][n]);
  }
}
