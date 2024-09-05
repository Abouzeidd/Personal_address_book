#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <limits>
using namespace std;
class contact{
private:
    string phone_number;
    string fname, lname, address, email;
public:
    void create_contact(){
        cout<<"Enter frist name :";
        cin>>fname;
        cout<<"Enter last name :";
        cin>>lname;
        cout<<"Enter phone number :";
        cin>>phone_number;
        cout<<"Enter email address :";
        cin>>email;
        cout<<"Enter address :";
        cin>>address;
    }
    void show_contact(){
        cout<<"Name:"<<fname<<" "<<lname<<endl;
        cout<<"Phone number:"<<phone_number<<endl;
        cout<<"Email:"<<email<<endl;
        cout<<"Address:"<<address<<endl;
    };
    void writeOnFile() {
        char user_choice;
        fstream f1;
        f1.open("mycontacts.txt",ios::app);
        do {
            create_contact();
            f1<<fname<<endl<<lname<<endl<<phone_number<<endl<<email<<endl<<address<<endl;
            cout<<endl;
            cout<<"Do you have next data? (y/n) :";
            cin>>user_choice;
        }while(user_choice=='y');
        cout<<"Contact has been Sucessfully Created...\n";f1.close();
    }
    void readFromFile() {
        fstream f2;
        f2.open("mycontacts.txt");
        cout<<"\n================================\n";
        cout<<"LIST OF CONTACTS";
        cout<<"\n================================\n";
        while(getline(f2, fname) && getline(f2, lname) && getline(f2, phone_number) && getline(f2, email) && getline(f2, address))
        {

            show_contact();
            cout<<"\n*********************\n";
        }
        f2.close();
    }
    void search_contacts(){
        fstream fsearch;
        int select;
        string search_phone,fname_search,lname_search;
        fsearch.open("mycontacts.txt");
        cout<<"[1] search with phone"<<endl<<"[2] search with frist name"<<endl<<"[3] search with last name"<<endl;
        cout<<"Enter ";
        cin>>select;
        switch (select) {
            case 1:
                cout<<"Enter the phone number ";
                cin>>search_phone;
                break;
            case 2:
                cout<<"Enter frist name ";
                cin>>fname_search;
                break;
            case 3:
                cout<<"Enter last name ";
                cin>>lname_search;
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Wrong selection\n";
        }
        int count=0;
        while (getline(fsearch, fname) && getline(fsearch, lname) && getline(fsearch, phone_number) && getline(fsearch, email) && getline(fsearch, address)) {
            if (phone_number == search_phone||fname==fname_search||lname_search==lname) {
                show_contact();
                cout<<"-----------------------------------"<<endl;
                count++;
            }
        }
        if(count==0){
            cout<<"not found";}
        fsearch.close();
    }
    void delete_a_contact() {
        int select, count = 0;
        string remove_phone, fname_remove, lname_remove;
        fstream fremove, ftemp;
        fremove.open("mycontacts.txt", ios::in);
        ftemp.open("new.txt", ios::out);
        cout << "[1] search with phone" << endl << "[2] search with first name" << endl << "[3] search with last name" << endl;
        cout << "Enter: ";
        cin >> select;
        switch (select) {
            case 1:
                cout << "Enter the phone number: ";
                cin >> remove_phone;
                break;
            case 2:
                cout << "Enter first name: ";
                cin >> fname_remove;
                break;
            case 3:
                cout << "Enter last name: ";
                cin >> lname_remove;
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Wrong selection\n";
        }
        while (getline(fremove, fname) && getline(fremove, lname) && getline(fremove, phone_number) && getline(fremove, email) && getline(fremove, address)) {
            if (phone_number == remove_phone || fname == fname_remove || lname == lname_remove) {
                count++;
            } else {
                ftemp << fname << endl << lname << endl << phone_number << endl << email << endl << address << endl;
            }
        }
        fremove.close();
        ftemp.close();
        if (count == 0) {
            remove("new.txt");
            cout << "Not found" << endl;
        } else {
            remove("mycontacts.txt");
            rename("new.txt", "mycontacts.txt");
            cout << "!!DELETED!!" << endl;
        }
    }
    void edit_on_contacts(){
        int select,count=0;
        string edit_phone,fname_edit,lname_edit;
        fstream fedit,ftemp;
        fedit.open("mycontacts.txt",ios::in);
        ftemp.open("edit.txt",ios::out);
        cout<<"[1] search with phone"<<endl<<"[2] search with frist name"<<endl<<"[3] search with last name"<<endl;
        cout<<"Enter ";
        cin>>select;
        switch (select) {
            case 1:
                cout<<"Enter the phone number ";
                cin>>edit_phone;
                break;
            case 2:
                cout<<"Enter frist name ";
                cin>>fname_edit;
                break;
            case 3:
                cout<<"Enter last name ";
                cin>>lname_edit;
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Wrong selection\n";
        }
        while (getline(fedit, fname) && getline(fedit, lname) && getline(fedit, phone_number) && getline(fedit, email) && getline(fedit, address)) {
            if (phone_number == edit_phone||fname==fname_edit||lname_edit==lname) {
                create_contact();
                ftemp<<fname<<endl<<lname<<endl<<phone_number<<endl<<email<<endl<<address<<endl;
                cout<<"-----------------------------------"<<endl;
                count++;
            }else{
                ftemp<<fname<<endl<<lname<<endl<<phone_number<<endl<<email<<endl<<address<<endl;
            }
        }
        fedit.close();
        ftemp.close();
        if(count>1){
            remove("edit.txt");
            cout<<"not found";}
        else{
            remove("mycontacts.txt");
            rename("edit.txt","mycontacts.txt");

        }
    }
};
int main(){
    system("color 6");
    cout<<"                                                                  ==  Hi to PERSONAL ADDRESS BOOK =="<<endl;
    cout<<"                                                                      ===  press any key ===    " <<endl;
    getch();
    while(true) {
        system("color 5");
        contact c1;
        int choice ,choice1=1;
        cout <<endl<< "                                                                        PERSONAL ADDRESS BOOK";
        cout << "\n\nMAIN MENU";
        cout << "\n=====================\n";
        cout << "[1] Add a new Contact\n";
        cout << "[2] List all Contacts\n";
        cout << "[3] Search for contact\n";
        cout << "[4] Delete a Contact\n";
        cout << "[5] Edit a Contact\n";
        cout << "[0] Exit";
        cout << "\n=====================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice==0){
            cout<<"thank you for using our program";
            break;
        }
        switch (choice) {
            case 1:
                c1.writeOnFile();
                break;
            case 2:
                c1.readFromFile();
                break;
            case 3:
                c1.search_contacts();
                break;
            case 4:
                c1.delete_a_contact();
                break;
            case 5:
                c1.edit_on_contacts();
                break;
            default:
                continue;
        }
        cout<<"[1] MAIN MENU"<<endl;
        cout<<"[0] Exit "<<endl;
        cout << "Enter your choice: ";
        cin>>choice1;
        if (choice1==0) {
            cout<<"thank you for using our program";
            break;
        } else{
            continue;
        }

    }


}
