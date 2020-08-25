#define ll long long int
vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans;
    
    ll n = A.size();
    ll i = 0 , index = -1 , mx_sum = 0 , temp_sum = 0 , cnt = 0;

    ll mx_len = 0 ;    
    while(i < n){
        if(A[i] < 0 ){
            if(mx_sum < temp_sum){
                mx_sum = temp_sum;
                index = i - cnt ;
                mx_len = cnt-1;
            }
            else if(mx_sum == temp_sum){
                if(cnt > mx_len){
                    index = i - cnt;
                    mx_len = cnt-1;
                }
            }
            temp_sum = 0;
            cnt = 0;
            //  cout << mx_sum << " " << temp_sum << endl;
        }
        else{
            temp_sum += A[i];
            cnt++;
        }
        ++i;
    }
    if(mx_sum < temp_sum){
        mx_sum = temp_sum;
        index = i - cnt ;
        mx_len = cnt-1;
    }
    else if(mx_sum == temp_sum){
        if(cnt > mx_len){
            index = i - cnt;
            mx_len = cnt-1;
        }
    }
    
        // cout << mx_len << " " << index << endl;
    if(index == -1)
        return ans;
        
    for(int i = index ; i <= index+mx_len ; ++i)
        ans.push_back(A[i]);
        
    return ans;
}
