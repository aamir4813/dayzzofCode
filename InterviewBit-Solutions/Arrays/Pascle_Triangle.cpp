vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>> ans;
    if(A == 0)
        return ans;
    ans.push_back({1});
    vector<int> prev ;
    for(int i = 2 ; i <= A ; ++i){
        vector<int> temp;
        temp.push_back(1);
        
        for(int j = 1 ; j < prev.size(); ++j){
            temp.push_back(prev[j] + prev[j-1]);
        }
        temp.push_back(1);
        prev = temp;
        ans.push_back(temp);
        // temp.clear();
    }
    return ans;
}
