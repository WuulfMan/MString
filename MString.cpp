#include "MString.h"
#include <iostream>
#include <conio.h>


//Constructors & Destructors
MString::MString() : str{nullptr}
{
	str = new char[1];
	str[0] = '\0';
}

MString::MString(const char *s) : str{nullptr}
{
	if (s == nullptr)
	{
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		size_t aux = 0;
		while (s[aux] != 0)
		{
			aux++;
		}

		str = new char [aux + (size_t)1];
		str[aux] = '\0';

		size_t i = 0;
		while (i < aux)
		{
			str[i] = s[i];
			i++;
		}
	}
}

MString::MString(const MString &source) : str{nullptr}
{
	MString aux = {source.str};
	size_t s_aux = aux.getLen();

	str = new char[s_aux + 1];
	str[s_aux] = '\0';
	
	size_t i = 0;
	while (i < s_aux)
	{
		str[i] = source.str[i];
		i++;
	}
}

MString::~MString()
{
	delete[] str;
}



//Operator Overloading
MString &MString::operator=(const MString &rightSource)
{
	if (this == &rightSource)
		return *this;

	delete [] this->str;
	this->str = new char [rightSource.getLen() + 1];
	str[rightSource.getLen() + 1] = '\0';
	
	int i = 0;
	while (rightSource.str[i] != 0)
	{
		this->str[i] = rightSource.str[i];
		i++;
	}
	return *this;
	
}


//Functions Public

void MString::display() const
{
	std::cout << str << std::endl;
}

size_t MString::getLen() const
{
	size_t x = 0;
	while (this->str[x] != 0)
	{
		x++;
	}
	return x;
}

void MString::input()
{
	if (this->getLen() < 1)
	{
		char aux[500];
		std::cin.getline(aux, 500);

		MString aux2 = {aux};
		size_t s_aux2 = aux2.getLen();

		delete[] this->str;
		this->str = new char[s_aux2 + 1];

		str[s_aux2] = '\0';

		size_t i = 0;
		while (i < s_aux2)
		{
			this->str[i] = aux[i];
			i++;
		}
	}
	else
	{
		std::cout << "Can't overwrite string: " << "\"" << this->str << "\"" << std::endl;
	}
	
	
}

void MString::concat(MString source, MString dest)
{
	size_t word1_s = source.getLen();
	size_t word2_s = dest.getLen();

	delete[] this->str;
	this->str = new char[word1_s + word2_s + 2];
	this->str[word1_s + word2_s + 1] = '\0';

	size_t i = 0;
	size_t x = 0;

	while (i < (word1_s + word2_s + 1))
	{
		while (i < word1_s)
		{
			this->str[i] = source.str[i];
			i++;
		}

		if (word1_s > 0)
		{
			this->str[i] = ' ';
			i++;
		}

		while (i < (word1_s + word2_s + 1))
		{
			this->str[i] = dest.str[x];
			i++;
			x++;
		}
	}
}

void MString::concat(MString source, char dest[])
{
	MString aux = {dest};
	size_t word1_s = source.getLen();
	size_t word2_s = aux.getLen();

	delete[] this->str;
	this->str = new char[word1_s + word2_s + 2];
	this->str[word1_s + word2_s + 1] = '\0';

	size_t i = 0;
	size_t x = 0;

	while (i < (word1_s + word2_s + 1))
	{
		while (i < word1_s)
		{
			this->str[i] = source.str[i];
			i++;
		}

		if (word1_s > 0)
		{
			this->str[i] = ' ';
			i++;
		}

		while (i < (word1_s + word2_s + 1))
		{
			this->str[i] = aux.str[x];
			i++;
			x++;
		}
	}
}

void MString::concat(char source[], MString dest)
{
	MString aux = {source};
	size_t word1_s = aux.getLen();
	size_t word2_s = dest.getLen();

	delete[] this->str;
	this->str = new char[word1_s + word2_s + 2];
	this->str[word1_s + word2_s + 1] = '\0';

	size_t i = 0;
	size_t x = 0;

	while (i < (word1_s + word2_s + 1))
	{
		while (i < word1_s)
		{
			this->str[i] = aux.str[i];
			i++;
		}

		if (word1_s > 0)
		{
			this->str[i] = ' ';
			i++;
		}

		while (i < (word1_s + word2_s + 1))
		{
			this->str[i] = dest.str[x];
			i++;
			x++;
		}
	}
}

