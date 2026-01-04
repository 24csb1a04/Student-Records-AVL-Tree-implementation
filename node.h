#ifndef NODE_H
#define NODE_H
#include "courseinfo.h"
#include <string>
#include <vector>
using namespace std;
struct Node {
    int roll;
    string name;
    float cgpa;
    int numSubjects;
    vector<CourseInfo> courses;
    Node*left;
    Node*right;
    Node(int a , string b , float cg , int c , vector<CourseInfo>arr){
          roll = a;
          name = b;
          cgpa = cg;
          numSubjects = c;
          courses = arr;
          left = NULL;
          right = NULL;
    }
};

#endif