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
	
	friend ostream& operator<<(ostream& os, const spaceShip& ss) { 
		os << ss.name <<'('<< ss.type <<" type " << ss.speed <<" speed " << ss.Vfuel <<" fuel " << ss.reachSpeedWithOutRefuel <<" not refuel" << ')' << endl;
		return os;

	}
	
};

void displaymenu() {
	cout <<endl <<"choose actions (1-6)" << endl;
	cout << "1: set space ship name" << endl << "2: set type of ship" << endl << "3: set speed your ship" << endl << "4: set value of fuel ship" << endl << "5 show your ship stat" << endl << "6: new ship" << endl << "7: show all ships" << endl << "8: delete stat" << endl << "9: edit ships" << endl << "10: exit" << endl;
	cout << " your action set -> ";
}

int main(spaceShip) {

	cout << "program of spaceships" << endl;
	int showAllCount = 1;
	bool typeCheck = 0;
	int deleteUserSet = 0;
	int VectorCount = 0;
	int userNumberSet = 0;
	int userSpeedSet = 0;
	int userVfuelSet = 0;
	int userReachSpeedWithOutRefuelSet = 0;
	char userTypeSet = 'n';
	int userChoiseDelete = 0;
	string userNameSet = "Null";
	string userPreset = "Null";
	int j = 1;
	string userChangeName = "";
	char userChangeChar = ' ';
	int userChangeSpeed = 0;
	int userchangeVfuel = 0;
	int userChangeRefuel = 0;

	spaceShip* ship = new spaceShip(" ", ' ', 0, 0, 0);

	vector<spaceShip> userSpaceShips;


	do {
		displaymenu();
		cin >> userNumberSet;
		cout << endl;
		switch (userNumberSet) {

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
			if (userTypeSet == 'C' || userTypeSet == 'c')
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

				cout << "your ship speed is -> " << ship->speed << " of lightYear" << endl;

			}
			if (userVfuelSet == 0)
			{
				cout << "you don't set Amount fuel for your ship" << endl;
			}
			else {

				cout << "your ship amount fuel is -> " << ship->Vfuel << " of gallon" << endl;
				cout << "time you can fly foward with out refuel is -> " << ship->reachSpeedWithOutRefuel << " of hours" << endl;
			}

			break;
		}
		case 6: {

			userSpaceShips.push_back(spaceShip(ship->name, ship->type, ship->speed, ship->Vfuel, ship->reachSpeedWithOutRefuel));
			VectorCount++;
			ship->name = "";
			ship->type = ' ';
			ship->speed = 0;
			ship->Vfuel = 0;
			ship->reachSpeedWithOutRefuel = 0;
			showAllCount = 1;
			break;
		}

		case 7: {

			if (showAllCount == 1) {
				
				for (int i = 0; i < userSpaceShips.size();i++) {

					cout <<j<<" | " << userSpaceShips[i];
					j++;
				}
				showAllCount = 2;
				break;
			}
			if (showAllCount == 2) {

				for (int i = 0; i < userSpaceShips.size();i++) {

					cout << j<< " | " << userSpaceShips[i];
					j++;
				}
				break;
			}
			break;
		}

		case 8: {

			do
			{
				cout << "what you want delete?" << endl;
				cout << "1: name" << endl << "2: type" << endl << "3: speed" << endl << "4: fuel" << endl << "5: exit" << endl;
				cout << "set number action -> " << endl;
				cin >> deleteUserSet;

				switch (deleteUserSet)
				{
				case 1: {
					userNameSet = "";
					ship->name = "";
					cout << "done" << endl;
					break;
				}
				case 2: {
					userTypeSet = ' ';
					ship->type = ' ';
					cout << "done" << endl;
					break;;
				}
				case 3: {
					userSpeedSet = 0;
					ship->speed = 0;
					cout << "done" << endl;
					break;
				}
				case 4: {
					userVfuelSet = 0;
					ship->Vfuel = 0;
					userReachSpeedWithOutRefuelSet = 0;
					ship->reachSpeedWithOutRefuel = 0;
					cout << "done" << endl;
					break;
				}
				case 5: {

					cout << "removed done" << endl;
					break;
				}
				default: {
					cout << "error use number of action" << endl;
					break;
				}

				}


			} while (deleteUserSet != 5);
			break;
		}





		case 9: {
			
			
				cout << "chose ship";
			cin >> userChoiseDelete;
			userChoiseDelete--;
			cout << "what you want change?" << endl;
			cout << "1: name" << endl << "2: type" << endl << "3: speed" << endl << "4: fuel" << endl << "5: exit" << endl;
			cout << "set number action -> " << endl;
			cin >> deleteUserSet;
				switch (deleteUserSet)
				{
				case 1: {
					cout << "change name -> ";
					cin >> userChangeName;
					userSpaceShips[userChoiseDelete].name = userChangeName;
					cout << "done" << endl;
					break;
				}
				case 2: {
					cout << "change type -> ";
					cin >> userChangeChar;
					userSpaceShips[userChoiseDelete].type = userChangeChar;
					cout << "done" << endl;
					break;;
				}
				case 3: {
					cout << "change speed -> ";
					cin >> userChangeSpeed;
					userSpaceShips[userChoiseDelete].speed = userChangeSpeed;
					cout << "done" << endl;
					break;
				}
				case 4: {
					cout << "change fuel -> ";
					cin >> userchangeVfuel;
					userSpaceShips[userChoiseDelete].Vfuel = userchangeVfuel;
					userSpaceShips[userChoiseDelete].reachSpeedWithOutRefuel=
					userReachSpeedWithOutRefuelSet = userChangeSpeed / (userchangeVfuel / 2);
					ship->reachSpeedWithOutRefuel = 0;
					cout << "done" << endl;
					break;
				}
				case 5: {

					cout << "removed done" << endl;
					break;
				}
				default: {
					cout << "error use number of action" << endl;
					break;
				}

				}
			
			break;
		}

		case 10: {

			cout << "goodbye";
			break;
		}
		default: {

			cout << "whoops incorrect action set";
			break;
		}
		}
	} while (userNumberSet != 10);


}