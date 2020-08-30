int Solution::isPalindrome(string A) {
    
    string curr = "";
    
    for(auto x : A){
        if(isalpha(x)){
            curr += tolower(x);
        }
        else if(isdigit(x))
            curr += x;
    }
    
    int i = 0 , j = curr.size()-1;
    // cout << curr << endl;
    while( i < j){
        if(curr[i++] != curr[j--]) return 0;
    }
    return 1;
}
