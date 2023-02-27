#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    char cch;
    char ch; 
    unsigned seed= time(0)
    srand(seed)
    cch = 'a' + rand()%26;
    ch=cch;
    cout<<"computer chose "<< ch<<endl;
} 	
