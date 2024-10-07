class Solution {
public:
    int minLength(string s) {
         stack<char> charStack;
        for (char currentChar : s) {
            if (!charStack.empty() && 
                ((charStack.top() == 'A' && currentChar == 'B') || 
                 (charStack.top() == 'C' && currentChar == 'D'))) {
                charStack.pop(); // Remove the matching pair
            } else {
                charStack.push(currentChar); // Add character to stack
            }
        }
        return charStack.size(); 
    }
};