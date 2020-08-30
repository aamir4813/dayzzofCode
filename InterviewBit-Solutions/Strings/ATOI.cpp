int Solution::atoi(const string A) {
    
    int n = A.size();
    bool isPostive = false , isNegative = false; 
    
    int i = 0;
    if(A[0] == '+'){
        isPostive = true;
        ++i;
    }
    else if(A[0] == '-'){
        isNegative = true;
        ++i;
    }
    

    string ans = "";
    bool outofrange = false;
    long number = 0;
    bool first = false;
    for( ; i < n ; ++i){
        if(!isdigit(A[i]) and !first)
            return 0;
        else if(isdigit(A[i])){
            first= true;
            // ans += A[i];
            number = number*10 + (A[i] - '0');
            
            if(number > INT_MAX){
                outofrange = true;
                break;
            }
        }
        else
            break;
    }
    // cout << number << endl;
    
    if(outofrange){
        if(isNegative)
            return INT_MIN;
        
        return INT_MAX;
    }
    
    if(isNegative){
        return -1*number;
    }
    
    return number;
}
