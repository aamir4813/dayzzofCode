int Solution::isValid(string A) {
    
    stack<char> s;
    for(auto x : A){
        
        if(x == '{' or x == '(' or x == '['){
            s.push(x);
        }
        else{
            if(s.empty())
                return 0;
            
            char ch = s.top();
            s.pop();
            if(ch =='{' and x == '}'){
                continue;
            }
            else if(ch == '(' and x == ')'){
                continue;
            }
            else if(ch == '[' and x == ']'){
                continue;
            }
            else
                return false;
        }
        
    }
    
    if(s.size())
        return 0;
        
    return 1;
}

