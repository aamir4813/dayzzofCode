void Solution::setZeroes(vector<vector<int> > &A) {

    int n = A.size();
    int m = A[0].size();
    
    bool is_row = false , is_colum = false;
    // so checking any 0 is present in 0th colum
    for(int i = 0 ; i < n ; ++i){
        if(A[i][0] == 0){
            is_colum= true;
            break;
        }
    }
    // here same for 0th row
    for(int i = 0  ;i < m ; ++i){
        if(A[0][i] == 0){
            is_row = true;
            break;
        }
    }
    // we marked these checker just because to use 0th th row and colum as our Map or Set
    // to keep trace of all rows and colum
    for(int i = 1 ; i < n ; ++i){
        for(int j = 1 ;  j < m ; ++j){
            if(A[i][j] == 0)
            // marking the 0th colum for Mapping
                A[0][j] = 0;
        }
    }
    
    for(int i = 1 ; i < m ; ++i){
        for(int j = 1 ; j < n ; ++j){
            if(A[j][i] == 0){
            // here 0th row marking
                A[j][0] =  0;
            }
        }
    }
    // so whatever we marked time to give a shot...so doing same
    for(int i = 1 ; i < n ; ++i){
        if(A[i][0] == 0){
            for(int j = 1 ; j < m ; ++j){
                A[i][j] = 0;
            }
        }
    }
    // same for colum wise also
    for(int i = 1 ; i < m ; ++i){
        
        if(A[0][i] == 0){
            for(int j = 1 ; j < n ; ++j){
                A[j][i] = 0;
            }
        }
    }
    // so here checkers are use to know whether any of colum in 0th row has zero
    if(is_row){
        for(int i = 0 ; i < m ; ++i){
            A[0][i] = 0 ;
        }
    }
    // same for colum i guess...s
    if(is_colum){
        for(int i = 0 ; i < n ; ++i){
            A[i][0] =  0;
        }
    }
    // so here all we are all setup to get AC @aamir4813
}
