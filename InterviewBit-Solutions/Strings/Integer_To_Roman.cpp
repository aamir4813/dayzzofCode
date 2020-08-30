string Solution::intToRoman(int A) {
    
   string ans="";
    int values[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string roman[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(A){
        
        int divisor = A/values[i];
        
        A = A%values[i];
        
        while(divisor--){
            ans=ans+roman[i];
        }
        
        i--;
    
    }
    return ans;
}
