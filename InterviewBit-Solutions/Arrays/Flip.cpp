vector<int> Solution::flip(string A) {
    int n = A.size();
    
    int l = 0 , r = -1;
    int power = 0;
    
    int ans = 0 ;
    int indexL = -1 , indexR = 0;;
    
    for(int i = 0 ; i < n ; ++i){
        
        r++;
        if(A[i] == '1'){
            power--;
        }
        else{
            power++;
        }
        
        if(power < 0){
            l = i+1;
            r = i;
            power = 0;
        }
        
        if(power > ans){
            indexL = l;
            indexR = r;
            ans = power;
        }
    }
    
    if(indexL == -1)
        return {};
        
    return {indexL+1 , indexR+1};
}
