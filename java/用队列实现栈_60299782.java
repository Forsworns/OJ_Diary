class MyStack {
    Queue<Integer> q1,q2; //remove,peek,add,isEmpty()
    int t;
    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(q1.isEmpty()){
            q2.add(x);
        }else{
            q1.add(x);
        }
        t = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(q1.isEmpty()){
            while(q2.size()>1){
                q1.add(q2.peek());
                t = q2.remove();
            }
            return q2.remove();
        }else{
            while(q1.size()>1){
                q2.add(q1.peek());
                t = q1.remove();
            }
            return q1.remove();
        }
    }
    
    /** Get the top element. */
    public int top() {
        return t;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty()&&q2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */