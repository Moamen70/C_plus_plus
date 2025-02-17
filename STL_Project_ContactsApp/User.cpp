#include "User.h"

// Setters
void User::setFirstName(const std::string& fn) {firstName = fn; }
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
//Group User::getGroup() const { return group; }



// Display function
void User::displayUser() const {
    std::cout << "User Details:\n";
    std::cout << "Name: " << firstName << " " << lastName << "\n";
    std::cout << "Primary Phone: " << primaryPhoneNumber << "\n";
    std::cout << "Secondary Phone: " << secondaryPhoneNumber << "\n";
    std::cout << "Email: " << emailID << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Company: " << company << "\n";
    std::cout << "////////////////////////////////////////////////////////////////////////" <<  "\n";
    //std::cout << "Group: " << group.getName() << "\n";
}



template<typename Comparator>
void displaySortedSet(const std::vector<User>& v , Comparator comp) {
    std::multiset<User, Comparator> sortedSet(v.begin(),v.end(), comp);
    // Display sorted users
    for (const auto& user : sortedSet) {
        user.displayUser();
    }
}

void displayAllContactsSortedByName(const std::vector<User>& v)
{
    if (v.empty()) {
        std::cout << "There is no contacts!" << std::endl;
        return;
    }
    int x{};
    while (true) {
        std::cout << "Sorted by first name --> Press 1" << std::endl;
        std::cout << "Sorted by last name --> Press 2" << std::endl;
        std::cin >> x;
        if (x == 1) {
            displaySortedSet(v, [](const auto& e1, const auto& e2) {
                return e1.getFirstName() < e2.getFirstName();
                });
            break;
        }
        else if (x == 2) {
            displaySortedSet(v, [](const auto& e1, const auto& e2) {
                return e1.getLastName() < e2.getLastName();
                });
            break;
        }
        else {
            std::cout << "Invalid Choise!" << std::endl;
        }
    }
}

void displayFirstNameAndPrimaryNumber(const std::vector<User>& v)
{
    if (v.empty()) {
        std::cout << "There is no contacts!" << std::endl;
        return;
    }else{
        std::for_each(v.begin(), v.end(), [](const auto& e) {
            std::cout << "First Name: " << e.getFirstName() << " __ Primary Phone Number: " << e.getPrimaryPhoneNumber() << std::endl;
            });
    }
}


void displayContactsWithSameCompany(const std::vector<User>& v,const std::string& company)
{
    int x{};
    if (v.empty()) {
        std::cout << "There is no contacts!" << std::endl;
        return;
    }else{
        for (const auto& u : v) {
            if (u.getCompany() == company) {
                u.displayUser();
                x++;
            }
        }
        if (x == 0) {
            std::cout << "There is no contacts!" << std::endl;
        }
    }
}

void displayCountByCompany(const std::vector<User>& v, const std::string& company)
{
    if (v.empty()) {
        std::cout << "There is no contacts!" << std::endl;
        return;
    }
    else {
        int count{};
        count = std::count_if(v.begin(), v.end(), [company](const auto& u) {
           return u.getCompany() == company;
            });
        //for (const auto& u : v) {
        //    if (u.getCompany() == company) {
        //        x++;
        //    }
        //}
        if (count == 0) {
            std::cout << "There is no contacts in "<<company << std::endl;
        }else { std::cout << "There is " <<count <<" contacts in "<<company << std::endl; }
    }
}

// Struct to collect users with matching first names
struct UserNamesByFirst {
    std::vector<User> names;
    std::string search_name; // Store the name to search for

    // Constructor to accept the name parameter
    UserNamesByFirst(const std::string& name) : search_name(name) {}

    void operator()(const User& u) {
        if (u.getFirstName() == search_name) {
            names.push_back(u);
        }
    }
};

// Struct to collect users with matching first names
struct UserNamesByLast {
    std::vector<User> names;
    std::string search_name; // Store the name to search for

    // Constructor to accept the name parameter
    UserNamesByLast(const std::string& name) : search_name(name) {}

    void operator()(const User& u) {
        if (u.getLastName() == search_name) {
            names.push_back(u);
        }
    }
};
void findByName(const std::vector<User>& v, const std::string& name)
{
    int x{};
    while (true) {
        std::cout << "Sorted by first name --> Press 1" << std::endl;
        std::cout << "Sorted by last name --> Press 2" << std::endl;
        std::cin >> x;
        if (x == 1) {
            auto users = std::for_each(v.begin(), v.end(), UserNamesByFirst(name));
            if (users.names.empty()) {
                std::cout << "There is no contacts with that first name! " << std::endl;
            }
            for (const auto& u : users.names) {
                u.displayUser();
            }
            break;
        }
        else if (x == 2) {
            auto users = std::for_each(v.begin(), v.end(), UserNamesByLast(name));
            if (users.names.empty()) {
                std::cout << "There is no contacts with that last name! " << std::endl;
            }
            for (const auto& u : users.names) {
                u.displayUser();
            }
            break;
        }
        else {
            std::cout << "Invalid Choise! " << std::endl;
            continue;
        }
    }
    
}



//void displayBySet(const std::multiset<User, std::function<bool(const User&, const User&)>>& set){
//    if (set.empty()) {
//        std::cout << "There is no contacts!" << std::endl;
//        return;
//    }
//    std::function<bool(const User&, const User&)> f;
//    int x{};
//    while (true) {
//        std::cout << "Sorted by first name --> Press 1" << std::endl;
//        std::cout << "Sorted by last name --> Press 2" << std::endl;
//        std::cin >> x;
//        if (x == 1) {
//            f = CompareByFirstName();
//            for (const auto& user : set) {
//                user.displayUser();
//            }
//            break;
//        }
//        else if (x == 2) {
//            f = CompareByLastName();
//            for (const auto& user : set) {
//                user.displayUser();
//            }
//            break;
//        }
//        else {
//            std::cout << "Invalid Choise!" << std::endl;
//            continue;
//        }
//        
//    }
//}




//struct CompCompare {
//    bool operator()(const User& u1, const User& u2) const {
//        return u1.getCompany() == u2.getCompany();
//    }
//};


/**************Using Vector & sort******************/
//void displayAllContactsSortedByName( std::vector<User>& v)
//{
//    if (v.empty()) {
//        std::cout << "There is no contacts!" << std::endl;
//        return;
//    }
//    int x{};
//    while(true){
//        std::cout << "Sorted by first name --> Press 1" << std::endl;
//        std::cout << "Sorted by last name --> Press 2" << std::endl;
//        std::cin >> x;
//        if (x == 1) {
//            std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
//                return e1.getFirstName() < e2.getFirstName();
//                });
//            for (const auto& e : v) {
//                e.displayUser();
//            }
//            break;
//        }
//        else if (x == 2) {
//            std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
//                return e1.getLastName() < e2.getLastName();
//                });
//            for (const auto& e : v) {
//                e.displayUser();
//            }
//            break;
//        }
//        else {
//            std::cout << "Invalid Choise!" << std::endl;
//        }
//    }
//}
