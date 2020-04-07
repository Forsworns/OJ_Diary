class Solution {
    class Pair implements Comparable<Pair>{
        int idx;
        int score;
        Pair(int i, int s){
            idx = i;
            score = s;
        }

        @Override
	    public int compareTo(Pair p){
            return p.score-score;
        }
    } 

    public String[] findRelativeRanks(int[] nums) {
        String[] ans = new String[nums.length];
        List<Pair> l = new ArrayList<>(nums.length);
        for(int i=0;i<nums.length;++i){
            l.add(new Pair(i,nums[i]));
        }
        Collections.sort(l);
        for(int i=0;i<l.size();++i){
            Pair p = l.get(i);
            if(i>=3){
                ans[p.idx] = String.valueOf(i+1);
            }else{
                switch (i) {
                    case 0: ans[p.idx]="Gold Medal"; break;
                    case 1: ans[p.idx]="Silver Medal"; break;
                    case 2: ans[p.idx]="Bronze Medal"; break;
                }
            }
        }
        return ans;
    }
}