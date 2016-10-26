#include <iostream>
#include <cctype>

using namespace std;

char getAge(char & age); 
char getRound(char & round);
char getPeak(char & peak);
bool validAge(char input);
bool validRound(char input);
bool validPeak(char input);
double getCost(double & cost,char age, char round,char peak);
double getDouble();
double calculateChange(double money,double cost);
bool validate(char input,string type);
bool purchaseAgain(bool & purchase);

int main(){
	//define age variable
	char round;
	char peak;
	char age;
	double cost;
	double money;
	bool purchase = true;
	
	cout << "Welcome to the train station!\n";
	while(purchase == true){
		if(getAge(age) == 'X'){
			cout << "Exiting\n";
			return 0;
		}
		if(getRound(round) == 'X'){
			cout << "Exiting\n";
			return 0;
		}
		if(getPeak(peak) == 'X'){
			cout << "Exiting\n";
			return 0;
		}
		
		getCost(cost,age,round,peak);
		cout << "That will be:\n";
		cout << cost << endl;

		money = getDouble();
		
		if(money > cost){
			money = calculateChange(money,cost);
			cout << "Your change is: " << money << endl;
			cout << "Thank you for your purchase!\n";
		} else {
			cout << "Thanks for your purchase!\n";
		}
		purchase = purchaseAgain(purchase);
	}
}

bool validate(char input,string type){
	if(type == "age"){
		if (input == 'R' || input == 'S' || input == 'C' || input == 'X'){
			return true;
		} else {
			return false;
		}
	} else if (type == "round"){
		if (input == 'O' || input == 'R' || input == 'X'){
			return true;
		} else {
			return true;
		}
	} else if (type == "peak"){
		if (input == 'O' || input == 'R' || input == 'X'){
			return true;
		} else {
			return true;
		}
	} else {
		return false;
	}
}
//validate
bool validAge(char input){
	if (input == 'R' || input == 'S' || input == 'C' || input == 'X'){
		return true;
	} else {
		return false;
	}
}

bool validRound(char input){
	if (input == 'O' || input == 'R' || input == 'X'){
		return true;
	} else {
		return false;
	}
}

bool validPeak(char input){
	if (input == 'P' || input == 'O' || input == 'X'){
		return true;
	} else {
		return false;
	}
}

char getAge(char & age){
	char input;
	cout << "Choose your ticket age:\n R -- Regular \n S -- Senior \n C -- Child\n";
	cin >> input;
	
	while (!validAge(input)){
		cout << "Please make a valid selection\n";
		cin >> input;
		input = toupper(input);
	}

	age = input;
	return age;
}

//get input
char getRound(char & round){
	char input;
	cout << "Choose your ticket trip type:\n O -- One Way \n R -- Round Trip \n";
	cin >> input;
	while (!validRound(input)){
		cout << "Please make a valid selection\n";
		cin >> input;
		input = toupper(input);
	}

	round = input;
	return round;
}

char getPeak(char & peak){
	char input;
	cout << "Choose your ticket peak:\n P -- Peak \n O -- Off Peak \n";
	cin >> input;
	while (!validPeak(input)){
		cout << "Please make a valid selection\n";
		cin >> input;
		input = toupper(input);
	}

	peak = input;
	return peak;
}

//operate on input
double getCost(double & cost,char age, char round, char peak){
	if(age == 'R'){
		//regular
		if (round == 'O'){
			if(peak == 'O'){
				cost = 6.50;
				return 6.50;
			}
			if(peak == 'P'){
				cost = 8.75;
				return 8.75;
			}
		}
		if (round == 'R'){
			if(peak == 'O'){
				cost = 13.00;
				return 13.00;
			}
			if(peak == 'P'){
				cost = 17.50;
				return 17.50;
			}
		}
	} else if (age == 'C') {
		//child
		if (round == 'O'){
			if(peak == 'O'){
				cost = 3.25;
				return 3.25;
			}
			if(peak == 'P'){
				cost = 4.25;
				return 4.25;
			}
		}
		if (round == 'R'){
			if(peak == 'O'){
				cost = 6.50;
				return 6.50;
			}
			if(peak == 'P'){
				cost = 8.50;
				return 8.50;
			}
		}
	} else {
		//seniors
		if (round == 'O'){
			if(peak == 'O'){
				cost = 4.25;
				return 4.25;
			}
			if(peak == 'P'){
				cost = 4.25;
				return 4.25;
			}
		}
		if (round == 'R'){
			if(peak == 'O'){
				cost = 8.50;
				return 8.50;
			}
			if(peak == 'P'){
				cost = 17.50;
				return 17.50;
			}
		}
	}
	return 0;	
}

double getDouble(){
	double amount;
	cout << "Please Enter an amount of money:\n";
	cin >> amount;
	return amount;
}

double calculateChange(double money,double cost){
	double change;
	cout << "Calculating change...\n";
	change = money - cost;
	return change;
}

bool purchaseAgain(bool & purchase){
	char input;
	cout << "Would you like to buy another ticket? Y - Yes N - No\n";
	cin >> input;
	input = toupper(input);
	if (input == 'Y'){
		return true;
	} else {
		return false;
	}
	return false;
}

//passing by value:
	//will not change the variable in memory

//passing by reference:
	//WILL change the variable in memory