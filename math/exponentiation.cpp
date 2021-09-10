#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)

// Brute force - recursive
ll pow(ll x,ll n){
    if(n==0)
        return 1;
    else
        return x*pow(x,n-1);
}
//binary exponentiation - recurive
ll pow(ll x, lln){
	if(n==0)
		return 1;
	else if(n%2==0){
		y=pow(x,n/2);
		return y*y;
	}
	else{
		return x*pow(x,n-1);
	}
}
//binary exponentiation - iterative
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
// to calculate a^b % m - bitmasking
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
// to calculate a^b % m - recursion
ll moduloExp(ll x, ll, n, ll m){
    if(n==0)
        return 1;
    else if(n%2==0){
        y=moduloExp(x,n/2,m);
        return (y*y) % m;
    }
    else{
        return ((x % m) * moduloExp(x,n-1,m)) % m;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a,b;
    cin>>a>>b;
    cout<<binary_exp(a,b)<<endl;
    cout<<fastModuloExp(a,b,10)<<endl;
    } 
    return 0;
}
//O(n)
//O(logn)
//T=log2N - BE
//T=logB where B=no. of bits in n - ME
//TC = logn where n=power
