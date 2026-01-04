#include <iostream>
#include <fstream>
#include "courseinfo.h"
#include "node.h"
#include "filehandler.h"
#include "AVL_TREE.h"
#include <string>
#include <queue>
using namespace std;
void filehandler::display(AVL_TREE& tree){
    Node* root = tree.root;
    if(!root){
      cout<<"Empty Tree!"<<endl;
      return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
       Node*n = q.front();
       q.pop();
       if(n){
          cout<<"Roll No: "<<n->roll<<" Name: "<<n->name<<" cgpa "<<n->cgpa<<" numSubjects: "<<n->numSubjects<<endl;
          cout<<"Courses: "<<endl;
          for(int i=0 ; i<n->numSubjects ; i++){
              cout<<"courseId: "<<n->courses[i].courseId<<" "<<" marks: "<<n->courses[i].marks<<endl;
          }
          if(n->left) q.push(n->left);
          if(n->right) q.push(n->right);
       }
    }    
 }
 vector<string> filehandler:: trim(string& line){
     vector<string>ans;
     int i=0;
     int d = line.length();
     while(i<d){
         if(line[i]==' ' || line[i]==','){
             i++;
             continue;
         }
         int j=i;
         string curr="";
         while(j<d && line[j]!=',' && line[j]!=' '){
             curr+=line[j];
             j++;
         }
         i = j;
         ans.push_back(curr);
     }
     return ans;
 }
 void filehandler::processfile(AVL_TREE& studentTree) {
     ifstream fin(f);
     if(!fin){
        cout<<"Can't Open file!";
        return;
     }
     string line;
     string s;
     int code;
     vector<string>l;
     while (getline(fin , line)) {
         int len = line.length();
         if(len==0) continue;
         l = trim(line);
         if(l[0]!="#"){
             cout<<"Invalid!!";
             return;
         }
         if(len==1 || line[1]!=' '){
             cout<<"Invalid Input!! Space required after # along with function code!!";
             return;
         }
         int len2 = l[1].length();
         code = (len2==2)?(l[1][0]-'0'):((l[1][0]-'0')*10 + (l[1][1]-'0'));
         int roll ; string name ; float cgpa ; int numSubjects; vector<CourseInfo>courses; int courseId;
         float marks;
         int roll1 , roll2;
         float cgpa1 , cgpa2;
         getline(fin , line);
         l = trim(line);
         cout<<endl;
         if(code==1){
             try{
                 roll = stoi(l[0]);
                 name = l[1]+" "+l[2];
                 cgpa = stof(l[3]);
                 numSubjects = stoi(l[4]);
             }
             catch(...){
                 cout<<"Invalid input!";
                 return;
             }
             if(numSubjects==0){
                 cout<<"After Insertion: "<<endl;
                 studentTree.insert_student_without_courses(roll ,  name ,  cgpa);
                 display(studentTree);
                 continue;
             }
             for(int i=0 ; i<numSubjects ; i++){
                 getline(fin , line);
                 l = trim(line);
                 courseId = stoi(l[0]);
                 marks = stof(l[1]);
                 CourseInfo k(courseId , marks);
                 courses.push_back(k);
             }
             cout<<"After Insertion: "<<endl;
             studentTree.insert_student_with_courses(roll , name , cgpa , numSubjects , courses);
         }
         else if(code==2){
             try{
                 roll = stoi(l[0]);
                 cgpa = stof(l[1]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"After modification: "<<endl;
             studentTree.modify_student_cgpa(roll , cgpa);
         }
         else if(code==3){
             try{
                 roll = stoi(l[0]);
                 courseId = stoi(l[1]);
                 marks = stof(l[2]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"After addition new course: "<<endl;
             studentTree.add_new_course( roll , courseId , marks);
         }
         else if(code==4){
             try{
                 roll = stoi(l[0]);
                 courseId = stoi(l[1]);
                 marks = stof(l[2]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"After modification of course marks: "<<endl;
             studentTree.modify_course_marks(roll , courseId , marks);
         }
         else if(code==5){
             try{
                 roll = stoi(l[0]);
                 courseId = stoi(l[1]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"After deletion of course: "<<endl;
             studentTree.delete_course( roll ,courseId);
         }
         else if(code==6){
             try{
                 roll = stoi(l[0]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"After deletion: "<<roll<<endl;
             studentTree.delete_student(roll);
         }
         else if(code==7){
             try{
                 roll = stoi(l[0]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"Students with greater roll number than"<<roll<<endl;
             studentTree.students_with_greater_roll(roll);
             continue;
         }
         else if(code==8){
             try{
                 roll = stoi(l[0]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"Students with smaller roll number than "<<roll<<endl;
             studentTree.students_with_smaller_roll(roll);
             continue;
         }
         else if(code==9){
             try{
                 roll1 = stoi(l[0]);
                 roll2 = stoi(l[1]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"Students with roll number in between:"<<roll1<<" and "<<roll2<<": "<<endl;
             studentTree.students_with_between_roll(roll1 ,roll2);
             continue;
         }
         else if(code==10){
             try{
                 cgpa = stof(l[0]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"Students with greater cgpa than"<<cgpa<<" :"<<endl;
             studentTree.students_with_greater_cgpa(cgpa);
             continue;
         }
         else if(code==11){
             try{
                 cgpa = stof(l[0]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<"Students with smaller cgpa than: "<<cgpa<<": "<<endl;
             studentTree.students_with_smaller_cgpa(cgpa);
             continue;
         }
         else if(code==12){
             try{
                 cgpa1 = stof(l[0]);
                 cgpa2 = stof(l[1]);
             }
             catch(...){
                 cout<<"Invalid Input!";
                 return;
             }
             cout<<" Students with cgpa between: "<<cgpa1<<" and "<<cgpa2<<endl;
             studentTree.students_with_between_cgpa(cgpa1 ,cgpa2);
             continue;
         }
         else{
             cout<<"Invalid code entered!!";
             return;
         }
         display(studentTree);
         cout<<endl;
         cout<<endl;
     }
     fin.close();
 }