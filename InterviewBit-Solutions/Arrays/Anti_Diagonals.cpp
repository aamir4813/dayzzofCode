vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    // so it is sqaure
    
    vector<vector<int>> ans;
    
    // colum wise i here
    for(int i = 0 ; i < n ; ++i){
        vector<int> temp;
        int j = i ;
        int row = 0;
        while(row < n and j >= 0){
            temp.push_back(A[row++][j--]);
        }
        ans.push_back(temp);
    }
    
    for(int i = 1 ; i < n ; ++i){
        int row = i ;
        int j = n-1;
        vector<int> temp;
        
        while( row < n and j >= 0){
            temp.push_back(A[row++][j--]);
        }
        ans.push_back(temp);
    }
    
    return ans;
}
