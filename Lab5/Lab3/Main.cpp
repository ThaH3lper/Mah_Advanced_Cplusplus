#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <stdlib.h>
#include <crtdbg.h>

#include "VG.h"
#include "String.h"

////#include "UnsignedTest.h"
//#include "String.h"
//
////#include <string>
//
#include <iostream>
using std::cout;
using std::cin;
//
//#include <cassert>
//
////#include <utility>

#include "StringTest.h"
#include "StringIttTest.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));
	//TestUnsigned();
	TestFörGodkäntString();
#ifdef VG
	TestFörVälGodkäntString();
#endif VG

#ifdef ITT
    TestIttPart();
	TestIttPartR();

#ifdef VG
    TestIttPartC();
    TestIttPartCR();
#endif VG
    TestIttInAlg();
    TestRevIttInAlg();
	TestFörGodkäntItt();
#endif ITT
    cin.get();
}

