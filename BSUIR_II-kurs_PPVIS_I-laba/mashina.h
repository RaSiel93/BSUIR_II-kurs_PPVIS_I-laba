#include <iostream>

#include "conio.h"

using std::ostream;

const int n = 40;

class Pravila {
public:
	Pravila();
	int getEl() const;
	void setEl( int );
	int getCar() const;
	void setCar( int );
	int getGo() const;
	void setGo( int );
private:
	int actEl;
	int actCar;
	int go;
};

class Lenta {
	friend ostream &operator<<( ostream &, const Lenta );
public:
	int getLenta( int ) const;
	void setLenta( int, int );
	int getCaretka() const;
	void setCaretka( int );
	void clearLenta();
private:
	int lenta[ n ];	
	int caretka;
};

class MashinTuring {
friend MashinTuring* creatAlgo( const char* );
friend MashinTuring* loadAlgo( const char* );
friend void saveAlgo( MashinTuring*, const char* );
friend MashinTuring* editAlgo( MashinTuring* );
friend void runAlgo( MashinTuring*, const char* );
public:
	MashinTuring();
	Pravila getPravilo( int, int );
	void setPravilo( int, int, int, int, int );
	void printPravilo( int, int );
	void printStatusAlgo();
	int stepGo( int, int );
	int searchStop( int );
	Lenta tLenta;
private:
	Pravila pravilo[ 15 ][ 2 ];
};