#include <iostream>
#ifndef _alphabet_H_
#define _alphabet_H_
#include <math.h>
namespace Laba3 {
	class code_str{
	private:
		
		char* string;
		int str_num;
		int CN;
	public:
		code_str():CN(0), str_num(7),string(new char[7]){
			char string_1[7] = "street";
			for (int i = 0; i < 7; ++i)
				string[i] = string_1[i];
		}


		char* get_string() {
			return string;
		}

		int get_str_num() {
			return str_num;
		}

		int get_CN() {
			return CN;
		}

		code_str& set_CN(int n);
		code_str& set_string(char* str);


		~code_str() { delete[] string; }

	};



	class alphabet {
	private:
		static const int SZ = 100;
		int num;
		 char* alph;
		
	public:
		

		alphabet():num(26),alph(new char[26]){
			char alph_1[27] ="abcdefghijklmnopqrstuvwxyz";
			for (int i = 0; i <26; ++i)
				alph[i] = alph_1[i];
		
		}

		alphabet(int number) :num(number), alph(new char[number]) {
			
			char alph_2[100] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+-./:;<=>?@[\]^_`{|}~";
			for (int i = 0; i < number;++i)
			alph[i] = alph_2[i];
			
		}


		alphabet(char* str){
			num =0;
			for(int i=0; i<strlen(str); ++i){
				if (!check(str[i])) {
					++num;
					char* tptr = alph;
					alph = nullptr;
					alph = new char[num];
					if (tptr!=NULL)
					for (int i = 0; i < num - 1; ++i)
						alph[i] = tptr[i];
					alph[num - 1] = str[i];

					delete[] tptr;
				}
			}
		}
		
		alphabet(const alphabet& E) :num(E.num), alph(nullptr) {

			if (num) {
				alph = new char[num];
				for (int i = 0; i < num; ++i)
					alph[i] = E.alph[i];

			}
		}

		 alphabet(alphabet&& E) :num(E.num), alph(E.alph) {

			E.alph = nullptr;
		}




		int get_num() const {
			return num;
	    }

		char* get_alph() {
			return alph;
		}


		
		alphabet& set_alph(char* str);
	

		int find(char str);
		int coding(Laba3::code_str& E);
		int decoding(Laba3::code_str& E);
		int add(char str);
		int check(char str);
		int merge(Laba3::alphabet& E, Laba3::alphabet& E2);

		int operator()(char);
		int operator()(Laba3::code_str& E2);
		alphabet& operator =(alphabet&);
		alphabet& operator =(alphabet&&);
		alphabet func(const alphabet& E);

		alphabet& operator +=(alphabet&);
		alphabet& operator +(alphabet&);
		friend std::ostream& operator << (std::ostream&, const alphabet&);


		~alphabet() { delete[] alph; }
	};



	
}
#endif