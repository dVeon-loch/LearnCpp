#pragma once

#include <iostream>
#include <string>


class Book
{
public:
	std::string m_title = "";


	Book()=default;
	Book(std::string title):m_title(title)
	{}
};

