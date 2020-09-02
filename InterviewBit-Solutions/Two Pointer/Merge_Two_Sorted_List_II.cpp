void Solution::merge(vector<int> &A, vector<int> &B) {

        int n = A.size();
        int m = B.size();
        
        int i = 0  , j = 0 ;
        vector<int> arr(A.begin() , A.end());
        A.clear();
        while(i < n and j < m){
            
            if(arr[i] < B[j]) A.push_back(arr[i++]);
            else A.push_back(B[j++]);
        }
        
        while(i < n) A.push_back(arr[i++]);
        while(j < m) A.push_back(B[j++]);
}
