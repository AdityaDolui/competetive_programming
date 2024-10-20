//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n=str.size();
        if(str[n-1]=='0')return str;
        
        int val=str[n-1]-'0';
        int carry=0;
        if(val<6)str[n-1]='0';
        else {
            str[n-1]='0';
            carry=1;
        }
        n-=2;
        while(n>=0 && carry){
            val=str[n]-'0';
            val++;
            carry--;
            if(val==10){
                str[n]='0';
                carry++;
            }else{
                str[n]=val+'0';
            }
            n--;
        }
        if(carry)str='1'+str;
        return str;
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends