// Recursive Way

void inOrder(node * n){
    if(n==NULL){
        return;
    }
    inOrder(n->left);
    cout<<n->data<<" ";
    inOrder(n->right);
}

void preOrder(node * n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    preOrder(n->left);
    preOrder(n->right);
}

void postOrder(node * n){
    if(n==NULL){
        return;

    postOrder(n->left);
    postOrder(n->right);
    cout<<n->data<<" ";
}

// Non recursive way

void inOrder(node * n){
    stack<node *>s;
    node * current = n;
    while(current!=NULL || s.empty()==false){
        while(current!=NULL){
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}

void levelOrder(node * n){
    if(n==NULL){
        return;
    }
    queue<node *>q;
    q.push(n);
    while(q.empty()==false){
        node * nn=q.front();
        cout<<nn->data<<" ";
        q.pop();

        if(nn->left!=NULL){
            q.push(nn->left);
        }
        if(nn->right!=NULL){
            q.push(nn->right);
        }
    }
}
