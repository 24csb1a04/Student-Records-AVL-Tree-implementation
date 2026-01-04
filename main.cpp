#include <iostream>
#include <fstream>
#include "courseinfo.h"
#include "node.h"
#include "filehandler.h"
#include "AVL_TREE.h"
#include <string>
#include <queue>
using namespace std;
int main(int argc , char*argv[]) {
    if(argc < 3){
        cout<<"Too few arguments"<<endl;
        return 0;
    }
    bool useCGPA;
    string first = string(argv[1]);
    if(first=="CGPA"|| first=="cgpa") useCGPA = 1;
    else if(first=="roll" || first=="ROLL") useCGPA = 0;
    else{
        cout<<"Invalid key input. Enter CGPA/cgpa for cgpa as key or ROLL/roll for roll number as key"<<endl;
        return 0;
    }
    string filename = string(argv[2]);
    AVL_TREE studentTree(useCGPA);
    filehandler file(filename);
    file.processfile(studentTree);
    return 0;
}