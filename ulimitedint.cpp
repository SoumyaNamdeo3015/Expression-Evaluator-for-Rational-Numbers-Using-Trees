
#include "ulimitedint.h"
// #include <iostream>

//helper function division with 10 
UnlimitedInt* divideBy10(UnlimitedInt*num){

    int*arr = num->get_array();
    int size = num->get_size();

    if(size==1){
        int*temp_arr = new int[1];
        temp_arr[0]=0;
        UnlimitedInt* zero = new UnlimitedInt(temp_arr,1,1,1);
        return zero;
    }

    int*temp_arr = new int[size-1];
    for(int i=0;i<size-1;i++){
        temp_arr[i] = arr[i];
    }   
    UnlimitedInt* by10 =new UnlimitedInt(temp_arr,size-1,1,size-1);
    return by10;
}

//helper function add trailing zeros 
int* addTrailingZeros(int*arr, int size, int n, int&updatesize){
    int size1 = size;
    int newsize = size1+n;
    int* newarr= new int[newsize];
    int i=0;
    int j=0;
    while(i<size1){
        newarr[j++] =arr[i++];
    }    
    while(j<newsize){
        newarr[j++] = 0;
    }
    updatesize = newsize;
    return newarr;
}

// helper function : modify array
int *modify_arr(int *sub_arr, int &size){

    int count = 0;
    int index = 0;
    while (sub_arr[index] == 0)
    {
        count++;
        index++;
    }
    int *new_sub_arr = new int[size - count];
    int j = 0;
    int i = index;
    while (i < size)
    {
        new_sub_arr[j++] = sub_arr[i++];
    }
    size = size - count;
    delete[] sub_arr;
    return new_sub_arr;
}

//helper function : reverse array 
void reverseArray(int *array, int size){
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        swap(array[i], array[j]);
        i++;
        j--;
    }
    return;
}

