class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        if(strs.length!=pattern.length()){
            return false;
        }
        Map<Integer,String> dict = new HashMap<>();
        for(int i=0;i<pattern.length();++i){
            int idx = pattern.charAt(i)-'a';
            if(dict.containsKey(idx)){
                if(!dict.get(idx).equals(strs[i])){
                    return false;
                }
            }else{
                dict.put(idx,strs[i]);
            }
        }
        Set<String> set = new HashSet<>();
        for(String s:strs){
            set.add(s);
        }
        if(set.size()!=dict.size()){
            return false;
        }
        return true;
    }
}