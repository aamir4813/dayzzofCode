vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> ans;
    
    stack<int> s;
    for(auto x : A){
        
        if(s.empty() or s.top() >= x ){
            while(!s.empty() and s.top() >= x){
                s.pop();
            }
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
            s.push(x);
        }
        else{
            ans.push_back(s.top());
            s.push(x);
        }
    }
    
    return ans;
}

