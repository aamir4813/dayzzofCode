vector<int> Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> ans;
    
    auto it = lower_bound(A.begin() , A.end() , 0);
    
    int index = it - A.begin();
    
    // cout << index << endl;
    
    int i = index-1 , j = index;
    
    // ans.push_back(A[index] * A[index]);
    while( i >= 0 and j < n){
        
        if(abs(A[i]) == A[j]){
            int val = A[j] * A[j] ;
            ans.push_back(val);
            ans.push_back(val);
            --i;
            ++j;
        }
        else if(abs(A[i]) > A[j]){
            ans.push_back(A[j]*A[j]);
            ++j;
        }
        else if(abs(A[i]) < A[j]){
            ans.push_back(A[i]*A[i]);
            --i;
        }
    }
    
    while(i >= 0 ){
        ans.push_back(A[i] * A[i]);
        --i;
    }
    while(j < n){
        ans.push_back(A[j] * A[j]);
        ++j;
    }
    
    return ans;
}
