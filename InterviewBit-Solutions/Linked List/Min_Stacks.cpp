#define ll
stack<int> s;
int mn =  INT_MIN;
MinStack::MinStack() {
    // public :
    // s.clear();
    while(!s.empty()) s.pop();
}

void MinStack::push(int x) {
    
    if(s.empty()){
        s.push(x);
        mn = x;
    }
    else{
        
        if(x >= mn){
            s.push(x);
        }
        else{
            s.push(2*(1LL*x) - mn);
            mn = x;
        }
    }
}

void MinStack::pop() {
    
    if(s.empty())
        return ;
    
    if(s.top() <= mn){
        mn = 2*(1LL*mn)- s.top();
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()) return -1;
    
    int num = s.top();
    if(num < mn){
        return mn;
    }
    return num;
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
        
    return mn ;
}


