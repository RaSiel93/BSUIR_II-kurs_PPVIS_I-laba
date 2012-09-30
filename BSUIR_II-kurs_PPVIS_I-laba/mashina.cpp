#include "mashina.h";
#include "conio.h"
#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

Pravila::Pravila() {
	actEl = -2;
	actCar = -2;
	go = -2;
}
int Pravila::getCar () const {
	return actCar;
}
int Pravila::getEl () const {
	return actEl;
}
int Pravila::getGo () const {
	return go;
}
void Pravila::setCar( int temp ) {
	actCar = temp;
}
void Pravila::setEl( int temp ) {
	actEl = temp;
}
void Pravila::setGo( int temp ) {
	go = temp;
}
//-----------------------------------------
ostream &operator<<( ostream &output, const Lenta lenta ) {
	for( int i = 0; i < n; i++ )
		output << lenta.getLenta( i ) << " ";
	return output;
}
int Lenta::getLenta( int temp ) const {
	return lenta[ temp ];
}
void Lenta::setLenta( int position, int temp ) {
	if ( position > n || position < 0 || temp > 1 || temp < 0 ) 
		return; 
	lenta[ position ] = temp;		
}
void Lenta::clearLenta() {
	for( int i = 0; i < n; i++ ) 
		setLenta( i, 0 );
	setCaretka( 20 );
}
int Lenta::getCaretka() const {
		return caretka;
	}
void Lenta::setCaretka( int temp ) {
	if ( temp < 0 ) temp = 0;
	if ( temp > n - 1 ) temp = n - 1;
	caretka = temp;
}
//-----------------------------------------
MashinTuring::MashinTuring() {
	tLenta.clearLenta();
}
Pravila MashinTuring::getPravilo( int x, int y ) {
	return pravilo[ x ][ y ];
}
void MashinTuring::setPravilo( int x, int y, int E, int C, int G ) {
	pravilo[ x ][ y ].setEl( E );
	pravilo[ x ][ y ].setCar( C );
	pravilo[ x ][ y ].setGo( G );
}
void MashinTuring::printPravilo( int x, int y ) {
	if( this->getPravilo( x, y ).getEl() == -2 )
		cout << " ";
	else
		cout << this->getPravilo( x, y ).getEl();
	if( this->getPravilo( x, y ).getCar() == -2 ) cout << " ";
	if( this->getPravilo( x, y ).getCar() == -1 ) cout << "<";
	if( this->getPravilo( x, y ).getCar() == 1 ) cout << ">";
	if( this->getPravilo( x, y ).getCar() == 0 ) cout << "-";
	if( this->getPravilo( x, y ).getGo() == -1 ) 
		cout << "S ";
	else if( this->getPravilo( x, y ).getGo() == -2 )
		cout << "  ";
	else
		cout << setfill( '0' ) << setw (2) << this->getPravilo( x, y ).getGo() + 1;
}
void MashinTuring::printStatusAlgo() {
	cout << "===============================================================================" << endl;
	cout << " / ";
	for( int i = 0; i < 15; i++ )
		cout << "| Q" << setfill( '0' ) << setw(2) << i + 1;
	cout << endl;
	cout << " 0 ";
	for( int x = 0, y = 0; x < 15; x++ ) {
		cout << "|"; 
		this->printPravilo( x, y );
	}
	cout << endl;
	cout << " 1 ";
	for( int x = 0, y = 1; x < 15; x++ ) {
		cout << "|"; 
		this->printPravilo( x, y );
	}
	cout << endl;
	cout << "===============================================================================" << endl;
}

