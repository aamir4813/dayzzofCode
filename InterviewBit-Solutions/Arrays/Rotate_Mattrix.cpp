void Solution::rotate(vector<vector<int> > &A) {
 
    int n = A.size();
    
    for(int i = 0 ; i < n ; ++i){
        for(int j = i+1 ; j < n ; ++j){
            swap(A[i][j] , A[j][i]);
        }
    }
   
    
    for(int i = 0 ; i < n/2 ; ++i){
        for(int j = 0 ; j < n ; ++j){
            swap(A[j][i] , A[j][n-i-1]);
        }
    }
    // for(auto x : A){
    //     for(auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    
}
