#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val <= root->data){
        Node *lchild = insert(root->left, val);
        root->left  = lchild;
        lchild->parent = root;
    }
    else{
        Node *rchild = insert(root->right, val);
        root->right  = rchild;
        rchild->parent = root;
    }

    return root;
}

Node* search(Node* root, int key){
    
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(root->data > key){
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

Node* inOrderSuccessor(Node* root){
    Node* cur = root;
    while(cur && cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

Node* Delete(Node* root, int key){

    if(key < root->data){
        root->left = Delete(root->left, key);
    }
    else if(key > root->data){
        root->right = Delete(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        
        // Case 3
        Node* temp = inOrderSuccessor(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void inOrder(struct Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* Min(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* Max(Node* root){
    while(root->right != NULL){
        root = root->right;
    }
    cout<<root->data;
    return root;
}

Node* preorderPredecessor(Node* root, Node* n) {
    if (n == root)
        return NULL;

    Node* parent = n->parent;
    if (parent->left == NULL || parent->left == n)
        return parent;
 
    Node* curr = parent->left;
    while (curr->right != NULL)
        curr = curr->right;
 
    return curr;
}

Node* preorderSuccessor(Node* root, Node* n) {
    if (n->left)
        return n->left;

    if (n->right)
          return n->right;

    Node *curr = n, *parent = curr->parent;
    while (parent != NULL && parent->right == curr) {
        curr = curr->parent;
        parent = parent->parent;
    }

    if (parent == NULL)
        return NULL;
 
    return parent->right;
}

Node* postorderSuccessor(Node* root, Node* n) {
    if (n == root)
        return NULL;

    Node* parent = n->parent;
    if (parent->right == NULL || parent->right == n)
        return parent;

    Node* curr = parent->right;
    while (curr->left != NULL)
        curr = curr->left;
  
    return curr;
}

Node* postorderPredecessor(Node* root, Node* n) {
    if (n->right)
        return n->right;

    Node *curr = n, *parent = curr->parent;
    while (parent != NULL && parent->left == curr) {
        curr = curr->parent;
        parent = parent->parent;
    }

    if (parent == NULL)
        return NULL;
 
    return parent->left;
}

Node* findPredecessor(Node* root, Node* prec, int key){
    if (root == NULL) {
        return prec;
    }

    if (root->data == key)
    {
        if (root->left != NULL) {
            return Max(root->left);
        }
    }
    else if (key < root->data) {
        return findPredecessor(root->left, prec, key);
    }
    else {
        prec = root;
        return findPredecessor(root->right, prec, key);
    }
    return prec;
}

int main(){
    Node* root = NULL;
    root = insert(root,4);
    insert(root,2);
    insert(root,3);
    insert(root,5);
    insert(root,1);
    insert(root,7);
    insert(root,6);
    Delete(root, 5);

	cout<<"Inorder Traversal: ";
    inOrder(root);
    Node* nodeToCheck = root->left;
 
    Node* res = findPredecessor(root, NULL, nodeToCheck->data);
    
    if (res) {
        cout<<"\n\nPredecessor of " << nodeToCheck->data << " is: " <<res->data;
    }
    else {
        cout<<"\n\nPredecessor of " << nodeToCheck->data << " is NULL."<<endl;
    }
}