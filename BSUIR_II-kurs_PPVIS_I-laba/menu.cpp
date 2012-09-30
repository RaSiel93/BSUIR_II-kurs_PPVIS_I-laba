#include <iostream>
#include <conio.h>
#include <windows.h>

#include "menu.h"

using std::cout;
using std::endl;

int menu( int count, char* selected ) {
	int button = 0, position = 0;
	while( button != 13 ) {
		change( position, count, selected );
		button = getch();
		system( "CLS" );
		if( button == 72 ) {
			position--;
		}
		if( button == 80 ) {
			position++;
		}
		if ( button > 48 && button < 49 + count ) {
			position = button - 49;
			change( position, count, selected );
			system( "CLS" );
			return position + 1; 
		}
		if ( button == 27 )
			return 0;
	}
	return position + 1;
}

void change ( int &m, int count, char* textSelected ) {
	if ( m < 0 ) m = count - 1;
	if ( m > count - 1 ) m = 0;
	for ( int i = 0, pos = 0; i < count; i++ ) {
		if ( i == m ) 
			cout << " => ";
		else
			cout << "    ";
		char temp[ 30 ];
		int size = 0;
		CharToOem( textSearch( textSelected, pos ), temp );
		cout << i + 1 << ". " << temp << endl;
	}
}

char* textSearch( char* string, int &posString ) {
	char textPoint[ 30 ];
	int j = 0;
	for( ; posString < strlen( string ); posString++ ) {
		if( string[ posString ] != ';' ) 
			textPoint[ j++ ] = string [ posString ];
		else 
			break;
	}
	posString++;
	textPoint[ j ] = '\0';
	return textPoint;
}