void MString::add(MString source)
{
	MString aux = {this->str};
	size_t aux_s = this->getLen();
	size_t source_s = source.getLen();

	delete[] this->str;
	this->str = new char[aux_s + source_s + 2];
	this->str[aux_s + source_s + 1] = '\0';

	size_t i = 0;
	size_t x = 0;

	while (i < (aux_s + source_s + 1))
	{
		while (i < aux_s)
		{
			this->str[i] = aux.str[i];
			i++;
		}
		
		if (aux_s > 0)
		{
			str[i] = ' ';
			i++;
		}

		while (i < (aux_s + source_s + 1))
		{
			this->str[i] = source.str[x];
			i++;
			x++;
		}
	}
}

void MString::add(char source[])
{
	MString aux = {this->str};
	MString source_aux = {source};
	size_t aux_s = this->getLen();
	size_t source_s = source_aux.getLen();

	delete[] this->str;
	this->str = new char[aux_s + source_s + 2];
	this->str[aux_s + source_s + 1] = '\0';

	size_t i = 0;
	size_t x = 0;

	while (i < (aux_s + source_s + 1))
	{
		while (i < aux_s)
		{
			this->str[i] = aux.str[i];
			i++;
		}

		if (aux_s > 0)
		{
			str[i] = ' ';
			i++;
		}

		while (i < (aux_s + source_s + 1))
		{
			str[i] = source_aux.str[x];
			i++;
			x++;
		}
	}
}

MString MString::reverse()
{
	MString aux = {this->str};
	MString aux2 = {aux};

	size_t s_aux = aux.getLen();

	size_t i = 0;
	size_t x = s_aux-1;

	while (i < s_aux)
	{
		aux.str[i] = aux2.str[x];
		i++;
		x--;
	}

	std::cout << aux.str << std::endl;

	return aux.str;

}

int MString::find(const char aux[])
{
	if (aux == "None")
	{
		return -1;
	}

	MString aux2 = {aux};
	int i = 0;
	int x = 0;
	while (i < this->getLen())
	{
		if (this->str[i] = aux[x])
		{
			while (x < aux2.getLen())
			{
				if (this->str[i + x] == aux[x])
				{
					x++;
				}
				else
				{
					x = 0;
					break;
				}
			}

		}
		i++;

		if (x == aux2.getLen())
			return i;
	}
	return 0;

}

int MString::find(MString aux)
{
	if (aux.str == "None")
	{
		return -1;
	}

	int i = 0;
	int x = 0;
	while (i < this->getLen())
	{
		if (this->str[i] = aux.str[x])
		{
			while (x < aux.getLen())
			{
				if (this->str[i + x] == aux.str[x])
				{
					x++;
				}
				else
				{
					x = 0;
					break;
				}
			}

		}
		i++;

		if (x == aux.getLen())
			return i;
	}
	return 0;
}

void MString::empty()
{
	delete[] this->str;
	this->str = new char[1];
	this->str[0] = '\0';
}

void MString::compare(MString cmp)
{
	int ok = 1;

	if (this->getLen() == cmp.getLen())
	{
		int i = 0;
		while (i < this->getLen())
		{
			if (this->str[i] != cmp.str[i])
			{
				ok = 0;
				break;
			}
			i++;
		}

		if (ok == 1)
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}

}

void MString::compare(char cmp[])
{
	MString comparee = {cmp};
	int ok = 1;

	if (this->getLen() == comparee.getLen())
	{
		int i = 0;
		while (i < this->getLen())
		{
			if (this->str[i] != comparee.str[i])
			{
				ok = 0;
				break;
			}
			i++;
		}

		if (ok == 1)
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
}

void MString::uppercase()
{
	for (int i = 0; i < this->getLen(); i++)
	{
		char aux = this->str[i];
	
		if ((int)aux >= 65 && (int)aux <= 90)
			continue;
		else if ((int)aux < 65 || ((int)aux > 90 && (int)aux < 97 ) || (int)aux > 122)
			continue;
		else
			this->str[i] = (char)((int)aux - 32);
	}
}

void MString::capitalize()
{
	int i = 0;
	while (i < this->getLen())
	{
		char aux = this->str[i];
		if ((int) aux >= 65 && (int) aux <= 90)
		{
			this->str[i] = (char) ((int) aux + 32);
			break;
		}
		else if ((int) aux >= 97 && (int) aux <= 122)
		{
			this->str[i] = (char) ((int) aux - 32);
			break;
		}

		i++;
	}
}

void MString::lowercase()
{
	for (int i = 0; i < this->getLen(); i++)
	{
		char aux = this->str[i];

		if ((int) aux >= 97 && (int) aux <= 122)
			continue;
		else if ((int) aux < 65 || ((int) aux > 90 && (int) aux < 97) || (int) aux > 122)
			continue;
		else
			this->str[i] = (char) ((int) aux + 32);
	}
}
