int Solution::perfectPeak(vector<int> &A) {
    int n=A.size();
    int right[n] , left[n];
    left[0]=A[0];
    int i;
    for( i=1;i<n;i++){
        left[i]=max(left[i-1],A[i]);
    }
    right[n-1]=A[n-1];
    for(i=n-2;i>=0;i–){
        right[i]=min(A[i],right[i+1]);
    }
    for(i=1;i<n-1;i++){
        if(A[i]>left[i-1] && A[i]<right[i+1])
            return 1;
    }
    return 0
}
