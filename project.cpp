#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include<climits>
using namespace std;

int generateterminal()
{
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 7 + 1;
}
string generateboardinggate()
{
    srand(static_cast<unsigned int>(time(0)));

    const string alphabets = "ABCD";
    const int numAlphabets = alphabets.length();

    const string numbers = "1234";
    const int numNumbers = numbers.length();

    string result;
    result += alphabets[rand() % numAlphabets];
    result += numbers[rand() % numNumbers];

    return result;
}

string generateflightnumber(int length)
{
    srand(static_cast<unsigned int>(time(0)));

    const string numbers = "0123456789";
    const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int numNumbers = numbers.length();
    const int numAlphabets = alphabets.length();

    string result;

    result += numbers[rand() % numNumbers];
    result += alphabets[rand() % numAlphabets];

    for (int i = 2; i < length; ++i)
    {
        const string characters = numbers + alphabets;
        const int numCharacters = characters.length();
        result += characters[rand() % numCharacters];
    }

    random_shuffle(result.begin(), result.end());
    return result;
}
string showdate(int n)
{
    time_t today = time(nullptr);
    time_t tomorrow = today + 86400 * n;
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&tomorrow));
    return buffer;
}
string generateBillNumber()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    string billNumber;
    for (int i = 0; i < 20; ++i)
    {
        int digit = rand() % 10;
        billNumber += to_string(digit);
    }
    return billNumber;
}
void mainMenu();
class Management
{
public:
    Management()
    {
        mainMenu();
    }
};

class Details
{
private:
    static string name;
    static string gender;
    static string PhoneNo;
    static int age;
    static string add;
    static string nid;
    static string id;
    static string customerId;
    char arr[100];
public:

    void information()
    {
        cout << "\nEnter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "\nEnter your age : ";
        cin >> age;
        cout << "\nEnter your address :";
        cin.ignore();
        getline(cin, add);
        cout << "\nEnter your gender : ";
        cin >> gender;
       while (true) {
        cout << "\nEnter your phone number (10 digits): ";
        cin >> PhoneNo;
        if (cin.fail() || PhoneNo.length() != 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid phone number. Please enter a 10-digit number." << endl;
        } else {
            break;
        }
    }
        cout << "\nEnter your card number : ";
        cin >> nid;
        cout<< "\nEnter your card pin : ";
        cin>>id;
        customerId = generateflightnumber(10);
        cout << "\nYour Customer ID is : " << customerId << endl;
        ofstream file("record.txt", ios::app);
        if (file.is_open())
        {
            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "Address: " << add << endl;
            file << "Gender: " << gender << endl;
            file << "Phone Number: " << PhoneNo << endl;
            file << "Card Number: " << nid << endl;
            file << "Card pin: "  <<id<<endl;
            file << "Customer ID: " << customerId << endl;
            file << "------------------------------------------\n";
            file << endl;
            file.close();
            cout << "\nInformation added to record.txt successfully." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
        cout << "\nYour details are saved with us. Please go to Main menu and press 2 for registration.\n"<< endl;
    }
    friend class Ticket;//friend class
};
string Details::customerId;
string Details::name;
string Details::gender;
int Details::age;
string Details::PhoneNo;
string Details::add;
string Details::nid;
string Details::id;

class Registration
{
private:
    static int choice;
    int choice1;
    int Back;
    static string billnumber;
    static float charges;
    static int departure_hour;
    static int departure_minute;
    static int arrival_hour;
    static int arrival_minute;
    static string date;
    static string classselect;
    static int seatnumber;
    string promocode;
    static string food;
    static int durationofflight;
    static int avail;

public:
    void showticketinfo();
    string foodchoice();
    void showflightdate();
    void showflighttime(int Dur, int price);
    void seatmanagement();
    void showpromo();
    void flight()
    {
        string flight[] = {"Delhi, Banglore", "Chandigarh, Hydrabad", "Srinagar, Banglore", "Delhi, Mumbai", };

        int serial = 1;
        for (int i = 1; i < 4; i++)
        {
            cout << serial << " -> Flight from "
                 << "Delhi, Banglore"
                 << " to " << flight[i] << endl;
            serial++;
        }
        for (int i = 1; i < 4; i++)
        {
            cout << serial << " -> Flight from " << flight[i] << " to "
                 << "Chandigarh, Hydrabad" << endl;
            serial++;
        }
        cout << "\nWelcome to the Air India!" << endl;
        cout << "\nPress the number of the place which you want to book the flight: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            showflightdate();
            showflighttime(54, 2749);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }

