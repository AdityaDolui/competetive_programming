class Solution {
    public String finalAns="ADI";
    public int f(int i, int j, String s1, String s2){
        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }
        

        if(s1.charAt(i)==s2.charAt(j)){
            return 1+f(i+1,j+1,s1,s2);
        }
        return Math.max(f(i+1,j,s1,s2),f(i,j+1,s1,s2));


    }
    public String longestPalindrome(String s) {
          StringBuilder T = new StringBuilder();
        T.append("#");
        for (char c : s.toCharArray()) {
            T.append(c).append("#");
        }

        int n = T.length();
        int[] P = new int[n];  // Array to store the lengths of palindromes
        int C = 0, R = 0;  // Current center and right boundary

        for (int i = 1; i < n - 1; i++) {
            // Mirror the current index i with respect to center C
            if (i < R) {
                P[i] = Math.min(R - i, P[2 * C - i]);  // Use symmetry if within the right boundary
            }

            // Expand around center i
            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T.charAt(i + P[i] + 1) == T.charAt(i - P[i] - 1)) {
                P[i]++;
            }

            // Update center and right boundary if we've extended past the current boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum length of palindrome and its center
        int max_len = 0, center_index = 0;
        for (int i = 0; i < n; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                center_index = i;
            }
        }

        // Extract the palindrome from the original string
        int start = (center_index - max_len) / 2;
        return s.substring(start, start + max_len);
    }
}