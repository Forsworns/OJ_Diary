class Solution {
    final char dict[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    public String toHex(int num) {
        if(num==0){return "0";}
        String ans = "";

        Stack<Integer> s = new Stack<>();
        int digit = 0;
        int bitn = 0;
        while(num!=0){
            digit += (num & 1)*Math.pow(2,bitn);
            bitn++;
            if(bitn==4){
                s.push(digit);
                digit = 0;
                bitn = 0;
            }
            num = num>>>1;
        }
        if(digit!=0){
            s.push(digit);
        }

        while(!s.empty()){
            ans+=dict[s.peek()];
            s.pop();
        }
        return ans;
    }
}