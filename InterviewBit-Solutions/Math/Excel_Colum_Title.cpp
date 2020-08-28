string Solution::convertToTitle(int A) {
    
    string ans = "";
    
    while(A){
        int num = A%26;
        if(num == 0){
            ans = 'Z' + ans;
            A -= 26;
        }
        else{
            ans = char(64+num) + ans;
        }
        A /= 26;
        // cout << num << " " << A << endl;;
        
    }
    
    return ans;
    
}
