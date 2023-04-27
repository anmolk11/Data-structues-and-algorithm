#include <iostream>
using namespace std;

// Trie node
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;
    // Initialize your data structure here.
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

// Inserts a word into the trie.
void insert(TrieNode *root, string word)
{
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (!p->children[index])
            p->children[index] = new TrieNode();
        p = p->children[index];
    }
    p->isEndOfWord = true;
}

// Returns if the word is in the trie.
bool search(TrieNode *root, string word)
{
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (!p->children[index])
            return false;
        p = p->children[index];
    }
    return p->isEndOfWord;
}

int main()
{
    // sample code to demonstrate trie
    TrieNode *root = new TrieNode();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "worlds");

    cout << search(root, "hello") << endl;
    cout << search(root, "world") << endl;
    cout << search(root, "worlds") << endl;
    cout << search(root, "bye") << endl;

    return 0;
}
