void countSort(){
    int n;
    cin>>n;
    vi ar(n);
    vi count(10, 0);
    rep(i,n)
        cin>>ar[i];
  
  
  
    rep(i, n)
        count[ar[i]]++;
    int i;
    for(i=1;i<10;i++){
        count[i] += count[i-1];
    }
    //_print(count);
    vi c(n);
    for(i=n-1; i>=0;i--){
        count[ar[i]]--;
        c[count[ar[i]]]=ar[i];
    }
    _print(c);
}

//make some changes so that count array is in range of max - min + 1 instead of (0, max)

void countSort(){
    void countSort(){
    int n;
    cin>>n;
    vi ar(n);

    rep(i,n)
        cin>>ar[i];

    int max = *max_element(ar.begin(), ar.end());
    int min = *min_element(ar.begin(), ar.end());
    int range = max - min + 1;
    vi count(range, 0);
    rep(i, n){
        int idx = ar[i] - min;
        count[idx]++;
    }
    int i;
    for(i=1;i<range;i++){
        count[i] += count[i-1];
    }
    //_print(count);
    vi c(n);

    for(i=n-1; i>=0;i--){
        int val = ar[i];
        int pos = count[val - min];
        int idx = pos - 1;
        c[idx] = val;
        count[val - min]--;
    }
    _print(c);
}
}

i/p
15
9 6 3 5 3 4 3 9 6 4 6 5 8 9 9
o/p
[ 3 3 3 4 4 5 5 6 6 6 8 9 9 9 9 ] 
  
Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 
Auxiliary Space: O(n+k)
  
Modify for range M  to N
