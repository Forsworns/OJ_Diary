// 通过移位计数1
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int counter = 0;
        while(z){
            if(z&1 == 1) counter++;
            z = z>>1;
        }
        return counter;
    }
};