struct MinStack {
    stack: Vec<i32>,
    min: i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        Self{
            stack: Vec::new(),
            min: std::i32::MAX,
        }
    }
    
    fn push(&mut self, x: i32) {
        if self.stack.is_empty() {
            self.min = x;
        } else if x <= self.min  {
            self.stack.push(self.min);
            self.min = x;
        } 
        self.stack.push(x);
    }
    
    fn pop(&mut self) {
        if let Some(v) = self.stack.pop(){
            if v == self.min {
                self.min = self.stack.pop().unwrap_or(std::i32::MAX);
            }
        }
    }
    
    fn top(&self) -> i32 {
        if let Some (v) = self.stack.last() {
            *v
        } else {
            std::i32::MAX
        }
    }
    
    fn get_min(&self) -> i32 {
        self.min
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(x);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */