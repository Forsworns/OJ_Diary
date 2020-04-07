class Solution {
    public String[] findWords(String[] words) {
        Map<Character,Integer> m = new HashMap<>();
        m.put('q',1);
        m.put('w',1);
        m.put('e',1);
        m.put('r',1);
        m.put('t',1);
        m.put('y',1);
        m.put('u',1);
        m.put('i',1);
        m.put('o',1);
        m.put('p',1);

        m.put('a',2);
        m.put('s',2);
        m.put('d',2);
        m.put('f',2);
        m.put('g',2);
        m.put('h',2);
        m.put('j',2);
        m.put('k',2);
        m.put('l',2);

        m.put('z',3);
        m.put('x',3);
        m.put('c',3);
        m.put('v',3);
        m.put('b',3);
        m.put('n',3);
        m.put('m',3);


        List<String> l = new ArrayList<>();
        for(String s:words){
            int row = m.get(Character.toLowerCase(s.charAt(0)));
            boolean the_same = true;
            for(char c:s.toCharArray()){
                if(row!=m.get(Character.toLowerCase(c))){
                    the_same=false;
                    break;
                }
            }
            if(the_same){
                l.add(s);
            }
        }
        String[] ans = new String[l.size()];
        for(int i=0;i<l.size();++i){
            ans[i] = l.get(i);
        }
        return ans;    
    }
}