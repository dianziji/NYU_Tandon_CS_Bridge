#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

const long HUNDY = 100;

class Money { // From the textbook, mostly untouched
private:
    long allCents;
public:
    Money();
    Money(int cents);   // I found it more convenient to initialize with cents, as opposed to dollars
    Money(long dollars, int cents);
    long getValue() const;
    void setValue(const long dollars, const int cents) { allCents = dollars * HUNDY + cents; }
    friend Money operator + (const Money& amountOne, const Money& amountTwo);
    friend Money operator - (const Money& amountOne, const Money& amountTwo);
    friend Money operator - (const Money& amount);
    friend bool operator < (const Money& amountOne, const Money& amountTwo);
    friend istream& operator >> (istream& ins, Money& amount);
    friend ostream& operator << (ostream& outs, const Money& amount);
};

class Check {
private:
    int checkNumber;
    double amount;
    bool cashedStatus;
public:
    Check() : checkNumber(0), amount(0), cashedStatus(false) {} // default constructor 
    Check(int newCheckNumber, double newAmount, bool newCashedStatus);
    void setCheckNumber(const int& newCheckNumber) { this->checkNumber = newCheckNumber; }  //setters
    void setAmount(const double& newAmount) { this->amount = newAmount; }
    void setCashedStatus(const bool& newCashedStatus) { this->cashedStatus = newCashedStatus; }
    int getCheckNumber() const { return this->checkNumber; }  //getters
    double getAmount() const { return this->amount; }
    bool getCashedStatus() const { return this->cashedStatus; }
};

int digitToInt(const char c);
void lineBreak();  // Segmenting the prompt on the console
void verifyAnswer(char Answer); // If its not N/Y, you'll get two more chances.
Money doubleToMoney(const double& cash);
void fillCheckBook(vector <Check>& checkBook, int& numberOfChecks);
void printCashedChecks(const vector<Check> checkList, const int arrSize, Money& cashedTotal);    //Reading through the Check array for cashed checks, passing the total
void printUncashedChecks(const vector<Check> checkList, const int arrSize, Money& uncashedTotal); //Reading through the Check array for uncashed checks, passing the total

