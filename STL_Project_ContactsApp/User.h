#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include<functional>




class Group {
private:
    std::string friends;
    std::string family;
    std::string coworker;
    std::string acquaintance;
public:
    // Constructor
    Group(const std::string& fr = "", const std::string &fam = "", const std::string &co = "", const std::string& ac = ""):
         friends(fr), family(fam), coworker(co), acquaintance(ac) {}
    // Setters
    void setFriends(const std::string& fr) { friends = fr; }
    void setFamily(const std::string& fam) { family = fam; }
    void setCoworker(const std::string& co) { coworker = co; }
    void setAcquaintance(const std::string& ac) { acquaintance = ac; }

    // Getters
    std::string getFriends() const { return friends; }
    std::string getFamily() const { return family; }
    std::string getCoworker() const { return coworker; }
    std::string getAcquaintance() const { return acquaintance; }
};


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
    bool operator < (const User& u) const{
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
struct comp
{
    bool operator()(const User& u1, const User& u2) const {
        return u1.getFirstName() < u2.getFirstName();
    }
};

struct CompareByFirstName
{
    bool operator()(const User& u1, const User& u2) const {
        return u1.getFirstName() == u2.getFirstName();
    }
};

struct CompareByLastName
{
    bool operator()(const User& u1, const User& u2) const {
        return u1.getLastName() == u2.getLastName();
    }
};

void displayAllContactsSortedByName(const std::vector<User>& v);
void displayFirstNameAndPrimaryNumber(const std::vector<User>& v);
void displayContactsWithSameCompany(const std::vector<User>& v, const std::string& company);
void displayCountByCompany(const std::vector<User>& v, const std::string& company);
void findByName(const std::vector<User>& v, const std::string& name);

//void displayBySet(const std::multiset<User, std::function<bool(const User&, const User&)>>& set);

