#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)
#define mp make_pair

string addBinary(string a, string b) {
    string res;
    ll i = a.size() - 1, j = b.size() - 1;
    ll sum, carry = 0;
    while(i >= 0 || j >= 0) {
        sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        res += to_string(sum % 2);
        carry = sum / 2;
    }
    if(carry != 0) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; 
}

int multiplySingleBit(string a, string b)
{  return (a[0] - '0')*(b[0] - '0');  }

ll karatsuba(string X, string Y)
{
    int n = makeEqualLength(X, Y);
 
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return multiplySingleBit(X, Y);
 
    int fh = n/2;   // First half of string, floor(n/2)
    int sh = (n-fh); // Second half of string, ceil(n/2)

    string a = X.substr(0, fh);
    string b = X.substr(fh, sh);
 
    string c = Y.substr(0, fh);
    string d = Y.substr(fh, sh);
 
    ll P1 = karatsuba(a, c);
    ll P2 = karatsuba(addBinary(a, b), addBinary(c, d));
    ll P3 = karatsuba(b, d);

    return P1*(1<<(2*sh)) + (P2 - P1 - P3)*(1<<sh) + P3;
}
string DecimalToBinary(ll number)
{
    string result = "";
    if (number <= 0)
    {
        return "0";
    }
    else
    {
        int i = 0;
        while (number > 0)
        {
             
            ll num= number % 2;
            stringstream ss;
            ss<<num;
            result = ss.str() + result;
            number = number / 2;
            i++;
        }
        return result;
         
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        string x=DecimalToBinary(a);
        string y=DecimalToBinary(b);
        //string ans = karatsuba(x, y);
        //cout<<ans<<endl;
        cout<<karatsuba(x, y)<<endl;
    }
    return 0;
}
// o(n^log2(3)) ~ o(n^1.585)
