#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    char data;
    bool isTerm;
    unordered_map<char,Node*> children;
    Node(char data)
    {
        this->data = data;
        this->isTerm = false;
    }
    void makeTerminal()
    {
        this->isTerm = true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(curr->children.find(ch) != curr->children.end()) //found
            curr = curr->children[ch]; // traversing
            else
            {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        } // at the loop end curr will be at the last character which will be terminal
        curr->makeTerminal();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(curr->children.find(ch) == curr->children.end())
            return false;
            else curr = curr->children[ch];
        }
        return curr->isTerm;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.length();i++)
        {
            char ch = prefix[i];
            if(curr->children.find(ch) == curr->children.end())
            return false;
            else curr = curr->children[ch];
        }
        return true; // no need to check for the terminal
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // return True
    cout<<trie->search("app")<<endl;     // return False
    cout<<trie->startsWith("app")<<endl; // return True
    trie->insert("app");
    cout<<trie->search("app")<<endl;     // return true
    return 0;
}