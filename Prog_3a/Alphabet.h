
#ifndef _alphabet_H_
#define _alphabet_H_
#include <math.h>
namespace Laba3 {
	class code_str{
	private:
		static const int SZ = 100;
		char string[SZ];
		int str_num;
		int CN;
	public:
		code_str(){
			CN = 0;
			str_num = 7;
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

	};



	class alphabet {
	private:
		static const int SZ = 100;
		int num;
		 char alph[SZ];
		
	public:
		

		alphabet(){
			num = 26;
			
			char alph_1[27] ="abcdefghijklmnopqrstuvwxyz";
			for (int i = 0; i <27; ++i)
				alph[i] = alph_1[i];
		
		}

		alphabet(int number){
			
			char alph_2[SZ] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+-./:;<=>?@[\]^_`{|}~";
			for (int i = 0; i < number;++i)
			alph[i] = alph_2[i];
			num = number;
			alph[number] = '\0';
		}


		alphabet(char* str){
			int i=0;
			num = 0;

			while (str[i]){
				alph[i] = str[i];
				++i;
				++num;
			}
			alph[num] = '\0';
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

		
	};
}
#endif