vector<int> Solution::plusOne(vector<int> &A) {
    
    vector<int> ans ;
    
    int n = A.size();
    int carry = 1 ;
    for(int i = n-1 ; i >= 0 ; --i ){
        
        int dig = A[i] + carry;
        
        carry = dig / 10;
        
        ans.push_back(dig%10);
    }
    
    if(carry)
        ans.push_back(carry);
    int count  = 0 ;
    reverse(ans.begin() , ans.end());

    vector<int> finalAns ;
    int i = 0;
    for(; i < ans.size() ; ++i){
        if(ans[i] == 0)
            count++;
        else{
            break;
        }
    }
    
    for( ; i <ans.size() ; ++i ){
        finalAns.push_back(ans[i]);
    }
    return finalAns;
        
}
