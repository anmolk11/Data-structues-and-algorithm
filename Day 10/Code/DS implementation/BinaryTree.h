// Binary Tree - (NOT BST) Implementation
// I have considered the value of all nodes in Tree are Unique
// Otherwise it would make search and delete function
// difficult to implement, since then user would have to 
// enter the TreeNode Pointer to node that he/she wants to search and delete
// Sample Input :- 1 2 3 4 5 6 7 8 9 null 10 11 12 13 14 16
#ifndef BIN_TREE
#define BIN_TREE

#ifndef _IOSTREAM_H
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#endif


template<typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(const T val, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr) 
        : 
        val{val}, left{left}, right{right}{}
};

template<typename T> 
class BinaryTree {
    public:
        // Constructors/Destructors
        BinaryTree() : root{nullptr},length{0} {}
        ~BinaryTree() {

        }
        
        // Main Methods        
        // Since it is a binary tree we make tree initially and then perform different opertions on it
        bool make_tree(string);

        // iterative search
        bool search_itr(const T&) const;
        // recursive search
        bool search_rec(TreeNode<T>*,const T&) const;

        // iterative minimum
        T minimum() const;
        // recursive minimum
        T minimum(TreeNode<T>*) const;

        // iterative maximum
        T maximum() const;
        // recursive maximum
        T maximum(TreeNode<T>*) const;

        // iterative height
        const size_t getHeight() const;
        // recursive height
        const size_t getHeight(TreeNode<T>*) const;

        // iterative bfs
        vector<T> bfs() const;
        // recursice bfs
        void bfsRecHelper(queue<TreeNode<T>*>&,vector<T>&) const;
        void bfs(TreeNode<T>*,vector<T>&) const;

        // DFS - iterative preorder
        void pre_itr() const;
        // DFS - recursive preorder
        void pre_rec(TreeNode<T>*) const;
    
        // DFS - iterative inorder
        void in_itr() const;
        // DFS - recursive inorder
        void in_rec(TreeNode<T>*) const;

        // DFS - iterative postorder
        void post_itr() const;
        // DFS - recursive postorder
        void post_rec(TreeNode<T>*) const;

        // Delete Node
        T deleteNode(const T&);

        // finding inorder successor 
        T inorderSucc(T);

        // getter for root
        TreeNode<T>* getRoot() const {return root;}

        // getter for size of tree
        size_t size() const {return length;}
    private:
        TreeNode<T>* root;
        size_t length;
};

template<typename T>
bool BinaryTree<T>::make_tree(string ref_str) {
    istringstream ss(ref_str);
    string token;
    vector<string> allTokens;
    while(ss >> token) { allTokens.push_back(token); }
    
    int i = 0;
    queue<TreeNode<T>*> q;
    root = new TreeNode<T>(stoi(allTokens[i]));
    q.push(root);
    while(!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();
        if(i*2+1 < allTokens.size() && allTokens[i*2+1] != "null") {
            TreeNode<T>* left = new TreeNode<T>(stoi(allTokens[i*2+1]));
            curr->left = left;
            q.push(left);
            length++;
        }
        if(i*2+2 < allTokens.size() && allTokens[i*2+2] != "null") {
            TreeNode<T>* right = new TreeNode<T>(stoi(allTokens[i*2+2]));
            curr->right = right;
            q.push(right);
            length++;
        }
        i++;
    }
    return true;
} 

template<typename T>
bool BinaryTree<T>::search_itr(const T& val) const {
    if(root == nullptr)
        throw runtime_error("Tree is empty");
    TreeNode<T>* curr = root;
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();
        if(curr->val == val)
            return true;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return false;
}

template<typename T>
bool BinaryTree<T>::search_rec(TreeNode<T>* root,const T& val) const {
    if(root == nullptr)
        return false;
    if(root->val == val)
        return true;
    return (search_rec(root->left,val) || search_rec(root->right,val));
}

