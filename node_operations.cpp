#include <iostream>
#include "courseinfo.h"
#include "AVL_TREE.h"
#include "node.h"
#include "string"
#include <vector>
#include <queue>
using namespace std;
void AVL_TREE::insert_student_with_courses(int roll , string name , float cgpa , int numSubjects , vector<CourseInfo> courses){
   Node*n = new Node(roll , name , cgpa , numSubjects , courses);
   insert(n);
}
void AVL_TREE::insert_student_without_courses(int roll , string name , float cgpa){
   Node*n = new Node(roll , name , cgpa , 0 , {});
   insert(n);
}
void AVL_TREE::modify_student_cgpa(int roll , float k){
   Node*l = search_roll(roll);
   if(!l){
     cout<<"Student Not Found!"<<endl;
     return;
   }
   l->cgpa = k;
}
void AVL_TREE::add_new_course(int roll , int code , float marks){
   Node*l = search_roll(roll);
   if(!l){
     cout<<"Student Not Found!"<<endl;
     return;
   }
   vector<CourseInfo> temp(l->numSubjects+1);
   for(int i=0 ; i<l->numSubjects ; i++){
      temp[i] = l->courses[i];
   }
   CourseInfo* z = new CourseInfo(code , marks);
   temp[l->numSubjects] = *z;
   l->numSubjects++;
   l->courses = temp;
}
void AVL_TREE::modify_course_marks(int roll , int code , float marks){
  Node*l = search_roll(roll);
  if(!l){
    cout<<"Student Not Found!"<<endl;
    return;
  }
  for(int i=0 ; i<l->numSubjects ; i++){
    if((l->courses)[i].courseId==code){
       (l->courses)[i].marks = marks;
       return;
    }
  }
  cout<<"Course Not Found!"<<endl;
}
void AVL_TREE::delete_course(int roll , int code){
   Node*l = search_roll(roll);
   if(!l){
    cout<<"Student Not Found!"<<endl;
    return;
  }
  vector<CourseInfo>temp;
  for(int i=0 ; i<l->numSubjects ; i++){
     if((l->courses)[i].courseId==code) continue;
     temp.push_back((l->courses)[i]);
  }
  vector<CourseInfo> ans(temp.size());
  int r = temp.size();
  for(int i=0 ; i<r ; i++){
     ans[i] = temp[i];    
  }  
  l->numSubjects = temp.size();
  l->courses = ans;
}
void AVL_TREE::delete_student(int roll){
   Node*l = search_roll(roll);
   if(!l){
     cout<<"Student Not Found!"<<endl;
     return;
   }
   del(l);
}
void AVL_TREE::students_with_greater_roll(int roll){
    if(flag){
        cout<<"Cannot exectue as roll number is not a key"<<endl;
        return;
    }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node*k = q.front();
       q.pop();
       if(k->roll > roll){
           cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
           cout<<"Courses: "<<endl;
           for(int i=0 ; i<k->numSubjects ; i++){
               cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
           }
           cout<<endl;
           if(k->right) q.push(k->right);
       }
       if(k->left) q.push(k->left);
   }
}
void AVL_TREE::students_with_smaller_roll(int roll){
    if(flag){
        cout<<"Cannot exectue as roll number is not a key"<<endl;
        return;
    }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node*k = q.front();
       q.pop();
       if(k->roll < roll){
           cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
           cout<<"Courses: "<<endl;
           for(int i=0 ; i<k->numSubjects ; i++){
               cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
           }
           cout<<endl;
           if(k->right) q.push(k->right);
       }
       if(k->left) q.push(k->left);
   }
}
void AVL_TREE::students_with_greater_cgpa(float cgpa){
    if(!flag){
        cout<<"Cannot execute as CGPA is not the key"<<endl;
        return;
    }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node*k = q.front();
       q.pop();
       if(k->cgpa > cgpa){
           cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
           cout<<"Courses: "<<endl;
           for(int i=0 ; i<k->numSubjects ; i++){
               cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
           }
           cout<<endl;
           if(k->left) q.push(k->left);
       }
       if(k->right) q.push(k->right);
   }
}
void AVL_TREE::students_with_smaller_cgpa(float cgpa){
   if(!flag){
        cout<<"Cannot execute as CGPA is not the key"<<endl;
        return;
   }
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node*k = q.front();
       q.pop();
       if(k->cgpa < cgpa){
           cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
           cout<<"Courses: "<<endl;
           for(int i=0 ; i<k->numSubjects ; i++){
               cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
           }
           cout<<endl;
           if(k->right) q.push(k->right);
       }
       if(k->left) q.push(k->left);
   }
}
void AVL_TREE::students_with_between_roll(int roll1 , int roll2){
    if(flag){
        cout<<"Cannot exectue as roll number is not a key"<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*k = q.front();
        q.pop();
        if(k->roll <= roll1){
            if(k->right) q.push(k->right);
        }
        else if(k->roll >= roll2){
            if(k->left) q.push(k->left);
        }
        else{
             cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
             cout<<"Courses: "<<endl;
             for(int i=0 ; i<k->numSubjects ; i++){
                 cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
             }
             cout<<endl;
             if(k->left) q.push(k->left);
             if(k->right) q.push(k->right);
        }
    }
}
void AVL_TREE::students_with_between_cgpa(float cgpa1 , float cgpa2){
    if(!flag){
        cout<<"Cannot execute as CGPA is not the key"<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*k = q.front();
        q.pop();
        if(k->cgpa <= cgpa1){
            if(k->right) q.push(k->right);
        }
        else if(k->cgpa >= cgpa2){
            if(k->left) q.push(k->left);
        }
        else{
             cout<<"Roll No: "<<k->roll<<" Name: "<<k->name<<" cgpa "<<k->cgpa<<" numSubjects: "<<k->numSubjects<<endl;
             cout<<"Courses: "<<endl;
             for(int i=0 ; i<k->numSubjects ; i++){
                 cout<<k->courses[i].courseId<<" "<<k->courses[i].marks<<endl;
             }
             cout<<endl;
             if(k->left) q.push(k->left);
             if(k->right) q.push(k->right);
        }
    }
}