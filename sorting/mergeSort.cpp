template <class T>
void print(vector<T> v)
{
    fore(v) cout << x << ' ';
    cout << endl;
}
void merge(vi &arr, int lo, int mid, int hi, ll &invCnt){
    int nL = mid-lo+1;
    int nR = hi-mid;
    //int invCnt=0;
  
    //auto *leftArr = new int[nL];
      //   * rightArr = new int[nR];
    vi leftArr, rightArr;

    rep(i, nL){
        leftArr.pb(arr[lo+i]);
    }
    rep(i, nR){
        rightArr.pb(arr[mid+1+i]);
    }
    int i=0, j=0, k=lo; //ptrs for left, right, arr
    while(i<nL && j<nR){
        if(leftArr[i]<=rightArr[j]){
            arr[k]=leftArr[i];
            i++;
        }
        else{
            arr[k]=rightArr[j];
            j++;
            //invCnt+=(mid-i);
            invCnt+=(leftArr.size()-i);        /*********************/
        }
        k++;
    }
    while(i<nL){
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    while(j<nR){
        arr[k]=rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(vi &arr, int lo, int hi, ll &invCnt){

    //b.c
    if(lo>=hi){
        return;
    }

    int mid = lo + (hi-lo)/2;
    mergeSort(arr, lo, mid, invCnt);
    mergeSort(arr, mid+1, hi, invCnt);
    merge(arr, lo, mid, hi, invCnt);

}
int main(){
    NFS;

    int t;
    cin>>t;
    while(t--){
        int n, item;
        ll invCnt=0;
        cin>>n;
        //int arr[n];
        vi arr;
        rep(i,n){
            cin>>item;
            arr.pb(item);
        }
        //cin>>arr[i];

        mergeSort(arr, 0, n-1, invCnt);
        //print(arr);
        co<<invCnt;nl;
           
    }

    return 0;
}
