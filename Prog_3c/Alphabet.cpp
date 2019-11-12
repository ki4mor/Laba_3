#define _CRT_SECURE_NO_WARNINGS
#include <strstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <exception>
#include "Alphabet.h"
#include "menu.h"

namespace Laba3 {
	
	int alphabet::check(char str) {
		for (int i = 0; i < num; ++i)
			if (str == alph[i])
				return 1;
		return 0;
	}

	int alphabet::find(char str) {
		for (int i = 0; i < num; ++i)
			if (str == alph[i])
				return i;
		return -1;
	}



	int alphabet::add(char str) {
		if (!check(str)) {
			++num;
			char* tptr = alph;
			alph = nullptr;
			alph = new char[num];
			for (int i = 0; i < num-1; ++i)
				alph[i] = tptr[i];
			alph[num-1] = str;

			delete[] tptr;
		}
		else 
			throw std::exception("This symbol already exists.");
		return 0;
	}


	

	

	code_str& code_str::set_CN(int n) {
		if (n == 0)
			throw std::exception("Invalid value");
		CN = n;
		

		return *this;
	}



	alphabet& alphabet::set_alph(char* str) {


		num = 0;
		for (int i = 0; i < strlen(str); ++i) {
			if (!check(str[i])) {
				++num;
				char* tptr = alph;
				alph = nullptr;
				alph = new char[num];
				if (tptr != NULL)
					for (int i = 0; i < num - 1; ++i)
						alph[i] = tptr[i];
				alph[num - 1] = str[i];

				delete[] tptr;
			}
		}


		return *this;
	}

	code_str& code_str::set_string(char* str) {
		str_num =strlen(str);
		delete[] string;
		string = new char[str_num];
	for(int i=0; i<str_num; ++i) {
		string[i] = str[i];
		}


		return *this;
	}

/*
	int alphabet::find(Laba3::alphabet& E,char str) {
		
	if (E.check(str))
			std::cout << "The symbol is in the alphabet" << std::endl;
	else 
			std::cout << "The symbol is no in the alphabet" << std::endl;

		return 0;
	}
	*/

	int alphabet::coding(Laba3::code_str& E) {
		int k;
		int CN = E.get_CN();
		char* string = E.get_string();
		if ((CN==0)||(CN>=num)||(CN<=-num))
			throw std::exception("Invalid number for coding");
		for(int i = 0; i<E.get_str_num();++i) {
			int number = find(string[i]);
			if (number!=-1) {
				k = number + CN;
				if (k >= num)
					k = k - num;
				if (k<0)
					k = k + num;
				string[i] = alph[k];
			}
			
		}

		return 0;
	}


	int alphabet::decoding(Laba3::code_str& E) {
		int k;
		int CN = E.get_CN();
		char* string = E.get_string();
		for (int i = 0; i < E.get_str_num(); ++i) {
			int number = find(string[i]);
			if (number != -1) {
			
				k = number - CN;
				if (k < 0)
					k = k + num;
				if (k >= num)
					k = k - num;
				string[i] = alph[k];
			}

		}

		return 0;
	}


	int alphabet::merge(Laba3::alphabet& E, Laba3::alphabet& E2){
		int k;
		k= E2.get_num();
		char* str = E2.get_alph();
		for (int i = 0; i <E2.get_num(); ++i){
			if (num > SZ)
				throw std::exception("The alphabet is full");
			E.add(str[i]);

			}
		return 0;
	}

	

	std::ostream& operator << (std::ostream& s, const alphabet& E)
	{
		s << "-----------------------------------" << std::endl;
		s << "Alphabet:  ";
		for (int i = 0; i < E.num; ++i)
			s << E.alph[i];

		return s;
	}




	std::istream& operator >> (std::istream& s, char* str)
	{
		int fl = 0;
		int r = 0;
		do {
			s >> str;
			if (std::cin.eof()) {
				std::cin.clear();
				throw std::exception("");
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				fl++;
			}
			else fl = 0;
		} while (fl);

		return s;
	}








	std::istream& operator >> (std::istream& s, char str)
	{
		int fl = 0;
		int r = 0;
		do {
			s >> str;
			if (std::cin.eof()) {
				std::cin.clear();
				throw std::exception("");
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				fl++;
			}
			else fl = 0;
		} while (fl);

		return s;
	}





	int alphabet::operator()(char str) {

		for (int i = 0; i < num; ++i)
		if (str == alph[i])
			return 1;
		return 0;
	}



	int alphabet::operator()(Laba3::code_str& E) {
		int CN = E.get_CN();
		char* string = E.get_string();
		int k;
		if ((CN == 0) || (CN >= num) || (CN <= -num))
			throw std::exception("Invalid number for coding");
		for (int i = 0; i < E.get_str_num(); ++i) {
			int number = find(string[i]);
			if (number != -1) {
				k = number + CN;
				if (k >= num)
					k = k - num;
				if (k < 0)
					k = k + num;
				string[i] = alph[k];
			}

		}

		return 0;

	}



	alphabet&  alphabet::operator =(alphabet& E2){
		num = E2.num;
		delete[] alph;
		alph = new char[num];
		for (int i = 0; i < num; ++i){
			alph[i] = E2.alph[i];
		}
		return *this;
	}
	
	
	alphabet& alphabet::operator =(alphabet&& E2){
		int tn=num;
		num = E2.num;
		E2.num = tn;
		char* tptr=alph;
		alph =E2.alph;
		E2.alph = tptr;
	
		return *this;

	}
	


	alphabet alphabet::func(const alphabet& E) {
		alphabet a(E);
		return a;
	}
	

	alphabet&  alphabet::operator +(alphabet& E2){
		alphabet C();
		char* ptr = nullptr;
		int n = 0;
		for (int i = 0; i <E2.num; ++i){
			if (num > SZ)
				throw std::exception("The alphabet is full");
			if (!check(E2.alph[i])) {
				char* tptr = ptr;
				ptr = nullptr;
				++n;
				ptr = new char[n];
				if (tptr!=NULL)
				for (int i = 0; i < n; ++i)
					ptr[i] = tptr[i];
				ptr[n - 1] = E2.alph[i];
				delete[] tptr;
			}	
		}
		if (ptr != NULL) {
			num = num + n;
			char* tptr = alph;
			alph = nullptr;
			alph = new char[num];
			for (int i = 0; i < num-n; ++i)
				alph[i] = tptr[i];
			for (int i = 0; i < n ; ++i) {
				alph[num+i-n] = ptr[i];
			}
			delete[] tptr;
		}
		delete[] ptr;
		return *this;
	}
	

	alphabet&  alphabet::operator +=(alphabet& E2){
		char* ptr=nullptr;
		int n = 0;
		for (int i = 0; i <E2.num; ++i){
			if (num > SZ)
				throw std::exception("The alphabet is full");
			if (!check(E2.alph[i])) {
				char* tptr = ptr;
				ptr = nullptr;
				++n;
				ptr = new char[n];
				if (tptr != NULL)
					for (int i = 0; i < n; ++i)
						ptr[i] = tptr[i];
				ptr[n - 1] = E2.alph[i];

				delete[] tptr;
			}
		}
		if (ptr != NULL) {
			num = num + n;
			char* tptr = alph;
			alph = nullptr;
			alph = new char[num];
			for (int i = 0; i < num - n; ++i)
				alph[i] = tptr[i];
			for (int i = 0; i < n; ++i) {
				alph[num + i - n] = ptr[i];
			}
			delete[] tptr;
		}
		delete[] ptr;

		return *this;
	}

}