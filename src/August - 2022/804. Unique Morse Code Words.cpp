class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        set<string> st;
        for(int i=0; i<words.size(); i++)
        {
            string str = "";
            for(int j=0; j<words[i].size(); j++)
            {
                for(int k=0; k<26; k++)
                {
                    if(words[i][j]==alphabet[k])
                    {
                        str+=code[k];
                    }
                }
            }
            st.insert(str);
        }
        return st.size();
    }
};
