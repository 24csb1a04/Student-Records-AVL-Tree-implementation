// node_operations.h
#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "courseinfo.h"
#include "node.h"
#include <vector>
class AVL_TREE{
    private:
        bool flag;
        int getHeight(Node* n);
        int CheckBalance(Node*n);
        Node* getMin(Node*n);
        Node* leftRotate(Node*n);
        Node* rightRotate(Node*n);
        void insert(Node* n);
        void del(Node* n);
        void balance(Node*n);
        Node* parent(Node*n);
        void trav();
        Node* search_roll(int  roll);
        Node* search_cgpa(float cgpa);
    public:
        Node* root;
        AVL_TREE(bool flag){
            root = NULL;
            this->flag = flag;
        }
        void insert_student_with_courses(int roll , string name , float cgpa , int numSubjects , vector<CourseInfo> courses);
        void insert_student_without_courses(int roll , string name , float cgpa );
        void modify_student_cgpa(int roll , float k );
        void add_new_course(int roll , int code , float marks);
        void modify_course_marks(int roll , int code , float marks);
        void delete_course(int roll , int code);
        void delete_student(int roll);
        void students_with_greater_roll(int roll);
        void students_with_smaller_roll(int roll);
        void students_with_greater_cgpa(float cgpa);
        void students_with_smaller_cgpa(float cgpa);
        void students_with_between_roll(int roll1 , int roll2);
        void students_with_between_cgpa(float cgpa1 , float cgpa2);
};
#endif
