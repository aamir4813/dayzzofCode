string Solution::reverseString(string A) {
    stack<char> s;
    
    for(auto x : A)
        s.push(x);
    
    A.clear();
    
    while(!s.empty())
        A += s.top() , s.pop();
        
    return A;
}

