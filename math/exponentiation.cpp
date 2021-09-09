#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)

//binary exponentiation
// to calculate a^b
ll binary_exp(ll x, ll n){
    ll ans=1;
    while(n>0){
        if(n%2==0){
            x=x*x;
            n/=2;
        }
        else{
            ans=ans*x;
            n-=1;
        }
    }
    return ans;
}
// to calculate a^b % m
ll fastModuloExp(ll x, ll n, ll m){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans = (ans*x)%m;
        }
        x = (x*x)%m;
        n = n>>1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<binary_exp(a,b)<<endl;
        cout<<fastModuloExp(a,b,10)<<endl;
    } 
    return 0;
}
//T=log2N - BE
//T=logB where B=no. of bits in n - ME

