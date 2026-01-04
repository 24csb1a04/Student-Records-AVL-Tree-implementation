#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>
#include "courseinfo.h"
#include "node.h"
#include "AVL_TREE.h"
#include <string>
#include <queue>
class filehandler{
  public:
    string f;
    filehandler(string f){
        this->f = f;
    }
    void display(AVL_TREE& tree);
    vector<string> trim(string& line);
    void processfile(AVL_TREE& tree);
};
#endif