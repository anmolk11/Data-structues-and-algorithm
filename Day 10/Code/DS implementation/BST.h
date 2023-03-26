#ifndef BIN_SEARCH_TREE
#define BIN_SEARCH_TREE

#ifndef _IOSTREAM_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#endif

template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(const T val, TreeNode<T> *left = nullptr, TreeNode<T> *right = nullptr)
        : val{val}, left{left}, right{right}
        {}
};

template <typename T>
class BST
{
public:
    // Constructors/Destructors
    BST() : root{nullptr}, length{0} {}
    ~BST() {}

    // Main Methods

    // iterative insert
    bool insert_itr(const T &);
    // recursice insert
    bool insert_rec(const T &, TreeNode<T> *);

    // iterative search
    bool search_itr(const T &) const;
    // recursive search
    bool search_rec(TreeNode<T> *, const T &) const;

    // iterative minimum
    T minimum() const;
    // recursive minimum
    T minimum(TreeNode<T> *) const;

    // iterative maximum
    T maximum() const;
    // recursive maximum
    T maximum(TreeNode<T> *) const;

    // iterative height
    const size_t getHeight() const;
    // recursive height
    const size_t getHeight(TreeNode<T> *) const;

    // iterative bfs
    vector<T> bfs() const;
    // recursice bfs
    void bfsRecHelper(queue<TreeNode<T> *> &, vector<T> &) const;
    void bfs(TreeNode<T> *, vector<T> &) const;

    // DFS - iterative preorder
    void pre_itr() const;
    // DFS - recursive preorder
    void pre_rec(TreeNode<T> *) const;

    // DFS - iterative inorder
    void in_itr() const;
    // DFS - recursive inorder
    void in_rec(TreeNode<T> *) const;

    // DFS - iterative postorder
    void post_itr() const;
    // DFS - recursive postorder
    void post_rec(TreeNode<T> *) const;

    // Delete Node
    T deleteNode(const T &);

    // finding inorder successor - iterative
    T inorder_succ_itr(const T &);

    // finding inorder successor - recurrsive
    T inorder_succ_rec_helper(const T &, TreeNode<T> *, bool &);
    T inorder_succ_rec(const T &, TreeNode<T> *);

    // getter for root
    TreeNode<T> *getRoot() const { return root; }

    // getter for size of tree
    size_t size() const { return length; }

private:
    TreeNode<T> *root;
    size_t length;
};

template <typename T>
bool BST<T>::insert_itr(const T &val)
{
    if (root == nullptr)
        root = new TreeNode<T>(val);
    else
    {
        TreeNode<T> *curr = root;
        TreeNode<T> *prev = root;
        while (curr)
        {
            prev = curr;
            if (curr->val > val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (prev->val > val)
        {
            prev->left = new TreeNode<T>(val);
        }
        else
        {
            prev->right = new TreeNode<T>(val);
        }
    }
    length++;
    return true;
}

template <typename T>
bool BST<T>::insert_rec(const T &val, TreeNode<T> *root)
{
    if (root == nullptr)
    {
        root = new TreeNode<T>(val);
        return true;
    }
    if (root->val > val)
    {
        if (root->left)
        {
            insert_rec(val, root->left);
        }
        else
        {
            root->left = new TreeNode<T>(val);
            length++;
            return true;
        }
    }
    else if (root->val < val)
    {
        if (root->right)
        {
            insert_rec(val, root->right);
        }
        else
        {
            root->right = new TreeNode<T>(val);
            length++;
            return true;
        }
    }
    return true;
}

template <typename T>
bool BST<T>::search_itr(const T &val) const
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    TreeNode<T> *curr = root;
    while (curr)
    {
        if (curr->val == val)
        {
            return true;
        }
        else if (curr->val > val)
        {
            curr = curr->left;
        }
        else if (curr->val < val)
        {
            curr = curr->right;
        }
    }
    return false;
}

template <typename T>
bool BST<T>::search_rec(TreeNode<T> *root, const T &val) const
{
    if (root == nullptr)
        return false;
    if (root->val == val)
        return true;
    if (root->val > val)
        return search_rec(root->left, val);
    return search_rec(root->right, val);
}

template <typename T>
T BST<T>::minimum() const
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    TreeNode<T> *curr = root;
    while (curr->left)
        curr = curr->left;
    return curr->val;
}

template <typename T>
T BST<T>::minimum(TreeNode<T> *root) const
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    if (root->left == nullptr)
        return root->val;
    return minimum(root->left);
}

template <typename T>
T BST<T>::maximum() const
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    TreeNode<T> *curr = root;
    while (curr->right)
        curr = curr->right;
    return curr->val;
}

template <typename T>
T BST<T>::maximum(TreeNode<T> *root) const
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    if (root->right == nullptr)
        return root->val;
    return maximum(root->right);
}

