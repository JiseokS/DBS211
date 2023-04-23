// Group 6 Milestone2
// 2021-11-30
// Name              Email         
// Jiseok Shim       jshim13@myseneca.ca
// Anson Hammell     athammell@myseneca.ca
#include <iostream>
#include <iomanip>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;
//Jiseok Shim 122758170
struct Passenger {
	int PassengerNumber;
	string DepartureStationID;
	string DestinationStationID;
	string PassengerName;
	string Gender;
	int Fare;
	int Age;
	int SeatNumber;
};
//Anson Hammell 022458145
struct User
{
	int userNum;
	int couponNum;
	string fName;
	string lName;
	string address;
	string gender;
	double phoneNum;
	int age;
	string email;
};
//Jiseok Shim 122758170
int findPassenger(Connection* conn, int PassengerNumber, struct Passenger* pas);
void displayPassenger(Connection* conn, struct Passenger pas);
void displayAllPassenger(Connection* conn);
//Anson Hammell 022458145
int findUser(Connection* conn, int userNumber, struct User* usr);
void displayUser(Connection* conn, struct User usr);
void displayAllUsers(Connection* conn);
//Jiseok Shim 122758170
//Anson Hammell 022458145
int menu();
int main(void)
{

	//OCCI Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	//User Variables
	string str;
	string usr = "dbs211_213i25";
	string pass = "61321698";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	struct Passenger pass1;
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Database Connection is Successful!" << endl;
		cout << "Project Milestone 1 and 2" << endl;
		cout << "--Project Group 6--" << endl;
		cout << " Anson Hammell" << endl;
		cout << " Jiseok Shim " << endl << endl;;

		struct Passenger pas;
		struct User usr;
		bool keepgoing = false;

		int input, num = 0;
		do
		{
			input = menu();

			switch (input)
			{
			//Jiseok Shim 122758170
			case 1:
				keepgoing = true;
				cout << "Enter Passenger Number: ";
				cin >> num;
				if (findPassenger(conn, num, &pas) == 1)
				{
					cout << endl << "Valid Passenger" << endl << endl;
				}
				else
				{
					cout << "Passenger " << num << " does not exist." << endl << endl;
				}
				break;
			case 2:
				keepgoing = true;
				cout << "Enter Passenger Number to display an Passenger: ";
				cin >> num;
				if (findPassenger(conn, num, &pas) == 1)
				{
					displayPassenger(conn, pas);
				}
				else
				{
					cout << "Passenger " << num << " does not exist." << endl << endl;
				}
				break;
			case 3:
				keepgoing = true;
				displayAllPassenger(conn);
				break;
				
			//Anson Hammell 022458145
			case 4:
				keepgoing = true;
				cout << "Enter User Number: ";
				cin >> num;
				if (findUser(conn, num, &usr) == 1)
				{
					cout << endl << "Valid User" << endl << endl;
				}
				else
				{
					cout << "User " << num << " does not exist." << endl << endl;
				}
				break;
			case 5:
				keepgoing = true;
				cout << "Enter the User Number to display a User: ";
				cin >> num;
				if (findUser(conn, num, &usr) == 1)
				{
					displayUser(conn, usr);
				}
				else
				{
					cout << "User " << num << " does not exist." << endl << endl;
				}
				break;
			case 6:
				keepgoing = true;
				displayAllUsers(conn);
				break;
  
			case 0:
				cout << endl << "Thank You and Goodbye!" << endl;
				keepgoing = false;
				break;
				
			}
		} while (keepgoing);

		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}
//Jiseok Shim 122758170
int findPassenger(Connection* conn, int PassengerNumber, Passenger* pas)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT PassengerNumber, DepartureStationID, DestinationStationID, PassengerName, Gender, Fare, Age, SeatNumber FROM Passenger WHERE PassengerNumber=" + to_string(PassengerNumber));

	if (!rs->next())
	{
		return 0;
	}
	else
	{
		pas->PassengerNumber = rs->getInt(1);
		pas->DepartureStationID = rs->getString(2);
		pas->DestinationStationID = rs->getString(3);
		pas->PassengerName = rs->getString(4);
		pas->Gender = rs->getString(5);
		pas->Fare = rs->getInt(6);
		pas->Age = rs->getInt(7);
		pas->SeatNumber = rs->getInt(8);
		return 1;
	}
}

