#include <bits/stdc++.h>  
int main() {  
    int a, b;  
    std::cin >> a >> b;  
    std::cout << a << "+" << b << "=" << a + b << "\n";  
    std::cout << a << "*" << b << "=" << a * b << "\n";  
    std::cout << a << "-" << b << "=" << a - b << "\n";  
    int c = a % b;  
    if (c < 0) {  
        std::cout << a << "/" << b << "=" << a / b - 1 << "..." << a % b + b << "\n";  
    } else {  
        std::cout << a << "/" << b << "=" << a / b << "..." << a % b << "\n";  
    }  
    return 0;  
}  