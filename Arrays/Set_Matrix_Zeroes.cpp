void setZeroes(vector<vector<int>>& a) {
        int i, j, r= a.size(), c=a[0].size();
        bool col=1;
            for(i=0; i<r; i++){
                if(a[i][0]==0){
                    col=0;
                }
                for(j=1; j<c; j++){
                    if(a[i][j]==0){
                        a[i][0] = a[0][j]=0;
                    }
                }
            }
            for(i=r-1; i>=0; i--){
                for(j=c-1; j>=1; j--){
                    if(a[0][j]==0 || a[i][0]==0){
                        a[i][j]=0;
                    }
                }
                if(col==0){
                a[i][0]=0;
            }
        }
    }
