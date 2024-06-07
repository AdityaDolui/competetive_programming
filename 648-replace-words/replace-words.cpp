class Node{
    public:
    Node * links[26];
    bool flag=false;
    bool containKey(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
     void setTrue(){
         flag=true;
     }
     bool isTrue(){
         return flag;
     }
};
class Trie{
    private: 
    Node* root;
    public:
    
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node * node=root;
        for(int i=0;i<s.length();i++){
            if(!node->containKey(s[i])) node->put(s[i],new Node());
            node=node->get(s[i]);
        }
        node->setTrue();
    }
    bool search(string s){
         Node * node=root;
         for (int i = 0; i < s.length(); i++) {
              if(!(node->containKey(s[i]))) return 0;
             node=node->get(s[i]);
              
         }
         return node->isTrue();
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie=new Trie();
        vector<string> str;
        string temp="";
        for(int i=0;i<sentence.length();i++){
            if(isspace(sentence[i])){
                str.push_back(temp);
                temp="";
            }
            else temp+=sentence[i];
        }
        str.push_back(temp);
   
        for(auto it :dictionary)trie->insert(it);

        for(int i=0;i<str.size();i++){
            bool flag=false;
            string news="";
            for(int j=0;j<str[i].length();j++){
                news+=str[i][j];
                if(trie->search(news)){
                    str[i]=news;
                    flag=true;
                    break;
                }
                
            }
            
        }
        int x=str.size();
        cout<<str[x-1];
         string ans="";
        for(int i=0;i<str.size();i++){
            ans+=str[i];
            if(i<str.size()-1)ans+=" ";
        }
      
    return ans;
    }
};