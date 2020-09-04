int Solution::solve(string A) {
    
    stack<char> s;
    
    for(auto x : A){
        
        if(x == ')'){
            if(s.size() == 0)
                return 0;
            
            if(s.top() != '(')
                return 0;
            s.pop();
        }
        else{
            s.push(x);
        }
    }
    if(s.size())
        return 0;
        
    return 1;
}

