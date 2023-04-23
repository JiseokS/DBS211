// Group 6 Milestone1
// 2021-11-12
// Name              Email         
// Jiseok Shim       jshim13@myseneca.ca
// Anson Hammell     athammell@myseneca.ca
// Quoc Thai Phan    qtphan@myseneca.ca
#include <iostream>
#include <iomanip>
#include <occi.h>
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;
int main(void)
{
	//OCCI Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	//User Variables
	string str;
	string usr = "dbs211_213i12";
	string pass = "20482270";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Connection is Successful!" << endl;
		cout << "--Project Group 6--" << endl;
		cout << " Anson Hammell" << endl;
		cout << " Jiseok Shim " << endl;
		cout << " Quoc Thai " << endl << endl;;
		Statement* stmt = conn->createStatement();
		ResultSet* rs = stmt->executeQuery("SELECT officecode, city, state, country, postalcode FROM offices ORDER BY officecode");
		cout << "The company offices are:" << endl;
		cout << "# City State Country Postal Code" << endl;
		while (rs->next())
		{
			int count = rs->getInt(1);
			string city = rs->getString(2);
			string state = rs->getString(3);
			string country = rs->getString(4);
			string pc = rs->getString(5);
			//Create a more readable table
			cout << left << setw(2) << setfill(' ') << count;
			cout << left << setw(18) << setfill(' ') << city;
			cout << left << setw(19) << setfill(' ') << state;
			cout << left << setw(14) << setfill(' ') << country;
			cout << pc << endl;
		}
		string employeeNumber;
		bool f_validNum = false;
		do
		{
			cout << "Please enter your employee number: ";
			cin >> employeeNumber;
			if (!cin)
			{
				f_validNum = false;
				cout << "Invalid Number" << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
			{
				f_validNum = true;
			}
		} while (f_validNum == false);
		cout << "Valid Employee Number" << endl;
		Statement* stmt1 = conn->createStatement();
		ResultSet* rs1 = stmt1->executeQuery("SELECT employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle FROM employees WHERE employeenumber = '" + employeeNumber + "'");
		cout << "The employee is :" << endl;
		cout << "# Employee Number      Last Name       First Name       Extension     Email                            Office Code     Reports To      Job Title           " << endl;
		while (rs1->next())
		{
			int eNumber = rs1->getInt(1);
			string lastname = rs1->getString(2);
			string firstname = rs1->getString(3);
			string extension = rs1->getString(4);
			string email = rs1->getString(5);
			string officecode = rs1->getString(6);
			int reportsto = rs1->getInt(7);
			string jobtitle = rs1->getString(8);
			//Create a more readable table
			cout << "  ";
			cout << left << setw(21) << setfill(' ') << eNumber;
			cout << left << setw(16) << setfill(' ') << lastname;
			cout << left << setw(17) << setfill(' ') << firstname;
			cout << left << setw(14) << setfill(' ') << extension;
			cout << left << setw(33) << setfill(' ') << email;
			cout << left << setw(16) << setfill(' ') << officecode;
			cout << left << setw(16) << setfill(' ') << reportsto;
			cout << left << setw(20) << setfill(' ') << jobtitle;
		}
		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}