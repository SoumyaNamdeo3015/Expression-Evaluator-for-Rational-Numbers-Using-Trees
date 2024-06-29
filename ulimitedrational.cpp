#include "ulimitedrational.h"
// #include<iostream>



UnlimitedInt* copyMagnitude(UnlimitedInt* i1, int sign ){

    int new_size = i1->get_size();
    int* arr = new int[new_size];
    for(int i=0;i<new_size;i++){
        arr[i] = i1->get_array()[i];
    }
    UnlimitedInt* copynum = new UnlimitedInt(arr,new_size,sign,new_size);
    return copynum;
}

UnlimitedInt* copyDelete(UnlimitedInt* i1, int sign){

    int new_size = i1->get_size();
    int* arr = new int[new_size];
    for(int i=0;i<new_size;i++){
        arr[i] = i1->get_array()[i];
    }
    UnlimitedInt* copynum = new UnlimitedInt(arr,new_size,sign,new_size);
    delete i1;
    return copynum;
}

//helper function gcd :
UnlimitedInt* gcd(UnlimitedInt* num, UnlimitedInt* den){

    UnlimitedInt* a = copyMagnitude(num,1);
    UnlimitedInt* b= copyMagnitude(den,1);
   
    while(b->get_array()[0]!=0){
         UnlimitedInt* temp = copyMagnitude(b,1);  //copying b in temp;
         UnlimitedInt* mod= UnlimitedInt::mod(a,b); // mfinding mod; 
         delete b; // deleting b;
         b= copyDelete(mod,1);  //copying mod in b and deleting mod; 
         a = copyDelete(temp,1); //copying temp in a and deleting temp;
    }
    delete b;
    return a;
}

//constructor
 UnlimitedRational::UnlimitedRational(){
    p = NULL;
    q = NULL;
 }
 
 //constructor 
 UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){

    if(num->get_array()[0]==0 && den->get_array()[0]!=0){
        p = new UnlimitedInt("0");
        q =  new UnlimitedInt("1");
        return;
    }

    if(den->get_array()[0]==0){
        p = new UnlimitedInt("0");
        q = new UnlimitedInt("0");
        return;
    }

    UnlimitedInt* a = copyMagnitude(num,1);
    UnlimitedInt* b = copyMagnitude(den,1);
    UnlimitedInt* g = gcd(a,b);
    UnlimitedInt* pdiv = UnlimitedInt::div(a,g);
    UnlimitedInt* qdiv = UnlimitedInt::div(b,g);

    int sign = 1;
    int num_sign = num->get_sign();
    int den_sign  = den->get_sign();

    if(num_sign*den_sign==-1){
        sign = -1;
    }

    p = copyDelete(pdiv,sign);
    q = copyDelete(qdiv,1);

    delete a;
    delete b;
    delete g;
}

 //destructor 
 UnlimitedRational::~UnlimitedRational(){
    string s =get_frac_str();
    delete p;
    delete q;
    // cout << "deleted rational " << s << endl;   
 }

//member function
UnlimitedInt*  UnlimitedRational::get_p(){return p;}

//member function
UnlimitedInt*  UnlimitedRational::get_q(){return q;}

//member function
string  UnlimitedRational::get_p_str(){return p->to_string();} // Return the numerator as a string

//member function
string  UnlimitedRational::get_q_str(){return q->to_string();} // Return the denominator as a string

//member function 
string  UnlimitedRational::get_frac_str(){
    if(p==NULL || q == NULL){
        return "/";
    }
    string s=  p->to_string() +"/"+q->to_string();
    return s;
} // Return the rational as "p/q"

//member function
UnlimitedRational* UnlimitedRational ::add(UnlimitedRational* i1, UnlimitedRational* i2){
    
    UnlimitedInt* num1 = i1->get_p();
    UnlimitedInt* num2 = i2->get_p();
    UnlimitedInt* den1 = i1->get_q();
    UnlimitedInt* den2 = i2->get_q();

    UnlimitedInt* numerator  = UnlimitedInt::add(UnlimitedInt::mul(num1,den2),UnlimitedInt::mul(num2,den1));
    UnlimitedInt* denominator = UnlimitedInt:: mul(den1,den2);

    UnlimitedRational* addition = new UnlimitedRational(numerator,denominator);
    return addition;
}

//member function
UnlimitedRational* UnlimitedRational:: sub(UnlimitedRational* i1, UnlimitedRational* i2){
     UnlimitedInt* num1 = i1->get_p();
    UnlimitedInt* num2 = i2->get_p();
    UnlimitedInt* den1 = i1->get_q();
    UnlimitedInt* den2 = i2->get_q();

    UnlimitedInt* numerator  = UnlimitedInt::sub(UnlimitedInt::mul(num1,den2),UnlimitedInt::mul(num2,den1));
    UnlimitedInt* denominator = UnlimitedInt:: mul(den1,den2);

    UnlimitedRational* subtraction = new UnlimitedRational(numerator,denominator);
    return subtraction;
}


//member function
UnlimitedRational* UnlimitedRational:: mul(UnlimitedRational* i1, UnlimitedRational* i2){
     UnlimitedInt* num1 = i1->get_p();
    UnlimitedInt* num2 = i2->get_p();
    UnlimitedInt* den1 = i1->get_q();
    UnlimitedInt* den2 = i2->get_q();

    UnlimitedInt* numerator  = UnlimitedInt::mul(num1,num2);
    UnlimitedInt* denominator = UnlimitedInt:: mul(den1,den2);

    UnlimitedRational* multiplication = new UnlimitedRational(numerator,denominator);
    return multiplication;
}

//member function
UnlimitedRational*  UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
     UnlimitedInt* num1 = i1->get_p();
    UnlimitedInt* num2 = i2->get_p();
    UnlimitedInt* den1 = i1->get_q();
    UnlimitedInt* den2 = i2->get_q();

    UnlimitedInt* numerator  = UnlimitedInt::mul(num1,den2);
    UnlimitedInt* denominator = UnlimitedInt:: mul(den1,num2);

    UnlimitedRational* division = new UnlimitedRational(numerator,denominator);
    return division;
}

