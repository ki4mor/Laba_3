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
			alph[num] = str;
			++num;
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
		int i = 0;
		while (str[i]){
			if (!check(str[i])) {
				alph[num] = str[i];
				
				++num;
			}
			++i;
		}


		return *this;
	}

	code_str& code_str::set_string(char* str) {
		str_num = 0;
		int i = 0;
		while (str[i]) {
			string[i] = str[i];
			++str_num;
			++i;
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
			if (!check(str[i])) {
				alph[num] = str[i];
				++num;
			}

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
		num = 0;
		for (int i = 0; i < E2.num; ++i){
			alph[i] = E2.alph[i];
			++num;
		}
		return *this;
	}
	

	

	alphabet&  alphabet::operator +(alphabet& E2){
		alphabet C();

		for (int i = 0; i <E2.num; ++i){
			if (num > SZ)
				throw std::exception("The alphabet is full");
			if (!check(E2.alph[i])) {
				alph[num] = E2.alph[i];
				++num;
			}
		}
		return *this;
	}
	

	alphabet&  alphabet::operator +=(alphabet& E2){

		for (int i = 0; i <E2.num; ++i){
			if (num > SZ)
				throw std::exception("The alphabet is full");
			if (!check(E2.alph[i])) {
				alph[num] = E2.alph[i];
				++num;
			}
		}

		return *this;
	}

}