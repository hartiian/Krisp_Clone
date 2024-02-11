//solution1

void write(std::string name, std::string text)
{
    std::ofstream output(name);
    if (output.is_open()) 
	{
        output << text;
        output.close();
        std::cout << "Text written to file." << std::endl;
    } 
	else 
	{
        std::cerr << "Error!" << std::endl;
    }
}

//solution2

void read(std::string name) 
{
    std::ifstream input(name);
    if (input.is_open()) 
	{ 
        std::string line;
        while (std::getline(input, line)) 
		{
            std::cout << line << std::endl; 
        }
        input.close(); 
    } 
	else 
	{
        std::cerr << "Error!" << std::endl;
    }
}

//solution3

void delete(std::string name) 
{
    std::ifstream input(name);
    if (input.is_open()) 
    {
        std::string line;
        std::ofstream temp("example.txt");
        bool delete_f = false;
        while (std::getline(input, line)) 
		{
            if (!delete_f) 
	    	{
                temp << line << std::endl;
            }
            delete_f = !delete_f; 
		}
        input.close();
        temp.close(); 
        std::remove(name.c_str());
        std::rename("example.txt", name.c_str());
		std::cout << "Every 2 line deleted." << std::endl;
    } 
    else 
    {
        std::cerr << "Error!" << std::endl;
    }
}

//solution4

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end; 
		*end = tmp;
		start++;
		end--;
	}
}

void reverse_words(char* arr)
{
	int len = strlen(arr);
	reverse(arr, arr + len - 1);
	char* start = arr;
	char* end = arr;
	while (*start)
	{
		while(*end && *end != ' ')
		{
			end++;
		}
		reverse(start, end - 1);
		if (*end == ' ')
		{
			end++;
		}
		start = end;
	}
}
