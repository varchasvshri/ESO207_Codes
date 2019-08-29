#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;

vector<cd> Rec_FFT(vector<cd> a, int n)
{
    if(n==1) return a;
    vector<cd>a_even(n/2);
    vector<cd>a_odd(n/2);
    for(int i=0;i<n/2;i++)
    {
        a_even[i] = a[i*2];
        a_odd[i] = a[2*i + 1];
    }
    vector<cd> ye = Rec_FFT(a_even,n/2);
    vector<cd> yo = Rec_FFT(a_odd,n/2);
    
    cd w = cd(1,0);cd wn = cd(cos((2*M_PI)/n),sin((2*M_PI)/n));
    vector<cd> y(n);
    for(int i=0;i<(n/2);i++)
    {
        cd w = cd(cos((2*M_PI*i)/n),sin((2*M_PI*i)/n));
        y[i] = ye[i] + w*yo[i];
        y[i+n/2] = ye[i] - w*yo[i];
        // w = w*wn;
        // cout<<w<<endl;
    }
    return y;
}

 int main() {
    int t;cin>>t;
    while(t--)
    {
        int n,N;cin>>n;
        if(n==0){N=1;}
        else if(fmod(log(n)/log(2),1)) N = pow(2,int(log(n)/log(2)))*2;
        else N = n;
        vector<cd> a(N);
        double real,img;
        for(int i=0;i<n;i++){cin>>real>>img;a[i] = cd(real,img);}
        vector<cd> y(N);
        y = Rec_FFT(a,N);
        cout<<setprecision(3)<<fixed;
        for(int i=0;i<N;i++)cout<<y[i]<<endl;
    }
    return 0;
}