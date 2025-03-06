class Solution {
   public String longestPalindrome(String s) {
		  if (s.length()==1)return s;
        int start=0,end=0,maxi=-1;
        String ans="";
        if(s.length()==2 && s.charAt(0)==s.charAt(1))return s;
        int n=s.length();
        boolean [][] dp=new boolean[n+1][n+1];

        for(int g=0;g<n;g++){
          //  dp[i][i]=true;
            for(int i=0, j=g;j<n;i++,j++){
                if(g==0)dp[i][j]=true;
               else if(g==1){
                    dp[i][j]=(s.charAt(i)==s.charAt(j))?true:false;
                }
                else{
                    dp[i][j]=(s.charAt(i)==s.charAt(j)) && (dp[i+1][j-1]==true)?true:false;
                }
                // if((s.charAt(i)==s.charAt(j)) && (i-j<=2 || dp[i+1][j-1]==true)){
                //     dp[i][j]=true;
                //     if(i-j+1>maxi){
                //         start=i;
                //         end=j;
                //         maxi=i-j+1;
                //     }
                // }
                if(dp[i][j]==true && maxi<g){
                    maxi=g;
                    ans=s.substring(i,j+1);
                }
            }
        }
        return ans;
	}
	private boolean isPalindrome(String s){
        for(int left = 0 , right = s.length()-1 ; left < right ; left++, right--){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
        }
		return true;
	}
}