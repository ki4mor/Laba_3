#include <iostream>
#include "Alphabet.h"
#include <math.h>
#include <limits>
#include "menu.h"
#include "stdlib.h"

using namespace menu;
using namespace Laba3;

int main(int argc, const char* argv[]) {
	
	
	Laba3::alphabet E;
	int a = 0,fl;
	Laba3::code_str S;
	do {
		int  d = dialog(E);
		if (menu_t(d, E, S)) {
			system("pause");
			return 1;
		}
		system("pause");
		system("cls");
		fl = d;
		
	} while (fl);


	std::cin.get();
	return 0;
}