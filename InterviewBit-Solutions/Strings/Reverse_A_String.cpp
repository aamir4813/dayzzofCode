string Solution::solve(string A) {
    
    int n = A.size();
    stack<string> arr;
    string ans = "";
    string temp ="";
    for(int i = 0 ; i < n ; ++i ){
        if(isalpha(A[i]))
            temp += A[i];
        else {
            if(temp.size())
                arr.push(temp);
            temp = "";
        }
    }
    if(temp.size())
        arr.push(temp);
    while(!arr.empty()){
        ans += arr.top() ;
        if(arr.size() != 1)
            ans += " ";
        arr.pop();
    }
    
    return ans;
}
