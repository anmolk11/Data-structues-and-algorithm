#include <iostream>
#include "AVL.h"
using namespace std;
int main() {
    cout << "------------------------------------------" << endl;
    AVL<int> bt;
    bt.root = bt.insert_rec(5,bt.getRoot());
    bt.root = bt.insert_rec(3,bt.getRoot());
    bt.root = bt.insert_rec(2,bt.getRoot());
    bt.root = bt.insert_rec(4,bt.getRoot());
    bt.root = bt.insert_rec(8,bt.getRoot());
    bt.root = bt.insert_rec(6,bt.getRoot());
    bt.root = bt.insert_rec(7,bt.getRoot());
    bt.root = bt.insert_rec(9,bt.getRoot());


    if(bt.root != nullptr) {
        cout << "Tree Created Successfully" << endl;
    }else {
        cout << "Some error caused while creating tree" << endl;
    }
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "Preorder - recursive : ";
    bt.pre_rec(bt.getRoot());
    cout << endl;
    cout << "Preorder - iterative : ";
    bt.pre_itr();
    cout << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "Inorder - reursive  : ";
    bt.in_rec(bt.getRoot());
    cout << endl;
    cout << "Inorder - iterative : ";
    bt.in_itr();
    cout << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "PostOrder - recursive : ";
    bt.post_rec(bt.getRoot());
    cout << endl;
    cout << "PostOrder - iterative : ";
    bt.post_itr();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "ITR : Searching element in tree : ";
    int x;
    cin >> x;
    if(bt.search_itr(x))
        cout << x << " : !! Element found !!" << endl;
    else
        cout << x << " : !! Element Not found !!" << endl;

    cout << "REC : Searching element in tree : ";
    if(bt.search_rec(bt.getRoot(),x))
        cout << x << " : !! Element found !!" << endl;
    else
        cout << x << " : !! Element Not found !!" << endl;
    cout << "------------------------------------------" << endl;
    
    cout << "------------------------------------------" << endl;
    cout << "(ITR) Minimum element in tree : " << bt.minimum() << endl;
    cout << "(ITR) Maximum element in tree : " << bt.maximum() << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "(REC) Minimum element in tree : " << bt.minimum(bt.getRoot()) << endl;
    cout << "(REC) Maximum element in tree : " << bt.maximum(bt.getRoot()) << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "ITR : Height of Binary tree : " << bt.getHeight() << endl;
    cout << "REC : Height of Binary tree : " << bt.getHeight(bt.getRoot()) << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    vector<int> bfs = bt.bfs();
    cout << "BFS - iterative : ";
    for(auto x : bfs) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> bfs_rec;
    bt.bfs(bt.getRoot(),bfs_rec);
    cout << "BFS - recursive : ";
    for(auto x : bfs_rec) {
        cout << x << " ";
    }
    cout << endl;
    cout << "------------------------------------------" << endl;

    cout << "------------------------------------------" << endl;
    cout << "Delete Node : ";
    int val;
    cin >> val;
    TreeNode<int>* deletedNode = bt.delete_node_rec(bt.getRoot(),val);
    if(deletedNode != nullptr) {
        cout << "Node deleted successfully" << endl;
    }else {
        cout << "!! Error: can't delete node !!" << endl;
    }
    cout << "PRE -> ";
    bt.pre_itr();
    cout << endl;
    cout << "IN -> ";
    bt.in_itr();
    cout << endl;
    cout << "POST -> ";
    bt.post_itr();
    cout << endl;
    bfs = bt.bfs();
    cout << "BFS : ";
    for(auto x : bfs) {
        cout << x << " ";
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
}