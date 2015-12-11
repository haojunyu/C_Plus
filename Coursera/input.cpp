#include<iostream>

using namespace std;

int main(){
    int i;
    char str[10];
    cout<<(cin>>i)<<endl;
    // 吃掉i后面的换行符
    cin.get();

    // get不会跳过终止符
    
    cin.get(str,10,'e');
    cout<<str<<endl;
    cin.get(str,10,'e');
    cout<<"here:"<<str<<endl;
   

    // getline会跳过终止符
    /*
    cin.getline(str,10,'e');
    cout<<str<<endl;
    cin.getline(str,10,'e');
    cout<<"here:"<<str<<endl;
    */

    return 0;
}
