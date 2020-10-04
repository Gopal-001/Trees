#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    Node* left;
    int data;
    Node* right;
};
class Tree
{
public:
    Node *root;
    Tree(){root = NULL;}
    void CreateTree();
    void Preorder(Node* p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void Levelorder(Node* p);
    int Height(Node* root);
};

Node* create(Node* root)
{

        root = new Node;
        cout<<"Enter the parent element.";
        cin>>root->data;
         if(root->data != -1){
        cout<<endl<<"Enter left child of "<<root->data<<" :";
        create(root->left);
        cout<<endl<<"Enter right child of "<<root->data<<" :";
        create(root->right);
        return root;
    }
    return NULL;
}
void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    queue<Node*> q;
    root = new Node;
    cout<<"Enter the root value: ";
    cin>>x;
    root->data = x;
    root->left = root->right = NULL;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<"Enter left child of: "<<p->data<<" : "<<flush;
        cin>>x;
        if(x!= -1){
            t=new Node;
        t->data = x;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        q.push(t);
        }
        cout<<"Enter right child of: "<<p->data<<" : ";
        cin>>x;
        if(x!= -1){
            t= new Node;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            q.push(t);
        }
    }
}
void Tree::Preorder(Node* root)
{
    if(root){
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Tree::Inorder(Node* root)
{
    if(root){
        Preorder(root->left);
        cout<<root->data<<" ";
        Preorder(root->right);
    }
}
void Tree::Postorder(Node* root)
{
    if(root){
        Preorder(root->left);
        Preorder(root->right);
        cout<<root->data<<" ";
    }
}
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << root->data << ", " << flush;
    q.push(root);

    while (! q.empty()){
        p = q.front();
        q.pop();

        if (p->left){
            cout << p->left->data << ", " << flush;
            q.push(p->left);
        }

        if (p->right){
            cout << p->right->data << ", " << flush;
            q.push(p->right);
        }
    }
}
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == NULL){
        return 0;
    }

    l = Height(p->left);
    r = Height(p->right);

    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

void DTree(Node* root)
{
    DTree(root->left);
    if(root->left == NULL && root->right == NULL)
        delete(root);
    DTree(root->right);
    if(root->left == NULL && root->right == NULL)
        delete(root);
}
void LeafNode(Node* root){
    LeafNode(root->left);
    LeafNode(root->right);
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
}


int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r",stdin);
	// freopen("output.txt", "w",stdout);
	// #endif

    Tree t;
    t.CreateTree();
    t.Levelorder(t.root);
    cout<<endl<<t.Height(t.root)<<endl;
    DTree(t.root);
    cout<<endl;
    LeafNode(t.root);
    return 0;
}
