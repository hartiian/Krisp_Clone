//solution1

void content(const char* name) 
{
    std::ifstream file(name, std::ios::binary);
    if (!file.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return;
    }
    char header[44];
    file.read(header, 44);
    int channel = header[22] | (header[23] << 8);
    int rate = header[24] | (header[25] << 8) | (header[26] << 16) |      (header[27] << 24);
    int bit = header[34] | (header[35] << 8);
    int data = header[40] | (header[41] << 8) | (header[42] << 16) | (header[43] << 24);
    std::cout << "Channels are: " << channel << std::endl;
    std::cout << "Rate is: " << rate  << std::endl;
    std::cout << "Bits are: " << bit << std::endl;
    std::cout << "Data is: " << data << std::endl;
    file.close();
}

//solution2

void copy(const char* src, const char* dest) 
{
    std::ifstream src_file(src, std::ios::binary);
    if (!src_file.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return;
    }
    std::ofstream dest_file(dest, std::ios::binary);
    if (!dest_file.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return;
    }
    char header[44];
    src_file.read(header, 44);
    dest_file.write(header, 44);
    std::vector<char> buffer(1024);
    while (!src_file.eof()) 
    {
        src_file.read(buffer.data(), buffer.size());
        std::streamsize byte = src_file.gcount();
        dest_file.write(buffer.data(), byte);
    }
    src_file.close();
    dest_file.close();
}

//solution3

void reverse(const char* name) 
{
    std::ifstream file(name, std::ios::binary);
    if (!file.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return;
    }
    char header[44];
    file.read(header, 44);
    std::vector<char> data;
    char sample[2];
    while (file.read(sample, 2)) 
    {
        data.insert(data.begin(), sample, sample + 2);
    }
    std::ofstream out("reversed_" + std::string(name), std::ios::binary);
    if (!out.is_open()) 
    {
        std::cerr << "Error!" << std::endl;
        return;
    }
    out.write(header, 44);
    for (size_t i = 0; i < data.size(); i += 2) 
    {
        out.write(&data[i], 2);
    }
}
