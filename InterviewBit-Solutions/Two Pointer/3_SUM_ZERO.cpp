vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int n = A.size();
    
    set<vector<int>> s;
    
    sort(A.begin() ,  A.end());
    for(int i =  0;  i < n-2 ; ++i){
        
        int j = i+1 , k = n-1;
        
        while(j < k){
            long long sum = 1LL*A[i] + 1LL*A[j] + 1LL*A[k];
            
            if(sum == 0){
                s.insert({A[i] , A[j] , A[k]});
                ++j;
                --k;
            }
            else if( sum < 0){
                ++j;
            }
            else{
                --k;
            }
        }
    }
    
    vector<vector<int>> ans;
    for(auto x : s){
        ans.push_back(x);
    }
    return ans;
}
