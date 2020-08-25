vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A , vector<int>(A , 0));
    
    int val = 1;
    
    int left = 0 , top = 0;
    int right = A-1 , bottom = A-1;
    
    while(left <= right and top <= bottom){
        
        for(int i = left ; i <= right ;++i){
            ans[top][i] = val++;
        }
        
        top++;
        for(int i = top ; i <= bottom ; ++i){
            ans[i][right] = val++;
        }
        
        right--;
        for(int i = right ; i >= left ; --i){
            ans[bottom][i] = val++;
        }
        bottom--;
        
        for(int i = bottom ; i >= top ; --i){
            ans[i][left] = val++;
        }
        left++;
    }
    
    return ans;
}
