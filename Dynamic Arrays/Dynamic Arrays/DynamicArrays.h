#ifndef __DTYNAMICARRAYS_H__
#define __DYNAMICARRAYS_H__

#include <iostream>
#include <assert.h>
using namespace std;
#define MIN_ARRAY_BLOCK_SIZE 10

template<class Type>
class DynArray
{
public:

	DynArray();
	DynArray(unsigned int memSize);
	~DynArray();

	bool empty() const;
	unsigned int size() const;

	bool insert(unsigned int index, const Type& elem);
	bool remove(unsigned int index);

	Type& operator[] (unsigned int index) const;
	void shrinkToFit();

	void print() const;

private:

	void allocMem(unsigned int memSize);

	Type* arrayElems;
	unsigned int memSize;
	unsigned int numElems;

};

#endif // !__DYNAMICARRAYS_H__

template<class Type>
DynArray<Type>::DynArray()
{
	allocMem(MIN_ARRAY_BLOCK_SIZE);
	memSize = MIN_ARRAY_BLOCK_SIZE;
	numElems = 0;
}

template<class Type>
DynArray<Type>::DynArray(unsigned int memSize)
{
	allocMem(memSize);
	this->memSize = memSize;
	numElems = 0;
}

template<class Type>
DynArray<Type>::~DynArray()
{
	delete arrayElems;
}

template<class Type>
bool DynArray<Type>::empty() const
{
	return numElems == 0;
}

template<class Type>
unsigned int DynArray<Type>::size() const
{
	return numElems;
}

template<class Type>
bool DynArray<Type>::insert(unsigned int index, const Type & elem)
{
	bool result = false;
	if (index >= memSize)
	{
		Type* temp = arrayElems;
		allocMem(memSize + MIN_ARRAY_BLOCK_SIZE);
		for (int i = 0; i < numElems; i++)
		{
			arrayElems[i] = temp[i];
		}
		delete temp;
	}
	if (index <= numElems)
	{
		if (index != numElems)
		{
			for (int i = numElems; i > index; i--)
			{
				arrayElems[i] = arrayElems[i - 1];
			}
		}
		arrayElems[index] = elem;
		numElems++;
		result = true;
	}

	return result;
}

template<class Type>
bool DynArray<Type>::remove(unsigned int index)
{
	bool result = false;
	if (index <= numElems)
	{
		for (int i = index; i < numElems - 1; i++)
		{
			arrayElems[i] = arrayElems[i + 1];
		}
		numElems--;
		result = true;
	}
	return result;
}

template<class Type>
Type & DynArray<Type>::operator[](unsigned int index) const
{
	assert(index < numElems);
	return arrayElems[index];
}

template<class Type>
void DynArray<Type>::shrinkToFit()
{
	if (numElems < memSize)
	{
		Type* temp = arrayElems;
		allocMem(numElems);
		for (int i = 0; i < numElems; i++)
		{
			arrayElems[i] = temp[i];
		}
		delete temp;
	}
}

template<class Type>
void DynArray<Type>::print() const
{
	for (int i = 0; i < numElems; i++)
	{
		cout << arrayElems[i];
	}
	cout << endl;
}

template<class Type>
void DynArray<Type>::allocMem(unsigned int memSize)
{
	arrayElems = new Type[memSize];
	this->memSize = memSize;
}
