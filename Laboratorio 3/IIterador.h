#pragma once

template<class T>
class IIterador
{
public:
	virtual bool haySiguiente() = 0;
	virtual T* actual() = 0;
};