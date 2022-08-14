class Trie {
    Trie * child[26];
    bool isend;
    
public:
    Trie() {
    isend=false;
        for(int i=0; i<26; i++) child[i]=NULL;
    }
    
    void insert(string word) {
        int ind, n=word.length();
        Trie* curr=this;
        // child[ind]=
        for(int i=0; i<n; i++)
        {
            ind=word[i]-'a';
            if(curr->child[ind]==NULL)
            {
                Trie* nw=new Trie();
                curr->child[ind]=nw;
                curr=nw;
            }
            else
                curr=curr->child[ind];
            if(i==n-1) curr->isend=true;
        }
        
    }
    
    bool search(string word) {
        int ind, n=word.length();
        Trie* curr=this;
        // child[ind]=
        for(int i=0; i<n; i++)
        {
            ind=word[i]-'a';
            if(curr->child[ind]==NULL)
                return false;
            else
                curr=curr->child[ind];
            if(i==n-1 and curr->isend==true) return true;
        }
        return false;
    }
    
    bool startsWith(string word) {
        int ind, n=word.length();
        Trie* curr=this;
        // child[ind]=
        for(int i=0; i<n; i++)
        {
            ind=word[i]-'a';
            if(curr->child[ind]==NULL)
                return false;
            else
                curr=curr->child[ind];
            if(i==n-1) return true;
        }
        return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */