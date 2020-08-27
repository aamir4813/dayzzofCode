bool isPrime(int n ){
    
    for(int i = 2 ; i <= sqrt(n) ; ++i){
        if(n % i == 0)
            return false;
    }
    
    return 1;
}

vector<int> Solution::primesum(int A) {
    
    
    
    for(int i = 2 ; i <= sqrt(A) ; ++i){
        if(isPrime(i) and isPrime(A-i)){
            return {i , A-i};
        }
    }
    
    // return {
}
