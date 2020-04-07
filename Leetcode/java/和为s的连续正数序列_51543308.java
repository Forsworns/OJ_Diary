// 不需要真的维护一个队列，因为我们存入队列的都是顺序的数字，所以只需要记录头部就行了
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<List<Integer>> l = new ArrayList<>();
        int sum = 0;
        int q_head = 1;
        for(int i=1;i<=target/2+1;++i){
            sum+=i;
            while(sum>target){
                sum-=q_head;
                q_head++;
            } 
            if (sum==target && i-q_head>0){ // i-q_head is the size of queue
                List<Integer> temp = new ArrayList<>();
                for(int x=q_head;x<=i;x++){
                    temp.add(x);
                }
                l.add(temp);
            }
        }
        if(l.size()==0){
            return new int[0][0];
        }else{
            int[][] ans = new int[l.size()][];
            for(int i=0;i<l.size();++i){
                List<Integer> temp = l.get(i);
                ans[i] = new int[temp.size()];
                for(int j=0;j<temp.size();++j){
                    ans[i][j] = temp.get(j);
                }
            }
            return ans;
        }
    }
}