void MashinTuring::loadPravila() {
	char textL1[] = "Алгоритм успешно загружен.\0", text1[ 50 ];
	CharToOem ( textL1, text1 );
	
	this->tLenta.setCaretka( 20 );

	this->tLenta.setLenta( 18, 1 );
	this->tLenta.setLenta( 17, 1 );
	this->tLenta.setLenta( 16, 1 );
	this->tLenta.setLenta( 21, 1 );
	this->tLenta.setLenta( 22, 1 );
	this->tLenta.setLenta( 23, 1 );

	this->setPravilo( 0, 0, 0, -1, 0 );
	this->setPravilo( 1, 0, 0, 1, 4 );
	this->setPravilo( 3, 0, 0, 1, 3 );
	this->setPravilo( 4, 0, 1, -1, 0 );
	this->setPravilo( 5, 0, 0, 1, 5 );
	this->setPravilo( 6, 0, 1, 0, -1 );
	this->setPravilo( 0, 1, 1, -1, 1 );
	this->setPravilo( 1, 1, 1, 1, 2 );
	this->setPravilo( 2, 1, 0, 1, 3 );
	this->setPravilo( 3, 1, 1, -1, 4 );
	this->setPravilo( 4, 1, 0, 1, 5 );
	this->setPravilo( 5, 1, 1, -1, 6 );

	cout << text1;

	getch();
}
void MashinTuring::editAlgo() {
	int change = -1;
	char textT1[] = "1.Добавить правило/2.Удалить правило/3.Сброс правил/4.Сброс ленты/5.Назад\0", text1[ 90 ];
	char textT2[] = "Введите позицию правила. Пример: 9 1 это Q09/1: \0", text2[ 80 ];
	char textT3[] = "Введите действие над текущей ячейкой (0 или 1), сдвиг каретки (-1, 0, 1) и позицию следующего правила( или 0 - stop ). Пример: 0 1 8 это изменить содержимое на 0, сдвинуть каретку влево, перейти на правило Q08: \0", text3[ 220 ];
	CharToOem ( textT1, text1 ); CharToOem ( textT2, text2 ); CharToOem ( textT3, text3 );
	while ( change != 13 ) {
		change = -1;
		cout << tLenta;
		int size = this->tLenta.getCaretka();
		for( int i = 0; i < this->tLenta.getCaretka(); i++ ) {
			cout << "  ";
		}
		cout << "^" << endl;
		this->printStatusAlgo();
		
		int x, y;
		int a, s, p;

		cout << text1 << endl;
		change = getch();
		if ( change == 77 )
			this->tLenta.setCaretka( ++size );
		if ( change == 75 )
			this->tLenta.setCaretka( --size );
		if (change == 32 )
			if( this->tLenta.getLenta( size ) == 1 )
				this->tLenta.setLenta( size, 0 );
			else
				this->tLenta.setLenta( size, 1 );
		switch ( change - 48 ) {
		case 1:
			
		case 2: 
			cout << change - 48 << "." << text2; 
			while( 1 ) {
				cin >> x >> y;
				x -= 1;
				if ( y < 0 || y > 1 || x < 0 || x > 14 ) cout << "Invalid data!" << endl; 
				else break;
			}
			
			if( change - 48 == 1) {
				cout << endl << text3;
				cin >> a >> s >> p;
				p -= 1;
				this->setPravilo( x, y, a, s, p );
			}
			else 
				this->setPravilo( x, y, -2, -2, -2 );
			system( "CLS" );
			break;
		case 3:
			for( int x = 0; x < 15; x++ ) {
				this->setPravilo( x, 0, -2, -2, -2 );
				this->setPravilo( x, 1, -2, -2, -2 );
			}
			system( "CLS" );
			break;
		case 4:
			this->tLenta.clearLenta();
			system( "CLS" );
			break;
		case 5: change = 13; 
		}
		system( "CLS" );
	}
}
int MashinTuring::stepGo( int x, int y ) {
	this->tLenta.setLenta( this->tLenta.getCaretka(), this->getPravilo( x, y ).getEl() );
	this->tLenta.setCaretka( this->tLenta.getCaretka() + this->getPravilo( x, y ).getCar() );
	return this->getPravilo( x, y ).getGo();
}
int MashinTuring::searchStop( int position ) {
	char textA1[] = "Алгоритм успешно завершен!\0", text0[ 50 ];
	char textE1[] = "Ошибка! Нет правила для текущей ячейки.\0", text1[ 50 ];
	char textE2[] = "Ошибка! Выход за пределы ленты.\0", text2[ 50 ];
	CharToOem ( textA1, text0 ); CharToOem ( textE1, text1 ); CharToOem ( textE2, text2 );
	if( position == -1 )
		cout << text0;
	else
		if( this->tLenta.getLenta( this->tLenta.getCaretka() ) == 0 && this->getPravilo( position, 0 ).getGo() == -2 ||  this->tLenta.getLenta( this->tLenta.getCaretka() ) == 1 && this->getPravilo( position, 1 ).getGo() == -1 )
			cout << text1;
		else
			if( this->tLenta.getCaretka() == 0 || this->tLenta.getCaretka() == n - 1 )
			cout << text2;
			else return 1;
	return 0;
}
void MashinTuring::runAlgo() {
	int position = 0;
	int run = 1;
	while ( run ) { 
		position = stepGo( position, this->tLenta.getLenta( this->tLenta.getCaretka() ));
		system( "CLS" );
		cout << tLenta;
		for( int i = 0; i < this->tLenta.getCaretka(); i++ ) 
			cout << "  ";
		cout << "^" << endl;
		this->printStatusAlgo();
		if( position != -1 ) {
			cout << "    ";
			for( int i = 0; i < position - 1; i++ )
				cout << "     ";
			cout << "^^^^" << endl;
			cout << "Q" << setfill( '0' ) << setw( 2 ) << position + 1 << " : "; 
			this->printPravilo( position, this->tLenta.getLenta( this->tLenta.getCaretka() ) );
			cout << endl;
		}
		run = this->searchStop( position );
		Sleep( 1000 );
	}
	getch();
}