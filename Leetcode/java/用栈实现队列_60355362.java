class MyQueue {
    Stack<Integer> s1,s2;
    int p;
    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(s1.empty()&&s2.empty()){
            s1.push(x);
            p=x;
        }else{
            s1.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        while(s1.size()>1){
            s2.push(s1.pop());
        }
        if(!s2.empty()){
            p = s2.peek();
        }
        int ans = s1.pop();
        while(!s2.empty()){
            s1.push(s2.pop());
        }
        return ans;
    }
    
    /** Get the front element. */
    public int peek() {
        return p;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */