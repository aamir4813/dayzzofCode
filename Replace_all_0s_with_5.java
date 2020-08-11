// Replace all 0's with 5

class GfG {
    int convertfive(int num) {
        // Your code here
        int ans = 0 ;
        int i = 0;
        while(num > 0){
            int rem = num % 10;
            // int val = n / 10;
            
            if(rem == 0){
                rem = 5;
            }
            
            if(i == 0){
                ans = rem;   
            }
            else{
                ans = rem*(int)(Math.pow(10 , i)) + ans ;
            }
            ++i;
            
            num /= 10;
        }
        
        return ans;
    }
}