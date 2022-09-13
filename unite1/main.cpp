#include <iostream>
#include "stdio.h"

//c 面向过程
void trace(char* s) {
    printf("%s\n", s);
}

//c++ 面向对象
class Trace {
public:
    Trace(){
        noisy = 0;
        f = stdout;
    }
    Trace(FILE* ff) {
        noisy = 0;
        f = ff;
    }
    void print(char* s) {
        if(noisy) {
            fprintf(f, "%s\n", s);
        }
    }
    void on() {
        noisy = 1;
    }
    void off() {
        noisy = 0;
    }
private:
    int noisy; // 状态信息变量
    FILE* f;
};

void fopen_s(FILE **pFile, const char *string, const char *string1);

int main() {
    std::cout << "Hello, World!" << std::endl;
    trace("hello h1");
    FILE* f;
    fopen_s(&f, "test.txt", "w");
    Trace T(f);
    T.print("hello h2");
    return 0;
}


// 这里不会写
void fopen_s(FILE **pFile, const char *string, const char *string1) {

}
