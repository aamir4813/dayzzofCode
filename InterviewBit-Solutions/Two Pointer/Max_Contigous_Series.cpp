vector<int> Solution::maxone(vector<int> &A, int B) {
    
     int n=A.size();
    int ans=INT_MIN;
    int count=0,l=0;
    int k,index;
    for(int i=0;i<n;i++){
        if(A[i]==0) count++;
        
        while(count>B){
            if(A[l]==0) 
                count--;
                l++;
        }
        if(ans<i-l+1){
            ans=i-l+1;
            k=i;
            index=l;
        }

    }
    // cout<<k<<" "<<p;
    vector<int> vec;
    for(int i=index;i<=k;i++) 
        vec.push_back(i);
    return vec;
}