//Jiseok Shim 122758170
void displayPassenger(Connection* conn, struct Passenger pas)
{
	cout << "------------- Passenger Information -------------" << endl;
	cout << "Passenger Number = " << pas.PassengerNumber << endl;
	cout << "Departure Station ID = " << pas.DepartureStationID << endl;
	cout << "Destination Station ID = " << pas.DestinationStationID << endl;
	cout << "Passenger Name = " << pas.PassengerName << endl;
	cout << "Gender = " << pas.Gender << endl;
	cout << "Fare = " << pas.Fare << endl;
	cout << "Age = " << pas.Age << endl;
	cout << "Seat Number = " << pas.SeatNumber << endl << endl;
}
//Jiseok Shim 122758170
void displayAllPassenger(Connection* conn)
{

		Statement* stmt2 = conn->createStatement();
		ResultSet* rs2 = stmt2->executeQuery("SELECT PassengerNumber, DepartureStationID, DestinationStationID, PassengerName, Gender, Fare, Age, SeatNumber FROM passenger");

		cout << endl << "------------- All Passengers -------------" << endl << endl;
		cout << "Passenger Number  " << setw(18) << "Departure Station ID  " << setw(18) << "Destination Station ID  " << setw(18) << "Passenger Name" << setw(10) << "Gender" << setw(10) << "Fare" << setw(10) << "Age   " << setw(10) << "Seat Number" << endl;
		cout.width(110);
		cout.fill('-');
		cout << '-' << endl;
		cout.fill(' ');

		while (rs2->next())
		{
			int PassengerNumber = rs2->getInt(1);
			string DepartureStationID = rs2->getString(2);
			string DestinationStationID = rs2->getString(3);
			string PassengerName = rs2->getString(4);
			string Gender = rs2->getString(5);
			int Fare = rs2->getInt(6);
			int Age = rs2->getInt(7);
			int SeatNumber = rs2->getInt(8);
			cout.setf(ios::left);
			cout.width(18);
			cout << PassengerNumber << " ";
			cout.width(18);
			cout << DepartureStationID << " ";
			cout.width(28);
			cout << DestinationStationID << " ";
			cout.width(18);
			cout << PassengerName << " ";
			cout.width(10);
			cout << Gender << " ";
			cout.width(10);
			cout << Fare << " ";
			cout.width(10);
			cout << Age << " ";
			cout.width(10);
			cout << SeatNumber << endl;
		}
		cout << endl;
}
//Jiseok Shim 122758170
//Anson Hammell 022458145
int menu(void)
{
	cout << "------------- HR Menu -------------" << endl;
	cout << "1. Find Passenger" << endl;
	cout << "2. Passenger Report" << endl;
	cout << "3. Display All Passenger" << endl;
	cout << "4. Find User" << endl;
	cout << "5. Display User" << endl;
	cout << "6. Display All Users" << endl;
	cout << "0. Exit" << endl; cout << "\nEnter your choice: ";
	int choice;
	char newline;
	bool done;
	do
	{
		cin >> choice;
		newline = cin.get();
		if (cin.fail() || newline != '\n')
		{
			done = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid. Enter an option from 0 to 12: ";
		}
		else
		{
			done = choice >= 0 && choice <= 12;
			if (!done)
			{
				cout << "Invalid. Enter an option from 0 to 12: ";
			}
		}
	} while (!done);
	return choice;
}
//Anson Hammell 022458145
int findUser(Connection* conn, int userNumber, User* usr)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT USER_NUMBER, COUPON_NUMBER, FIRSTNAME, LASTNAME, ADDRESS, GENDER, PHONE, AGE, EMAIL FROM TrainUser WHERE USER_NUMBER =" + to_string(userNumber));
	if (rs->next())
	{
		return 0;
	}
	else
	{
		usr->userNum = rs->getInt(1);
		usr->couponNum = rs->getInt(2);
		usr->fName = rs->getString(3);
		usr->lName = rs->getString(4);
		usr->address = rs->getString(5);
		usr->gender = rs->getString(6);
		usr->phoneNum = rs->getDouble(7);
		usr->age = rs->getInt(8);
		usr->email = rs->getString(9);
		return 1;
	}
}
void displayUser(Connection* conn, struct User usr)
{
	cout << "\n---------------- User Information ----------------" << endl;
	cout << "\n";
	cout << "User Number: ";
	cout << usr.userNum;
	cout << "\n";
	cout << "Coupon Number: ";
	cout << usr.couponNum;
	cout << "\n";
	cout << "First Name: ";
	cout << usr.fName;
	cout << "\n";
	cout << "Last Name: ";
	cout << usr.lName;
	cout << "\n";
	cout << "Address: ";
	cout << usr.address;
	cout << "\n";
	cout << "Gender: ";
	cout << usr.gender;
	cout << "\n";
	cout << "Phone Number: ";
	cout << usr.phoneNum;
	cout << "\n";
	cout << "Age: ";
	cout << usr.age;
	cout << "\n";
	cout << "Email: ";
	cout << usr.email;
}
void displayAllUsers(Connection* conn)
{
	Statement* stmt2 = conn->createStatement();
	ResultSet* rs2 = stmt2->executeQuery("SELECT USER_NUMBER, COUPON_NUMBER, FIRSTNAME, LASTNAME, ADDRESS, GENDER, PHONE, AGE, EMAIL FROM trainuser");
	cout << endl << "------------- All Users -------------" << endl << endl;
	cout << setw(19) << "\nUser Number" << setw(14) << "Coupon Number" << setw(14) << "First Name" << setw(14) << "Last Name" << setw(14) << "Address" << setw(14) << "Gender" << setw(14) << "Phone Number" << setw(14) << "Age" << setw(35) << "Email";
	while (rs2->next())
	{
		int UserNumber = rs2->getInt(1);
		int CouponNumber = rs2->getInt(2);
		string FirstName = rs2->getString(3);
		string LastName = rs2->getString(4);
		string Address = rs2->getString(5);
		string Gender = rs2->getString(6);
		int PhoneNumber = rs2->getDouble(7);
		int Age = rs2->getInt(8);
		string Email = rs2->getString(9);
		cout.setf(ios::left); 
		cout << UserNumber << " ";
		cout.width(18);
		cout << CouponNumber << " ";
		cout.width(18);
		cout << FirstName << " ";
		cout.width(18);
		cout << LastName << " ";
		cout.width(10);
		cout << Address << " ";
		cout.width(10);
		cout << Gender << " ";
		cout.width(10);
		cout << PhoneNumber << " ";
		cout.width(10);
		cout << Age << " ";
		cout.width(10);
		cout << Email << " ";
		cout.width(10);
	}
	cout << endl;
}