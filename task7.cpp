#include <iostream>

typedef void(*sort)(int*, int);

void bubble(int* arr, int size) 
{
	bool flag;
    for (int i= 0; i < size - 1; ++i)
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

void selection(int* arr, int size) 
{
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

sort get() 
{
    int choice;
    std::cout << "0 -> Bubble\n";
    std::cout << "1 -> Selection\n";
    std::cin >> choice;
    if (choice)
	{
		return selection;
	}
	else
	{
		return bubble;
	}
}

void print(int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int arr[] = {5, 2, 71, 1, 97, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort choice = get();
    choice(arr, size);
    print(arr, size);
    return 0;
}
