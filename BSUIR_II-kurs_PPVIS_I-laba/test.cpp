//#include "stdafx.h"
#include "UnitTest++.h" // Главный заголовочный файл библиотеки UnitTest++
#include <iostream>
#include <fstream>
#include <strstream>

#include "menu.h"
#include "mashina.h"

TEST( test1 )
{
	MashinTuring ob1, ob2, ob3;

	ob1.AddElement( 20 );
	ob2 = ob1;
	MashinTuring ob4 = ob2;
	ob3.AddElement( 30 );

	CHECK( ob1 == ob2 );
	CHECK( ob3 != ob2 );
	CHECK( ob4 == ob2 );
}

TEST( test2 )
{
	MashinTuring ob;

	ob.AddPravilo( 20, 1, 0, -1, 21 );
	CHECK( ob.SearchPravilo( 20, 1 )->getEl() == 0 );
	CHECK( ob.SearchPravilo( 20, 1 )->getCar() == -1 );
	CHECK( ob.SearchPravilo( 20, 1 )->getGo() == 21 );
}

TEST( test3 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	CHECK( ob[ 20 ] == true );
}

TEST( test4 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );

	CHECK( ob.SearchElement( 20 ) == true );
	CHECK( ob.SearchElement( 21 ) == true );
	CHECK( ob.SearchElement( 22 ) != true );
}

TEST( test5 )
{
	MashinTuring ob;

	char buf[ 1000 ];
	ostrstream out( buf, 1000 );
	out << 3 << endl;
	out << ends;

	istrstream in( buf );
	in >> ob;

	CHECK( 1 == ob[ 3 ] );
}

TEST( test6 )
{
	MashinTuring ob;
	ob.setCaretka( 20 );
	ob++;
	CHECK( 21 == ob.getCaretka() );
}

TEST( test7 )
{
	MashinTuring ob;
	ob.setCaretka( 20 );
	ob--;
	CHECK( 19 == ob.getCaretka() );
}

TEST( test8 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );
	ob.AddElement( 22 );

	CHECK( ob.SearchElement( 20 ) );
	CHECK( ob.SearchElement( 21 ) );
	CHECK( ob.SearchElement( 22 ) );

	ob.DelElement( 20 );

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( ob.SearchElement( 21 ) );
	CHECK( ob.SearchElement( 22 ) );

	ob.ClearElements();

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( !ob.SearchElement( 21 ) );
	CHECK( !ob.SearchElement( 22 ) );
}

TEST( test9 )
{
	MashinTuring ob;
	
	ob.setHelpScreen( 20 );
	CHECK( ob.getHelpScreen() == 20 );
}

TEST( test10 )
{
	MashinTuring ob;
	
	ob.setHelpScreenPravila( 20 );
	CHECK( ob.getHelpScreenPravila() == 20 );
}

TEST( test11 )
{
	MashinTuring ob1 = load( "testcase/test2.txt", 0 );
	MashinTuring ob2 = load( "testcase/test2.txt", 0 );
	MashinTuring ob3 = ob2;
	ob3.setCaretka( 100000 );
	CHECK( ob1 == ob2 );
	CHECK( ob3 != ob2 ); 
	CHECK( ob3 != ob1 );
}

TEST( test12 )
{
	MashinTuring ob1 = load( "testcase/test2.txt", 0 );
	MashinTuring ob2;
	CHECK( ob1 != ob2 );
	
	ob1.ClearElements();
	CHECK( ob1 != ob2 );

	ob1.ClearPravila();

	CHECK( ob1 == ob2 );
}

TEST( test13 )
{
	MashinTuring ob1 = load( "testcase/test2.txt", 0 );
	MashinTuring ob2;
	ob2.setCaretka( 17 );

	ob2.AddElement( 17 );
	ob2.AddElement( 18 );
	ob2.AddElement( 19 );
	ob2.AddElement( 20 );

	ob2.AddPravilo( 1 - 1, 0, 0, 1, 0 - 1 );
	ob2.AddPravilo( 2 - 1, 0, 0, 1, 3 - 1 );
	ob2.AddPravilo( 3 - 1, 0, 1, 1, 4 - 1 );
	ob2.AddPravilo( 4 - 1, 0, 1,-1, 5 - 1 );
	ob2.AddPravilo( 5 - 1, 0, 0,-1, 6 - 1 );
	ob2.AddPravilo( 6 - 1, 0, 0, 1, 1 - 1 );
	ob2.AddPravilo( 7 - 1, 0, 0, 1, 1 - 1 );
	ob2.AddPravilo( 1 - 1, 1, 0, 1, 2 - 1 );
	ob2.AddPravilo( 2 - 1, 1, 1, 1, 2 - 1 );
	ob2.AddPravilo( 3 - 1, 1, 1, 1, 3 - 1 );
	ob2.AddPravilo( 5 - 1, 1, 1,-1, 5 - 1 );
	ob2.AddPravilo( 6 - 1, 1, 1,-1, 7 - 1 );
	ob2.AddPravilo( 7 - 1, 1, 1,-1, 7 - 1 );

	CHECK( ob1 == ob2 );
}

TEST( test14 )
{
	MashinTuring ob1 = load( "testcase/test2.txt", 0 );
	MashinTuring ob2 = ob1;
	ob1 = run( ob1, 0 );

	ob2.ClearElements();

	ob2.setCaretka( ob1.getCaretka() );

	ob2.AddElement( 22 );
	ob2.AddElement( 23 );
	ob2.AddElement( 24 );
	ob2.AddElement( 25 );
	ob2.AddElement( 26 );
	ob2.AddElement( 27 );
	ob2.AddElement( 28 );
	ob2.AddElement( 29 );

	CHECK( ob1 == ob2 );
}

