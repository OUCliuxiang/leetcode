#include <string> 
#include <cstdio>
#include <iostream>
#include <algorithm>

int main(){
    std::string str = "this is a sentence";
    std::reverse(str.begin(), str.begin()+4);
    printf("%s\n", str.c_str());
    return 0;
}