int main() {
    char noOrYes = 'z';    //For input

    Money depositTotal;
    double tempAmount = 0, deposit;
    cout << "Please enter your old account balance, without symbols (e.g., \"50.00\", or \"116.75\"): )";
    cin >> tempAmount;
    Money oldAccountBalance = doubleToMoney(tempAmount);
    cout << "Please enter your current account balance, without symbols (e.g., \"50.00\", or \"116.75\"): ";
    cin >> tempAmount;
    Money initialAccountBalance = doubleToMoney(tempAmount);

    cout << "Would you like to make a cash deposit? (\"Y\" for yes and \"N\" for no.): ";
    cin >> noOrYes;
    verifyAnswer(noOrYes); // If its not N/Y, you'll get two more chances. If its Y we deposit again, if its N we continue.

    while (noOrYes == 'y' || noOrYes == 'Y') {
        cout << "Please enter the amount you would like to deposit, without symbols (e.g., \"50.00\", or \"116.75\"): ";
        cin >> deposit;
        depositTotal = depositTotal + doubleToMoney(deposit);

        cout << "Would you like to make another cash deposit? (Y/N): ";
        cin >> noOrYes;
        verifyAnswer(noOrYes);
    }

    lineBreak();

    int numOfChecks = 0;
    vector<Check> checkBook;
    fillCheckBook(checkBook, numOfChecks);

    Money cashedTotal, uncashedTotal;
    Money oldBalance, availableBalance, checkBookbalance;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    lineBreak();
    printCashedChecks(checkBook, numOfChecks, cashedTotal);
    lineBreak();
    printUncashedChecks(checkBook, numOfChecks, uncashedTotal);
    lineBreak();

    cout << "\nNumber of Checks:\t" << numOfChecks << endl;
    cout << "Initial Balance:\t" << initialAccountBalance << endl;
    cout << "Total Deposits:\t\t" << depositTotal << endl;
    cout << "Old Balance: \t\t" << oldAccountBalance << endl;
    cout << "Available Balance: \t" << initialAccountBalance + depositTotal - cashedTotal << endl;
    cout << "Checkbook Balance: \t" << initialAccountBalance + depositTotal - cashedTotal - uncashedTotal << endl;
    lineBreak();
    cout << "\nThe difference between your available balance \nand your checkbook balance: \t" << uncashedTotal << endl;

    return 0;
}
Money doubleToMoney(const double& cash) {
    long dollars;
    int cents;
    dollars = static_cast<int>(cash);
    cents = (cash - dollars) * HUNDY;
    return Money(dollars, cents);
}
void fillCheckBook(vector <Check>& checkBook, int& numberOfChecks) {
    double tempAmount;
    int tempID;
    bool tempTruthVal;
    char yesOrNo, cashedOrNot = 'z';

    cout << "\nWould you like to provide check information? (Y/N): ";
    cin >> yesOrNo;
    verifyAnswer(yesOrNo);

    while (yesOrNo == 'Y' || yesOrNo == 'y') {
        cout << "\nPlease enter the Check ID, amount, and cashed status (Example: # ##.## Y): ";
        cin >> tempID >> tempAmount >> cashedOrNot;
        verifyAnswer(cashedOrNot);

        if (cashedOrNot == 'y' || cashedOrNot == 'Y')
            tempTruthVal = true;
        else
            tempTruthVal = false;

        Check temp(tempID, tempAmount, tempTruthVal);
        checkBook.push_back(temp);
        numberOfChecks++;

        cout << "Would you like to provide information for another check? (Y/N)?";
        cin >> yesOrNo;
        verifyAnswer(yesOrNo);
    }
}
void printCashedChecks(const vector<Check> checkList, const int arrSize, Money& cashedTotal) {
    Money cashedCheckTotal;
    int numberOfCashedChecks = 0;
    cout << "\nCheck Number:\t Check Amount:\tCashed:" << endl;
    for (int i = 0; i < arrSize; i++) {
        if (checkList[i].getCashedStatus() == true) {
            cout << checkList[i].getCheckNumber() << "\t\t" << checkList[i].getAmount()
                << "\t\t" << checkList[i].getCashedStatus() << endl;
            cashedCheckTotal = cashedCheckTotal + doubleToMoney(checkList[i].getAmount());
            numberOfCashedChecks++;
        }
    }
    cout << "\nNumber of cashed checks:\t" << numberOfCashedChecks << endl;
    cout << "Cashed Checks Total:\t\t" << cashedCheckTotal << endl;

    cashedTotal = cashedCheckTotal;
}
void printUncashedChecks(const vector<Check> checkList, const int arrSize, Money& uncashedTotal) {
    Money uncashedCheckTotal;
    int numberOfUncashedChecks = 0;
    cout << "\nCheck Number:\t Check Amount:\tCashed:" << endl;
    for (int i = 0; i < arrSize; i++) {
        if (checkList[i].getCashedStatus() == false) {
            cout << checkList[i].getCheckNumber() << "\t\t" << checkList[i].getAmount()
                << "\t\t" << checkList[i].getCashedStatus() << endl;
            uncashedCheckTotal = uncashedCheckTotal + doubleToMoney(checkList[i].getAmount());
            numberOfUncashedChecks++;
        }
    }
    cout << "\nNumber of cashed checks:\t" << numberOfUncashedChecks << endl;
    cout << "Uncashed Checks Total:\t\t" << uncashedCheckTotal << endl;
    uncashedTotal = uncashedCheckTotal;
}
void lineBreak() {
    cout << "\n================================================================================\n";
}
void verifyAnswer(char answer) { // Three tries
    int count = 3;
    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
        cout << "You've entered an invalid character. Please try again... (" << count << ") attempts remaining." << endl;
        cin >> answer;
        count--;
        if (count == 0) {
            cout << "Too many attempts. Terminating program." << endl;
            exit(1);
        }
    }
}
Money::Money() : allCents(0) { // Initializes cents to 0
}
Money::Money(int cents) : allCents(cents) { // Initializes allCents to dollars * 100
}
Money::Money(long dollars, int cents) { // Initializes allCents to the sum of (dollars * 100) and (cents)
    if (dollars * cents < 0) {  // Both have to be same sign (+/-)
        cout << "Illegal values for dollars and cents. Terminating rogram" << endl;
        exit(1);
    }
    allCents = dollars * HUNDY + cents;
}
long Money::getValue() const {
    return allCents;
}
Money operator - (const Money& amount) {
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}
Money operator - (const Money& amountOne, const Money& amountTwo) {
    Money temp(amountOne.getValue() - amountTwo.getValue());
    return temp;
}
Money operator + (const Money& amountOne, const Money& amountTwo) {
    Money temp(amountOne.getValue() + amountTwo.getValue());
    return temp;
}
bool operator < (const Money& amountOne, const Money& amountTwo) {
    return (amountOne.allCents < amountTwo.allCents);
}
istream& operator >> (istream& ins, Money& amount) {
    char oneChar, decimalPoint, digitOne, digitTwo;
    long dollars;
    int cents;
    bool negative;

    ins >> oneChar;
    if (oneChar == '-') {
        negative = true;
        ins >> oneChar;
    }
    else
        negative = false;

    ins >> dollars >> decimalPoint >> digitOne >> digitTwo;

    if (oneChar != '$' || decimalPoint != '.' || !isdigit(digitOne) || !isdigit(digitTwo)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digitOne) * 10 + digitToInt(digitTwo);

    amount.allCents = static_cast<long>(dollars * HUNDY + cents);
    if (negative)
        amount.allCents = -amount.allCents;

    return ins;
}
ostream& operator << (ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;

    positive_cents = static_cast<long>(labs(amount.allCents));
    dollars = positive_cents / HUNDY;
    cents = positive_cents % HUNDY;

    if (amount.allCents < 0)
        outs << " - $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}
int digitToInt(const char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}
Check::Check(int newCheckNumber, double newAmount, bool newCashedStatus) : checkNumber(newCheckNumber), amount(newAmount), cashedStatus(newCashedStatus) {
}