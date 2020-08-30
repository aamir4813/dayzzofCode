#define ll long long int
const ll mod = 10000003;


ll isValid(vector<int>&arr , int painter  , int target){
    int n = arr.size();
    
    ll curr = 0 ;
    for(int i = 0 ; i < n ; ++i){
        curr += arr[i];
        if(arr[i] > target)
            return 0;
        if(target < curr){
            curr = arr[i];
            painter--;
        }
        
        if(painter <= 0)
            return 0;
    }
    
    return 1;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    
    ll mx = *max_element(C.begin() , C.end());
    if(A >= n)
        return (mx * B)%mod;
        
    ll high = 0 ;
    for(auto x : C)
        high += x;
    ll low = 1;
    
    ll ans = 0;
    while(low <= high){
        ll mid = (low + (high - low)/2);
        // cout << low << " " << mid << " " << high << " - " << isValid(C , A , mid) << endl;
        if(isValid(C , A , mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return (ans * B*1LL) % mod;
}