// helper function : check which number is greater
int isGreater(UnlimitedInt *num1, UnlimitedInt *num2){

    // signs will be dealt while using the functions //
    // this function has 3 outputs  : if num1>num2 then it returns 1
    //                                if num2>num1 then it returns 0
    //                                if num1=num2 then it returns -1

    int size1 = num1->get_size();
    int size2 = num2->get_size();

    int *number1 = num1->get_array();
    int *number2 = num2->get_array();

    if (size1 > size2)
    {
        return 1;
    }

    if (size1 < size2)
    {
        return 0;
    }

    if (size1 == size2)
    {

        for (int i = 0; i < size1; i++)
        {
            int digit1 = number1[i];
            int digit2 = number2[i];
            // cout <<  "d1"<<digit1 << " " << "d2"<<  digit2 << endl;
            if (digit1 > digit2)
            {
                return 1;
            }
            if (digit1 < digit2)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
    }
    return -1;
}

// helper function addition
int *returnSumAdditive(int *arr1, int size1, int *arr2, int size2, int&newsize){

    // my size1 >= size2 :
    // arr1  : 1 2 3 4 5
    // arr2   :    3 4 5

    int sum_size = max(size1, size2) + 1;
    int *sum_arr = new int[sum_size];
    int sum_index = 0;

    int upperindex = size1 - 1;
    int lowerindex = size2 - 1;
    int carry = 0;

    while (lowerindex >= 0)
    {
        int num1 = arr1[upperindex];
        int num2 = arr2[lowerindex];
        int temp = num1 + num2 + carry;
        int sum = temp % 10;
        sum_arr[sum_index++] = sum;
        carry = (temp - sum) / 10;
        upperindex--;
        lowerindex--;
    }

    while (upperindex >= 0)
    {
        int temp = carry + arr1[upperindex];
        int sum = temp % 10;
        carry = (temp - sum) / 10;
        sum_arr[sum_index++] = sum;
        upperindex--;
    }

    sum_arr[sum_index++] = carry;
    newsize = sum_index;

    int i = 0;
    int j = sum_size - 1;
    while (i <= j)
    {
        swap(sum_arr[i], sum_arr[j]);
        i++;
        j--;
    }

    // modifying the array if last carry was 0;
    if (sum_arr[0] == 0)
    {

       int* newarr = new int[newsize-1];
        int j =0;
        for(int i=1;i<newsize;i++){
            newarr[j++] = sum_arr[i];        
        }
        newsize= newsize-1;
        delete []sum_arr;
        return newarr;


    }

    return sum_arr;
}

// helper function bigger- smaller
int *returnSubtract(int *s1, int size1, int *s2, int size2, int &newsize){
    // my size1 >= size2 :
    // arr1  : 1 2 3 4 5
    // arr2   :    3 4 5
    int sub_arr_size = max(size1, size2);
    int *sub_arr = new int[sub_arr_size]; // declaring temp array of max(size1,size2) size;
    int mainindex = sub_arr_size - 1;
    int upperindex = size1 - 1;
    int lowerindex = size2 - 1;

    while (lowerindex >= 0)
    {
        int digit1 = s1[upperindex];
        int digit2 = s2[lowerindex];
        int difference = digit1 - digit2;
        sub_arr[mainindex--] = difference;
        lowerindex--;
        upperindex--;
    }

    while (upperindex >= 0)
    {
        int digit1 = s1[upperindex];
        sub_arr[mainindex--] = digit1;
        upperindex--;
    }

    
    int count = 0;
    for (int i = sub_arr_size - 1; i >= 0; i--)
    {

        if (sub_arr[i] >= 0)
        {
            if (count != 0)
            {
                sub_arr[i] = sub_arr[i] - 1;
            }
           
            count = 0;
        }

        if (sub_arr[i] < 0)
        {
           
            count++;
            if (count == 1)
            {
                sub_arr[i] = sub_arr[i] + 10;
            }

            else
            {
                sub_arr[i] = sub_arr[i] + 9;
            }
        }
    }

    newsize = sub_arr_size;
    int *new_sub_arr = modify_arr(sub_arr, newsize);
    return new_sub_arr;
}

// helper function multiply with single digit 
int* multiplicationSingleDigit(int* arr, int size, int digit, int&newsize){
//returns string when numbers of arr are multiplied by this digit;
    newsize= size+1;
    int* ans;
    
    
    if(digit==0){
        ans= new int[1];
        ans[0]= 0;
        newsize = 1;
       return ans;
    }

      ans = new int[newsize];
      int carry =0;
      int j= newsize-1;
      for(int i=size-1;i>=0;i--){

        int temp = arr[i]*(digit) + carry;
        int product = temp%10;
        ans[j--]= product;
        carry = (temp-product)/10;
        

    }
    
    ans[0]= carry;
    if(carry==0){
        newsize= size;
        // ans = ans+1;
        int* newarr = new int[newsize];
        int index=0;
        for(int i=1;i<size+1;i++){
            newarr[index++] = ans[i];
        }

        delete ans;
        return newarr;
    
    }
    
    return ans;
}

// helper function 
int* returnMultiplication(UnlimitedInt* i1, UnlimitedInt* i2, int&mul_size){

    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int size1 = i1->get_size();
    int size2 = i2->get_size();


    UnlimitedInt* product = new UnlimitedInt("0");

   int trailing_count =0;
    for(int i=size2-1; i>=0; i--){
        int digit = arr2[i];
        int newsize=0;

        int* singleProduct = multiplicationSingleDigit(arr1,size1,digit,newsize);
        int* temparr = singleProduct;
        singleProduct = addTrailingZeros(singleProduct,newsize,trailing_count,newsize);
        delete temparr;
        
        trailing_count++;
        int capacity = newsize;
        UnlimitedInt* integer = new UnlimitedInt(singleProduct,capacity,1,newsize);
        // cout << "adding"<< endl;

       UnlimitedInt* temp = product;
        product =product->add(product,integer);
       delete temp;
       
        delete integer;
        // cout << "deleted"<<endl;

    }

    int* ans  = product->get_array();
    mul_size = product->get_size();
    int* prd = new int[mul_size];
   
    for(int i=0;i<mul_size;i++){
        prd[i] = ans[i];
        
    }

    delete product;
    return prd;
}

//helper function : division

int* returnDivide(UnlimitedInt*i1, UnlimitedInt*i2, int&new_size, UnlimitedInt*&mod){

        
    //initials

    if(isGreater(i1,i2)==0){
        int* arr = new int[1];
        arr[0]=0;
        new_size = 1;

        int mod_size = i1->get_size();
        int*mod_arr = new int[mod_size];
        for(int i=0;i<mod_size;i++){
            mod_arr[i] = i1->get_array()[i];
        }

        mod = new UnlimitedInt(mod_arr,mod_size,1,mod_size);
        return arr;
    };


    int size1 = i1->get_size();
    int size2 = i2->get_size();
    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int* div_arr;
    int div_arr_size;

    //creating temp array
    int zero_count = size1-size2;

    int temp_size = 0;
    int* temp = addTrailingZeros(arr2,size2,zero_count,temp_size);
    UnlimitedInt* newint = new UnlimitedInt(temp,temp_size,1,temp_size);

    if(isGreater(i1,newint)==0){
        //changed
        UnlimitedInt*b = newint;
        newint = divideBy10(newint);
        delete b;

    }



    int*i1_copy_arr = new int[size1];
    for(int i=0;i<size1;i++){
        i1_copy_arr[i] = arr1[i];
    }
    // cout<<"copied" << endl;
    UnlimitedInt* i1_copy_number = new UnlimitedInt(i1_copy_arr,size1,1,size1);
    UnlimitedInt* temp_number =newint; 


    int*ans_arr = new int[size1];
    int ans_size =0;

    // changed
    while(isGreater(temp_number,i2)!=0){
        int temp_count =0;
        //changed
        while(isGreater(i1_copy_number,temp_number)!=0){

            UnlimitedInt*b = i1_copy_number;
            i1_copy_number = UnlimitedInt::sub(i1_copy_number,temp_number);
            delete b;

            temp_count++;
        }
        ans_arr[ans_size++] =temp_count;

        UnlimitedInt*b = temp_number;
        temp_number = divideBy10(temp_number);
        delete b;

    }


    mod = i1_copy_number;

    div_arr= new int[ans_size];
    for(int i=0;i<ans_size;i++){
        div_arr[i] = ans_arr[i];
      
    }

   

    div_arr_size = ans_size;
    new_size = div_arr_size;

    delete []ans_arr;
    return div_arr;
}

// helper function mod:
UnlimitedInt* quickMod(UnlimitedInt*num1, UnlimitedInt* num2){

    if(num2->get_array()[0]==0){
        // cout << "mod with 0 error" << endl;
        return NULL;
    }

    UnlimitedInt*mod = new UnlimitedInt();
    int newsize =0;
    int*div_arr= returnDivide(num1,num2,newsize,mod);
    delete div_arr;
    return mod;
}

// constructor
UnlimitedInt ::UnlimitedInt(){
    // size = 1;
    // unlimited_int = new int[1];
    // unlimited_int[0]= -1;
    // capacity = 1;
    // sign = 1;
    size =0;
    unlimited_int = NULL;
    capacity =0;
    sign = 1;
}

// Create from string
UnlimitedInt::UnlimitedInt(string s){

    sign = 1;
    if (s[0] == '-')
    {
        s.erase(0, 1);
        sign = -1;
    }
    if (s[0] == '+')
    {
        s.erase(0, 1);
    }
    capacity = s.size();
    int *newarr = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        newarr[i] = s[i] - '0';
    }
    unlimited_int = newarr;
    size = capacity;
}

