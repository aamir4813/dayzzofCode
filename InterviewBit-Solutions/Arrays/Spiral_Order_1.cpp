vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    
    int left = 0 , right = m-1;
    int bottom = n-1 , up = 0;
    
    vector<int> ans ;
    while(left <= right and up <= bottom and left < m and right >=0  and up < n  and bottom >=0){
        
        for(int i = left  ; i <= right ; ++i){
            ans.push_back(A[up][i]);
        }
        ++up;
        
        for(int i = up ; i <= bottom ; ++i){
            ans.push_back(A[i][right]);
        }
        right--;
        // cout << right << " ";
        if(up <= bottom){
            for(int i = right ; i>= left ; --i ){
            ans.push_back(A[bottom][i]);
            }
        --bottom;
        }
        if(left <= right){
            for(int i = bottom ;  i >= up ; --i){
                ans.push_back(A[i][left]);
            }
        ++left;
        }
    }
    
    return ans;
}
