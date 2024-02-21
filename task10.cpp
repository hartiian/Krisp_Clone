#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::fstream output("example.txt");
    if (!output.is_open()) 
    {
        std::cerr << "Error!\n";
    }
    output << "Arpine\n";
    output << "Anahit\n";
    output << "Astghik\n";
    output << "Emma\n";
    output.close();

    std::fstream input("example.txt");
    if (!input.is_open()) 
    {
        std::cerr << "Error!\n";
    }
	
    std::string name;
    while (std::getline(input, name)) 
    {
        std::cout << name << std::endl;
    }
    input.close();
    return 0; 
}
