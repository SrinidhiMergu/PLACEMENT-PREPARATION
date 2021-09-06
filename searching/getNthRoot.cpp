#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)
//#define eps 1e-6
//binary exponentiation
double multiply(double x, int n){
    double ans = 1.0;
    ll nn = n;
    while(nn){
        if(nn%2==0){
            x = x*x;
            nn/=2;
        }
        else{
            ans=ans*x;
            nn-=1;
        }
    }
    return ans;
}

double getNthRoot(int n, int m){
    double s=1, e=m;
    double eps = 1e-6;
    while((e-s)>eps){
        double mid=(s+e)/2;
        if(multiply(mid, n)<m){
            s=mid;
        }
        else{
            e=mid;
        }
    }
    return s;

}
int main(){
    int n, m;
    cin>>n>>m;
    cout<<getNthRoot(n, m)<<endl;
    cout<<pow(m, (1.0/n));
    return 0;
}

//getNthRoot - log2(M*10)
//multiply - log2N
// T = log2N * log2(M*10)
// T = log2N * log2M
