/*
This problem is based on bucketing the elements...

Like mapping the values in ranges and find the min and max of corresponding ranges...

when we get the range obviously it's gonna be sorted...
so instead of inserting the whole elements in that range we can manage minimum and maximum of all in that particular range..
so our ans will be lie somewhere......
ans = abs((maximum of i bucket) - (minumum of i+1 bucket))

so can we find max of all these ....?
That's the answer !!!
Really BrainStorming !!!!
*/


int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    int mn = *min_element(A.begin() , A.end());
    int mx = *max_element(A.begin() , A.end());
    
    int bckt_size = ((mx-mn)/(n-1) )+1 ;
    
    vector<pair<int , int>> bucket(n , {INT_MIN , INT_MAX});
    
    for(int i = 0 ;  i < n ; ++i){
        if(A[i] != mn and A[i] != mx){
            int index  = (A[i]-mn) / bckt_size ;
            
            // cout << index <<  " ";
            
            bucket[index].first = max(bucket[index].first , A[i]);
            bucket[index].second = min(bucket[index].second , A[i]);
        }
    }
    
    int ans = 0; 
    int prev = mn ;
    
    for(auto x : bucket){
        if(x.first == INT_MIN and x.second == INT_MAX)
            continue;
        
        ans = max(ans , x.second - prev);
        prev = x.first;
    }
    
    ans = max(ans , mx - prev);
    
    return ans;
}
