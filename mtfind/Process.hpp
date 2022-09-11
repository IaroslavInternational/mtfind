#pragma once

#include <vector>
#include <string>
#include <regex>

// ����� ��������� ������ �� �����
class Process
{
public:
	Process(const std::string& adr); // adr - ����� �����
public:
	void Find(const std::string& mask); //����� ������ �� ������� � ������ �����������
private:
	void FindSubStr(size_t id, const std::string& str, const std::string& mask); // ����� ������ � ����� 
	void Search(const std::string& mask);										 // ����� �� ���� �������
private:
	std::vector<std::string>				    lines;		 // ������ �����
	std::vector<std::pair<size_t, std::smatch>> matches;	 // ��������� �������
	size_t										counter = 0; // ���. ����������
};