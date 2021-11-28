#include <iostream>
using namespace std;

struct PersonInfo
{
    string fName;
    string lName;
    char Gender;
    int Age;
};

struct PersonInfo initialize()
{
    struct PersonInfo info = {"Shantanu", "Mane", 'M', 19};

    return info;
}

int main()
{
    string firstName, lastName;
    char Gender;
    int Age;

    struct PersonInfo info = initialize();

    firstName = info.fName;
    lastName = info.lName;
    Gender = info.Gender;
    Age = info.Age;

    cout << "First Name : " << firstName << "\nLast Name : " << lastName << "\nGender : " << Gender << "\nAge : " << Age << endl;

    return 0;
}