// Create from int
UnlimitedInt ::UnlimitedInt(int i){
    capacity = 12;
    sign = 1;
    if (i < 0)
    {
        sign = -1;
        i = -i;
    }
    // intitializing the array
    int *number_array = new int[capacity];
    unlimited_int = number_array;
    // inserting digits in the array
    size = 0;
    int number = i;
    int index = 0;

    if (number == 0)
    {
        size = 1;
        unlimited_int[0] = 0;
        return;
    }
    while (number != 0)
    {
        int digit = number % 10;
        unlimited_int[index++] = abs(digit);
        number = number / 10;
        size++;
    }
    reverseArray(unlimited_int, size);
}

// Complete constructor
UnlimitedInt::UnlimitedInt(int *ulimited_int, int cap, int sgn, int sz){
    int* newarr = new int[sz];
    for(int i=0;i<sz;i++){
        newarr[i] = ulimited_int[i];
    }
    unlimited_int = newarr;
    capacity = sz;
    sign = sgn;
    size = sz;
}

// destructor
UnlimitedInt ::~UnlimitedInt(){
    if(unlimited_int!=NULL){
    delete []unlimited_int;
    }
}

// member function
int UnlimitedInt::get_size(){
    return size;
}

// member function
int UnlimitedInt::get_capacity(){
    return capacity;
}

// member function
int *UnlimitedInt ::get_array(){
    return unlimited_int;
}

// member function
int UnlimitedInt::get_sign(){
    return sign;
}
// member function
string UnlimitedInt ::to_string(){
    if (this == NULL)
    {
        return "";
    }
    string num_string = "";
    if (sign == -1)
    {
        num_string += '-';
    }
    for (int i = 0; i < size; i++)
    {
        num_string += unlimited_int[i] + '0';
    }
    return num_string;
}

