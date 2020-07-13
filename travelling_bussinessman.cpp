/*
Travelling Businessman Flag Question
Problem Description

Anurag left his job as a travelling salesman. He started his own venture "MacroHard" and became a successful businessman.
He is planning a road trip along with his friends. So, he went to a car rental company to rent a car. The Car rental company showed him A cars parked in a row.

Anurag has a superstition that he always buys things as a contiguous subarray.

So, he asked you a question: Considering all ways to rent the cars; for each car, find the number of ways to rent it.



Problem Constraints
1 <= A <= 91000


Input Format
First and the only argument of input is an integer A denoting number of cars.


Output Format
return an integer array of size A where integer at index i represents the number of ways to choose the ith car.


Example Input
Input 1:
A = 4
Input 2:

A = 3


Example Output
Output 1:
[4, 6, 6, 4]
Output 2:

[3, 4, 3]


Example Explanation
Explanation 1:
You can assume any car array. for example A = [Car 1, Car 2, Car 3, Car 4]
subarray that contains 'Car 1' are [1], [1, 2], [1, 2, 3], [1, 2, 3, 4]
subarray that contains 'Car 2' are [1, 2], [1, 2, 3], [1, 2, 3, 4], [2, 3], [2, 3, 4], [2]
*/

vector<int> Solution::solve(int A) {
    
    vector<int> arr(A);
    
    for(int i = 0 ; i < A ; ++i){
        int left = i ;
        
        int right = A - i  ;
        
        arr[i] = left * right + right;
    }
    
    return arr;
}
