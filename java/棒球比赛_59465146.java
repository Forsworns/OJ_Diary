class Solution {
    public int calPoints(String[] ops) {
        int ans=0;
        Stack<Integer> s = new Stack<>();
        for(String x:ops){
            switch(x){
                case "C":{
                    int t = s.pop();
                    ans-=t;
                    break;
                }
                case "D":{
                    int t = s.peek()*2;
                    ans+=t;
                    s.push(t);
                    break;
                }
                case "+":{
                    int t = s.pop();
                    int tt = s.peek();
                    ans+=(t+tt);
                    s.push(t);
                    s.push(tt+t);
                    break;
                }
                default:{
                    int t = Integer.valueOf(x);
                    ans+=t;
                    s.push(t);
                    break;
                }
            }
        }
        return ans;
    }
}