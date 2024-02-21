#include <iostream>

int main() 
{
    int num = 10;
    int* p = &num;
	int& ref = num;
    std::cout << "Original number is: " << num << std::endl;
    *p = 20;
    std::cout << "After pointed: " << num << std::endl;
    ref = 30;
    std::cout << "After refereced: " << num << std::endl;
    return 0;
}
