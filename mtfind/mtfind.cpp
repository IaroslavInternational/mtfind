#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

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

void FindSubStr(size_t id, const std::string& str, const std::string& mask)
{
    std::string rgx_mask = "";

    for (auto& ch : mask)
    {
        ch == '?' ? rgx_mask += "[0-9A-Za-z]*" : rgx_mask += ch;
    }

    std::regex  rgx{ rgx_mask };
    std::smatch res;
    std::regex_search(str, res, rgx);
    
    std::cout << id + 1 << " " << str.find(res[0]) + 1 << " " << res[0] << std::endl;
}

int main(int argc, char* argv[])
{   
    std::vector<std::string> lines;
    
    ReadFile(argv[1], &lines);
    
    for (size_t i = 0; i < lines.size(); i++)
    {
        FindSubStr(i, lines[i], argv[2]);
    }

    return 0;
}