class Solution {
    public int[][] findContinuousSequence(int target) {
        List<Integer> q = new ArrayList<>();
        List<List<Integer>> l = new ArrayList<>();
        int sum = 0;
        for(int i=1;i<=target/2+1;++i){
            q.add(i);
            sum+=i;
            while(sum>target){
                int head = q.remove(0);
                sum-=head;
            } 
            if (sum==target && q.size()>1){
                List<Integer> temp = new ArrayList<>();
                for(int x:q){
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