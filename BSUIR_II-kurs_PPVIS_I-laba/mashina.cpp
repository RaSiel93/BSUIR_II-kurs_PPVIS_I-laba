#include "mashina.h";
#include "conio.h"
#include <windows.h>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;
//-----------------------------------------
Pravila::Pravila() {
	actEl = -2;
	actCar = -2;
	go = -2;

	number = -2;
	next = 0;
}

int Pravila::getCar () const {
	return actCar;
}
void Pravila::setCar( int temp ) {
	actCar = temp;
}
int Pravila::getEl () const {
	return actEl;
}
void Pravila::setEl( int temp ) {
	actEl = temp;
}
int Pravila::getGo () const {
	return go;
}
void Pravila::setGo( int temp ) {
	go = temp;
}

//----------------------------------------
void MashinTuring::AddPravilo( int temp2, int temp1, int E, int C, int G ) {
	Pravila *s = this->pravilo[ temp1 ];
	while( s != NULL) {
		if( s->getNum() == temp2 ) {
			return; 
		}
		s = s -> getNext();
	}
	Pravila *t = new Pravila;
	t->setNum( temp2 );
	t->setNext( this->pravilo[ temp1 ] );
	t->setEl( E );
	t->setCar( C );
	t->setGo( G );
	this->pravilo[ temp1 ] = t;
}

Pravila *MashinTuring::SearchPravilo( int temp2, int temp1 ) const  {
	Pravila *t = this->pravilo[ temp1 ];
	while( t!=NULL ) {
		if( t->getNum() == temp2 )
			return t;
		t = t->getNext();
	}
	return 0;
}

void MashinTuring::DelPravilo( int temp2, int temp1 ) {
	if( this->SearchPravilo( temp1, temp2 ) )
	{
		Pravila *s = this->pravilo[ temp1 ];
		Pravila *t = this->pravilo[ temp1 ]->getNext();
		if( temp2 == s->getNum() ) {
			delete s;
			this->pravilo[ temp1 ] = t;
			return;
		}
		while( t!=NULL ) {
			if( t->getNum() == temp2 ) {
				s->setNext( t->getNext() );
				delete t;
				return;
			}
			s = t;
			t = t->getNext();	
		}
	}
}
void MashinTuring::ClearPravila() {
	Pravila *t;
	while( this->pravilo[ 0 ] != NULL ) {
		t = this->pravilo[ 0 ];
		this->pravilo[ 0 ] = this->pravilo[ 0 ]->getNext();
		delete t;
	}
	while( this->pravilo[ 1 ] != NULL ) {
		t = this->pravilo[ 1 ];
		this->pravilo[ 1 ] = this->pravilo[ 1 ]->getNext();
		delete t;
	}
}
//-----------------------------------------
ostream &operator<<( ostream &output, const MashinTuring &MT ) {
	for( int i = MT.getHelpScreen(); i < MT.getHelpScreen() + 40; i++ ) {
		Lenta *t = MT.lentMassiv;
		while( t != NULL ) {
			if( i == t->getInfo() ) {
				cout << "1 ";
				break;
			}
			t = t->getNext();
		}
		if( t == NULL )
			cout << "0 ";
	}
	return output;
}
istream &operator>>( istream &input, MashinTuring &MT ) {
	int position;
	input >> position;
	MT.AddElement( position );
	return input;
}

MashinTuring &MashinTuring::operator++(){
	this->setCaretka( this->getCaretka() + 1 );
	return *this;
}

MashinTuring &MashinTuring::operator--(){
	this->setCaretka( this->getCaretka() - 1 );
	return *this;
}

