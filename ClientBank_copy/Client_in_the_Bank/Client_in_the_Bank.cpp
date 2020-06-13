#include <iostream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

struct inf {
	string fio;
	int day_Birthday;
	int month_Birthday;
	int year_Birthday;
};


class Human {
protected: string name;
protected: string surname;
public:
	Human() {};
	~Human() {};
public: void setName(string newName) {
	name = newName;
}
public:void setSurname(string newSurname) {
	name = newSurname;
}
public: string getName() {
	return name;
}
public: string getSurname() {
	return surname;
}
};

//наследуем класс Human
class Employee :public Human {

private:int number_ph;
	   inf personalData;
protected: string adress;
public:string post_office;
	  Employee();
	  ~Employee();
	  inf getData();
	  Employee(string n, string s, int p) { name = n; surname = s; number_ph = p; }//конструктор
};

Employee::Employee() :Human()
{
	number_ph = 1111111;
	adress = "Sevastopl,Sevastopolskya31";
	post_office = "manager";
	personalData.fio = "Ivanov Ivan Ivanovich";
	personalData.year_Birthday = 1990;
	personalData.month_Birthday = 1;
	personalData.day_Birthday = 1;
}

Employee::~Employee()
{
	number_ph = 0;
	adress = "\0";
	post_office = "\0";
	personalData.fio = "\0";
	personalData.year_Birthday = 0;
	personalData.month_Birthday = 0;
	personalData.day_Birthday = 0;
}

inf Employee::getData()
{
	return personalData;
}

class IdCard {
public: int number;
private:
	bool active;
	string type;
public: IdCard(int n) {
	number = n;
}
public:

	IdCard();
	IdCard(string _type);
	~IdCard();
public:
	void SetActive();
	void getMoney();

};

IdCard::IdCard(string _type)
{
	active = false;
	type = _type;
	cout << " > " << type << " card was created." << endl;
}

IdCard::~IdCard()
{
	active = false;
	type = "\0";
}

void IdCard::SetActive()
{
	active = true;
	cout << " > The card became active." << endl;

}

void IdCard::getMoney()
{
	cout << ">The card account is successfully replenished" << endl;
}


class Client :public Human {
private:int ID;
private:string work;
	   inf personalData;
public:
	Client();
	~Client();

	inf getData();

	void give_cash();
	void get_cash();
	void give_idcard();
	void agreement();
	void fill_application();
	void make_payment_mob();
	void make_payment_remittance();
	inf give_documents();
};

Client::Client()
{
	ID = 1111111;
	work = "teacher";
	personalData.fio = "Nikolaev Nikolay Nikolaevich";
	personalData.year_Birthday = 1990;
	personalData.month_Birthday = 1;
	personalData.day_Birthday = 1;
}

Client::~Client()
{
	ID = 0;
	work = "\0";
	personalData.fio = "\0";
	personalData.year_Birthday = 0;
	personalData.month_Birthday = 0;
	personalData.day_Birthday = 0;
}

void Client::give_cash()
{
	cout << " > The cash was giving to Cashier." << endl;
}

void Client::get_cash()
{
	cout << " > The cash was accepted by Client." << endl;
}

void Client::give_idcard()
{
	cout << " > The ID_Card was gave by Client." << endl;
}

void Client::agreement()
{
	cout << " > The agreement was concluted." << endl;
}

void Client::fill_application()
{
	cout << " > The application was filled." << endl;
}

void Client::make_payment_mob()
{
	cout << "> The payment mobile was bill." << endl;
}

void Client::make_payment_remittance()
{
	cout << "> Bill payment remittance." << endl;
}

inf Client::give_documents()
{
	cout << " > Client gave the documents." << endl;
	return personalData;
}

class Cashier :public Employee {
private:int cashident;
	   inf personalData;
	   //inf getData();
	   void choose_client(inf data_Client);
	   void see_op(inf data_Client);

public:
	Cashier() :Employee() {};
	~Cashier() {};
	void give_cred();
	void get_dep(Client* client);
	void getpayment_cred(Client* client);
	void knowcourse(int val);
};



void Cashier::choose_client(inf data_Client)
{
	cout << "> Client is choose." << endl;
}

