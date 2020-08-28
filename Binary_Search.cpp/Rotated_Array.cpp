int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    
    
    if(n == 1)
        return A[0];
   int low=0; int high=n-1; int index=0; 
    while(low<=high)
    {
    int mid = (low+high)/2;
    if(A[mid]<A[index]) 
    {
        index=mid;
        high = mid-1;
    }
    else
        low=mid+1; 
}
    return A[index];
}
