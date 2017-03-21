#include "Matricula.h"
#include <math.h>

void int_to_char(char* str, int num, int length)
{
	int result;

	for (int i = 0; i < length; i++)
	{
		result = num;
		result /= pow(10.0, (length - 1 - i));
		str[i] = result + 48;
		num -= result * pow(10.0, (length - 1 - i));
	}
	str[length] = '\0';
}

Matricula::Matricula() : nums(9999), string("ZZZ")
{
	int_to_char(nums_c, nums, 4);
}

Matricula::Matricula(int num, char* str): nums(num), string(str)
{
	int_to_char(nums_c, nums, 4);
}

Matricula::Matricula(const Matricula& matricula2): nums(matricula2.nums), string(matricula2.string)
{
	int_to_char(nums_c, nums, 4);
}

Matricula::~Matricula()
{
}

char* Matricula::to_string()
{
	full_matricula[0] = nums_c[0];
	full_matricula[1] = nums_c[1];
	full_matricula[2] = nums_c[2];
	full_matricula[3] = nums_c[3];
	full_matricula[4] = '-';
	full_matricula[5] = string[0];
	full_matricula[6] = string[1];
	full_matricula[7] = string[2];
	full_matricula[8] = '\0';

	return &full_matricula[0];
}

bool Matricula::is_equal(Matricula matricula2)
{
	bool result = false;

	if (this->string == matricula2.string)
	{
		if (this->nums == matricula2.nums)
		{
			result = true;
		}
	}

	return result;
}