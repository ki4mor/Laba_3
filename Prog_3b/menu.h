#ifndef menu_h
#define menu_h
#include <iostream>
#include "Alphabet.h"

namespace menu {
	
	

int dialog(Laba3::alphabet& E);
int menu_t(int, Laba3::alphabet&, Laba3::code_str&);
int get_char(char& str);
int get_int(int &a);
int get_str(char*);
}
#endif