#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void ReadFile(const std::string& adr, std::vector<std::string>* lines)
{
    std::ifstream file(adr); 
    std::string s;

    while (std::getline(file, s)) 
    { 
        lines->push_back(s);
    }

    file.close();

    lines->shrink_to_fit();
}

int main(int argc, char* argv[])
{   
    std::vector<std::string> lines;

    ReadFile(argv[1], &lines);

    for (auto& s : lines)
    {
        std::cout << s << std::endl;
    }

    return 0;
}