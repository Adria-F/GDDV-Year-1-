#pragma once
class Matricula
{
private:

	int nums;
	char nums_c[5];
	char* string;
	char full_matricula[9];

public:
	Matricula();
	Matricula(int num, char* str);
	Matricula(const Matricula& matricula2);
	~Matricula();

	char* to_string();

	bool is_equal(Matricula matricula2);
};

