
#include "symtable.h"
// #include<iostream>

//helper function inorder
void inorder(SymEntry* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
}   

void print(SymEntry* root){
    inorder(root);
}

//helperfunction:
void deleteTree(SymEntry* root){
    if(root== NULL){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    

}

//constructor
SymbolTable :: SymbolTable(){
    size = 0;
    root = NULL;
}

//destructor
SymbolTable :: ~SymbolTable(){
    deleteTree(root);
}

//member function insert
void SymbolTable :: insert(string k, UnlimitedRational* v){

    if(root==NULL){
        root = new SymEntry(k,v);
        size++;
        return;
    }
    SymEntry* root_node = root;
    SymEntry* previous;

    while(root_node !=NULL){
        previous = root_node;

        string root_value = root_node->key;
        if(k>root_value){
            root_node = root_node->right;
        }

        else if(k<root_value){
            root_node = root_node->left;
        }

        else{
            break;
        }
    }

    if(k >previous->key){
        SymEntry* newEntry = new SymEntry(k,v);
        previous->right = newEntry;
        size++;
        return;
    }

    if(k<previous->key){
        SymEntry* newEntry = new SymEntry(k,v);
        previous->left = newEntry;
        size++;
        return;
    }
}


//member function search
UnlimitedRational* SymbolTable :: search(string k){
    SymEntry* root_node = root;
    while(root_node!=NULL){
        if(k>root_node->key){
            //search in the right: 
            root_node = root_node->right;
        }
        else if(k== root_node->key){
            return root_node->val;
        }   
        else{
            // k<root_node->key
            root_node = root_node->left;
        }
    }
    // key not found:
    UnlimitedRational* notfound = new UnlimitedRational();
    return notfound;
}

int SymbolTable:: get_size(){
    return size;
}

SymEntry* SymbolTable::get_root(){
    return root;
}

//delete node
SymEntry* minVal(SymEntry*root){
    SymEntry* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

SymEntry* maxVal(SymEntry*root){
    SymEntry* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

SymEntry* deleteionBST(SymEntry* root,string k){
    //base case:
    if(root==NULL){
        return root;
    }

    if(root->key == k){
        //0 child 
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;  
        }
        // 1 child

        //left child present right child is null : 
        if(root->left != NULL && root->right == NULL){
            SymEntry* temp = root->left;
            delete root;
            return temp;
        }

        //right child present leff child is null:
        if(root->right!=NULL && root->left == NULL){
            SymEntry* temp = root->right;
            delete root;
            return temp;
        }


        //2 child 
        if(root->left!=NULL && root->right!=NULL){
        SymEntry* min_key =minVal(root->right);
        root->key = min_key->key;
        root->val = min_key->val;
        root->right = deleteionBST(root->right,min_key->key);
        return root;
        }
    }

    else if(root->key > k){
        root->left = deleteionBST(root->left,k);

    }

    else{
        root->right = deleteionBST(root->right,k);
    }
    return root;
}

void SymbolTable::remove(string k){

    UnlimitedRational* v = search(k);
    if(v->get_p()!=NULL && v->get_q()!=NULL){
        size--;
        root = deleteionBST(root,k);
    }
   
}

//complete deletion in BST:
// int main(){
//     SymbolTable* table = new SymbolTable();
//     string k1 = "5";
//     UnlimitedInt* num1 = new UnlimitedInt("1");
//     UnlimitedInt* den1 = new UnlimitedInt("9");
//     UnlimitedRational* r1 = new UnlimitedRational(num1,den1);
//     string k2 ="7";
//     UnlimitedInt* num2 = new UnlimitedInt("3");
//     UnlimitedInt* den2 = new UnlimitedInt("9");
//     UnlimitedRational* r2 = new UnlimitedRational(num2,den2);

//     string k3 ="2";
//     UnlimitedInt* num3 = new UnlimitedInt("6");
//     UnlimitedInt* den3 = new UnlimitedInt("4");
//     UnlimitedRational* r3 = new UnlimitedRational(num3,den3);
    
//     string k4 ="1";
//     UnlimitedInt* num4 = new UnlimitedInt("11");
//     UnlimitedInt* den4 = new UnlimitedInt("7");
//     UnlimitedRational* r4 = new UnlimitedRational(num4,den4);
    
    
//     string k5 ="3";
//     UnlimitedInt* num5 = new UnlimitedInt("-9");
//     UnlimitedInt* den5 = new UnlimitedInt("2");
//     UnlimitedRational* r5 = new UnlimitedRational(num5,den5);

//     string k6 ="6";
//     UnlimitedInt* num6 = new UnlimitedInt("9");
//     UnlimitedInt* den6 = new UnlimitedInt("-11");
//     UnlimitedRational* r6 = new UnlimitedRational(num6,den6);


//     table->insert(k1,r1);
//     table->insert(k2,r2);
//     table->insert(k2,r2);
//     table->insert(k3,r3);
//     table->insert(k4,r4);
//     table->insert(k5,r5);
//     table->insert(k6,r6);
//     
//               5
//             /   \
//            2     7  
//           / \    /
//          1   3  6  
//     
//    SymEntry* root  = table->get_root(); 
//    print(root);
//    cout << table->get_size()<< endl;
// //    UnlimitedRational* v= table->search("hello");
//     // cout << v->get_frac_str() << endl;
//     table->remove("51");

//     cout << table->get_size() << endl;

//     cout <<"deleting.." << endl;
//     delete table;
//     cout <<"deleted!" << endl;
// }