//member function
UnlimitedInt *UnlimitedInt::add(UnlimitedInt *i1, UnlimitedInt *i2){

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    int *arr1 = i1->get_array();
    int *arr2 = i2->get_array();
    int size1 = i1->get_size();
    int size2 = i2->get_size();
    int sign = 1;
    int *sum_arr;
    int sum_arr_size = 0;
    int capacity =0;

    if (sign1 * sign2 == 1)
    {
        if (sign1 == 1 && sign2 == 1)
        {
            if (size1 >= size2)
            {
                sum_arr = returnSumAdditive(arr1, size1, arr2, size2, sum_arr_size);
            }
            else
            {
                sum_arr = returnSumAdditive(arr2, size2, arr1, size1, sum_arr_size);
            }
            sign = 1;
        }

        if (sign1 == -1 && sign2 == -1)
        {

            if (size1 >= size2)
            {
                sum_arr = returnSumAdditive(arr1, size1, arr2, size2, sum_arr_size);
            }
            else
            {
                sum_arr = returnSumAdditive(arr2, size2, arr1, size1, sum_arr_size);
            }
            sign = -1;
        }

        capacity = sum_arr_size;
      
        UnlimitedInt *addition = new UnlimitedInt(sum_arr, capacity, sign, sum_arr_size);
        // return addition;
        return addition;
    }

    // + addtion with -
    int*difference;
    sign = 1;
    int newsize=0;

    int*s1 = i1->get_array();
    int* s2 = i2->get_array();
    
    int checker = isGreater(i1,i2);
    if(sign1 == 1 && sign2 == -1){

        if(checker == 1){
            difference = returnSubtract(s1,size1,s2,size2,newsize); //i1>i2
            sign = 1;
        }

        if(checker ==0 ){
            //i2>i1
            difference = returnSubtract(s2,size2,s1,size1,newsize);
            sign =-1;
        }

       if(checker==-1){
        difference = new int[1];
        difference[0] = 0;
        sign =1;
        newsize =1;
       }
    }

    if(sign1 == -1 && sign2 == 1){

        if(checker == 1){
            difference = returnSubtract(s1,size1,s2,size2,newsize); //i1>i2
            sign = -1;
        }

        if(checker ==0 ){
            //i2>i1
            difference = returnSubtract(s2,size2,s1,size1,newsize);
            sign =1;
        }

       if(checker==-1){
        difference = new int[1];
        difference[0] = 0;
        sign =1;
        newsize =1;
       }
    }

    capacity = newsize;
    UnlimitedInt* additionSubtractive = new UnlimitedInt(difference,capacity,sign,newsize);
    return additionSubtractive;
    
}

//member function
UnlimitedInt *UnlimitedInt ::sub(UnlimitedInt *i1, UnlimitedInt *i2){

    int size1 = i1->get_size();
    int size2 = i2->get_size();
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    int *num1 = i1->get_array();
    int *num2 = i2->get_array();
    int sign = 1;
    int *difference;
    int newsize = 0; 

    if (sign1 * sign2 == 1){

        int checker = isGreater(i1, i2);

        if (sign1 == 1 && sign2 == 1)
        {

            if (checker == 1)
            {
                // i1>i2 magnitude
                sign = 1;
                difference = returnSubtract(num1, size1, num2, size2, newsize);
            }

            if (checker == 0)
            {
                // i2>i1 magnitude
                sign = -1;
                difference = returnSubtract(num2, size2, num1, size1, newsize);
            }

            if (checker == -1)
            {
                // i1 == i2
                sign = 1;
                difference = new int[1];
                difference[0]=0;
                newsize = 1;
            }
        }

        if (sign1 == -1 && sign2 == -1)
        {

            if (checker == 1)
            {
                // i1>i2 magnitude
                sign = -1;
                difference = returnSubtract(num1, size1, num2, size2, newsize);
            }

            if (checker == 0)
            {
                // i2>i1 magnitude
                sign = 1;
                difference = returnSubtract(num2, size2, num1, size1, newsize);
            }

            if (checker == -1)
            {
                // i1 == i2
                sign = 1;
                difference = new int[1];
                difference[0] = 0;
                newsize = 1;
            }
        }

        int capacity = newsize;
        UnlimitedInt *subtraction = new UnlimitedInt(difference, capacity, sign, newsize);
        return subtraction;
    }

     int*s1 = i1->get_array();
    int* s2 = i2->get_array();
   
    
    int checker = isGreater(i1,i2);

    if(sign1 == 1 && sign2 == -1){

        if(checker == 1){
            difference = returnSumAdditive(s1,size1,s2,size2,newsize); //i1>i2
            sign = 1;
        }

        if(checker ==0 ){
            //i2>i1
            difference = returnSumAdditive(s2,size2,s1,size1,newsize);
            sign =1;
        }

       if(checker==-1){
        difference = returnSumAdditive(s1,size1,s2,size2,newsize);
        sign = 1;
       }
    }

    if(sign1 == -1 && sign2 == 1){

        if(checker == 1){
            difference = returnSumAdditive(s1,size1,s2,size2,newsize); //i1>i2
            sign = -1;
        }

        if(checker ==0 ){
            //i2>i1
            difference = returnSumAdditive(s2,size2,s1,size1,newsize);
            sign =-1;
        }

       if(checker==-1){
        difference = returnSumAdditive(s1,size1,s2,size2,newsize);
        sign =-1;
       }
    }

    int capacity = newsize;
    
    UnlimitedInt* additionSubtractive = new UnlimitedInt(difference,capacity,sign,newsize);
    return additionSubtractive;


}

