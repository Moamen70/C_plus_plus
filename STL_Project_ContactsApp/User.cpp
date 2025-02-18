#include "User.h"

std::function<bool(const User&, const User&)> f = [](const User& u1, const User& u2) {
    return u1.getFirstName() < u2.getFirstName();
    };

std::multiset<User, std::function<bool(const User&, const User&)>> userSet(f);


// Setters
void User::setFirstName(const std::string& fn) { firstName = fn; }
void User::setLastName(const std::string& ln) { lastName = ln; }
void User::setPrimaryPhoneNumber(const std::string& ppn) { primaryPhoneNumber = ppn; }
void User::setSecondaryPhoneNumber(const std::string& spn) { secondaryPhoneNumber = spn; }
void User::setEmailID(const std::string& eid) { emailID = eid; }
void User::setAddress(const std::string& addr) { address = addr; }
void User::setCompany(const std::string& comp) { company = comp; }
//void User::setGroup(const Group& grp) { group = grp; }

// Getters
std::string User::getFirstName() const { return firstName; }
std::string User::getLastName() const { return lastName; }
std::string User::getPrimaryPhoneNumber() const { return primaryPhoneNumber; }
std::string User::getSecondaryPhoneNumber() const { return secondaryPhoneNumber; }
std::string User::getEmailID() const { return emailID; }
std::string User::getAddress() const { return address; }
std::string User::getCompany() const { return company; }

// Display function
void User::displayUser() const {
    std::cout << "User Details:\n";
    std::cout << "Name: " << firstName << " " << lastName << "\n";
    std::cout << "Primary Phone: " << primaryPhoneNumber << "\n";
    std::cout << "Secondary Phone: " << secondaryPhoneNumber << "\n";
    std::cout << "Email: " << emailID << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Company: " << company << "\n";
    std::cout << "////////////////////////////////////////////////////////////////////////" << "\n";
    //std::cout << "Group: " << group.getName() << "\n";
}
//Group User::getGroup() const { return group; }





void setComparator(std::function<bool(const User&, const User&)> comp) {
    std::multiset<User, std::function<bool(const User&, const User&)>> newSet(comp);
    newSet.insert(userSet.begin(), userSet.end());
    userSet = std::move(newSet);
}

void insertUser(const User& user) {
    userSet.insert(user);
}

// Function to display all users
void displayUsers() {
    for (const auto& user : userSet) {
        user.displayUser();
    }
}
void displayAllContactsSortedByName()
{
    if (userSet.empty()) {
        std::cout << "There is no contacts!" << std::endl;
        return;
    }
    int x{};
    while (true) {
        std::cout << "Sorted by first name --> Press 1" << std::endl;
        std::cout << "Sorted by last name --> Press 2" << std::endl;
        std::cin >> x;
        if (x == 1) {
            setComparator([](const auto& e1, const auto& e2) {
                return e1.getFirstName() < e2.getFirstName();
                });
            displayUsers();
            break;
        }
        else if (x == 2) {
            setComparator([](const auto& e1, const auto& e2) {
                return e1.getLastName() < e2.getLastName();
                });
            displayUsers();
            break;
        }
        else {
            std::cout << "Invalid Choise!" << std::endl;
        }
    }
    
}

void displayFirstNameAndPrimaryNumber()
{
    std::for_each(userSet.begin(), userSet.end(), [](const auto& u) {
        std::cout << "First Name: " << u.getFirstName() << "___ Primary Phone Number: " << u.getPrimaryPhoneNumber() << std::endl;
        });
}

void displayContactsWithSameCompany(const std::string& company)
{
    int x = 0;
    std::for_each(userSet.begin(), userSet.end(), [&x,company](const auto& u) {
        if (u.getCompany() == company) {
            u.displayUser();
            x++;
        }
        });
    if (x == 0) {
        std::cout << "Not Company!" << std::endl;
    }
}

void displayCountByCompany(const std::string& company)
{
    int count{};
    std::for_each(userSet.begin(), userSet.end(), [&count,company](const auto& u) {
        if (u.getCompany() == company) {
            count++;
        }
        });
    if(count > 0) std::cout << count << std::endl;
    else {
        std::cout << "0 - No Contacts work here!" << std::endl;
    }
}

void findByName(const std::string& name)
{
    int x{};
    std::for_each(userSet.begin(), userSet.end(), [&x,name](const auto& u) {
        if (u.getFirstName() == name) {
            u.displayUser();
            x++;
        }
        });
    if (x == 0) std::cout << "There is no Contact with that name!" << std::endl;
}


 
