// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "user.h"

int main()
{   
    //std::function<bool(const User&, const User&)> f;
    //std::multiset<User, std::function<bool(const User&, const User&)>> set(f);
    //insertUser(User("Ahmed", "Sayed", "010243", "011234", "75432", "Cairo", "Google"));
    
    insertUser(User("Ahmed", "Sayed", "010243", "011234", "75432", "Cairo", "Google"));
    insertUser(User("Zeyad", "Amir", "012453", "011355", "39548", "Cairo", "Microsoft"));
    insertUser(User("Ahmed", "Nader", "010456", "011256", "29547", "Alex", "Ejad"));
    insertUser(User("Yasser", "Bakr", "011456", "010256", "45678", "Alex", "Siemens"));
    insertUser(User("Wael", "Zekri", "012756", "011556", "24547", "Giza", "Ejad"));

    displayCountByCompany("Ejad");
    displayCountByCompany("sdc");
    displayCountByCompany("Google");
    findByName("Zeyad");
    //displayContactsWithSameCompany("Ejad");
    //displayFirstNameAndPrimaryNumber();
    //displayAllContactsSortedByName();
    //displayUsers();
    //setComparator(comp2());
    //displayUsers();

//    for (const auto& u : set) {
//        u.displayUser();
//    }
}