//member function
UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    int sign =1;
    int*ans;
    int cap=0;
    int newsize=0;

    if((i1->get_size()==1 && i1->get_array()[0]==0) || (i2->get_size()==1 && i2->get_array()[0]==0)){
        ans = new int[1];
        ans[0]=0;
        sign = 1;
        newsize =1;
        cap = 1;
        UnlimitedInt* prd = new UnlimitedInt(ans,cap,sign,newsize);
        return prd;  
    }


    

    if(sign1*sign2 == 1){
        
        ans=  returnMultiplication(i1,i2,newsize);
        cap = newsize;
        sign =1;
    }

    else{
        
        ans = returnMultiplication(i1,i2,newsize);
        cap= newsize;
        sign = -1;
    }

    UnlimitedInt* multiplication = new UnlimitedInt(ans,cap,sign,newsize);
    return multiplication;
}

//member function

UnlimitedInt* UnlimitedInt :: div(UnlimitedInt*i1, UnlimitedInt*i2){  
    // divide function  

    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int sign1 = i1->get_sign();
    int sign2  = i2->get_sign();

    int sign =1;
    UnlimitedInt* mod = new UnlimitedInt();

    if(arr1[0]==0 && arr2[0]!=0){
        UnlimitedInt* zero = new UnlimitedInt("0");
        return zero;
    }

    if(arr2[0]==0){
        // cout <<"division with zero error" << endl;
        return NULL;
    }

    if(sign1*sign2==1){
        int new_size =0;
        int* div_arr = returnDivide(i1,i2,new_size,mod);
        UnlimitedInt* dvision = new UnlimitedInt(div_arr,new_size,sign,new_size);
        return dvision;
    }


    if(sign1*sign2 == -1){
        sign = -1;
        int new_size =0;
        int* div_arr = returnDivide(i1,i2,new_size,mod);
        UnlimitedInt* one = new UnlimitedInt("1");
        
        if(div_arr[0]==0){
                // -1/2 : ex
                UnlimitedInt* negone = new UnlimitedInt("-1");
                return negone;
                
        }

        mod = quickMod(i1,i2);
       
        UnlimitedInt* div =  new UnlimitedInt(div_arr,new_size,sign,new_size);
        if(mod->get_array()[0]==0){
            return div;
         }
        
        UnlimitedInt* floor_div = UnlimitedInt::sub(div,one);
        delete div;
        return floor_div;

    }
    return NULL;
}


//member function 
UnlimitedInt* UnlimitedInt :: mod(UnlimitedInt*i1, UnlimitedInt*i2){

    if(i2->get_array()[0]==0){
        // cout <<"mod by 0 error" << endl;
        return NULL;
    }

    if(i1->get_array()[0] == 0){
        UnlimitedInt* zero = new UnlimitedInt("0");
        return zero;
    }

    
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    if(sign1 == 1 && sign2 == 1){

        UnlimitedInt*mod = quickMod(i1,i2);
        return mod;

    }

    UnlimitedInt* remainder = UnlimitedInt::sub(i1,UnlimitedInt::mul(i2,UnlimitedInt::div(i1,i2)));
    return remainder;
}
// think about capacity for all of the constructors cap == size 
