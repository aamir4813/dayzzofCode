#define ll long long int
 
int isBase(ll base , ll len , ll target ){
    
    ll sum = 0;;
    for(int i = 0 ; i < len  ; ++i ){
       sum = sum * base + 1 ;
       if(sum > target){
           return 2;
       }
    }
    if(sum < target)
        return 0;
    
    return 1;
}
 
string Solution::solve(string A) {
    
    ll num = stoll(A);
    
    ll ans = num-1;
    ll mx_len = log2(num)+1;
    
    for(int i = mx_len ; i >= 2 ; --i){
        ll s = 2 , e = num - 1;
        
        while(s <= e){
            ll mid = s + (e-s) / 2 ;
            
            int gotSecret = isBase(mid , i , num);
            if(gotSecret == 1){
                return to_string(mid);
                
            // cout << "yes :" << mid << " ";
                // e = mid-1;
                // ans = mid;
            }
            else if(gotSecret == 2){
                // s = mid+1;
                e = mid -1;
            }
            else{
                s = mid+1;
            }
        }
    
    }
}