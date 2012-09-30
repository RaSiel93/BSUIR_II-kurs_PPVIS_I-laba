#include <iostream>

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
public:
	MashinTuring();
	Pravila getPravilo( int, int );
	void setPravilo( int, int, int, int, int );
	void printPravilo( int, int );
	void printStatusAlgo();
	void editAlgo();
	void loadPravila();
	void runAlgo();
	int stepGo( int, int );
	int searchStop( int );
private:
	Lenta tLenta;
	Pravila pravilo[ 15 ][ 2 ];
};