bool MashinTuring::operator==( const MashinTuring &MT ) const {
	if( this->getCaretka() != MT.getCaretka() )
		return 0;
	
	Lenta *t = MT.lentMassiv;
	while( t != NULL ) {
		if( !MT.SearchElement( this->lentMassiv->getInfo() ) ) 
			return 0;
		t = t->getNext();
	}
	t = this->lentMassiv;
	while( t != NULL ) {
		if( !this->SearchElement( MT.lentMassiv->getInfo() ) ) 
			return 0;
		t = t->getNext();
	}

	Pravila *p = MT.pravilo[ 0 ], *s;
	while( p != NULL ) {
		if( !( s = MT.SearchPravilo( this->pravilo[ 0 ]->getNum(), 0 ) ) ) 
			return 0;
		if( s->getCar() != this->pravilo[ 0 ]->getCar()) return 0;
		if( s->getEl() != this->pravilo[ 0 ]->getEl()) return 0;
		if( s->getGo() != this->pravilo[ 0 ]->getGo()) return 0;
		p = p->getNext();
	}	
	p = MT.pravilo[ 1 ];
	while( p != NULL ) {
		if( !( s = MT.SearchPravilo( this->pravilo[ 1 ]->getNum(), 1 ) ) ) 
			return 0;
		if( s->getCar() != this->pravilo[ 1 ]->getCar()) return 0;
		if( s->getEl() != this->pravilo[ 1 ]->getEl()) return 0;
		if( s->getGo() != this->pravilo[ 1 ]->getGo()) return 0;
		p = p->getNext();
	}
	p = this->pravilo[ 0 ];
	while( p != NULL ) {
		if( !( s = this->SearchPravilo( MT.pravilo[ 0 ]->getNum(), 0 ) ) ) 
			return 0;
		if( s->getCar() != MT.pravilo[ 0 ]->getCar()) return 0;
		if( s->getEl() != MT.pravilo[ 0 ]->getEl()) return 0;
		if( s->getGo() != MT.pravilo[ 0 ]->getGo()) return 0;
		p = p->getNext();
	}	
	p = this->pravilo[ 1 ];
	while( p != NULL ) {
		if( !( s = this->SearchPravilo( MT.pravilo[ 1 ]->getNum(), 1 ) ) ) 
			return 0;
		if( s->getCar() != MT.pravilo[ 1 ]->getCar()) return 0;
		if( s->getEl() != MT.pravilo[ 1 ]->getEl()) return 0;
		if( s->getGo() != MT.pravilo[ 1 ]->getGo()) return 0;
		p = p->getNext();
	}
	return 1;
}
//-----------------------------------------
MashinTuring::MashinTuring() {
	lentMassiv = 0;
	caretka = 100;
	helpScreen = 0;
	helpScreenPravila = 0;
	pravilo[ 0 ] = 0;
	pravilo[ 1 ] = 0;
}
MashinTuring::MashinTuring( const MashinTuring &copy )
	: caretka( copy.caretka ), helpScreen( copy.helpScreen ), 
	helpScreenPravila( copy.helpScreenPravila ){
	Lenta *t = copy.lentMassiv;
	this->lentMassiv = 0;
	while( t != NULL ) {
		this->AddElement( t->getInfo() );
		t = t -> getNext();
	}
	Pravila *p = copy.pravilo[ 0 ];
	this->pravilo[ 0 ] = 0;
	while( p != NULL) {
		this->AddPravilo( p->getNum(), 0, p->getEl(), p->getCar(), p->getGo() );
		p = p->getNext();
	}
	p = copy.pravilo[ 1 ];
	this->pravilo[ 1 ] = 0;
	while( p != NULL) {
		this->AddPravilo( p->getNum(), 1, p->getEl(), p->getCar(), p->getGo() );
		p = p->getNext();
	}
}

MashinTuring::~MashinTuring() {
	this->ClearElements();
	this->ClearPravila();
}

int MashinTuring::getCaretka() const {
	return caretka;
}
void MashinTuring::setCaretka( int temp ) {
	caretka = temp;
}

void MashinTuring::AddElement( int temp ) {
	Lenta *s = this->lentMassiv;
	while( s != NULL) {
		if( s->getInfo() == temp ) {
			return; 
		}
		s = s -> getNext();
	}
	Lenta *t = new Lenta;
	t->setInfo( temp );
	t->setNext( this->lentMassiv );
	this->lentMassiv = t;
}

bool MashinTuring::SearchElement( int temp ) const {
	Lenta *t = this->lentMassiv;
	while( t!=NULL ) {
		if( t->getInfo() == temp )
			return 1;
		t = t->getNext();
	}
	return 0;
}

