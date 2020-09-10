int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int i = 0 ;
    int j = n-1;
    int ans = 0 ;
    int mx1 = A[0] , mx2 = A[n-1];
    while(i <= j){
        if(A[i] < A[j]){
            if(A[i] > mx1) mx1 = A[i];
            else ans += (mx1 - A[i]);
            ++i;
        }
        else{
            if(A[j] > mx2) mx2 = A[j];
            else ans += (mx2 - A[j]);
            --j;
        }
    }
    return ans;
}
