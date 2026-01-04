#ifndef COURSE_INFO_H
#define COURSE_INFO_H
struct CourseInfo {
    int courseId;
    float marks;
    CourseInfo(int a , float b){
       courseId=a;
       marks=b;
    }
    CourseInfo(){
        courseId = 0;
        marks = 0.0;
    }
};
#endif