#pragma once
#include "Biblioteki.h"
#include <exception>

class BlednaWartosc :	public std::exception
{
public:
	virtual const char * what() const throw();
};
