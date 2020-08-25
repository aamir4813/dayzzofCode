vector<int> Solution::getRow(int A) {
    vector<int> ans ;
    if(A == 0)
        return {1};
    ans.push_back(1);
    ans.push_back(1);
    for(int i = 2 ; i <= A ; ++i){
        vector<int> temp;
        temp.push_back(1);
        
        for(int j =1 ; j < ans.size() ; ++j){
            temp.push_back(ans[j] + ans[j-1]);
        }
        temp.push_back(1);
        ans = temp;
    }
    return ans;
}
