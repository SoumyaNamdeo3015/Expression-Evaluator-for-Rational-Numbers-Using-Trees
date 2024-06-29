
#include "exprtreenode.h"
// #include<iostream>

ExprTreeNode:: ExprTreeNode(){
    type = ":="; //  for := node or the root node 
    id  = ":=";
    left = NULL;
    right = NULL;
    val = new UnlimitedRational();
}

ExprTreeNode:: ExprTreeNode(string t, UnlimitedInt*v){

    type = t;
    left = NULL;
    right = NULL;
    val = new UnlimitedRational();

    if(type=="VAL"){
     
      UnlimitedInt*one = new UnlimitedInt("1");
      val = new UnlimitedRational(v,one);
    }

    else if(type == "ADD"){
    }

    else if(type == "SUB"){
    }

    else if(type=="MUL"){   
    }

    else if(type == "DIV"){
    }

    else{
        type ="VAR";
        id = t;
    }
}

ExprTreeNode :: ExprTreeNode(string t, UnlimitedRational*v){
    type =t;
    left = NULL;
    right  = NULL;
    val = new UnlimitedRational();

    if(type=="VAL"){
        UnlimitedInt* one = new UnlimitedInt("1");
        UnlimitedRational*_1 = new UnlimitedRational(one,one);
        val = UnlimitedRational::mul(v,_1);
    }

    else if(type== "ADD"){
    }

    else if(type== "SUB"){     
    }

    else if(type == "MUL"){ 
    }

    else if(type == "DIV"){
    }

    else{
        type ="VAR";
        id = t;
    }
}

ExprTreeNode :: ~ExprTreeNode(){
    delete val;
}

//note deletion null rational number 
