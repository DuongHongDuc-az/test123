#include<iostream>
#include<vector>
using namespace std;
void intarrayInput(vector<int>& a, int elemnts[], int n){
    int i =0;
    a.resize(n);
    while(i<n){
        a.push_back(elemnts[i]);
        i++;
    }
}
void intarrayOutput(vector<int>& a, ostream& outDev){
    for(int i=0;i<a.size();i++){
        outDev << a[i] << " ";
    }
    outDev << endl;
}
void intarrayCat(vector<int>&a, vector<int>& b){
    int size1 = a.size(), size2 = b.size();
    int newsize = size1 + size2;
    int i = 0;
    int idx = size1;
    a.resize(newsize);
    while(i<size2){
        a[idx] = b[i]; 
        idx++;
        i++; 
    }
}
void intarrayCutForm(vector<int>& a, vector<int>& b, int pos){
    int size = a.size(), j = pos;
    if(j<0 || j>=size){
        return;
    }
    while(j<size){
        b.push_back(a[j]);
        j++;
    }
    a.resize(pos);
}
void intarrayInsert(vector <int>& a, vector<int>& b, int pos, int element){
    if(pos<0 || pos>a.size()){
        return;
    }
    intarrayCutForm(a, b, pos);
    a.push_back(element);
    intarrayCat(a, b);
}
int main(){
    int x[] = {3, 5, 2, 4, 9, 7, 8 ,6};
    int n = sizeof
}
