#include <iostream>
#include <fstream>
using namespace std;

class stud_details
{
  private:
    int roll;
    string div, name, add;

  public:
    void accept();
    bool check_roll(int n);
    void display();
};

void stud_details ::accept()
{
    cout << "Enter the student data\n";
    cout << "Enter roll No\n";
    cin >> roll;
    cout << "Enter Name\n";
    cin >> name;
    cout << "Enter Div\n";
    cin >> div;
    cout << "Enter Add\n";
    cin >> add;
}
bool stud_details::check_roll(int n)
{
    if (roll == n)
        return true;
    else
    {
        return false;
    }
}
void stud_details::display()
{
    cout << "Roll No : " << roll << endl;
    cout << "Name : " << name << endl;
    cout << "Div : " << div << endl;
    cout << "Add : " << add << endl;
}
void print_record(stud_details obj)
{
    fstream fout;
    fout.open("data.dat", ios::out | ios::app | ios::binary);
    fout.write((char *)&obj, sizeof(obj));
    fout.close();
}
void read_record(int rol)
{
    int nfoundflag = 0;
    fstream fin;
    stud_details obj;
    fin.open("data.dat", ios::binary | ios::in);
    while (fin.read((char *)&obj, sizeof(obj)))
    {
        if (obj.check_roll(rol))
        {
            obj.display();
            nfoundflag = 0;
            break;
        }
        else
        {
            nfoundflag = 1;
        }
    }
    if (nfoundflag == 1)
        cout << "Student details not Found\n";
}

int main()
{
    stud_details obj;
    int ch;
    do
    {
        cout << "Enter 1 to Enter the student details\n";
        cout << "Enter 2 to print the details\n";
        cout << "Enter 3 to Sort the array\n";
        cout << "Enter 4 to Display the array\n";
        cout << "Enter 5 to Exit the array\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.accept();
            print_record(obj);
            break;
        case 2:
            cout << "Enter Roll no of the student u want to find\n";
            int rol;
            cin >> rol;
            read_record(rol);
            break;
        case 5:
            cout << "Exit\n";
            break;
        default:
            break;
        }
    } while (ch != 5);
    return 0;
}