void MashinTuring::DelElement( int temp ) {
	if( this->SearchElement( temp ) )
	{
		Lenta *s = this->lentMassiv;
		Lenta *t = this->lentMassiv->getNext();
		if( temp == s->getInfo() ) {
			delete s;
			this->lentMassiv = t;
			return;
		}
		while( t!=NULL ) {
			if( t->getInfo() == temp ) {
				s->setNext( t->getNext() );
				delete t;
				return;
			}
			s = t;
			t = t->getNext();	
		}
	}
}

void MashinTuring::ClearElements() {
	Lenta *t;
	while( this->lentMassiv != NULL ) {
		t = this->lentMassiv;
		this->lentMassiv = this->lentMassiv->getNext();
		delete t;
	}
}
//-----------------------------------------
void MashinTuring::printPravilo( int x, int y ) {
	if( !this->SearchPravilo( x, y ) )
		cout << "    ";
	else {
	cout << this->SearchPravilo( x, y )->getEl();
	
	if( this->SearchPravilo( x, y )->getCar() == -1 ) cout << "<";
	if( this->SearchPravilo( x, y )->getCar() == 1 ) cout << ">";
	if( this->SearchPravilo( x, y )->getCar() == 0 ) cout << "-";
	
	if( this->SearchPravilo( x, y )->getGo() == -1 ) cout << "S ";
	else
		cout << setfill( '0' ) << setw (2) << this->SearchPravilo( x, y )->getGo() + 1;
	}
}

void MashinTuring::printStatusAlgo() {
	cout << "===============================================================================" << endl;
	cout << " / ";
	for(  int i = getHelpScreenPravila(); i < getHelpScreenPravila() + 15; i++ )
		cout << "| Q" << setfill( '0' ) << setw(2) << i + 1;
	cout << endl;
	cout << " 0 ";
	for( int i = getHelpScreenPravila(); i < getHelpScreenPravila() + 15; i++ ) {
		cout << "|"; 
		this->printPravilo( i, 0 );
	}
	cout << endl;
	cout << " 1 ";
	for( int i = getHelpScreenPravila(); i < getHelpScreenPravila() + 15; i++ ) {
		cout << "|"; 
		this->printPravilo( i, 1 );
	}
	cout << endl;
	cout << "===============================================================================" << endl;
}

int MashinTuring::stepGo( int x, int y ) {
	if ( this->SearchPravilo( x, y )->getEl() )
		this->AddElement( this->getCaretka() );
	else 
		this->DelElement( this->getCaretka() );
	this->setCaretka( this->getCaretka() + this->SearchPravilo( x, y )->getCar() );
	return this->SearchPravilo( x, y )->getGo();
}

int MashinTuring::searchStop( int position ) {
	char textE2[] = "Алгоритм успешно завершен!\0", text1[ 50 ];
	CharToOem ( textE2, text1 );
	char textA1[] = "Ошибка! Нет правила для текущей ячейки.\0", text2[ 50 ];
	CharToOem ( textA1, text2 );
	if( position == -1 ) {
		cout << text1 << endl;
		return 1;
	} else if( !this->SearchElement( this->getCaretka() ) && !( this->SearchPravilo( position, 0 ) ) ||  this->SearchElement( this->getCaretka() ) && !( this->SearchPravilo( position, 1 ) ) ) {
		cout << text2 << endl;
		return 1;
	}
	cout << endl;
	return 0;
}
//---------------------------------------
void MashinTuring::helpScreenEdit( MashinTuring &MT ) {
	if( MT.getHelpScreen() - MT.getCaretka() < - 39 ) MT.setHelpScreen( MT.getHelpScreen() + 1 );		
	if( MT.getHelpScreen() - MT.getCaretka() > 0 ) MT.setHelpScreen( MT.getHelpScreen() - 1 );
}

