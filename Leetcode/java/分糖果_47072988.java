class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> s = new HashSet<>();
        for(int x:candies){
            s.add(x);
        }
        return s.size()>candies.length/2?candies.length/2:s.size();
    }
}