template <typename T>
const size_t BST<T>::getHeight() const
{
    if (root == nullptr)
        return -1;
    queue<TreeNode<T> *> q;
    q.push(root);
    int height{-1};
    while (!q.empty())
    {
        height++;
        size_t n = q.size();
        while (n--)
        {
            TreeNode<T> *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return height;
}

template <typename T>
const size_t BST<T>::getHeight(TreeNode<T> *root) const
{
    if (root == nullptr || (!root->left && !root->right))
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

template <typename T>
vector<T> BST<T>::bfs() const
{
    vector<T> v;
    if (root == nullptr)
        return v;

    queue<TreeNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        size_t n = q.size();
        while (n--)
        {
            TreeNode<T> *curr = q.front();
            v.push_back(curr->val);
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return v;
}

template <typename T>
void BST<T>::bfsRecHelper(queue<TreeNode<T> *> &q, vector<T> &v) const
{
    if (q.empty())
        return;
    size_t n = q.size();
    for (int i = 0; i < n; i++)
    {
        TreeNode<T> *curr = q.front();
        v.push_back(curr->val);
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    bfsRecHelper(q, v);
}
template <typename T>
void BST<T>::bfs(TreeNode<T> *root, vector<T> &v) const
{
    if (root == nullptr)
        return;
    queue<TreeNode<T> *> q;
    q.push(root);
    bfsRecHelper(q, v);
}

template <typename T>
void BST<T>::pre_itr() const
{
    if (root == nullptr)
        return;
    stack<TreeNode<T> *> st;
    TreeNode<T> *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        while (curr)
        {
            cout << curr->val << " ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top()->right;
        st.pop();
    }
}

template <typename T>
void BST<T>::pre_rec(TreeNode<T> *root) const
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    pre_rec(root->left);
    pre_rec(root->right);
}

template <typename T>
void BST<T>::in_itr() const
{
    if (root == nullptr)
        return;
    stack<TreeNode<T> *> st;
    TreeNode<T> *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

template <typename T>
void BST<T>::in_rec(TreeNode<T> *root) const
{
    if (root == nullptr)
        return;
    in_rec(root->left);
    cout << root->val << " ";
    in_rec(root->right);
}

template <typename T>
void BST<T>::post_itr() const
{
    if (root == nullptr)
        return;
    stack<TreeNode<T> *> st, out;
    st.push(root);
    while (!st.empty())
    {
        TreeNode<T> *curr = st.top();
        st.pop();
        out.push(curr);
        if (curr->left)
            st.push(curr->left);
        if (curr->right)
            st.push(curr->right);
    }
    while (!out.empty())
    {
        cout << out.top()->val << " ";
        out.pop();
    }
    cout << endl;
}

template <typename T>
void BST<T>::post_rec(TreeNode<T> *root) const
{
    if (root == nullptr)
        return;
    post_rec(root->left);
    post_rec(root->right);
    cout << root->val << " ";
}

template <typename T>
T BST<T>::deleteNode(const T &val)
{
    TreeNode<T> *parent = nullptr;
    TreeNode<T> *curr = root;
    bool leftChild{false};
    while (curr && curr->val != val)
    {
        parent = curr;
        if (curr->val > val)
        {
            leftChild = true;
            curr = curr->left;
        }
        else if (curr->val < val)
        {
            leftChild = false;
            curr = curr->right;
        }
    }
    if (!curr)
        return INT32_MAX;
    if (!curr->left && !curr->right)
    {
        if (leftChild && parent)
            parent->left = nullptr;
        else if (!leftChild && parent)
            parent->right = nullptr;
    }
    else if (!curr->left)
    {
        if (leftChild && parent)
            parent->left = curr->right;
        else if (!leftChild && parent)
            parent->right = curr->right;
        else
            root = curr->right;
    }
    else if (!curr->right)
    {
        if (leftChild && parent)
            parent->left = curr->left;
        else if (!leftChild && parent)
            parent->right = curr->left;
        else
            root = curr->left;
    }
    else
    {
        TreeNode<T> *temp = curr->right;
        TreeNode<T> *prev = curr;
        while (temp->left)
        {
            prev = temp;
            temp = temp->left;
        }
        if (prev == curr)
        {
            curr->val = temp->val;
            curr->right = temp->right;
            curr = temp;
        }
        else
        {
            prev->left = temp->right;
            curr->val = temp->val;
            curr = temp;
        }
    }
    T retrunVal = curr->val;
    delete curr;
    return retrunVal;
}

template <typename T>
T BST<T>::inorder_succ_itr(const T &val)
{
    if (root == nullptr)
        throw runtime_error("Tree is empty");
    stack<TreeNode<T> *> st;
    TreeNode<T> *curr = root;
    bool find{false};
    while (!st.empty() || curr)
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        TreeNode<T> *t = st.top();
        st.pop();
        if (find == true)
            return t->val;
        if (t->val == val)
            find = true;
        curr = t->right;
    }
}

template <typename T>
T BST<T>::inorder_succ_rec_helper(const T &val, TreeNode<T> *root, bool &find)
{
    if (root == nullptr)
        return INT32_MAX;
    if (val < root->val)
        return inorder_succ_rec(val, root->left, find);
    if (find)
    {
        find = false;
        return root->val;
    }
    if (val == root->val)
        find = true;
    if (val > root->val && !find)
        return inorder_succ_rec(val, root->right, find);
}

template <typename T>
T BST<T>::inorder_succ_rec(const T &val, TreeNode<T> *root)
{
    if (root == nullptr)
        return INT32_MAX;
    return inorder_succ_rec_helper(val, root, false);
}

#endif