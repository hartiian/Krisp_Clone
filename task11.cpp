#include <iostream>
#include <fstream>
#include <vector>

typedef enum
{
    Bubble,
    Selection
} SortingStrategy;

typedef struct
{
    SortingStrategy str;
    void (*sort)(std::vector<int>&);
} SortingOption;

void bubble(std::vector<int>& arr);
void selection(std::vector<int>& arr);

SortingOption op[] = {
    {Bubble, bubble},
    {Selection, selection}
};

SortingStrategy select()
{
    int choice;
    std::cout << "0 -> Bubble\n";
    std::cout << "1 -> Selection\n";
    std::cin >> choice;
    if (choice)
    {
		return Selection;
    }
    else
    {
		return Bubble;
    }
}

std::vector<int> read(const std::string& name)
{
    std::vector<int> arr;
    std::ifstream input(name);
    if (!input.is_open())
    {
        std::cerr << "Error: " << name << std::endl;
        exit(EXIT_FAILURE);
    }

    int num;
    while (input >> num)
    {
        arr.push_back(num);
    }
    input.close();
    return arr;
}

void save(const std::string& name, const std::vector<int>& arr)
{
    std::ofstream file(name);
    if (!file.is_open())
    {
        std::cerr << "Error: " << name << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int num : arr)
    {
        file << num << " ";
    }
    file.close();
}

void bubble(std::vector<int>& arr) 
{
    bool flag;
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i)
    {
        flag = false;
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

void selection(std::vector<int>& arr) 
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    std::string name;
    std::cout << "Enter filename: ";
    std::cin >> name;
    std::vector<int> arr = read(name);
    SortingStrategy choice = select();
    op[choice].sort(arr);
    std::string output = name;
    save(output, arr);
    std::cout << "Sorted data saved to: " << output << std::endl;
    return 0;
}
