#include <iostream> 
#include<algorithm>
using namespace std; 
int main() 
{ 
    string str; 
  	cin>>str;
    // Reverse str[begin..end] 
    reverse(str.begin(), str.end()); 
    cout << str; 
    return 0; 
} 
