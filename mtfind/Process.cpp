#include "Process.hpp"

#include <iostream>
#include <fstream>
#include <thread>

Process::Process(const std::string& adr)
{
    std::ifstream file(adr);
    std::string s;

    while (std::getline(file, s))
    {
        lines.push_back(s);
    }
    
    file.close();
    
    lines.shrink_to_fit();
}

void Process::Find(const std::string& mask)
{
    std::thread th{ &Process::Search, this, mask };
    th.join();

    matches.shrink_to_fit();

    std::cout << matches.size() << std::endl << std::endl;
   
    for (size_t i = 0; i < matches.size(); i++)
    {
        std::cout << matches[i].first + 1 << " " << lines[matches[i].first].find(matches[i].second[0]) + 1 
                  << " " << matches[i].second[0] << std::endl;
    }
}

void Process::FindSubStr(size_t id, const std::string& str, const std::string& mask)
{
    std::string rgx_mask = "";

    for (auto& ch : mask)
    {
        ch == '?' ? rgx_mask += "[0-9A-Za-z]*" : rgx_mask += ch;
    }

    std::regex  rgx{ rgx_mask };
    std::smatch match;
    std::regex_search(str, match, rgx);

    if (match.size() != 0)
    {
        matches.emplace_back(counter, std::move(match));
    }

    counter++;
}

void Process::Search(const std::string& mask)
{
    for (size_t i = 0; i < lines.size(); i++)
    {
        FindSubStr(i, lines[i], mask);
    }
}
