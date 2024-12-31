#include <iostream>
#include <fstream>
#include<conio.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
class SmartMachine
{
public:
    char id[5];
    char username[30];
    char password[20];
    char accHolderName[30];
    char mNumber[12];
    double balance;
    bool active;
};

class BankOperations
{
public:
    SmartMachine rb;
    SmartMachine t;
    fstream fp;
    fstream fp2;

    int autoid()
    {
        int max1 = 0, t = 0;
        fp.open("bankdata.txt",ios::in);
        if(fp.fail()==1)
        {
            max1 = 101;
            return max1;
        }
        fp.close();
        fp.open("bankdata.txt",ios::in);
        while(fp.read((char *)&rb,sizeof(rb)))
        {
            t = atoi(rb.id);
            if ( t > max1)
                max1 = t;
        }
        fp.close();
        max1 = (t == 0)? 101:max1 + 1;
        return max1;
    }

    void first()
    {
        system("cls");
        cout << "\t\tSmartKiosk System\n\n";
        cout << "1. User Panel\t\t\t2. Admin Panel\n";
        cout << "3. Exit\n\n";


    }

    void login()
    {
        system("cls");
        char username[30];
        char password[20];
        cout<<"\t\tACCOUNT LOGIN\n\n";
        cout<<"Enter Username: ";
        cin.getline(username, sizeof(username));

        cout<<"Enter Password: ";
        cin.getline(password, sizeof(password));

        if (authenticate(username, password))
        {
            char choice;
            do
            {
                system("cls");
                cout << "\t\t\tSmartKiosk System\n\n";
                cout << "1. Deposit Money\t\t\t2. Cash Withdrawal\n";
                cout << "3. Utilities Payment\t\t\t4. Nearby Shopping\n";
                cout<<"5. Exit";

                cout << "\n\nEnter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {
                case '1':
                    deposit();
                    break;
                case '2':
                    cash();
                    break;
                case '3':
                    utilitiesPayment();
                    break;
                case '4':
                    nearbyShopping();
                    break;
                case '5':
                    cout << "Thank you for visiting...";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            }
            while(true);


        }
        else
        {
            cout << "\nAuthentication failed. Please try again.\n";
            cout << "\nPress any Key to Continue...\n";
            getch();
        }
    }

    bool authenticate(const char* username, const char* password)
    {
        fp.open("bankdata.txt", ios::in);

        while (fp.read((char *)&rb, sizeof(rb)))
        {
            if (strcmp(username, rb.username) == 0 && strcmp(password, rb.password) == 0 && rb.active)
            {
                fp.close();
                return true;
            }
        }

        fp.close();
        return false;
    }

    void modFile()
    {

        fp.open("bankdata.txt",ios::in);
        fp2.open("TEMP.txt",ios::out | ios::app);
        while(fp.read((char *)&t,sizeof(t)))
        {
            if (strcmp(t.username,rb.username) == 0)
            {

                fp2.write((char *) &rb,sizeof(rb));
            }
            else
            {
                fp2.write((char *) &t,sizeof(t));
            }
        }
        fp2.close();
        fp.close();

        remove("bankdata.txt");
        rename("TEMP.txt","bankdata.txt");

    }