template<typename T>
T BinaryTree<T>::minimum() const {
    if(root == nullptr)
        throw runtime_error("Tree is empty");
    queue<TreeNode<T>*> q;
    q.push(root);
    T result = root->val;
    while(!q.empty()) {
        TreeNode<T>* curr = q.front();
        result = min(result,curr->val);
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return result;
}

template<typename T>
T BinaryTree<T>::minimum(TreeNode<T>* root) const {
    if(root == nullptr)
        return INT32_MAX;
    return min(root->val,min(minimum(root->left),minimum(root->right)));
}

template<typename T>
T BinaryTree<T>::maximum() const {
    if(root == nullptr)
        throw runtime_error("Tree is empty");
    queue<TreeNode<T>*> q;
    q.push(root);
    T result = root->val;
    while(!q.empty()) {
        TreeNode<T>* curr = q.front();
        result = max(result,curr->val);
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return result;
}

template<typename T>
T BinaryTree<T>::maximum(TreeNode<T>* root) const {
    if(root == nullptr)
        return INT32_MIN;
    return max(root->val,max(maximum(root->left),maximum(root->right)));
}

template<typename T>
const size_t BinaryTree<T>::getHeight() const {
    if(root == nullptr)
        return -1;
    queue<TreeNode<T>*> q;
    q.push(root);
    int height{-1};
    while(!q.empty()) {
        height++;
        size_t n = q.size();
        while(n--) {
            TreeNode<T>* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return height;
}

template<typename T>
const size_t BinaryTree<T>::getHeight(TreeNode<T>* root) const {
    if(root == nullptr || (!root->left && !root->right))
        return 0;
    return max(getHeight(root->left),getHeight(root->right)) + 1;
}

template<typename T>
vector<T> BinaryTree<T>::bfs() const {
    vector<T> v;
    if(root == nullptr)
        return v;

    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        size_t n = q.size();
        while(n--) {
            TreeNode<T>* curr = q.front();
            v.push_back(curr->val);
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return v;
}

template<typename T>
void BinaryTree<T>::bfsRecHelper(queue<TreeNode<T>*>& q, vector<T>& v) const {
    if(q.empty())
        return;
    size_t n = q.size();
    for(int i = 0; i < n; i++) {
        TreeNode<T>* curr = q.front();
        v.push_back(curr->val);
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    bfsRecHelper(q,v);
}   
template<typename T>
void BinaryTree<T>::bfs(TreeNode<T>* root, vector<T>& v) const {
    if(root == nullptr)
        return;
    queue<TreeNode<T>*> q;
    q.push(root);
    bfsRecHelper(q,v);
}

template<typename T>
void BinaryTree<T>::pre_itr() const {
    if(root == nullptr)
        return;
    stack<TreeNode<T>*> st;
    TreeNode<T>* curr = root;
    while(!st.empty() || curr != nullptr) {
        while(curr) {
            cout << curr->val << " ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top()->right;
        st.pop();
    }
}

template<typename T>
void BinaryTree<T>::pre_rec(TreeNode<T>* root) const{
    if(root == nullptr)
        return;
    // cout << "-----------------------" << endl;
    // cout << "root : " << root->val << " " << endl;
    // if(root->left)
    //     cout << "left : " << root->left->val << endl;
    // else
    //     cout << "left : " << "nullptr" << endl;
    // if(root->right)
    //     cout << "right : " << root->right->val << endl;
    // else
    //     cout << "right : " << "nullptr" << endl;
    cout << root->val << " ";
    pre_rec(root->left);
    pre_rec(root->right);
}

template<typename T>
void BinaryTree<T>::in_itr() const {
    if(root == nullptr)
        return;
    stack<TreeNode<T>*> st;
    TreeNode<T>* curr = root;
    while(!st.empty() || curr != nullptr) {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

template<typename T>
void BinaryTree<T>::in_rec(TreeNode<T>* root) const{
    if(root == nullptr)
        return;
    in_rec(root->left);
    cout << root->val << " ";
    in_rec(root->right);
}

template<typename T>
void BinaryTree<T>::post_itr() const {
    if(root == nullptr)
        return;
    stack<TreeNode<T>*> st,out;
    st.push(root);
    while(!st.empty()) {
        TreeNode<T>* curr = st.top();
        st.pop();
        out.push(curr);
        if(curr->left)  st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
    while(!out.empty()) {
        cout << out.top()->val << " ";
        out.pop();
    }
    cout << endl;
}

template<typename T>
void BinaryTree<T>::post_rec(TreeNode<T>* root) const{
    if(root == nullptr)
        return;
    post_rec(root->left);
    post_rec(root->right);
    cout << root->val << " ";
}

template<typename T>
T BinaryTree<T>::deleteNode(const T& val) {
    queue<pair<TreeNode<T>*,TreeNode<T>*>> q;
    q.push({root,nullptr});
    TreeNode<T>* node = nullptr;
    TreeNode<T>* nodeParent = nullptr;
    TreeNode<T>* rightMostNode = nullptr;
    while(!q.empty()) {
        pair<TreeNode<T>*,TreeNode<T>*> curr = q.front();
        q.pop();
        if(curr.first->val == val) {
            node = curr.first;
            nodeParent = curr.second;
        }
        if(curr.first->left) q.push({curr.first->left,curr.first});
        if(curr.first->right) q.push({curr.first->right,curr.first});
        rightMostNode = curr.first;
    }

    // node not found int the tree
    if(node == nullptr)
        throw runtime_error("Node not found");

    T returnVal = node->val;

    // Node to delete is root node
    if(nodeParent == nullptr) {
        if(node->left == nullptr && node->right == nullptr){
            root = nullptr;
        }else if(node->left == nullptr) {
            root = node->right;            
        }else if (node->right == nullptr) {
            root = node->left;
        }else if(node->left != nullptr && node->right != nullptr){
            TreeNode<T>* curr = nullptr;
            queue<TreeNode<T>*> q_t;
            q_t.push(root);
            while(!q_t.empty()) {
                curr = q_t.front();
                q_t.pop();
                if(curr->left) {
                    if(curr->left == rightMostNode) {
                        node->val = rightMostNode->val;
                        curr->left = nullptr;
                        delete rightMostNode;
                        break;
                    }else 
                        q_t.push(curr->left);
                }
                if(curr->right) {
                    if(curr->right == rightMostNode) {
                        node->val = rightMostNode->val;
                        curr->right = nullptr;
                        delete rightMostNode;
                        break;
                    }else 
                        q_t.push(curr->right);
                }
            }
        }
    }else {
        // node is left child of its parent
        if(nodeParent->left == node) {
            if(node->left == nullptr && node->right == nullptr){
                // cout << "Left : Case - 1" << endl;
                nodeParent->left = nullptr;
            }else if(node->left == nullptr) {
                // cout << "Left : Case - 2" << endl;
                nodeParent->left = node->right;            
            }else if (node->right == nullptr) {
                // cout << "Left : Case - 3" << endl;
                nodeParent->left = node->left;
            }else if(node->left != nullptr && node->right != nullptr){
                if(rightMostNode == root) {
                    node->val = rightMostNode->val;
                    root = root->left;
                    delete rightMostNode;
                }else {
                    TreeNode<T>* curr = nullptr;
                    queue<TreeNode<T>*> q_t;
                    q_t.push(root);
                    while(!q_t.empty()) {
                        curr = q_t.front();
                        q_t.pop();
                        if(curr->left) {
                            if(curr->left == rightMostNode) {
                                node->val = rightMostNode->val;
                                curr->left = nullptr;
                                delete rightMostNode;
                                break;
                            }else 
                                q_t.push(curr->left);
                        }
                        if(curr->right) {
                            if(curr->right == rightMostNode) {
                                node->val = rightMostNode->val;
                                curr->right = nullptr;
                                delete rightMostNode;
                                break;
                            }else 
                                q_t.push(curr->right);
                        }
                    }
                }
            }
        }
        // node is right child of its parent
        else if (nodeParent->right == node) {
            if(node->left == nullptr && node->right == nullptr){
                nodeParent->right = nullptr;
            }else if(node->left == nullptr) {
                nodeParent->right = node->right;            
            }else if (node->right == nullptr) {
                nodeParent->right = node->left;
            }else if(node->left != nullptr && node->right != nullptr){
                if(rightMostNode == root) {
                    node->val = rightMostNode->val;
                    root = root->left;
                    delete rightMostNode;
                }else {
                    TreeNode<T>* curr = nullptr;
                    queue<TreeNode<T>*> q_t;
                    q_t.push(root);
                    while(!q_t.empty()) {
                        curr = q_t.front();
                        q_t.pop();
                        if(curr->left) {
                            if(curr->left == rightMostNode) {
                                node->val = rightMostNode->val;
                                curr->left = nullptr;
                                delete rightMostNode;
                                break;
                            }else 
                                q_t.push(curr->left);
                        }
                        if(curr->right) {
                            if(curr->right == rightMostNode) {
                                node->val = rightMostNode->val;
                                curr->right = nullptr;
                                delete rightMostNode;
                                break;
                            }else 
                                q_t.push(curr->right);
                        }
                    }
                }                   
            }
        }
    }

    delete node;    
    return returnVal;
}

template<typename T>
T BinaryTree<T>::inorderSucc(T val) {
    if(root == nullptr)
        throw runtime_error("Tree is empty");
    TreeNode<T>* node = nullptr;
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();
        if(curr->val == val) {
            node = curr;
            break;
        }
        if(curr->left)  q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    if(node == nullptr)
        return -1;
    if(node->left == nullptr)
        return node->val;
    node = node->left;
    while(node->right != nullptr) {
        node = node->right;
    }
    return node->val;
}

#endif