void MashinTuring::helpScreenEditPravila( MashinTuring &MT, int position ) {
	if( position > 7 ) {
		if( MT.getHelpScreenPravila() - position < - 15 ) MT.setHelpScreenPravila( position + 7 );		
		if( MT.getHelpScreenPravila() - position > 0 ) MT.setHelpScreenPravila( position - 7 ); 
	}
	else 
		MT.setHelpScreenPravila( 0 );
}
//---------------------------------------
MashinTuring &creatAlgo( const char* path ) {
	char tempPath[ 50 ];
	char textL1[] = "Алгоритм успешно создан: \0", text1[ 50 ];
	CharToOem ( textL1, text1 );
	char textL2[] = "Ошибка создания файла: \0", text2[ 50 ];
	CharToOem ( textL2, text2 );
	
	FILE *Fc;
	if( !( Fc = fopen( path, "wb" ) ) )
	{
		cout << text2 << path << endl;
		exit( 1 );
	}
	fclose( Fc );
	cout << text1 << path;
	getch();
	MashinTuring *MT = new MashinTuring;
	return *MT;
}

MashinTuring &loadAlgo( const char* path ) {
	char textL1[] = "Алгоритм успешно загружен: \0", text1[ 50 ];
	CharToOem ( textL1, text1 );
	char textL2[] = "Ошибка загрузки файла: \0", text2[ 50 ];
	CharToOem ( textL2, text2 );
	
	int temp, count, t1, t2, t3, t4, t5;
	FILE *Fr = fopen( path, "r" );
	if( !Fr ) {
		cout << text2 << path;
		exit( 1 );
	}
	
	MashinTuring *MT = new MashinTuring;

	fscanf( Fr, "%d", &temp );
	MT->setCaretka( temp );
	fscanf( Fr, "%d", &count );
	for( int i = 0; i < count; i++ ) {
		fscanf ( Fr, "%d", &temp );
		MT->AddElement( temp );
	}
	fscanf( Fr, "%d", &count );
	for( int i = 0; i < count; i++ ) {
		fscanf( Fr, "%d", &t1 );
		fscanf( Fr, "%d", &t2 );
		fscanf( Fr, "%d", &t3 );
		fscanf( Fr, "%d", &t4 );
		fscanf( Fr, "%d", &t5 );
		MT->AddPravilo( t1 - 1, t2, t3, t4, t5 - 1 );
	}
	fclose( Fr );
	cout << text1 << path;
	getch();
	return *MT;
}

void saveAlgo( MashinTuring &MT, const char *path ) {
	char textL1[] = "Алгоритм успешно сохранен: \0", text1[ 50 ];
	CharToOem ( textL1, text1 );
	char textL2[] = "Ошибка сохранения файла: \0", text2[ 50 ];
	CharToOem ( textL2, text2 );
	
	int temp, count = 0, t1, t2, t3, t4, t5;
	FILE *Fw = fopen( path, "wb" );
	if( !Fw ) {
		cout << text2 << path;
		exit( 1 );
	}

	fprintf( Fw, "%d\n", MT.getCaretka() );
	for( int i = 0; i < 40; i++ ) {
		if( MT.SearchElement( i ) )
			count++;
	}
	fprintf( Fw, "%d\n", count );
	
	for( int i = 0; i < 40; i++ ) {
		if( MT.SearchElement( i ) ) {
			fprintf( Fw, "%d\n", i );
		}
	}

	count = 0;
	for( int x = 0; x < 15; x++ ) {
		for ( int y = 0; y < 2; y++ )
			if( MT.SearchPravilo( x, y ) )
				count++;
	}
	fprintf( Fw, "%d\n", count );
	for( int y = 0; y < 2; y++ ) {
		for ( int x = 0; x < 15; x++ ) {
			if( MT.SearchPravilo( x, y ) )
			{
				fprintf( Fw, "%d ", x + 1 );
				fprintf( Fw, "%d ", y );
				fprintf( Fw, "%d ", MT.SearchPravilo( x, y )->getEl() );
				fprintf( Fw, "%d ", MT.SearchPravilo( x, y )->getCar() );
				fprintf( Fw, "%d\n", MT.SearchPravilo( x, y )->getGo() + 1 );
			}
		}
	}
	fclose( Fw );
	cout << text1 << path;
	getch();
}

