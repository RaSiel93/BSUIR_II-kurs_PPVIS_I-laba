#include "menu.h";
#include "mashina.h";

int main() {
	int change = -1;
	MashinTuring TMashin;
	while(change != 0) {
		system( "CLS" );
		change = menu( 6, "Создать алгоритм;Загрузить алгоритм;Сохранить алгоритм;Редактировать алгоритм;Запустить;Выйти");
		switch( change ) {
		case 1: //TMashin.editAlgo(); break;
		case 2: TMashin.loadPravila(); break;
		case 3: break;
		case 4: TMashin.editAlgo(); break;
		case 5: TMashin.runAlgo(); break;
		default: change = 0;
		}
	}
	return 0;
}