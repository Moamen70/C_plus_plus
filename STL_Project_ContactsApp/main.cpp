// STL_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "User.h"

int main()
{
	std::vector<User> v{};
	v.emplace_back("Ahmed", "Sayed", "010243", "011234", "75432", "Cairo", "Google");
	v.emplace_back("Zeyad", "Amir", "012453", "011355", "39548", "Cairo", "Microsoft");
	v.emplace_back("Ahmed", "Nader", "010456", "011256", "29547", "Alex", "Ejad");
	v.emplace_back("Yasser", "Bakr", "011456", "010256", "45678", "Alex", "Siemens");
	v.emplace_back("Moamen", "Mohamed", "012543", "010689", "89437", "Cairo", "Siemens");

	
	//displayAllContactsSortedByName(v);
	//displayFirstNameAndPrimaryNumber(v);
	displayContactsWithSameCompany(v, "Ejad");
	displayCountByCompany(v, "Ejad");
	findByName(v, "Moamen");
}


