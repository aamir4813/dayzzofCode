int Solution::solve(string A) {
    
    stack<char> s;
    
    int ans = 0 ;
    for(auto x : A){
        
        if(x == ')'){
            if(s.empty()){
                ans++;
            }
            else{
                s.pop();
            }
        }
        else{
            s.push(x);
        }
    }
    
    return (ans + s.size());
  
}
