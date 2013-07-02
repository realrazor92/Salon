#pragma once
#include "Biblioteki.h"
#include <exception>

class BladWprowadzenia :	public std::exception
{
public:
	virtual const char * what() const throw();
};
