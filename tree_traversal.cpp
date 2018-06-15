#include<iostream>
using namespace std;
struct node{
    int value;
    struct node* left;
    struct node* right;
};
node* newNode(int val){
    node* temp=(node*)malloc(sizeof(struct node));
    temp->value=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* createTree(){
    int i,j,n,a;
    cin>>n;
    cin>>a;
    i=0;
    node* q[n];j=0;

    q[j]=newNode(a);j=j+1;i=i+1;
    //cout<<q[j-1]->value<<endl;

    while(i<n){
        cin>>a;
        q[j]=newNode(a);
        q[(j-1)/2]->left=q[j];
        j=j+1;i=i+1;

        if(i==n){
            break;
        }
        cin>>a;
        q[j]=newNode(a);
        q[(j-1)/2]->right=q[j];
        j=j+1;i=i+1;
    }
    return(q[0]);
}
void inorder(node* head){
    node* temp=head;
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout<<temp->value<<" ";
    inorder(temp->right);
}
void preorder(node* head){
    node* temp=head;
    if(temp==NULL){
        return;
    }
    cout<<temp->value<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(node* head){
    node* temp=head;
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->value<<" ";
}
void levelorder(node* head){
    node* q[100];
    int i=1,j=0;
    q[0]=head;
    while(q[j]!=NULL){
        q[i]=q[j]->left;i++;
        q[i]=q[j]->right;i++;
        cout<<q[j]->value<<" ";j++;
    }
}
int main(){
    node* head=createTree();
    inorder(head);cout<<"\n";
    preorder(head);cout<<"\n";
    postorder(head);cout<<"\n";
    levelorder(head);cout<<"\n";
    //do level order traversal with tree height and 
    //reverse level order traversal with tree height
    return 0;
}