void Cashier::see_op(inf data_Client)
{
	cout << "> Card options was saw. " << endl;
}


void Cashier::give_cred()
{
	cout << "> Credit was gave. " << endl;
}

void Cashier::get_dep(Client* client)
{
	{
		cout << "             GET DEPOSIT             " << endl
			<< "===============================================" << endl;
		client->give_cash();
		cout << "> The deposit was got." << endl
			<< "===============================================" << endl;
	}
}

void Cashier::getpayment_cred(Client* client)
{
	cout << "            CREDIT PAYMENT             " << endl
		<< "===============================================" << endl;
	client->give_documents();
	client->give_cash();
	cout << "> The credit was paid." << endl
		<< "===============================================" << endl;
}


void Cashier::knowcourse(int val)
{
	switch (val) {
	case 1:
		val++;
	case 2:
		val++;
	case 3:
		val++;
	}
	cout << "val =" << val;
}

class AccountDepartment
{
public:
	AccountDepartment() {};
	~AccountDepartment() {};

	void give_information_account();
	void open_account();
};

void AccountDepartment::give_information_account()
{
	cout << "> Information about client account was gave." << endl;
}

void AccountDepartment::open_account()
{
	cout << "> Client account was opened." << endl;
}

class CreditDepartment
{
public:
	CreditDepartment() {};
	~CreditDepartment() {};

	void get_information_account(AccountDepartment* account_department);
	void desisionCredit();

};

void CreditDepartment::get_information_account(AccountDepartment* account_department)
{
	account_department->give_information_account();
	cout << ">  Information about client account was got." << endl;
}

void CreditDepartment::desisionCredit()
{
	cout << "> Decision to sign the agreement." << endl;
}


class Worker : public Employee {
protected: int lvlcess;
		 inf personalData;
		 void checkAccount(inf dataOfCustomer);
public:
	Worker() {};
	~Worker() {};
	void SignCredit(Client* client, CreditDepartment* credit_department);
	void SignDeposit(Client* client, AccountDepartment* account_department);

};


void Worker::checkAccount(inf data_Client)
{
	cout << "> Account is checking." << endl;
}


void Worker::SignCredit(Client* client, CreditDepartment* credit_department)
{
	cout << "                 SIGN CREDIT             " << endl
		<< "===========================================" << endl;
	client->give_documents();
	client->fill_application();
	credit_department->desisionCredit();
	cout << "> The credit application signed by Worker." << endl
		<< "===========================================" << endl;
}


void Worker::SignDeposit(Client* client, AccountDepartment* account_department)
{
	inf data_Client;
	cout << "                 SIGN DEPOSIT             " << endl
		<< "===========================================" << endl;
	client->give_documents();
	client->fill_application();
	account_department->open_account();
	cout << "> Deposit account opened." << endl
		<< "===========================================" << endl;
}
void test_Client()
{
	cout << "Testing Client " << endl;
	Client* client = new Client();
	client->make_payment_mob();
	system("pause");
	client->make_payment_remittance();
	system("pause");
	delete client;
}

void test_Cashier()
{
	cout << "Testing Cashier " << endl;
	Client* client = new Client();
	Cashier* cashier = new Cashier();
	cashier->get_dep(client);
	system("pause");
	cashier->getpayment_cred(client);
	system("pause");
	delete client;
	delete cashier;
}

void test_Worker()
{
	cout << "Testing Worker " << endl;
	Client* client = new Client();
	CreditDepartment* credit_department = new CreditDepartment();
	AccountDepartment* account_department = new AccountDepartment();
	Worker* manager = NULL;
	manager->SignCredit(client, credit_department);
	system("pause");
	manager->SignDeposit(client, account_department);
	system("pause");
	delete client;
	delete credit_department;
	delete  account_department;
	delete manager;
}

void test_CreditDepartment()
{
	cout << "Testing Credit Department " << endl;
	CreditDepartment* credit_department = new CreditDepartment();
	AccountDepartment* account_department = new AccountDepartment();
	credit_department->get_information_account(account_department);
	system("pause");
	delete credit_department;
	delete  account_department;
}

int main()
{
	test_Client();
	test_Cashier();
	test_Worker();
	test_CreditDepartment();
	return 0;
}