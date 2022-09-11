#pragma once

#include <vector>
#include <string>
#include <regex>

// Класс проргаммы поиска по маске
class Process
{
public:
	Process(const std::string& adr); // adr - адрес файла
public:
	void Find(const std::string& mask); //Метод поиска по строкам и вывода результатов
private:
	void FindSubStr(size_t id, const std::string& str, const std::string& mask); // Метод поиска в сроке 
	void Search(const std::string& mask);										 // Поиск по всем строкам
private:
	std::vector<std::string>				    lines;		 // Строки файла
	std::vector<std::pair<size_t, std::smatch>> matches;	 // Результат поисков
	size_t										counter = 0; // Всп. переменная
};