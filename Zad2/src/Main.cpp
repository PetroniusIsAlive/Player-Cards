#include<fstream>
#include"PlayerRanklist.h"

int main() 
{
	 
	Player p1("Michael", "Vsauce", 11, 0);
	p1++;
	p1.print();
	p1.savePlayer();
	
	/*PLayerRanklist ranklist;
	Player p1("Michael", "Ivanovic", 4, 4);
	Player p2("Vsaouce", "Mos", 5,5);
	
	ranklist.addPlayers(p1);
	ranklist.addPlayers(p2);
	ranklist.loadPlayers();
	ranklist.printData();
	*/
	
	
	return 0;
}