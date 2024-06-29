
#include "entry.h"
// #include<iostream>

//constructor 1 
SymEntry ::SymEntry(){
    key = "def";
    val = new UnlimitedRational();
    left = NULL;
    right = NULL;
}

//constructor2
SymEntry :: SymEntry(string k, UnlimitedRational* v){
    key = k;
    val = v;
    left = NULL;
    right = NULL;
}
 
//destructor 
SymEntry :: ~SymEntry(){
    left = NULL;
    right = NULL;
    // delete val;
    // cout << "node with value " << key << " is deleted " << endl; 
}
