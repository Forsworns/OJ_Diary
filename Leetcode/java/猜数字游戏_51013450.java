class Solution {
    public String getHint(String secret, String guess) {
        int bull = 0, cow = 0;
        Map<Integer,Integer> sdict = new HashMap<>();
        Map<Integer,Integer> gdict = new HashMap<>();

        for(int i=0;i<secret.length();++i){
            int cs = Integer.valueOf(secret.charAt(i)), cg = Integer.valueOf(guess.charAt(i));
            if(cs==cg){
                bull++;
            }
            if(sdict.containsKey(cs)){
                sdict.put(cs,sdict.get(cs)+1);
            }else{
                sdict.put(cs,1);
            }
            if(gdict.containsKey(cg)){
                gdict.put(cg,gdict.get(cg)+1);
            }else{
                gdict.put(cg,1);
            }
        }

        for(int k:gdict.keySet()){
            if(sdict.containsKey(k)){
                cow+=Math.min(sdict.get(k),gdict.get(k));
            }
        }     

        String ans = String.valueOf(bull);
        ans += 'A';
        ans += String.valueOf(cow-bull);
        ans += 'B';
        return ans;
    }
}