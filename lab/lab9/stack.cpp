
#include "stack.h"


std::string Stack::get_palindrome(std::string str){  
std::stack<char> s;
std::string palin = "";
for(int i = 0; i < str.size(); ++i){
s.push(str[i]);
}
while(!s.empty()){
palin += s.top();
s.pop();
}
return palin;
}
