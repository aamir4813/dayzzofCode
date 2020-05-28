/*
College starts at eight in the morning! But Yash Jeswani is awake way before he is supposed to be. It's a beautiful day for him until he realizes Yash Agarwal took his shoes and had been away while Jeswani was sleeping. Jeswani is furious with such irresponsible behaviour. Now, what to do then? So he decides to go to "the Bali"'s shop to buy new shoes. Now Bali shows him a N pairs of shoes. But these shoes aren't some normal shoes! These are "the Bali" shoes. The size of left shoe will be always not equal to the size of the right shoe! Being such close friends Bali agrees to gift him a pair of shoes if he answers his question. Bali asks what are the total number of ways to select one shoe from each of the N pairs such that the summation of all the selected shoe sizes is odd? Then do help Jeswani to get free shoes. Since the answer can be too large print it modulo 10^9+7.

Input Format
First line contains N number of pairs N lines follows two space separated integer Li Ri representing shoe sizes

Constraints
1 ≤ N ≤ 10^5

1 ≤ Li,Ri ≤ 10^9

Li ≠ Ri

Output Format
Print number of ways to select one shoe from each of the N pairs such that the summation of the selected shoe sizes is odd. Since the answer can be too large print it modulo 10^9+7.

Sample Input
2
1 2
3 4
Sample Output
2
Explanation
The two ways are {1,4} and {2,3}.
*/


#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
signed main(){
    fast;
    int tt=1;
    // cin>> tt;
    while(tt--){
        int N;  cin>>N;
        int arr[N][2];
        for(int i=0;i<N;i++)    cin>>arr[i][0]>>arr[i][1];
        int dp[N][2]={0};
        
        //dp[i][0] stores the count of all possible even sum combinations up until index i
        //dp[i][1] stores the count of all possible odd sum combinations up until index i    
        
        if(arr[0][0]%2==1)    
        	dp[0][1]++; 
        else 
        	dp[0][0]++;
        if(arr[0][1]%2==1)
            dp[0][1]++;
        else
         	dp[0][0]++;
        
        for(int i=1;i<N;i++){
            for(int j=0;j<2;j++){
                // if the element is even then the dp[i][0] and dp[i][1] are exactly the same as upto index i-1
                if(arr[i][j]%2==0){
                    dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
                    dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;
                }
                // if the element is odd then the counts interchange
                else if(arr[i][j]%2==1){
                    dp[i][0]=(dp[i][0]+dp[i-1][1])%mod;
                    dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;
                }
            }
        }
        cout<<dp[N-1][1]<<endl;
    }
}

/*3
1 2
3 4 
5 6
7 8
        (1 , 2)
        1           2
    (3 , 4)     (3 , 4)
    3     4     3       4
(5 6)   (5 6)   (5 6)   (5 6)
5   6   5   6   5  6    5   6

1 3 5 = 9
1 3 6 = 10
1 4 5 = 10
1 4 6 = 11
2 3 5 = 10
2 3 6 = 11
2 4 5 = 11
2 4 6 = 12
*/