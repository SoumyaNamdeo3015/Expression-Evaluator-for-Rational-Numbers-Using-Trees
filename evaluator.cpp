
#include "evaluator.h"
// #include<iostream>

// using namespace std;

// void inorder(ExprTreeNode*Node){
//     if(Node== NULL){
//         return;
//     }
//     cout << "(";
//     inorder(Node->left);
//     string op;
//     if(Node->type == "ADD"){
//         op = "+";
//     }
    
//     if(Node->type == "SUB"){
//         op = "-";
//     }
//     if(Node->type == "MUL"){
//         op ="*";
//     }

//     if(Node->type == "DIV"){
//         op = "/";
//     }
//     if(Node->type == "VAL"){
//         op = Node->val->get_p()->to_string();
//     }
//     if(Node->type == "VAR"){
//         op = Node->id;
//     }
//     if(Node->type ==":="){
//         op = ":=";
//     }
//     cout << op <<"";
//     inorder(Node->right);
//     cout << ")";
// }

Evaluator :: Evaluator(){
    symtable = new SymbolTable();
}

Evaluator :: ~Evaluator(){
    delete symtable;
    int a = expr_trees.size();
    for(int i=0;i<a;i++){
        delete expr_trees[i];
    }
    expr_trees.clear();    
}

bool isOperator(string op){
    if( op=="+"|| op=="-" || op=="/" || op=="*"){
        return true;
    }
    return false;
}

bool isNumber(string TokenString){
    char TokenChar = TokenString[0];
    int AscciValue  = TokenChar;
    if(AscciValue>=48 && AscciValue<=57){
        return true;
    }
    return false;
}

ExprTreeNode* createNode(string TokenString){
    UnlimitedRational* val = new UnlimitedRational();
    ExprTreeNode* Node;

    if(TokenString ==":="){
        Node = new ExprTreeNode();
        return Node;
    }

    else if(TokenString == "+"){
        Node = new ExprTreeNode("ADD",val);
        return Node;
    }

    else if(TokenString== "-"){
        Node = new ExprTreeNode("SUB",val);
        return Node;
    }

    else if(TokenString == "*"){
        Node = new ExprTreeNode("MUL",val);
        return Node;
    }

    else if(TokenString == "/"){
        Node = new ExprTreeNode("DIV",val);
        return Node;
    }

    else if(isNumber(TokenString)){
        UnlimitedInt* TokenNumber = new UnlimitedInt(TokenString);
        Node = new ExprTreeNode("VAL",TokenNumber);
        return Node;
    }

        //type will be var:
        Node = new ExprTreeNode(TokenString,val);
        return Node;
}

void Evaluator :: parse(vector<string>code){    
    vector<ExprTreeNode*>VectorNodes;
    ExprTreeNode* VariableNode =createNode(code[0]);
    ExprTreeNode* EqaulNode = createNode(code[1]);
    EqaulNode->left = VariableNode;

    int s = code.size();
    for(int i=2;i<s;i++){
        string TokenString = code[i];
        if(TokenString == "("){
            //then do nothing:
        }

        else if(isNumber(TokenString)==1){
            ExprTreeNode* Node = createNode(TokenString);
            VectorNodes.push_back(Node);
        }

        else if(isOperator(TokenString)==1){
            ExprTreeNode* top = VectorNodes[VectorNodes.size()-1];
            VectorNodes.pop_back();
            ExprTreeNode* OperatorNode = createNode(TokenString);
            OperatorNode->left = top;
            VectorNodes.push_back(OperatorNode);
        }

        else if(TokenString ==")"){
            ExprTreeNode*top = VectorNodes[VectorNodes.size()-1];
            VectorNodes.pop_back();
            VectorNodes[VectorNodes.size()-1]->right = top;
        }

        else{
            //token string is a variable name:
            ExprTreeNode* VariableNode = createNode(TokenString);
            VectorNodes.push_back(VariableNode);
        }
    }

    EqaulNode->right =VectorNodes[0];
    expr_trees.push_back(EqaulNode);
}


void evaluator(SymbolTable* table,ExprTreeNode*root){

    //;leaf node:
    if(root->left == NULL && root->right == NULL){
        string type = root->type;
        if(type == "VAL"){
            root->evaluated_value = root->val;
        }
        else if(type =="VAR"){
            UnlimitedRational* value  = table->search(root->id);
            root->evaluated_value =  value;
        }
        return;
    }

    evaluator(table,root->left);
    evaluator(table,root->right);
    
    if(root->type == "ADD"){
        root->evaluated_value = UnlimitedRational::add(root->left->evaluated_value, root->right->evaluated_value);   
    }

    else if(root->type == "SUB"){
         root->evaluated_value = UnlimitedRational::sub(root->left->evaluated_value, root->right->evaluated_value);   
    }

    else if(root->type == "MUL"){
         root->evaluated_value = UnlimitedRational::mul(root->left->evaluated_value, root->right->evaluated_value);   
    }

    else if(root->type == "DIV"){
         root->evaluated_value = UnlimitedRational::div(root->left->evaluated_value, root->right->evaluated_value);   
    }
 

}

void Evaluator :: eval(){
    ExprTreeNode* LastNode = expr_trees[expr_trees.size()-1];
    ExprTreeNode*right = LastNode->right;
    evaluator(symtable,right);
    string VariableName = LastNode->left->id;
    
    symtable->insert(VariableName,right->evaluated_value);
};

// int main(){
//     vector<string> code1{"v", ":=", "(", "13", "+", "(", "2", "/", "51", ")", ")"};
//     vector<string> code2{"g" ,":=" ,"(" ,"2" ,"*" , "v" ,")"};
//     vector<string> code3{"x" ,  ":=" , "(" ,"g" ,"+" ,"6" ,")"};
//     vector<string> code4{"y" ,":=" ,"x"};
//     Evaluator* ev = new Evaluator();
//     // ev->parse(code1);
//     // ev->eval();
//     // // ev->parse(code2);
//     // // ev->eval();
//     // // ev->parse(code3);
//     // // ev->eval();
//     // // ev->parse(code4);
//     // // ev->eval();
//     // inorder2(ev->symtable->get_root());
//     return 0;
// }