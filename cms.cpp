#include "cms.h"

#include <bits/stdc++.h>

using namespace std;

Contact::Contact(const string &firstName, const string &lastName,
                 const string &phoneNumber)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
}

const string Contact::getFirstName() { return this->firstName; }

const string Contact::getLastName() { return this->lastName; }

const string Contact::getPhoneNumber() { return this->phoneNumber; }

void ContactManager::addContact(const Contact &contact)
{
    contacts.push_back(contact);
}

void ContactManager::printContacts(vector<Contact> result)
{
    if (result.size() == 0)
    {
        cout << "No contacts found" << endl;
    }
    else
    {
        cout << "Total Records found: " << result.size() << endl;
        cout << "S.No.\tFirst Name\tLast Name\tPhone Number" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << i + 1 << ".\t" << result[i].getFirstName() << "\t\t" << result[i].getLastName() << "\t\t" << result[i].getPhoneNumber() << endl;
        }
    }
}

vector<Contact> ContactManager::searchByFirstName(const string &firstName) {
    vector<Contact> result;
    for (auto &contact : contacts) {

        if (toLowerString(contact.getFirstName()) == toLowerString(firstName)) {
            result.push_back(contact);
        }
    }
    return result;
}

vector<Contact> ContactManager::searchByLastName(const string &lastName) {
    vector<Contact> result;
    for (auto &contact : contacts) {
        if (toLowerString(contact.getLastName()) == toLowerString(lastName)) {
            result.push_back(contact);
        }
    }
    return result;
}

vector<Contact> ContactManager::searchByPhoneNumber(const string &phoneNumber) {
    vector<Contact> result;
    for (auto &contact : contacts) {
        if (contact.getPhoneNumber() == phoneNumber) {
            result.push_back(contact);
        }
    }
    return result;
}

vector<Contact> ContactManager::searchByFirstNamePrefix(
        const string &firstNamePrefix) {
    vector<Contact> result;
    for (auto &contact : contacts) {
        if (toLowerString(contact.getFirstName()).find(toLowerString(firstNamePrefix)) == 0) {
            result.push_back(contact);
        }
    }
    return result;
}

vector<Contact> ContactManager::searchByLastNamePrefix(
        const string &lastNamePrefix) {
    vector<Contact> result;
    for (auto &contact : contacts) {
        if (toLowerString(contact.getLastName()).find(toLowerString(lastNamePrefix)) == 0) {
            result.push_back(contact);
        }
    }
    return result;
}

vector<Contact> ContactManager::searchByPhoneNumberPrefix(
        const string &phoneNumberPrefix) {
    vector<Contact> result;
    for (auto &contact : contacts) {
        if (contact.getPhoneNumber().find(phoneNumberPrefix) == 0) {
            result.push_back(contact);
        }
    }
    return result;
}

string ContactManager::toLowerString(const string inputString){
     string result;
    for(auto character : inputString){
        result+=tolower(character);
    }
    return result;
}


void ContactManager::inputContact()
{
    // Take contact input
    string firstName, lastName, phoneNumber;
    cout << "Enter first name: ";
    cin >> firstName;
    while (!isValidName(firstName))
    {
        cout << "Invalid first name. Please enter again: ";
        cin >> firstName;
    }
    cout << "Enter last name: ";
    cin >> lastName;
    while (!isValidName(lastName))
    {
        cout << "Invalid last name. Please enter again: ";
        cin >> lastName;
    }
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    // validate phone number
    while (!isValidPhoneNumber(phoneNumber))
    {
        cout << "Invalid phone number.\n";
        cout << "Note: format [+] [country code] [subscriber number including "
                "area code] and can have a max 15 digits & min 8 digits\n";
        cout << "Please enter again: ";
        cin >> phoneNumber;
    }

    // Create contact object
    Contact contact(firstName, lastName, phoneNumber);

    // Add contact to contact manager
    addContact(contact);
}

bool ContactManager::isValidPhoneNumber(const string &phoneNumber)
{
    if (phoneNumber[0] != '+')
    {
        return false;
    }
    if (phoneNumber.length() > 15 || phoneNumber.length() < 8)
    {
        return false;
    }
    for (int i = 1; i < phoneNumber.length(); i++)
    {
        if (!isdigit(phoneNumber[i]))
        {
            return false;
        }
    }
    return true;
}

bool ContactManager::isValidName(const string &name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]))
        {
            return false;
        }
    }
    return true;
}