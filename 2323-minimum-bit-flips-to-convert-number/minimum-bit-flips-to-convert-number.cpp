class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32>a(start);
        bitset<32>b(goal);

        string a1=a.to_string();
        string b1=b.to_string();

        int ans=0; 
        for(int i=0;i<a1.size();i++){
            if(a1[i]!=b1[i])ans++;
        }
        return ans;
    }
};