TEST( test15 )
{
	MashinTuring ob1 = load( "testcase/test2.txt", 0 );
	ob1 = run( ob1, 0 );
	save( ob1, "testcase/testSave2.txt", 0 );
	MashinTuring ob2 = load( "testcase/testSave2.txt", 0 );
	ob1.ClearElements();

	ob1.setCaretka( ob2.getCaretka() );

	ob1.AddElement( 22 );
	ob1.AddElement( 23 );
	ob1.AddElement( 24 );
	ob1.AddElement( 25 );
	ob1.AddElement( 26 );
	ob1.AddElement( 27 );
	ob1.AddElement( 28 );
	ob1.AddElement( 29 );

	CHECK( ob1 == ob2 );
}

TEST( test16 )
{
	MashinTuring ob1;
	ob1.AddPravilo( 1, 1, 1, 1, 1 );
	CHECK( ob1.SearchPravilo( 1, 1 ) );
	ob1.DelPravilo( 1, 1 );
	CHECK( !ob1.SearchPravilo( 1, 1 ) );
}

TEST( test17 )
{
	MashinTuring ob1;
	ob1.AddPravilo( 1, 1, 1, 1, 1 );
	CHECK( ob1.SearchPravilo( 1, 1 ) );
	ob1.ClearPravila();
	CHECK( !ob1.SearchPravilo( 1, 1 ) );
}

TEST( test18 )
{
	MashinTuring ob1;
	ob1.AddPravilo( 1, 1, 1, 1, 1 );
	ob1.setCaretka( 20 );
	MashinTuring ob2 = ob1;

	CHECK( ob1.SearchPravilo( 1, 1 ) );
	
	CHECK( ob1.stepGo( 1, 1 ) );
	ob2.AddElement( 20 );
	ob2++;
	CHECK( ob1 == ob2 );
}

TEST( test19 )
{
	MashinTuring ob1;
	
	CHECK( ob1.searchStop( 1, 0 ) == 1 );
}

TEST( test20 )
{
	MashinTuring ob1;
	ob1.AddPravilo( 1, 1, 1, 1, 666 );

	CHECK( ob1.stepGo( 1, 1 ) == 666 );
}

TEST( test21 )
{
	MashinTuring ob1, ob2;

	CHECK( ob1 == ob2 );
}

TEST( test22 )
{
	MashinTuring ob1, ob2;

	ob1.AddPravilo( 20, 1, 0, -1, 21 );
	ob2.AddPravilo( 20, 0, 1, 1, 25 );
	CHECK( ob1.SearchPravilo( 20, 1 )->getCar() == -1 );
	CHECK( ob2.SearchPravilo( 20, 0 )->getCar() == 1 );
}

TEST( test23 )
{
	MashinTuring ob1, ob2;

	ob1.AddPravilo( 20, 1, 0, -1, 21 );
	ob2.AddPravilo( 20, 0, 1, 1, 25 );
	CHECK( ob1.SearchPravilo( 20, 1 )->getEl() == 0 );
	CHECK( ob2.SearchPravilo( 20, 0 )->getEl() == 1 );
}

TEST( test24 )
{
	MashinTuring ob1, ob2;

	ob1.AddPravilo( 20, 1, 0, -1, 21 );
	ob2.AddPravilo( 20, 0, 1, 1, 25 );
	CHECK( ob1.SearchPravilo( 20, 1 )->getGo() == 21 );
	CHECK( ob2.SearchPravilo( 20, 0 )->getGo() == 25 );
}

TEST( test25 )
{
	MashinTuring ob;
	
	ob.setHelpScreenPravila( 99999999 );
	CHECK( ob.getHelpScreenPravila() == 99999999 );
}

TEST( test26 )
{
	MashinTuring ob;
	
	ob.setHelpScreen( -9999999 );
	CHECK( ob.getHelpScreen() == -9999999 );
}

TEST( test27 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );
	ob.AddElement( 22 );

	ob.DelElement( 20 );
	ob.DelElement( 21 );
	ob.DelElement( 22 );

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( !ob.SearchElement( 21 ) );
	CHECK( !ob.SearchElement( 22 ) );
}

TEST( test28 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );
	ob.AddElement( 22 );

	ob.ClearElements();

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( !ob.SearchElement( 21 ) );
	CHECK( !ob.SearchElement( 22 ) );
}

TEST( test29 )
{
	MashinTuring ob1, ob2;

	ob1.AddElement( 20 );
	ob2.AddElement( 21 );

	ob1.DelElement( 20 );
	ob2.ClearElements();

	CHECK( ob1 == ob2 );
}

TEST( test30 )
{
	MashinTuring ob;
	ob.AddPravilo( 0, 1, 0, -1, 21 );
	CHECK( !ob.SearchPravilo( 0, 1 )->getNum() );
}

int main( int argc, char const *argv[] )
{
	//testcaseMenu( "testcase/test2.txt", 0 );
	if ( argc == 2 ) {
		if ( !strcmp( argv[ 1 ], "-menu" ) )
			return testcaseMenu( "testcase/test2.txt", 0 );
		else if ( !strcmp( argv[ 1 ], "-log" ) )
		{
			return testcaseMenu( "testcase/test2.txt", 1 );
		}
	}
	else 
		return UnitTest::RunAllTests();
}