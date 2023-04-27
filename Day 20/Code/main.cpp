// Problem : find number of distinct rows in a matrix using trie

#include <iostream>
#include <vector>
using namespace std;

// Trie node
struct TrieNode
{
    TrieNode *children[2];
    bool isEndOfWord;
    // Initialize your data structure here.
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 2; i++)
            children[i] = NULL;
    }
};

// Inserts a matrix row into the trie and returns true if it is a new row
bool insert(TrieNode *root, int row, vector<vector<int>> &matrix)
{
    TrieNode *p = root;
    for (int i = 0; i < matrix[row].size(); i++)
    {
        int index = matrix[row][i];
        if (!p->children[index])
            p->children[index] = new TrieNode();
        p = p->children[index];
    }
    if (p->isEndOfWord)
        return false;
    p->isEndOfWord = true;
    return true;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 1},
                                  {1, 1, 1, 1},
                                  {1, 1, 0, 1},
                                  {1, 1, 1, 1}};

    TrieNode *root = new TrieNode();
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (insert(root, i, matrix))
            count++;
    }
    cout << count << endl;
}