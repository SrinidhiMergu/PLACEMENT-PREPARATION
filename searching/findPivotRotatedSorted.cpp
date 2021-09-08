#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)

int main(){

	int a[]={6,7,1,2,3,4};
	int n=sizeof(a)/sizeof(int);
	int s=0, e=n-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(mid<e && a[mid]>a[mid+1]){
			cout<<a[mid]<<endl;
			break;
		}
		else if(mid>s && a[mid]<a[mid-1]){
			cout<<a[mid-1]<<endl;
			break;
		}
		//right unsorted
		else if(a[e]<=a[mid]){
			s=mid+1;
		}
		//left unsorted
		//a[s]>=a[mid]
		else{
			e=mid-1;
		}
	}
	if(s>e){
		cout<<"Pivot element doesn't exist";
	}
	return 0;
}

//bs - log(n)

