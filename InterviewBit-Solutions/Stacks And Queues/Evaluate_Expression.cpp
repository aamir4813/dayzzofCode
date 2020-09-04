bool isdig(string& a){
    if(a.size() > 1)
        return 1;
    
    if(a == "*" or a == "-" or a == "/"  or a == "+" )
        return false;
        
    return 1;
}

int Solution::evalRPN(vector<string> &A) {
    
    int n = A.size();
    
    stack<int> s;
    
    for(auto x : A){
        if(isdig(x)){
            s.push(stoi(x));
        }
        else{
            
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            int res ;
            if(x == "*"){
                res = a*b;
            }
            else if( x == "-"){
                res = b-a;
            }
            else if( x == "+"){
                res = a+b;
            }
            else if(x == "/"){
                res = b/a;
            }
            
            s.push(res);
        }
    }
    
    return s.top();
}
