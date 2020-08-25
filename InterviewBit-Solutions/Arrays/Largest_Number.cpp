bool comp(const int &a , const int &b){
    string x = to_string(a);
    string y = to_string(b);

    return (x+y) > (y+x);
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<int> arr(A.begin() , A.end());
    
    sort(arr.begin() , arr.end() , comp);
    
    string ans = "";
    bool zero_only = true;
    for(auto x : arr){
        if(x != 0){
            zero_only = false;
        }
        ans += to_string(x);
    }
    
    if(zero_only)
        return "0";
    return ans;
}
