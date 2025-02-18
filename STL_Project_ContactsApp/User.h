#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include<functional>



class User
{
private:
    std::string firstName;
    std::string lastName;
    std::string primaryPhoneNumber;
    std::string secondaryPhoneNumber;
    std::string emailID;
    std::string address;
    std::string company;
    //Group group;

public:

    // Constructor
    User(const std::string& fn = "",
        const std::string& ln = "",
        const std::string& ppn = "",
        const std::string& spn = "",
        const std::string& eid = "",
        const std::string& addr = "",
        const std::string& comp = "")
        //const Group& grp = Group())
        : firstName(fn), lastName(ln),
        primaryPhoneNumber(ppn), secondaryPhoneNumber(spn),
        emailID(eid), address(addr),
        company(comp) {}


    // < overloading
    bool operator < (const User& u) const {
        return getFirstName() < u.getFirstName();
    }
    // Setters
    void setFirstName(const std::string& fn);
    void setLastName(const std::string& ln);
    void setPrimaryPhoneNumber(const std::string& ppn);
    void setSecondaryPhoneNumber(const std::string& spn);
    void setEmailID(const std::string& eid);
    void setAddress(const std::string& addr);
    void setCompany(const std::string& comp);
    //void setGroup(const Group& grp);


    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPrimaryPhoneNumber() const;
    std::string getSecondaryPhoneNumber() const;
    std::string getEmailID() const;
    std::string getAddress() const;
    std::string getCompany() const;
    //Group getGroup() const;
    void displayUser() const;

};
// Declare global multiset with runtime comparator
extern std::multiset<User, std::function<bool(const User&, const User&)>> userSet;
struct comp1
{
    bool operator()(const User& u1, const User& u2) {
        return u1.getFirstName() < u2.getFirstName();
    }
};

struct comp2
{
    bool operator()(const User& u1, const User& u2) {
        return u1.getLastName() < u2.getLastName();
    }
};
void setComparator(std::function<bool(const User&, const User&)> comp);
void insertUser(const User& u);
void displayUsers();

void displayAllContactsSortedByName();
void displayFirstNameAndPrimaryNumber();
void displayContactsWithSameCompany(const std::string& company);
void displayCountByCompany( const std::string& company);
void findByName( const std::string& name);


