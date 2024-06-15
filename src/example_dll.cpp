#include <iostream>

extern "C" __declspec(dllexport) int __stdcall Add(int a, int b) {
    return a + b;
}

extern "C" __declspec(dllexport) int __stdcall Mult(int a, int b) {
    return a * b;
}

extern "C" __declspec(dllexport) int __stdcall Sqrt(int a) {
    return std::sqrt(a);
}

extern "C" __declspec(dllexport) void __stdcall Print(const char* message) {
    std::cout << message << std::endl;
}
