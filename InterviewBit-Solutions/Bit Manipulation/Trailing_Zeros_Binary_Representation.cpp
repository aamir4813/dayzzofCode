int Solution::solve(int A) {
    
    int count =  0;
    
    for(int i = 0 ; i <= 31 ; ++i){
        bool bit = (1<< i) & A;
        
        if(!bit)
            count++;
        else
            break;
    }
    
    return count;
}
