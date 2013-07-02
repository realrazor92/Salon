#pragma once
#include "Biblioteki.h"
#include <exception>

class BlednyIndeks :	public std::exception
{
public:
	virtual const char * what() const throw();
};
