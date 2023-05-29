#include <iostream>
#include <string>
#include <vector>


using namespace std;


class spaceShip {

public:
	int speed;
	int Vfuel;
	int reachSpeedWithOutRefuel;
	char type;
	string name;

	spaceShip(string n, char t, int s, int Vf, int r) {
	
		name = n;
		type = t;
		speed = s;
		Vfuel = Vf;
		reachSpeedWithOutRefuel = r;
	
	}


};

void displaymenu() {
	cout <<endl <<"choose actions (1-6)" << endl;
	cout << "1: set space ship name" << endl << "2: set type of ship" << endl << "3: set speed your ship" << endl << "4: set value of fuel ship" << endl << "5 show your ship stat" << endl << "6: next ship" << endl <<"7: previos ship"<< endl << "8: show all ships" << endl << "9: exit"<< endl;
	cout << " your action set -> ";
}

int main(spaceShip) {

	cout << "program of spaceships"<<endl;

	int VectorCount=0;
	bool typeCheck = 0;
	int userNumberSet = 0;
	int userSpeedSet = 0;
	int userVfuelSet = 0;
	int userReachSpeedWithOutRefuelSet = 0;
	char userTypeSet = 'n';
	string userNameSet = "Null";
	string userPreset = "Null";

	spaceShip *ship = new spaceShip("", ' ', 0, 0, 0);

	vector<spaceShip> userSpaceShips;
	
	
	do {
		displaymenu();
		cin >> userNumberSet;
		cout << endl;
		switch (userNumberSet){

		case 1: {

			cout << "enter name of your space ship -> ";
			cin >> userNameSet;

			ship->name = userNameSet;
			

			cout << "name your ship is -> " << ship->name << endl;


			break;
		}
		case 2: {

			cout << "chose your type of ship (C - civilian|A - Armored|)";
			cin >> userTypeSet;
			cout << endl;
			typeCheck = 0;

				
			if (userTypeSet == 'A' || userTypeSet == 'a')
			{
				typeCheck = 1;
				ship->type = userTypeSet;
				cout << "Your type ship is Armored " << endl;
				break;
			}
				if (userTypeSet =='C' || userTypeSet == 'c')
				{
					typeCheck = 1;
					ship->type = userTypeSet;
					cout << "Your type ship is Civilian " << endl;
					break;
				}
				else
				{
					cout << "you entered incorrect symbol or don't choose type" << endl;
					break;
				}
				
			
			break;

		}

		case 3: {

			cout << "set speed your ship -> ";
			cin >> userSpeedSet;

			ship->speed = userSpeedSet;


			cout << "your ship speed is ->" << ship->speed << endl;
			break;

		}

		case 4: {

			cout << "set amount fuel your ship -> ";
			cin >> userVfuelSet;

			ship->Vfuel = userVfuelSet;

			cout << "your ship amount fuel is ->" << ship->Vfuel << endl;
			

			userReachSpeedWithOutRefuelSet = ship->speed / (ship->Vfuel / 2);
			ship->reachSpeedWithOutRefuel = userReachSpeedWithOutRefuelSet;

			break;
		}
		case 5: {
			
			if (ship->name == "") {
			
				cout << "you don't set name for your ship" << endl;
			
			}
			else
			{
				cout << "your ship name is -> " << ship->name << endl;
				
			}
			if (userTypeSet == 'A' || userTypeSet == 'a')
			{
				typeCheck = 1;
				cout << "Your type ship is Armored " << endl;
				
			}
			if (userTypeSet == 'C' || userTypeSet == 'c')
			{
				typeCheck = 1;
				cout << "Your type ship is Civilian " << endl;
				
			}
			else
			{
				cout << "you don't choose your type" << endl;
				
			}
			if (userSpeedSet == 0)
			{
				cout << "you don't set value speed for your ship" << endl;
			}
			else {

				cout << "your ship speed is -> " << ship->speed <<" of lightYear"<< endl;

			}
			if (userVfuelSet == 0)
			{
				cout << "you don't set Amount fuel for your ship" << endl;
			}
			else {

				cout << "your ship amount fuel is -> " << ship->Vfuel<<" of gallon"<< endl;
				cout << "time you can fly foward with out refuel is -> " << ship->reachSpeedWithOutRefuel<<" of hours"<< endl;
			}

			break;
		}
		case 6: {

			userSpaceShips[0] = *ship;
			VectorCount++;
			break;
		}
		case 7: {
		
			VectorCount--;
			break;
		}

		case 8: {
		
			userSpaceShips.push_back(spaceShip(ship->name,ship->type,ship->speed,ship->Vfuel,ship->reachSpeedWithOutRefuel));


			
			break;
		}

		case 9: {
		
			cout << "goodbye";
			break;
		}

		default: {

			cout << "whoops incorrect action set";
			break;
		     }
		}
	} while (userNumberSet != 9);
	

}