#ifndef MSTRING_H
#define MSTRING_H

#include <iostream>

/*
	A fully useable string library, without the use of 'cstring' or 'string' libraries, made by Matei Brinzea.

	This library is set to imitate, or even do better than the 'string' libraries already existent in C/C++ library modules. All of this has been done using C Strings, pointers and functions made by me(Matei Brinzea).
	
	I hope it will serve well to those who use it. 
	
	Any modifications are welcome ONLY with the approve of Matei Brinzea, the creator of the library.

	Last work : 02/11/2021

*/




class MString
{
	private:
		char *str;
		int cacat;
	
	public:
		//constructor. DO NOT USE
		MString();
		//constructor. DO NOT USE
		MString(const char *s);
		//destructor. DO NOT USE
		~MString();		
		//copy constructor. DO NOT USE
		MString(const MString &source);


		//operator overloading

		MString &operator=(const MString &rightSource);

		//functions

		/* Displays the string. */
		void display() const;

		/* Returns the length of the string, starting from 1, not 0, as 'size_t'. */
		size_t getLen() const;

		/* Takes input from the user and stores it inside the variable. */
		void input();
		
		/* Concatenates 2 MStrings into one. Also adds a space between words. */
		void concat(MString source, MString dest);
		/* Concatenates 1 MString(source) and 1 C-Style string(dest) into one. Also adds a space between words. */
		void concat(MString source, char dest[]);
		/* Concatenates 1 C-Style string(source) and 1 MString(dest) into one. Also adds a space between words. */
		void concat(char source[], MString dest);
		/* Adds a MString to the MString calling the method */
		void add(MString source);
		/* Adds a C-Style string to the MString calling the method */
		void add(char source[]);
		
		/* Reverses the string. */
		MString reverse();

		/* Finds the FIRST occurencce of a substring in the string, starting from 1, not 0.(For C-Style strings)
			Returns -1 if nothing is passed.
			Returns 0 if the string cannot be found.
			Returns x if the string is found, x being the position of the first letter in the string of the substring. */
		int find(const char aux[] = "None");
		/* Finds the FIRST occurencce of a substring in the string, starting from 1, not 0.(For MString strings)
			Returns -1 if nothing is passed.
			Returns 0 if the string cannot be found.
			Returns x if the string is found, x being the position of the first letter in the string of the substring. */
		int find(MString aux = {"None"});

		/* Empties the string. Adds a `0` at the end */
		void empty();

		/* Compares two strings. Outputs "True" if the strings are identical. Outputs "False" if the strings are NOT identical */
		void compare(MString cmp);
		/* Compares two strings. Outputs "True" if the strings are identical. Outputs "False" if the strings are NOT identical */
		void compare(char cmp[]);

		/* Turns every letter in the word in their uppercase version */
		void uppercase();

		/* Turns the first letter in the word in their opposing case verison */
		void capitalize();

		/* Turns every letter in the word in their lowercase version */
		void lowercase();


};

#endif