        case 2:
        {
            showflightdate();
            showflighttime(59, 4084);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        // program for Dhaka to Khulna
        case 3:
        {
            showflightdate();
            showflighttime(50, 2840);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        // program for Chandpur to Dhaka
        case 4:
        {
            showflightdate();
            showflighttime(54, 2749);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        // program for cox's bazar to Dhaka
        case 5:
        {
            showflightdate();
            showflighttime(59, 4084);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        // program for Khulna to Dhaka
        case 6:
        {
            showflightdate();
            showflighttime(50, 2840);
            seatmanagement();
            food = foodchoice();
            showpromo();
            showticketinfo();
            cout << "\nPress any integer key to go Main Menu." << endl;
            cin >> Back;
            if (Back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        // program for default case
        default:
        {
            cout << "Invalid Input. Press any integer key to go back to Main menu" << endl;
            int a;
            cin >> a;
            if (a)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        }
    }
    friend class Ticket;//friend class
};
int Registration::seatnumber;
int Registration::choice;
float Registration::charges;
string Registration::billnumber;
int Registration::departure_hour;
int Registration::departure_minute;
int Registration::arrival_hour;
int Registration::arrival_minute;
string Registration::date;
string Registration::classselect;
string Registration::food;
int Registration::durationofflight;
int avail;

void Registration::showticketinfo()
{
    cout << "\nYour seat Number : " << seatnumber << endl;
    cout << "Class : " << classselect << endl;
    cout << "Charges : " << charges << "Rupees" << endl;
    cout << "Departure Time : " << departure_hour << " : " << departure_minute << endl;
    cout << "Arrival Time : " << arrival_hour << " : " << arrival_minute << endl;
    cout << "Duration : "
         << "0 hour and " << durationofflight << " minutes" << endl;
    cout << "Date : " << date << endl;
    cout << "Food : " << food << endl;
}

void Registration::showpromo()
{
    string promo;
    cout << "Do you have any PROMO CODE? you must type Offer for discount." << endl;
    cin >> promo;
    if (promo == "Offer")
    {
        charges = charges - charges * 0.07;
    }
    else
    {
        cout << "Invalid Promo Code." << endl;
    }
}
void Registration::seatmanagement()
{
    seatnumber++;
    if (seatnumber > 60)
    {
        cout << "Seat fill up. Your ticket purchase unsuccessful." << endl;
        return;
    }
}
void Registration::showflighttime(int Dur, int price)
{
    cout << "Following are the flights.\n\n";

    vector<int> departureHours;
    vector<int> departureMinutes;
    vector<int> arrivalHours;
    vector<int> arrivalMinutes;

    int departureHour = 9;
    int departureMinute = 0;
    int avail =108;
    int duration = Dur;
    

    cout << "Flight Schedule:" << endl;

    for (int flight = 1; flight <= 3; flight++)
    {
        departureHours.push_back(departureHour);
        departureMinutes.push_back(departureMinute);
        arrivalHours.push_back(departureHour);
        arrivalMinutes.push_back(departureMinute + duration);
        if (arrivalMinutes[flight - 1] >= 60)
        {
            arrivalHours[flight - 1] += arrivalMinutes[flight - 1] / 60;
            arrivalMinutes[flight - 1] %= 60;
        }
        cout << "\nFlight: " << flight << "\nDeparture - "
             << departureHours[flight - 1] << ":" << departureMinutes[flight - 1]
             << "\nArrival - " << arrivalHours[flight - 1] << ":" << arrivalMinutes[flight - 1]
             << "\nFlight Duration: 0 hour and " << duration << " Minutes"
             << "\nPrice: Economy class " << price << " Rupees"
             << "\nPrice: Business class " << price * 1.5 << " Rupees"
             << "\nPrice: First class " << price * 2 << " Rupees";
        cout<<endl;
        cout<< "Available Seats: "<<avail;
        avail -= 10;
        cout<<endl;
        departureHour = arrivalHours[flight - 1] + 1;
        departureMinute = arrivalMinutes[flight - 1];
    }
    cout << "Choose your Flight option and then choice class option : " << endl;
    cin >> choice1;
    if(choice1>3)
    {
        cout<<"Invalid input"<<endl;
        mainMenu();
    }
    cout << "\nClass : " << endl;
    cout << "\n1. Economy Class. \t2. Business Class.\t3. First Class\n";
    int classchoise;
    cout << "\nEnter your class choice : " << endl;
    cin >> classchoise;
    switch (classchoise)
    {
    case 1:
    {
        classselect = "Economy Class";
        charges = price;
        break;
    }
    case 2:
    {
        classselect = "Business Class";
        charges = price * 1.5;
        break;
    }
    case 3:
    {
        classselect = "First Class";
        charges = price + price * 2;
        break;
    }
    default:
    {
        cout << "Invalid input" << endl;
    }
    mainMenu();
    }
    durationofflight = Dur;
    departure_minute = departureMinutes[choice1 - 1];
    departure_hour = departureHours[choice1 - 1];
    arrival_hour = arrivalHours[choice1 - 1];
    arrival_minute = arrivalMinutes[choice1 - 1];
}
void Registration::showflightdate()
{
    cout << "\t________________________Welcome to Air India________________________\n"<< endl;
    cout << "Your comfort is our priority. Enjoy the journey!" << endl;
    cout << "1. Date : " << showdate(1) << "\t2. Date : " << showdate(2) << "\t3. Date : " << showdate(3) << endl;
    cout << "4. Date : " << showdate(4) << "\t5. Date : " << showdate(5) << "\t6. Date : " << showdate(6) << endl;
    cout << "7. Date : " << showdate(7) << "\t8. Date : " << showdate(8) << "\t9. Date : " << showdate(9) << endl;
    cout << "Chose the date of your departure: " << endl;
    int date_choice;
    cin >> date_choice;

    if (date_choice == 1)
        date = showdate(1);
    else if (date_choice == 2)
        date = showdate(2);
    else if (date_choice == 3)
        date = showdate(3);
    else if (date_choice == 4)
        date = showdate(4);
    else if (date_choice == 5)
        date = showdate(5);
    else if (date_choice == 6)
        date = showdate(6);
    else if (date_choice == 7)
        date = showdate(7);
    else if (date_choice == 8)
        date = showdate(8);
    else if (date_choice == 9)
        date = showdate(9);
    else
    {
        cout << "Invalid Date Inpur" << endl;
        mainMenu();
    }
}

string Registration::foodchoice()
{
    cout << "\nWill you take any food during journey time? Choose from this option.\n" << endl;
    cout << "\nMain Courses:\n";
    cout << "1. Grilled salmon with lemon dill sauce, served with roasted potatoes and steamed asparagus\n";
    cout << "2. Chicken piccata with a side of creamy mashed potatoes and roasted vegetables\n";
    cout << "3. Vegetarian option: Portobello mushroom stuffed with quinoa, spinach, and feta cheese, served with a mixed green salad\n";
    cout << "\nSides:\n";
    cout << "4. Garlic butter roasted Brussels sprouts\n";
    cout << "5. Wild rice pilaf\n";
    cout << "6. Sweet potato fries with chipotle aioli\n";
    cout << "\nDesserts:\n";
    cout << "7. Chocolate lava cake with vanilla ice cream\n";
    cout << "8. Fresh fruit platter with a side of honey yogurt dip\n";
    cout << "9. New York cheesecake with raspberry sauce\n";

    cout << "Enter your choice. If you don't want to take food in flight then enter any number without (0-9) " << endl;
    int foodchoice;
    cin >> foodchoice;
    string foodd;
    switch (foodchoice)
    {
    case 1:
        foodd = "Grilled salmon with lemon dill sauce, served with roasted potatoes and steamed asparagus";
        break;
    case 2:
        foodd = "Chicken piccata with a side of creamy mashed potatoes and roasted vegetables";
        break;
    case 3:
        foodd = "Vegetarian option: Portobello mushroom stuffed with quinoa, spinach, and feta cheese, served with a mixed green salad";
        break;
    case 4:
        foodd = "Garlic butter roasted Brussels sprouts";
        break;
    case 5:
        foodd = "Wild rice pilaf";
        break;
    case 6:
        foodd = "Sweet potato fries with chipotle aioli";
        break;
    case 7:
        foodd = "Chocolate lava cake with vanilla ice cream";
        break;
    case 8:
        foodd = "Fresh fruit platter with a side of honey yogurt dip";
        break;
    case 9:
        foodd = "New York cheesecake with raspberry sauce";
        break;
    default:
        foodd = "No food selected.";
    }
    return foodd;
}
class Payment
{
public:
    static string billnumber;
    void payment()
    {
        cout << "You have successfully booked the flight. Please pay the ticket price using mobile banking or bank accout. For printing your ticket go to Main menu" << endl;
        billnumber = generateBillNumber();
        cout << "\n\t\t\t______________________Mobile Banking______________________" << endl;
        cout << "\nFor UPI, CASH payment Merchant Number: 111120022007007. Use bill Number as reference." << endl;
        cout << "\nFor bank payment : " << endl;
        cout << "1 bank account number: 20070071001" << endl;
        cout << "2 bank account number: 20070072002" << endl;
        cout << "3 bank account number: 20070073003" << endl;
        cout << "4 bank account number: 20070074004" << endl;
        cout << "\nUse BILL NUMBER as reference" << endl;
        cout << "\nYour bill Number : " << billnumber << endl;
    }
};
string Payment::billnumber;

class Ticket : public Registration, public Details, public Payment // multiple inheritance
{
public:
    void Bill()
    {
        string destination = "";
        ofstream out("Ticket.txt");
        if (Registration::choice == 1)
        {
            destination = "Flight from Delhi, Delhi to Banglore, Banglore";
        }
        else if (Registration::choice == 2)
        {
            destination = "Flight from Delhi, Delhi to Mumbai, Mumbai";
        }
        else if (Registration::choice == 3)
        {
            destination = "Flight from Delhi, Banglore to Hydrabad, Hydrabad";
        }
        else if (Registration::choice == 4)
        {
            destination = "Flight from Chandpigarh, Banglore to Mumbai, Mumbai";
        }
        else if (Registration::choice == 5)
        {
            destination = "Flight from Hydrabad, Chandigarh to Hydrabad , Delhi";
        }
        else if (Registration::choice == 6)
        {
            destination = "Flight from Srinagar, Srinagar to Mumbai, Banglore";
        }
        {
            out << "-------------------------------------------------------------------" << endl;
            out << "                               TICKET                              " << endl;
            out << "-------------------------------------------------------------------" << endl;
            out << "                              Air India                       " << endl;
            out << "-------------------------------------------------------------------" << endl;
            out << endl;
            out << "Passenger Details : " << endl;
            out << endl;
            out << "  Customer ID : " << Details::customerId << endl;
            out << "  Passenger Name : " << Details::name << endl;
            out << "  Passenger Address : " << Details::add << endl;
            out << "  Passenger Age : " << Details::age << endl;
            out << "  Passenger Phone number : " << PhoneNo << endl;
            out << "  Passenger Gender : " << Details::gender << endl;
            out << endl;
            out << "Flight Details :" << endl;
            out<<endl;
            out << "   Flight Number : " << generateflightnumber(7) << endl;
            out << "   " << destination << endl;
            out << "   Departure Date : " << Registration::date << endl;
            out << "   Departure Time : " << Registration::departure_hour << " : " << Registration::departure_minute << endl;
            out << "   Arrival Time : " << Registration::arrival_hour << " : " << Registration::arrival_minute << endl;
            out << "   Duration : "
                << "0 hour and " << Registration::durationofflight << " minutes" << endl;
            out << "   Seat Number : " << Registration::seatnumber << endl;
            out << "   Ticket Number : " << generateflightnumber(10) << endl;
            out << endl;
            out << "Additional Information :" << endl;
            out<<endl;
            out << "   Food : " << Registration::food << endl;
            out << "   Baggage Allowance : 1 piece, 7 kg (15.43  lbs)" << endl;
            out << "   Cabin : " << Registration::classselect << endl;
            out << "   Boarding Gate : " << generateboardinggate() << endl;
            out << "   Terminal : Terminal " << generateterminal() << endl;
            out << "   Check-in Counter : Counter " << generateterminal() << endl;
            out << endl;
            out << "------------------------------------------------" << endl;
        }
        out.close();
    }
    void display()
    {
        ifstream ifs("Ticket.txt");
        {
            if (!ifs)
            {
                cout << "File error" << endl;
            }
            while (!ifs.eof())
            {
                ifs.getline(arr, 200);
                cout << arr << endl;
            }
        }
        ifs.close();

        ifstream iifs("Ticket.txt");
        ofstream oofs("Registration_Record.txt", ios::app);

        if (!iifs)
        {
            cerr << "File error: Ticket.txt" << endl;
        }

        if (!oofs)
        {
            cerr << "File error: Registration_Record.txt" << endl;
        }

        string line2;
        while (getline(iifs, line2))
        {
            oofs << line2 << endl;
        }
        iifs.close();
        oofs.close();

        cout << "Contents copied from Ticket.txt to Registration_Record.txt." << endl;
    }
};

void mainMenu()
{
    int lchoice;
    int schoice;
    int Back;
    cout << endl;
    cout << "\033[1;31m";
    cout << "                                       |" << endl;
    cout << "                                       |" << endl;
    cout << "                                       |" << endl;
    cout << "                                     .-'-." << endl;
    cout << "                                    ' ___ '" << endl;
    cout << "                          ---------'  .-.  '---------" << endl;
    cout << "          _________________________'  '-'  '_________________________" << endl;
    cout << "           ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-''''''" << endl;
    cout << "                         \\    /  ||/   H   \\||  \\    /" << endl;
    cout << "                          '--'   OO   O|O   OO   '--'" << endl;
    cout << "\033[0m";// Reset text color to default (usually white)
    cout << "\033[1;32m";
    cout << "\t_________________________________________________________________" << endl;
    cout << "\t\t                   \033[31mAir India\033[0m          " << endl;
    cout << "\t____________________________Main Menu____________________________" << endl;
    cout << "\t_________________________________________________________________" << endl;
    cout << "\t\t\t\t\t\t\t" << endl;
    cout << "\033[1;31m";
    cout << "\t|\t  Press \033[1;37m1\033[1;31m to add the Customer Details                   |" << endl;
    cout << "\033[1;32m";
    cout << "\t|\t  Press \033[1;37m2\033[1;32m for Flight Registration                       |" << endl;
    cout << "\033[1;33m";
    cout << "\t|\t  Press \033[1;37m3\033[1;33m for Payment                                   |" << endl;
    cout << "\033[1;34m";
    cout << "\t|\t  Press \033[1;37m4\033[1;34m for Ticket                                    |" << endl;
    cout << "\033[1;35m";
    cout << "\t|\t  Press \033[1;37m5\033[1;35m for Contact us                                |" << endl;
    cout << "\033[1;36m";
    cout << "\t|\t  Press \033[1;37m6\033[1;36m to Exit                                       |" << endl;
    cout << "\033[0m";

    cout << "\t_________________________________________________________________" << endl;
    cout << "\033[1;33m";
    cout << "\033[0m";
    cout << "Enter the choice : ";
    cin >> lchoice;

    Details d;
    Registration r;
    Ticket t;
    Payment p;

    switch (lchoice)
    {
    case 1:
    {
        cout << "\t\t\t______________Customers____________\n"<< endl;
        d.information();
        mainMenu();
        break;
    }

    case 2:
    {
        cout << "\t\t\t___________Book a flight using this system____________\n"<< endl;
        r.flight();
        break;
    }
    case 3:
    {
        p.payment();
        int temp;
        cout<<"press any integer to go Back main menu: "<<endl;
        cin>>temp;

        mainMenu();

        break;
    }
    case 4:
    {
        cout << "\t\t\t______________Get your Ticket __________________________\n"<< endl;
        t.Bill();
        cout << "Your Ticket is printed, you can collect \n"<< endl;
        cout << "Press 1 to display your ticket : ";
        cin >> Back;
        if (Back == 1)
        {
            t.display();
            mainMenu();
        }
        else
        {
            mainMenu();
        }
        break;
    }
    case 5:
    {
        cout << "\t\t___________________________Contact us:____________________________" << endl;
        cout << "Phone: +91-9756748778" << endl;
        cout << "Website: www.REBOOTERS.com" << endl;
        mainMenu();
        break;
    }
    case 6:
    {
        cout << "\n\n\t\t\t________________Thank you_________________" << endl;
        break;
    }
    default:
    {
        cout << "Invalid input, Please try again\n"<< endl;
        mainMenu();
        break;
    }
    }
}
class Aircraft//Abstract Base Class with Pure Virtual Function
{
public:
    virtual void fly() = 0;//Pure Virtual Function
};

class Boeing747 : public Aircraft
{
public:
    void fly()
    {
        cout<<"\033[1;35m";
        cout << "\t\t\t\tAir India is flying" << endl;
        cout << "\033[0m";
    }
};

class AirbusA380 : public Aircraft
{
public:
    void fly() override
    {
        cout<<"\033[1;35m";
        cout << "\t\t\t\tAirbusA380 is flying" << endl;
        cout << "\033[0m";
    }
};

int main()
{
    Aircraft* aircraft = new Boeing747();
    aircraft->fly();
    Management mobj;
    return 0;
}

