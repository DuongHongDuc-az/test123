#include<iostream>
using namespace std;
typedef struct{
    int num, denom;
}FRACTION;
void INPUT(FRACTION& A){
    cout << "Input numerator: "; cin >> A.num;
    cout << "Input denominator: "; cin >> A.denom;
}
void OUTPUT(FRACTION A){
    cout << A.num << "/" << A.denom << endl;
}
int GCD(int a, int b){
    if(a==0){
        return b;
    }
    return (b%a, a);
}
void Reduce(FRACTION& A){
    int x = A.num, y = A.denom;
    int tmp = GCD(x, y);
    A.num /=tmp;
    A.denom /=tmp;
}
FRACTION operator + (FRACTION A, FRACTION B){
    FRACTION C;
    C.num = A.num*B.denom + B.num*A.denom;
    C.denom = A.denom*B.denom;
    //Reduce(C);
    return C; 
}
FRACTION operator - (FRACTION A, FRACTION B){
    FRACTION C;
    C.num = A.num*B.denom - B.num*A.denom;
    C.denom = A.denom*B.denom;
    return C; 
}
FRACTION operator * (FRACTION A, FRACTION B){
    FRACTION C;
    C.num = A.num*B.num;
    C.denom = A.denom*B.denom;
    return C;    
}
FRACTION operator / (FRACTION A, FRACTION B){
    FRACTION C;
    C.num = B.denom;
    C.denom = B.num;
    FRACTION D = A*C;
    return D; 
}
bool operator == (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    if(A.num==B.num && B.denom == A.denom){
        return true;
    }   
    return false;
}
bool operator != (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    if(!(A==B)){
        return true;
    }   
    return false;
}
bool operator > (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    FRACTION C = A-B;
    if(C.num>0){
        return true;
    }   
    return false;
}
bool operator >= (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    FRACTION C = A-B;
    if(C.num>=0){
        return true;
    }   
    return false;
}
bool operator < (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    FRACTION C = A-B;
    if(C.num<0){
        return true;
    }   
    return false;
}
bool operator <= (FRACTION A, FRACTION B){
    Reduce(A);
    Reduce(B);
    FRACTION C = A-B;
    if(C.num<=0){
        return true;
    }   
    return false;
}
void operator += (FRACTION& A, FRACTION B){
    FRACTION C = A+B;
    A = C;
}       
void operator -= (FRACTION& A, FRACTION B){
    FRACTION C = A-B;
    A = C;
}  
void Process(FRACTION& A, FRACTION& B){
    cout << "Input first fraction: " << endl;
    INPUT(A);
    cout << "Input second fraction: " << endl;
    INPUT(B);
    cout << "Sum = ";
    OUTPUT(A+B);
    cout << "Difference = ";
    OUTPUT(A-B);    
    cout << "Accumulation = ";
    OUTPUT(A*B);
    cout << "Quotient = ";
    OUTPUT(A/B);
    if(A==B){
        cout << "A=B" << endl;
    }
    if(A!=B){
        cout << "A!=B" << endl;
    }
    if(A>B){
        cout << "A>B" << endl;
    }
    if(A<B){
        cout << "A<B" << endl;
    }
    if(A>=B){
        cout << "A>=B" << endl;
    }
    if(A<=B){
        cout << "A<=B" << endl;
    }
    A +=B;
    OUTPUT(A);
    A -=B;
    OUTPUT(A);
}
int main(){
    FRACTION A, B;
    Process(A, B);
    return 0;
}