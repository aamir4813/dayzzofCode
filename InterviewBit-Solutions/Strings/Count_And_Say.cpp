string Solution::countAndSay(int A) {
    
    
    string ans = "";
    if(A == 0)
        return ans;
    
    string num = "1";
    if(A == 1)
        return num;
    for(int i = 2 ; i <= A; ++i){
        // 1211
        ans = "";
        for(int j = 0 ; j < num.size(); ++j){
            
            int k = 1;
            while(j+1 < num.size() && num[j] == num[j+1]){
                k++;
                ++j;
            }
            ans += to_string(k) + num[j];
        }
        // cout <<ans << " ";
        num = ans;
    }
    
    return ans;
}
