class Solution {
public:
     unordered_map<string, vector<int>> memo;  // Memoization map to store results of sub-expressions

    // This function will break the expression at each operator and solve the parts separately
    vector<int> computeWays(string exp) {
        // If this sub-expression has already been computed, return the result from memo
        if (memo.find(exp) != memo.end()) {
            return memo[exp];
        }

        vector<int> result;

        // Loop through each character in the expression
        for (int i = 0; i < exp.size(); ++i) {
            char ch = exp[i];

            // If the character is an operator, we split the expression around it
            if (ch == '+' || ch == '-' || ch == '*') {
                // Solve the left part of the expression (before the operator)
                vector<int> left = computeWays(exp.substr(0, i));

                // Solve the right part of the expression (after the operator)
                vector<int> right = computeWays(exp.substr(i + 1));

                // Combine the results from the left and right parts using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);
                        } 
                        else if (ch == '-') {
                            result.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operator is found, it means the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(exp));  // Convert the string to an integer and add to result
        }

        // Store the computed result in memo for future use
        return memo[exp] = result;
        // return memo[exp];
        // return result;
    }

public:
    // This is the main function that will be called to get all possible results
    vector<int> diffWaysToCompute(string exp) {
        return computeWays(exp);  // Call recursion with memoization
    }
};