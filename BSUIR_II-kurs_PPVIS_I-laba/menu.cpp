#include <iostream>
#include <conio.h>
#include <windows.h>

#include "mashina.h";
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

void testcaseMenu( char* path ) {
	int change = -1;
	MashinTuring *TMashin = 0;
	while( change ) {
		system( "CLS" );	
		change = menu( 6, "Создать алгоритм;Загрузить алгоритм;Сохранить алгоритм;Редактировать алгоритм;Запустить;Выйти");
		switch( change ) {
		case 1: TMashin = creatAlgo( path ); break;
		case 2: TMashin = loadAlgo( path ); break;
		case 3: saveAlgo( TMashin, path ); break;
		case 4: TMashin = editAlgo( TMashin ); break;
		case 5: runAlgo( TMashin, 1 ); break;
		default: change = 0;
		}
	}
}