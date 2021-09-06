#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<n;i++)

float square_root(int no, int n){
    //integer part
    int s=0, e=no;
    float valid_ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==no){
            return mid;
        }
        else if(mid*mid<no){
            valid_ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    //fractional part
    float inc=0.1;
    rep(i,n){
        while(valid_ans*valid_ans<=no){
            valid_ans += inc;
        }
        valid_ans -= inc;
        inc/=10;
    }
    return valid_ans;

}
int main(){
    int n, places;
    cin>>n>>places;
    cout<<square_root(n, places)<<endl;
    return 0;
}
// integer part is done using binary search - O(logN)
// iterating 9 times for each place value - 9 * p
// T = O(logN + p) ~ O(logN)

