#include <bits/stdc++.h>
using namespace std;

bool is_cc_String(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string CreditNumber;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\tWelcome!!!!!"<<endl;
    cout<<"\t\t\t\tProgram to check if a credit card number is valid or not."<<endl;
    cout << "\t\t\t\t\t\tYou can enter 'exit' anytime to quit." << endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    
    while (true) {
        
        cout << "Please enter a Credit Card number: ";
        cin >> CreditNumber;
        
        if (CreditNumber== "exit")
            break;
        
        else if (!is_cc_String(CreditNumber)) {
            cout << "Bad input! ";
            continue;
        }
            
        int len = CreditNumber.length();
        int doubleEvenSum = 0; 
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dble = ((CreditNumber[i] - 48) * 2);
            if (dble > 9) {
                dble = (dble / 10) + (dble % 10);
            }
            doubleEvenSum += dble;
        }
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (CreditNumber[i] - 48);
        }
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        continue;        
    }
    return 0;
}
