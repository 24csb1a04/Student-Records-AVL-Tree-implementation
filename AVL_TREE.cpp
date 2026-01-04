#include <iostream>
#include "courseinfo.h"
#include "node.h"
#include "AVL_TREE.h"
#include <stack>
#include <queue>
using namespace std;
int AVL_TREE:: getHeight(Node*n){
  if(!n) return 0;
  return 1+max(getHeight(n->left) , getHeight(n->right));
}
int AVL_TREE:: CheckBalance(Node*n){
  return getHeight(n->left)-getHeight(n->right);
}
Node* AVL_TREE::search_roll(int roll){
    if(!flag){
        Node*temp = root;
        while(temp){
            if(temp->roll == roll){
                return temp;
            }
            else if(temp->roll < roll) temp = temp->right;
            else temp = temp->left;
        }
        return NULL;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*n = q.front();
        q.pop();
        if(n->roll==roll) return n;
        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }
    return NULL;
}
Node*AVL_TREE::search_cgpa(float cgpa){
    if(flag){
        Node*temp = root;
        while(temp){
            if(temp->cgpa == cgpa) return temp;
            else if(temp->cgpa < cgpa) temp = temp->left;
            else temp = temp->right;
        }
        return NULL;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*n = q.front();
        q.pop();
        if(n->cgpa==cgpa) return n;
        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }
    return NULL;
}
Node* AVL_TREE:: getMin(Node* n){
    if(!n) return NULL;
    Node*temp = n;
    while(temp->left) temp = temp->left;
    return temp;
}
Node* AVL_TREE:: parent(Node*n){
    Node*prev = NULL;
    Node*temp = root;
    if(!flag){
        while(temp){
            if(temp->roll==n->roll) return prev;
            else if(n->roll < temp->roll){
                prev = temp;
                temp = temp->left;
            }
            else{
                prev = temp;
                temp = temp->right;
            }
        }
        return NULL;
    }
    while(temp){
        if(temp->cgpa==n->cgpa) return prev;
        else if(n->cgpa < temp->cgpa){
            prev = temp;
            temp = temp->left;
        }
        else{
            prev = temp;
            temp = temp->right;
        }
    }
    return NULL;
}
Node* AVL_TREE:: leftRotate(Node*n){
  Node*newroot = n->right;
  n->right= newroot->left;
  newroot->left =n;
  return newroot;
}
Node* AVL_TREE:: rightRotate(Node*n){
  Node*newroot = n->left;
  n->left = newroot->right;
  newroot->right = n;
  return newroot;
}
void AVL_TREE::balance(Node*n){
   bool r = (root==n);
   if(CheckBalance(n)==0) return;
   Node* x = (CheckBalance(n) >0)?(n->left):(n->right);
   Node*y = (CheckBalance(x) > 0)?(x->left):(x->right);
   if(x==n->left && y==x->left){
       Node*k = parent(n);
       if(k && k->left==n) k->left = rightRotate(n);
       else if(k && k->right==n) k->right = rightRotate(n);
       else if(r) root= rightRotate(n);
   }
   else if(x==n->left && y==x->right){
      n->left = leftRotate(x);
      Node*k = parent(n);
      if(k && k->left==n) k->left = rightRotate(n);
      else if(k && k->right==n) k->right = rightRotate(n);
      else if(r) root= rightRotate(n);
   }
   else if(x==n->right && y==x->left){
      n->right = rightRotate(x);
      Node*k = parent(n);
      if(k && k->left==n) k->left = leftRotate(n);
      else if(k && k->right==n) k->right = leftRotate(n);
      else if(r) root = leftRotate(n);
   }
   else{
       Node*k  = parent(n);
       if(k && k->left==n) {
           k->left = leftRotate(n);
       }
       else if(k && k->right==n){
           k->right = leftRotate(n);
       }
       else if(r) root = leftRotate(n);
   }
}
void AVL_TREE:: insert(Node* n){
  Node*temp = root;
  if(!root){
      root = n;
      return;
  }
  Node*prev = NULL;
  stack<Node*>st;
  if(!flag){
    while(temp){
      if(n->roll < temp->roll){
         prev = temp;
         st.push(temp);
         temp = temp->left;
      }
      else{
         prev = temp;
         st.push(temp);
         temp = temp->right;
      }
    }
    if(n->roll < prev->roll){
        prev->left = n;
    }
    else {
        prev->right = n;
    }
  }
  else{
     while(temp){
      if(n->cgpa < temp->cgpa){
         prev = temp;
         st.push(temp);
         temp = temp->left;
      }
      else{
         prev = temp;
         st.push(temp);
         temp = temp->right;
      }
    }
    if(n->cgpa < prev->cgpa) prev->left = n;
    else prev->right = n;
  }
  while(!st.empty()){
      if(abs(CheckBalance(st.top()))>1){
         balance(st.top());
      }
      st.pop();
  }
}
void AVL_TREE::del(Node* n){
    bool r = (root==n);
    Node* k = parent(n);
    if(!n->left && !n->right){
        if(k && k->left==n) k->left = NULL;
        if(k && k->right==n) k->right= NULL;
        else if(r) root = NULL;
        Node*temp = k;
        while(temp){
            if(abs(CheckBalance(temp))>1) balance(temp);
            temp = parent(temp);
        }
    }
    else if(!n->left || !n->right){
        Node* m = (n->left)?(n->left):(n->right);
        Node*k = parent(n);
        if(k && k->left==n)k->left = m;
        else if(k && k->right==n) k->right =m;
        else if(r) root = m;
        Node*temp = k;
        while(temp){
            if(abs(CheckBalance(temp))>1) balance(temp);
            temp = parent(temp);
        }
    }
    else{
        Node* m = getMin(n->right);
        Node* pm =parent(m);
        if(pm && pm->right==m) parent(m)->right = NULL;
        else if(pm) pm->left = NULL;
        Node*k = parent(n);
        if(k && k->left==n) k->left = m;
        else if(k && k->right==n) k->right = m;
        m->left = n->left;
        n->left = NULL;
        if(n->right!=m) m->right = n->right;
        n->right = NULL;
        if(r) root = m;
        Node*temp = pm;
        while(temp){
            if(abs(CheckBalance(temp))>1) balance(temp);
            temp = parent(temp);
        }
    }
}