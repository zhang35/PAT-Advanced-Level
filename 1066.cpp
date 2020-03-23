#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *l, *r;
};

Node* rotateRight(Node *root){
    Node *p = root->l;  
    root->l = p->r;
    p->r = root;
    return p;
}
Node* rotateLeft(Node *root){
    Node *p = root->r;  
    root->r = p->l;
    p->l = root;
    return p;
}
Node* rotateLeftRight(Node *root){
    root->l = rotateLeft(root->l);
    return rotateRight(root);
}
Node* rotateRightLeft(Node *root){
    root->r = rotateRight(root->r);
    return rotateLeft(root);
}
int getHeight(Node *root){
    if (root == NULL){
        return 0;
    }
    return max(getHeight(root->l), getHeight(root->r)) + 1;
}
Node* insertVal(Node *root, int val){
    if (root == NULL) {
        root = new Node();
        root->val = val;
        root->l = NULL;
        root->r = NULL;
    }
    else if (val < root->val){
        root->l = insertVal(root->l, val);
        if (getHeight(root->l) - getHeight(root->r) > 1){
            root = (val < root->l->val) ? rotateRight(root) : rotateLeftRight(root);
        }
    }
    else{
        root->r = insertVal(root->r, val);
        if (getHeight(root->r) - getHeight(root->l) > 1){
            root = (val >= root->r->val) ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
}
int main(){
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        root = insertVal(root, val);
    }
    cout << root->val << endl;
    return 0;
}
