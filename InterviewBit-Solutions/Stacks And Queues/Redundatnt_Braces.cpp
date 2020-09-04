int Solution::braces(string A) {
    
    int n = A.size();
    
    stack<char> s;
    
    // int cnt = 0;
    for(auto x : A){
        
        if(x == ')'){
            int cnt = 0 ;
            
            while(!s.empty() and s.top() != '('){
                cnt++;
                s.pop();
            }
            
            // cout << s.top() << " " << cnt << endl;
            if(cnt <= 1)
                return 1;
            if(!s.empty())
                s.pop();
        }
        else{
            s.push(x);
        }
    }
    
    return 0;;
}
