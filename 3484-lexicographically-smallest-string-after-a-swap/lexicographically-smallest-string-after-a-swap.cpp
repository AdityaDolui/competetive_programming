class Solution {
public:
    string getSmallestString(string s) {
        
        for(int i=0;i<s.length()-1;i++){
            int num1=(int)s[i];
            int num2=(int)s[i+1];
            cout<<num1<<num2;
            if((num1&1 && num2&1) || (num1%2==0 && num2%2==0)){
                cout<<"here";
            if(num1>num2){
                cout<<"yes";
                s[i]=(char)num2;
                s[i+1]=(char)num1;
                return s;
            }
            }
        }
        return s;
    }
};