MashinTuring &editAlgo( MashinTuring &MT ) {
	char textE1[] = "Файл не создан.\0", text1[ 50 ];
	CharToOem ( textE1, text1 );
	if ( &MT != 0 ) { 

	int change = -1;
	char textT1[] = "1.Добавить правило/2.Удалить правило/3.Сброс правил/4.Сброс ленты/5.Назад\0", text1[ 90 ];
	char textT2[] = "Введите позицию правила. Пример: 9 1 это Q09/1: \0", text2[ 80 ];
	char textT3[] = "Введите действие над текущей ячейкой (0 или 1), сдвиг каретки (-1, 0, 1) и позицию следующего правила( или 0 - stop ). Пример: 0 1 8 это изменить содержимое на 0, сдвинуть каретку влево, перейти на правило Q08: \0", text3[ 220 ];
	CharToOem ( textT1, text1 ); CharToOem ( textT2, text2 ); CharToOem ( textT3, text3 );
	MT.setHelpScreen( MT.getCaretka() - 20 );
	while ( change != 13 ) {
		change = -1;
		MT.helpScreenEdit( MT );
		cout << MT;
		int size = MT.getCaretka();
		for( int i = MT.getHelpScreen(); i < MT.getCaretka(); i++ ) {
			cout << "  ";
		}
		cout << "^" << endl;
		MT.printStatusAlgo();
		
		int x, y;
		int a, s, p;

		cout << text1 << endl;
		change = getch();
		if ( change == 77 )
			MT.setCaretka( ++size );
		if ( change == 75 )
			MT.setCaretka( --size );
		if (change == 32 )
			if( MT.SearchElement( size ) )
				MT.DelElement( size );
			else
				MT.AddElement( size );
		switch ( change - 48 ) {
		case 1:
			
		case 2: 
			cout << change - 48 << "." << text2; 
			while( 1 ) {
				cin >> x >> y;
				x -= 1;
				if ( y < 0 || y > 1 || x < 0 ) cout << "Invalid data!" << endl; 
				else break;
			}
			
			if( change - 48 == 1) {
				cout << endl << text3;
				cin >> a >> s >> p;
				p -= 1;
				MT.AddPravilo( x, y, a, s, p );
			}
			else 
				MT.DelPravilo( x, y );
			system( "CLS" );
			break;
		case 3:
			MT.ClearPravila();
			system( "CLS" );
			break;
		case 4:
			MT.ClearElements();
			system( "CLS" );
			break;
		case 5: change = 13; 
		}
		system( "CLS" );
	}
	}
	else {
		cout << text1;
		getch();
	}
	return MT;
}

void runAlgo( MashinTuring &MT, bool log ) {
	char textE1[] = "Файл не создан.\0", text1[ 50 ];
	CharToOem ( textE1, text1 );
	if ( &MT != 0 ) {
		MT.setHelpScreen( MT.getCaretka() - 20 );
		int position = 0, stop = 0;
		while ( !stop ) { 
			system( "CLS" );
			stop = MT.searchStop( position );
			MT.helpScreenEdit( MT );
			cout << MT;	
			for( int i = MT.getHelpScreen(); i < MT.getCaretka(); i++ ) 
				cout << "  ";
			cout << "^" << endl;

			//cout << position << "		" << MT.getHelpScreenPravila() << endl;	
			MT.helpScreenEditPravila( MT, position );
			MT.printStatusAlgo();	
			
			if( log ) {
				cout << "    ";
				for( int i = MT.getHelpScreenPravila(); i < position; i++ )
					cout << "     ";
				cout << "^^^^" << endl;

				cout << "Q" << setfill( '0' ) << setw( 2 ) << position + 1 << " : "; 
				MT.printPravilo( position, MT.SearchElement( MT.getCaretka() ) );
				
				getch();
			}
			if( !stop ) position = MT.stepGo( position, MT.SearchElement( MT.getCaretka() ) );
			//Sleep( 1000 );
		}
		getch();
	}
	else {
		cout << text1;
		getch();
	}
	return;
}