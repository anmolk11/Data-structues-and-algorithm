//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> tmp;
    if (root == NULL)
        return tmp; // NULL check

    stack<Node*> s1; // For levels to be printed from right to left
    stack<Node*> s2; // For levels to be printed from left to right

    // Push first level to first stack 's1'
    s1.push(root);

    // Keep printing while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty()) {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            tmp.push_back(temp->data);

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            tmp.push_back(temp->data);

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
    return tmp;
}