    void uMenu()
    {
        char choice;

        do
        {
            system("cls");
            cout << "\t\tSmartKiosk System\n\n";
            cout << "1. Create Account\t\t\t2. Login\n";
            cout << "3. Exit\n\n";


            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice)
            {

            case '1':
                createAccount();
                break;
            case '2':
                login();
                break;
            case '3':
                cout << "\nThank you for visiting...";
                return;
            default:
                cout << "\nInvalid choice. Please try again.\n";
            }
        }
        while (true);
    }

    void aMenu()
    {
        char choice;
        string ad,pas;

        do
        {
            system("cls");
            cout << "\t\tADMIN LOGIN\n\n";
            cout<<"Enter Admin ID : ";
            cin>>ad;
            cout<<"Enter Password : ";
            cin>>pas;

            if(ad == "ritesh21" && pas == "7597")
            {
                system("cls");

                cout << "\t\t\tADMIN PANEL\n\n";
                cout << "\t\t Welcome Ritesh Bagdi\n\n";
                cout << "1. Show Account Details\t\t2. Activate/Deactivate Account\n";
                cout << "3. Exit\n\n";

                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {
                case '1':
                    showAccounts();
                    break;
                case '2':
                    activeDeactive();
                    break;
                case '3':
                    cout << "\nThank you for visiting...";
                    return;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
                }

            }

            else if(ad == "abhi23" && pas == "0000")
            {

                system("cls");

                cout << "\t\t\tADMIN PANEL\n\n";
                cout << "\t\t Welcome Abhishek Sharma\n\n";
                cout << "1. Show Account Details\t\t2. Activate/Deactivate Account\n";
                cout << "3. Exit\n\n";

                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {
                case '1':
                    showAccounts();
                    break;
                case '2':
                    activeDeactive();
                    break;
                case '3':
                    cout << "\nThank you for visiting...";
                    return;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
                }
            }
            else
            {
                return;
            }

        }

        while (true);

    }


    void createAccount()
    {
        system("cls");
        cout << "\t\tCREATE ACCOUNT\n\n";
        itoa(autoid(),rb.id,10);
        cout<<"Your Smart ID -- "<<rb.id<<"\n";
        cout << "Enter Username: ";
        cin.getline(rb.username, sizeof(rb.username));

        cout << "Enter Password: ";
        cin.getline(rb.password, sizeof(rb.password));

        cout << "Enter Account Holder Name: ";
        cin.getline(rb.accHolderName, sizeof(rb.accHolderName));

        cout << "Enter Mobile Number: ";
        cin.getline(rb.mNumber, sizeof(rb.mNumber));

        cout << "Enter Initial Balance (MIN 500 RS) : ";
        cin >> rb.balance;
        cin.ignore();

        rb.active = true;

        fp.open("bankdata.txt", ios::out | ios::app);
        fp.write((char *)&rb, sizeof(rb));
        fp.close();

        cout << "\nAccount Created Successfully!\n";
        cin.get();
    }


    void showAccounts()
    {
        system("cls");
        char id[30];
        int t = 0;
        cout<<"\t\tSHOW ACCOUNT DETAILS\n";
        cout << "\nEnter Customer Smart ID: ";
        cin.getline(id, sizeof(id));

        fp.open("bankdata.txt", ios::in | ios::out);

        while (fp.read((char *)&rb, sizeof(rb)))
        {
            if (strcmp(id, rb.id) == 0)
            {
                if (rb.active)
                {

                    cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
                    cout<<"Account Username \t: "<<rb.username<<endl;
                    cout<<"Mobile Number \t\t: "<<rb.mNumber<<endl;
                    cout<<"Balance \t\t: "<< fixed<<setprecision(2)<<rb.balance<<" INR"<<endl;
                    cout<< "Status \t\t\t: Active\n";
                    cout<< endl;
                    t++;
                }
            }
        }
        if ( t == 0)
            cout<<"\n\nData Not Found..\n\n";
        fp.close();

        cin.get();
    }

    void deposit()
    {
        system("cls");
        cout << "\t\tDEPOSIT \n\n";

        double depositAmount;

        cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
        cout << "Current Balance\t\t: " << fixed << setprecision(2) << rb.balance << " INR" << endl;
        cout << "Enter Deposit Amount\t: ";
        cin >> depositAmount;
        cin.ignore();

        rb.balance += depositAmount;
        modFile();


        cout << "\nAmount Deposited Successfully!\n";
        getch();


    }

    void cash()
    {
        system("cls");
        cout << "\t\tCASH WITHDRAWAL\n\n";

        cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
        cout << "Current Balance\t\t: " << fixed << setprecision(2) << rb.balance << " INR" << endl;
        cout << "\n\n1. 100\t\t2. 200\t\t3. 500\n";
        cout << "4. 1000\t\t5. 2000\t\t6. 5000\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        int withdrawalAmount = 0;

        switch (choice)
        {
        case 1:
            withdrawalAmount = 100;
            break;
        case 2:
            withdrawalAmount = 200;
            break;
        case 3:
            withdrawalAmount = 500;
            break;
        case 4:
            withdrawalAmount = 1000;
            break;
        case 5:
            withdrawalAmount = 2000;
            break;
        case 6:
            withdrawalAmount = 5000;
            break;
        default:
            cout << "\nInvalid choice. Withdrawal canceled.\n";
            return;
        }

        if (withdrawalAmount <= rb.balance)
        {
            rb.balance -= withdrawalAmount;
            modFile();
            cout << "\nWithdrawal successful. You have withdrawn " << withdrawalAmount << " INR.\n";
            cout << "Remaining balance: " << fixed << setprecision(2) << rb.balance << " INR\n";
        }
        else
        {
            cout << "\nInsufficient balance for withdrawal.\n";
        }

        getch();
    }

    void utilitiesPayment()
    {
        system("cls");
        cout << "\t\tUTILITIES PAYMENT\n\n";

        char username[30];
        int found = 0;

        cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
        cout << "Current Balance\t\t: " << fixed << setprecision(2) << rb.balance << " INR" << endl;

        char choice;
        cout << "\n\n1. Mobile Recharge\t\t\t2. Electricity Bill\n";
        cout << "3. Water Bill\t\t\t\t4. Gas Bill\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            mobileRecharge();
            break;
        case '2':
            payBill("Electricity");
            break;
        case '3':
            payBill("Water");
            break;
        case '4':
            payBill("Gas");
            break;
        default:
            cout << "\nInvalid choice. No bill paid.\n";
        }



    }

    void mobileRecharge()
    {
        char mb[15];
        double rechargeAmount = 0.0;
        char choice;
        system("cls");
        cout<<"\t\tMOBILE RECHARGE\n";
        cout << "\n Enter Your Mobile Number -- ";
        cin>>mb;
        cout<<"\nSelect Your Operator";
        cout << "\n\n1. Jio\t\t\t2. Airtel\n";
        cout << "3. Vodafone\t\t4. BSNL\n";
        cout << "Enter your choice of operator: ";
        cin >> choice;

        cout << "\n\nSelect Recharge Plan:\n";

        if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
        {
            char y;

            cout << "1. Rs. 199\n2. Rs. 399\n3. Rs. 599\n";
            cout << "\nEnter your choice: ";
            cin >> y;

            switch (y)
            {
            case '1':
                rechargeAmount = 199.0;
                break;
            case '2':
                rechargeAmount = 399.0;
                break;
            case '3':
                rechargeAmount = 599.0;
                break;
            default:
                cout << "\nInvalid choice. Recharge failed.\n";
                return;

            }
            if (rechargeAmount > rb.balance)
            {
                cout << "\nInsufficient balance for recharge.\n";
            }
            else
            {
                rb.balance -= rechargeAmount;
                modFile();

                cout << "\n\nRecharge on mobile number " << mb << " is successful.";
                cout << "\n\nRemaining balance: " << fixed << setprecision(2) << rb.balance << " INR\n";
                getch();



            }


        }
        else
        {
            cout << "\nInvalid operator choice. Recharge failed.\n";

        }


        getch();

    }


    void payBill(const char *billType)
    {
        system("cls");
        cout<<"\t\tBILL PAYMENT\n";
        double billAmount,billN;
        cout << "Enter " << billType << " bill number : ";
        cin >> billN;
        cout << "Enter " << billType << " bill amount: ";
        cin >> billAmount;
        cin.ignore();

        if (billAmount > rb.balance)
        {
            cout << "\nInsufficient balance to pay the " << billType << " bill.\n";
        }
        else
        {
            rb.balance -= billAmount;
            modFile();
            cout << "\nBill payment successful. \nRemaining balance: " << fixed << setprecision(2) << rb.balance << " INR\n";
        }
        cin.get();

    }

    void nearbyShopping()
    {
        system("cls");
        cout << "\t\tNEARBY SHOPPING\n\n";
        cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
        cout << "Current Balance\t\t: " << fixed << setprecision(2) << rb.balance << " INR" << endl;
        shopping();

    }

    void shopping()
    {
        cout << "\n\nSelect items to purchase:\n";
        cout << "1. Sugar (5 kg) - Rs. 250\n";
        cout << "2. Ghee (1 kg) - Rs. 500\n";
        cout << "3. Salt (1 kg) - Rs. 20\n";
        cout << "4. Rice (10 kg) - Rs. 400\n";
        cout << "5. Milk (1 liter) - Rs. 50\n";

        char choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        double totalPrice = 0.0;
        switch (choice)
        {
        case '1':
            totalPrice = 250.0;
            break;
        case '2':
            totalPrice = 500.0;
            break;
        case '3':
            totalPrice = 20.0;
            break;
        case '4':
            totalPrice = 400.0;
            break;
        case '5':
            totalPrice = 50.0;
            break;
        default:
            cout << "\nInvalid choice. Shopping canceled.\n";
            return;
        }

        if (totalPrice > rb.balance)
        {
            cout << "\nInsufficient balance for shopping.\n";
        }
        else
        {
            rb.balance -= totalPrice;
            modFile();
            cout << "\nShopping successful.\nRemaining balance: " << fixed << setprecision(2) << rb.balance << " INR\n";

        }
        getch();
    }

    void activeDeactive()
    {
        system("cls");
        cout << "\t\tACCOUNT ACTIVATION/DEACTIVATION\n\n";

        char id[30];
        int found = 0;

        cout << "Enter Smart ID : ";
        cin.getline(id, sizeof(id));

        fp.open("bankdata.txt", ios::in | ios::out);

        while (fp.read((char *)&rb, sizeof(rb)))
        {
            if (strcmp(id, rb.id) == 0)
            {
                found = 1;
                cout<<"\nAccount Holder Name\t: "<< rb.accHolderName<< endl;
                cout<<"Account Username  \t: "<<rb.username<<endl;
                cout<<"Mobile Number \t\t: "<<rb.mNumber<<endl;
                cout<<"Balance \t\t: "<< fixed<<setprecision(2)<<rb.balance<<" INR"<<endl;
                cout <<"Current Status \t\t: " <<(rb.active ? "Active" : "Inactive") << endl;

                char choice;
                cout<<"\n1. Activate\t2. Deactivate\n";
                cout<<"Enter your choice: ";
                cin>>choice;
                cin.ignore();

                if (choice == '1' && !rb.active)
                {
                    rb.active = true;
                }
                else if (choice == '2' && rb.active)
                {
                    rb.active = false;
                }


                fp.seekp(-sizeof(rb), ios::cur);
                fp.write((char *)&rb, sizeof(rb));

                cout<<"\nAccount status updated successfully.\n Now account is "<<(rb.active ? "Activated" : "Deactivated");


            }
        }

        fp.close();

        if (found == 0)
        {
            cout<<"\nAccount not found.\n";
        }

        getch();
    }

};

int main()
{
    BankOperations bank;

    while (true)
    {
        bank.first();

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            bank.uMenu();
            break;
        case 2:
            bank.aMenu();
            break;
        case 3:
            cout<<"\nExiting the SmartKiosk\n";
            cout<<"\nThankyou for Visiting!\n";
            return 0;
        default:
            cout<<"Invalid choice. Please try again.\n";
        }

    }

}
