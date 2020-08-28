string Solution::solve(string A) {
    int n = A.size();
    
    int i = n-1 , j = n-1;
    
    while(j >=0 and A[j] >= A[j+1])    --j;
    
    // cout << j << endl;
    if(j == -1) return "-1";
    
    while(i>= j and A[i] <= A[j]) --i;
    
    swap(A[i] , A[j]);
    
    ++j;
    i = n-1;
    
    while(i > j) swap(A[i--] , A[j++]);
    
    return A;
}
// Actually its mean in more formal way to get next Permutation

