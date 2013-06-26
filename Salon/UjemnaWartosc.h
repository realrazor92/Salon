#pragma once
#include "Biblioteki.h"
#include <exception>

class UjemnaWartosc : public std::exception
{
public:
	virtual const char * what() const throw();
};
