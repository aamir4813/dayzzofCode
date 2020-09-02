vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int m = B.size();
    
    vector<int> ans ;
    int i = 0 , j =  0;
    // int index = 0 ;
    while(i < n and j < m){
        
        if(A[i] == B[j]){
            ans.push_back(A[i]);
            ++i;++j;
        }
        else if(A[i] < B[j]){
            ++i;
        }
        else{
            ++j;
        }
    }
    
    return ans;
}
