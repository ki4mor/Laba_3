#include <stdio.h>
#include "Alphabet.h"
#include "menu.h"

int fl1 = 1;
int fl2 = 1;

namespace menu {
	int dialog(Laba3::alphabet& E) {
		std::cout << "1 - Class state" << std::endl;
		std::cout << "2 - Add element" << std::endl; 
		std::cout << "3 - Merge alphabets" << std::endl; 
		std::cout << "4 - String encoding" << std::endl; 
		std::cout << "5 - String decoding" << std::endl; 
		std::cout << "6 - Character search in the alphabet" << std::endl;
		std::cout << "7 - Input new alphabet" << std::endl;
		std::cout << "0 - Exit" << std::endl; 
		int d = 0;
		get_int(d);
		return d;
	}




	int menu_t(int d, Laba3::alphabet& E, Laba3::code_str& S) {
		switch (d) {
			
		case 1: {
					std::cout << "=======CLASS STATE=======" << std::endl;

					std::cout << E << std::endl;

				
			return 0;
		}
		case 2: {
					std::cout << "=======ADD ELEMENT=======" << std::endl;

					char str(5);

					std::cout << "Enter new symbol:  ";
					std::cin >> str;

					try {
						std::cout << "-----------------------------------" << std::endl;


						E.add(str);
						std::cout << "Symbol added" << std::endl;

						std::cout << "-----------------------------------" << std::endl << std::endl;
					}

					catch (std::exception& ex)
					{
						std::cout << ex.what() << std::endl;
					}

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return 0;

		}
				
		
		case 3: {
			std::cout << "=======MERGE ALPHABETS=======" << std::endl;

			char New_alph[100];
			std::cout << "Enter new alphabets:" << std::endl;
			std::cin >> New_alph;
			try {
				std::cout << "-----------------------------------" << std::endl;
				Laba3::alphabet E2(New_alph);
				Laba3::alphabet C(0);
				//C=E+E2;
				//E=C;
				E += E2;
					std::cout << "-Alphabets merged-" << std::endl;
					
		
					std::cout << E << std::endl;
				
			}

			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		case 4: {
			std::cout << "=======STRING ENCODING=======" << std::endl;
			int x=0;
			std::cout << "Enter 0 to continue with standart string" << std::endl;
			std::cout << "Enter >0 to create new string" << std::endl;
			try {
				std::cout << "-----------------------------------" << std::endl;
				if (get_int(x)){
					return 1;
				}
				if (x) {
					
					char str[100];


					std::cout << "Enter your string:" << std::endl;
					std::cin >> str;
					S.set_string(str);
				}
				int a = 0;
				std::cout << "Enter number for coding from 1 to " << E.get_num() << ":  "<< std::endl;
				if (get_int(a)){
					return 1;
				}
				S.set_CN(a);
				E(S);


				char* b = S.get_string();
				std::cout << "Encoded string:" << std::endl;
				for (int i = 0; i < S.get_str_num(); ++i)
					std::cout << b[i];
				std::cout << std::endl << "-----------------------------------" << std::endl << std::endl;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		case 5: {
			std::cout << "=======STRING DECODING=======" << std::endl;
			try {
				std::cout << "-----------------------------------" << std::endl;
				E.decoding(S);
				char* b = S.get_string();
				std::cout << "Decoded string:" << std::endl;
				for (int i = 0; i < S.get_str_num(); ++i)
					std::cout << b[i];

				std::cout << std::endl << "-----------------------------------" << std::endl << std::endl;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;	
		}
		case 6: {
					std::cout << "=======SYMBOL SEARCH=======" << std::endl;
					char str(5);
					std::cout << "Symbol:  ";
					std::cin >> str;


					std::cout << "-----------------------------------" << std::endl;
					if (E(str))
						std::cout << "The symbol is in the alphabet" << std::endl;
					else
						std::cout << "The symbol is no in the alphabet" << std::endl;
					std::cout << "-----------------------------------" << std::endl << std::endl;



					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return 0;
		}
		

		case 7:{
				   char str[100];

		 
	std::cout << "=======INPUT ALPHABET=======" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Enter new alphabet" << std::endl;
					if (get_str(str)) {
					   return 1;
				   }
					E.set_alph(str);
						std::cout << "-----------------------------------" << std::endl;
				   return 0;
		}

		

		case 0: {
			std::cout << "Good bye!";
			return 0;
		}

		default: {
			std::cout << std::endl;
			std::cout << "Incorrect Data!" << std::endl << std::endl;
			
		}
		}
		return 0;
	}


	int get_char(char& str) {

		int r = 0;
		do {
			std::cin >> str;
			if (std::cin.eof()) {
				std::cin.clear();
				return -1;
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				r++;
			}
			else r = 0;
		} while (r);
		return r;
	}


	int get_int(int& a) {
		int r = 0;
		do {
			std::cin >> a;
			if (std::cin.eof()) {
				std::cin.clear();
				return -1;
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				r++;
			}
			else r = 0;
		} while (r);
		return r;
	}

	int get_str(char* a)
	{
		int r = 0;
		do {
			std::cin >> a;
			if (std::cin.eof()) {
				std::cin.clear();
				return -1;
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				r++;
			}
			else r = 0;
		} while (r);
		return r;
	}

}



