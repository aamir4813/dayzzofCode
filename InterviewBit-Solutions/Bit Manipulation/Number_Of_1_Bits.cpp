int Solution::numSetBits(unsigned int A) {
    
    int count  = 0 ;
    
    for(int i = 31 ; i>=0 ; --i){
        bool val = (1 << i) & A;
        
        if(val)
            count++;
    }
    
    return count;
}
