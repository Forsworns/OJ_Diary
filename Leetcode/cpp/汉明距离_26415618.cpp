// 用x&(x-1)统计x中1的个数，x|(x+1)统计x中0的个数
class Solution {
private:
    int myxor(const int &x, const int &y) noexcept{
        return (x&~y) | (~x&y);
    } // 忘了^是异或了……
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int counter = 0;
        while(z){
            counter++;
            z = z&(z-1);// 每次会把z最低位的1变成0
        }
        return counter;
    }
};