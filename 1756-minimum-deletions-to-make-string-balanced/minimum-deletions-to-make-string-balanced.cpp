class Solution {
public:
    int minimumDeletions(string s) {
         int count_a = 0, count_b = 0;
        for(auto i: s) i=='a' ? count_a++ : count_b++;
        int curr_a = 0, curr_b = 0;
        int del = INT_MAX;
        for(auto i: s){
            del = min(del,(count_a-curr_a)+(curr_b));
            i=='a' ? curr_a++ : curr_b++;
        }
        return min(del,(curr_b));
    }
};