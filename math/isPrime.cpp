#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_prime(unsigned long long int n){
    if(n<2 || (n%2==0 && n!=2))
        return 0;
    else if(n==2)
        return 1;
    else{
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    unsigned long long int n;
    cin>>n;
    if(is_prime(n))
        cout<<"Yes";
    else
        cout<<"No";
        
    return 0;
}
