class Solution {
    public int longestPalindrome(String s) {
        Map<Character,Integer> map = new HashMap<>();
        boolean odd = false;
        for(int i=0;i<s.length();++i){
            char c = s.charAt(i);
            if(map.containsKey(c)){
                map.put(c,map.get(c)+1);
            }else{
                map.put(c,1);
            }
        }
        int ans=0;
        for(int v : map.values()){
            if(v%2==1){
                if(!odd){
                    odd = true;
                }
                ans+=(v-1);
            }else{
                ans+=v;
            }
        }
        if(odd){
            ans+=1;
        }
        return ans;
    }
}