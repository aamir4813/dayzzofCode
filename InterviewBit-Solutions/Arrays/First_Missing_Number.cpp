int Solution::firstMissingPositive(vector<int> &A)
{
     int n = A.size();
     
     
     for(int i = 0 ; i < A.size() ; ++i){
        
        if(A[i]  == 1)
            cout << i << endl;
                
         if(A[i] > 0 and A[i] <= n and A[i] != i+1 ){
             swap(A[i] , A[A[i] - 1]);
         }
     }
     
    //  sort(A.begin() , A.end());
    // for(auto x : A)
    //     cout << x << " ";
    // cout << endl;
     for(int i = 0 ; i < n ; ++i){
         if(A[i] != i+1)
            return i+1;
     }
     
    
     return n+1;
