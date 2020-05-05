#include <string.h>
#include <cstring>
#include <sys/stat.h>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

string rand_string(const int len) {
    srand(time(NULL));
    const char alphanumerical[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    string st;
    int length = sizeof(alphanumerical) - 1;
    for (int i = 0; i < len; ++i) {
            st += alphanumerical[rand() % length];
        }

    return st;
}

inline bool fexists(const string& name) {
  struct stat buffer;   
  return (stat(name.c_str(), &buffer) == 0); 
}

char* empty_charr(char* arr) {
    for (int i = 0; i < sizeof(arr); i++)
        arr[i] = '\0';
    return arr;
}