#include <iostream>
#include <string>
using namespace std;

class GradStudent;

class Person
{
    private:
        int SSN;
    protected:
        int age;
        string HomeAddress;
    public:
        string name;
        void rename(string);
        string canDrink();
        Person();
        Person(int, int, string, string);
        ~Person();
        friend int noReason(Person);
};

class GradStudent: public Person
{
    public:
        string specialty;
        GradStudent(int, string, string, string);
};

Person::Person(int SocSec, int years, string addss, string na)
{
    SSN = SocSec;
    age = years;
    HomeAddress = addss;
    name = na;
}

int noReason(Person fella)
{
    return fella.age;
}

Person::Person()
{
    name = "John Doe";
    SSN = 100000000;
    age = 999;
    HomeAddress = "North Pole";
}

GradStudent::GradStudent(int years, string addss, 
    string na, string spec)
{
    age = years;
    HomeAddress = addss;
    name = na;
    specialty = spec;
    // SSN is private, not protected, so it can't be edited.
    // SSN = 123456789;
}

Person::~Person()
{
    // If I had made the private member variables of Person pointers to 
    // int's and strings, then this would delete them.
}

void Person::rename(string newname)
{
    name = newname;
}

string Person::canDrink()
{
    if (age > 20) 
        return "Yes!";
    return "NO!!!!!";
}

int main()
{
    Person nick(123456789, 34, "3001 Medical Arts St", 
        "Nicholas Tron Zufelt");
    Person colin(108675309, 16, "34th or so?", "Colin Carrollol");

    Person *karin;
    karin = new Person(111111111, 25, "34th or so?", "Karin Knudson");

    cout << "Can " << nick.name << " drink? " << nick.canDrink() << endl;
    cout << "Can " << colin.name << " drink? " << colin.canDrink() << endl;
    cout << "Can " << (*karin).name << " drink? " 
        << (*karin).canDrink() << endl;

    nick.rename("William Jefferson Clinton");
    cout << "Nick's new name is " << nick.name << endl;

    delete karin;
    karin = 0;

    GradStudent *newkarin;
    newkarin = new GradStudent(25, "34th or so?", "Karin Knudson", 
        "Homotopy Theory");

    return 0;
}
