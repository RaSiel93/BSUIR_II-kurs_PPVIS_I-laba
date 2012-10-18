/// @file mashina.h
/// @author Поплавский Александр Евгеньевич
/// @date октябрь 2012 года
///

#ifndef MASHINA_H
#define MASHINA_H

#include "conio.h"
#include <windows.h>

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include <fstream>
#include <string>
#include <fstream>

using namespace std;

/// @class Pravila
///
/// @brief Класс представляет набор правил к машине Тьюринга.
///
/// @author Поплавский Александр Евгеньевич
/// @date октябрь 2012 года
///
class Pravila {
public:
	/// @brief Создаёт путое правило.
	///
	Pravila();
	/// @return Номер действия над элементом, на котором, при выполнении правила, будет стоять каретка.
	///
	int getEl() const;
	/// @brief Задает номер действия над элементом, на котором, при выполнении правила, будет стоять каретка.
	///
	void setEl( int );
	/// @return Номер сдвига каретки, при выполнении правила.
	///	
	int getCar() const;
	/// @brief Задает номер сдвига каретки, при выполнении правила.
	///
	void setCar( int );
	/// @return Номер следующего правила.
	///	
	int getGo() const;
	/// @brief Задает номер следующего правила.
	///
	void setGo( int );
	/// @return Следующее по стеку правило.
	///	
	Pravila* getNext() { return this->next; }
	/// @brief Задает следующее по стеку правило.
	///	
	void setNext( Pravila *temp ) { this->next = temp; }
	/// @return Номер правила в стеке.
	///	
	int getNum() const { return number; }
	/// @brief Задает номер правила в стеке.
	///		
	void setNum( int temp ) { number = temp; }
private:
	int actEl;
	int actCar;
	int go;

	int number;
	Pravila *next;
};

/// @class Lenta
///
/// @brief Класс представляет ленту.
///
/// @author Поплавский Александр Евгеньевич
/// @date октябрь 2012 года
///
class Lenta {
public:
	/// @return Элемент ленты
	///
	Lenta* getNext() { return this->next; }
	/// @brief Задать элемент ленты
	///
	void setNext( Lenta *temp ) { this->next = temp; }
	/// @return Задать номер позиции еденицы в ленте
	///
	int getInfo() { return this->info; }
	/// @brief Задает номер позиции еденицы в ленте
	///
	void setInfo( int temp ) { this->info = temp; }
private:
	int info;
	Lenta *next;
};

/// @class MashinTuring
///
/// @brief Класс для представления машины Тьюринга.
///
/// @author Поплавский Александр Евгеньевич
/// @date октябрь 2012 года
///
class MashinTuring {
	/// @brief Считывает из потока stream ленту в принятом виде.
	///
	friend ostream &operator<<( ostream &, const MashinTuring & );
	/// @brief Выводит в поток stream ленту в принятом виде.
	///
	friend istream &operator>>( istream &, MashinTuring & );
	// создает объект класса MashinTuring
	friend MashinTuring &creat( const char*, bool );
	// загружает объект класса MashinTuring
	friend MashinTuring &load( const char*, bool );
	// сохраняет объект класса MashinTuring
	friend void save( MashinTuring&, const char*, bool );
	// редактирует объект класса MashinTuring
	friend MashinTuring &edit( MashinTuring &, bool );
	// запускает алгоритм объекта класса MashinTuring
	friend MashinTuring &run( MashinTuring &, bool );

public:
	bool operator==( const MashinTuring & ) const;
	bool operator!=( const MashinTuring & ) const;
	MashinTuring &operator=( const MashinTuring & );
	// сдвигает каретку вправо
	MashinTuring &operator++();
	// сдвигает каретку влево
	MashinTuring &operator--();
	// проверяет наличие единицы на элементе ленты
	bool operator[]( int ) const;

	MashinTuring();
	MashinTuring( const MashinTuring & );
	~MashinTuring();
	// возвращает позицию каретки	
	int getCaretka() const;
	// задает позицию каретки
	void setCaretka( int );
	// добавляет единицу на ленту
	void AddElement( int );
	// проверяет наличие единицы на элементе ленты
	bool SearchElement( int ) const;
	// обнуляет значение элемента ленты
	void DelElement( int );
	// обнуляет всю ленту
	void ClearElements();
	// добавляет правило
	void AddPravilo( int, int, int, int, int );
	// возвращает правило по адресу
	Pravila *SearchPravilo( int, int ) const;
	// удаляет правило по адресу
	void DelPravilo( int, int );
	// удаляет все правила
	void ClearPravila();
//вспомогательные элементы для отображения правил
	int getHelpScreenPravila() const { return helpScreenPravila; }
	void setHelpScreenPravila( int temp ){ helpScreenPravila = temp; }
	void helpScreenEditPravila( MashinTuring &, int );
//вспомогательные элементы для отображения ленты
	int getHelpScreen() const { return helpScreen; }
	void setHelpScreen( int temp ){ helpScreen = temp; }
	void helpScreenEdit( MashinTuring & );
	// вывод ленты на консоль
	void printStatusAlgo();
	// вывод правил на консоль
	void printPravilo( int, int );
	// выполняет текущее правило алгоритма
	int stepGo( int, int );
	// проверяет условие остоновки алгоритма
	int searchStop( int, bool );
private:	
//вспомогательная позиция для ленты и правил	
	int helpScreen;
	int helpScreenPravila;
//каретка, лента, правила
	int caretka;
	Lenta *lentMassiv;
	Pravila *pravilo[ 2 ];
};

#endif //MASHINA_H