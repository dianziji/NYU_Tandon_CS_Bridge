// or2092_hw15.cpp :
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
    double amount;
    string fullName;
public:
    Person() : amount(0), fullName("") { }
    Person(double newAmount, string newName) : amount(newAmount), fullName(newName) { }
    double getAmount() { return amount; }
    string getName() { return fullName; }
    void setAmount(double newAmount) { this->amount = newAmount; }
    void setName(string newName) { this->fullName = newName; }
    void setData(double newAmount, string newName) { amount = newAmount; fullName = newName; }
    double operator + (const Person& rhs) { return (amount + rhs.amount); }
    double operator - (const Person& rhs) { return (amount - rhs.amount); }
    bool operator == (const Person& rhs) { return (amount == rhs.amount); }
    bool operator != (const Person& rhs) { return (amount != rhs.amount); }
    bool operator > (const Person& rhs) { return (amount > rhs.amount); }
    bool operator >= (const Person& rhs) { return (amount >= rhs.amount); }
    bool operator < (const Person& rhs) { return (amount < rhs.amount); }
    bool operator <= (const Person& rhs) { return (amount <= rhs.amount); }
    friend ostream& operator << (ostream& outs, const Person& rhs);
};
template <class T>
class LList;    // Predefinition for friendship
template <class T>
class LListItr; // Predefine to preserve order
//================================================          NODE          ==================================================================
template <class T>
class LListNode {
    T data;
    LListNode<T>* next;
    LListNode<T>* prev;
public:
    LListNode(T newData) : data(newData), next(nullptr), prev(nullptr) { }
    LListNode(const T& newData = T(), LListNode<T>* newNext = nullptr, LListNode<T>* newPrev = nullptr) :data(newData), next(newNext), prev(newPrev) {}
    LListNode<T>* getNext() { return next; }
    LListNode<T>* getPrev() { return prev; }
    void setNext(LListNode<T>* newNext) { next = newNext; } // solely for sorting... maybe
    void setData(const T& newData) { data = newData; }
    T getData() { return data; }
    double getPersonAmount() { return data.getAmount(); }
    string getPersonName() { return data.getName(); }
    friend class LList<T>;
};
//================================================          LIST          ==================================================================
template <class T>
class LList {
    LListNode<T>* head;
    LListNode<T>* tail;
    LListNode<T>* recursiveCopy(const LListNode<T>* rhs);
public:
    LList();     // default constr
    ~LList();           // deconstr
    LList(const LList<T>& rhs); // copy constr

    LList<T>& operator=(const LList<T>& rhs) { clear(); head = recursiveCopy(rhs.head); }

    void clear() { while (!isEmpty()) popFront(); }
    bool isEmpty() { return head->next == tail; }
    void insertAfter(const LListItr<T>& pos, T value);
    void pushFront(const T& newData) { head->next = new LListNode<T>(newData, head->next, head);  head->next->next->prev = head->next; }
    void pushBack(const T& newData) { tail->prev = new LListNode<T>(newData, tail, tail->prev); tail->prev->prev->next = tail->prev; }
    void removeNext(const LListItr<T>& pos);
    LListNode<T>* getHead() { return head; }
    T popFront();
    T popBack();
    int size();
    LListItr<T> begin() { return head; }
    LListItr<T> end() { return nullptr; }

};
//================================================        ITERATOR        ==================================================================
template <class T>
class LListItr {    // not sure if I'll use but taken from webinar
    LListNode<T>* ptr;
public:
    LListItr(LListNode<T>* newptr = nullptr) : ptr(newptr) { }
    T operator*() const { return ptr->data; } // dereference overload
    T& operator*() { return ptr->data; }

    LListNode<T>* getPointer() { return ptr; }  // realized could just make LList an amigo

    LListItr<T>& operator++();      // increment overload
    LListItr<T> operator++(int);

    bool operator==(const LListItr<T>& rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const LListItr<T>& rhs) const { return !(*this == rhs); }

    friend class LList<T>;  // nuevo amigo
};

void lineBreak();
void pointToFirstNode(LList<Person>& list, LListNode<Person>*& here);
void openInputFile(ifstream& inFile);
void readInputFile(ifstream& inFile, LList<Person>& list, double& avg);
void vectorMinMaxPos(vector<Person>& v, int& minPos, int& maxPos);
void removeMathers(LList<Person>& list, const double& avg);

int main() {
    // containers & formatting
    double average = 0;
    double amountOwed = 0, amountPaid = 0;
    double totalAmountOwed = 0, totalAmountPaid = 0;
    cout.setf(ios::fixed);          // I know the assignment said not to worry about this, but without this VS was giving me precision(1)
    cout.setf(ios::showpoint);
    cout.precision(2);

    // grabbing input file
    ifstream inFile;
    openInputFile(inFile);

    // processing file, adding nodes
    LList<Person> Bill;
    readInputFile(inFile, Bill, average);
    cout << "\nThe approximate amount due from each individual is " << average << '\n';
    lineBreak();

    // Iteration pointer
    LListNode<Person>* here;
    pointToFirstNode(Bill, here);

    for (int i = 0; i < Bill.size(); i++) {
        cout << i + 1 << ") " << here->getData() << '\n';
        here = here->getNext();
    }
    pointToFirstNode(Bill, here);
    lineBreak();

    for (int i = 0; i < Bill.size(); i++) {
        if (here->getPersonAmount() > average) {
            cout << here->getPersonName() << " is owed $" << here->getPersonAmount() - average << endl;
            totalAmountPaid += here->getPersonAmount() - average;
        }
        else {
            cout << here->getPersonName() << " owes $" << average - here->getPersonAmount() << endl;
            totalAmountOwed += average - here->getPersonAmount();
        }
        here = here->getNext();
    }

    cout << "\nTotal amount due/owed: " << totalAmountOwed << '\n';
    pointToFirstNode(Bill, here);
    lineBreak();

    removeMathers(Bill, average);   // removing members who have paid the approximate average
    vector<Person> ledger;
    for (int i = 0; i < Bill.size(); i++) {
        ledger.push_back(here->getData());
        here = here->getNext();
    }

    int minPos, maxPos;
    double amountToBePaid = 0;
    double leftOver = 0;
    bool resetMoneyDue = false;
    vectorMinMaxPos(ledger, minPos, maxPos);
    amountOwed = ledger[maxPos].getAmount() - average;
    amountToBePaid = average - ledger[minPos].getAmount();
    while (totalAmountOwed > 1) {           //  #logicPro #not the DAW... #cashmeousside #oldmemes
        if (ledger[maxPos].getAmount() > average && ledger[minPos].getAmount() < average) {
            if (amountToBePaid < amountOwed) {
                amountOwed -= amountToBePaid;
                totalAmountOwed -= amountToBePaid;
                cout << ledger[minPos].getName() << ", you give " << ledger[maxPos].getName() << ' ' << amountToBePaid << '\n';
                ledger.erase(ledger.begin() + minPos);
                vectorMinMaxPos(ledger, minPos, maxPos);
                amountToBePaid = average - ledger[minPos].getAmount();
            }
            else {
                leftOver = amountToBePaid - amountOwed;
                amountToBePaid -= amountOwed;
                totalAmountOwed -= amountOwed;
                cout << ledger[minPos].getName() << ", you give  " << ledger[maxPos].getName() << ' ' << amountOwed << '\n';
                ledger.erase(ledger.begin() + maxPos);
                vectorMinMaxPos(ledger, minPos, maxPos);
                amountOwed = ledger[maxPos].getAmount() - average;
            }
        }
    }
    cout << "\nIn the end, you should all have spent around " << average << '\n';

    delete here; here = nullptr;

    return 0;
}

void vectorMinMaxPos(vector<Person>& v, int& minPos, int& maxPos) {
    int tmpMinPos = 0, tmpMaxPos = 0;
    double minAmount = v[0].getAmount();
    double maxAmount = v[0].getAmount();
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getAmount() < minAmount)
            tmpMinPos = i;
        if (v[i].getAmount() > maxAmount)
            tmpMaxPos = i;
    }
    minPos = tmpMinPos;
    maxPos = tmpMaxPos;
}
void lineBreak() {
    cout << '\n';
    for (int i = 0; i < 6; i++)
        cout << "==========";
    cout << "\n\n";
}
void pointToFirstNode(LList<Person>& list, LListNode<Person>*& here) {
    here = list.getHead();
    here = here->getNext();
}
void removeMathers(LList<Person>& list, const double& avg) {
    LListNode<Person>* temp;
    pointToFirstNode(list, temp);
    for (int i = 0; i < list.size(); i++) {
        if (temp->getPersonAmount() == avg) {
            cout << temp->getPersonName() << ", you don't need to do anything" << endl;
            temp = temp->getPrev();
            list.removeNext(temp);
            temp = temp->getNext();
        }
        else {
            temp = temp->getNext();
        }
    }
}
void openInputFile(ifstream& inFile) {
    string fileName;
    cout << "Enter the filename: ";
    cin >> fileName;
    inFile.open(fileName);
    while (!inFile) {
        cout << "Could not open file. Try again." << endl;
        cout << "Enter the filename: ";
        cin >> fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}
void readInputFile(ifstream& inFile, LList<Person>& list, double& avg) {
    double sum = 0, count = 0, tempAmount = 0;
    string tempName = "";
    while (inFile >> tempAmount) {
        inFile.ignore(9999, '\t');
        getline(inFile, tempName);
        Person* temp = new Person;
        temp->setData(tempAmount, tempName);
        list.pushBack(*temp);
        delete temp; temp = nullptr;
        sum += tempAmount;
        count++;
    }
    inFile.close();
    avg = sum / count;
}
//====================      PERSON      ====================
ostream& operator << (ostream& outs, const Person& rhs) {
    outs << "Name: " << rhs.fullName << "     "
        << "Amount: " << rhs.amount << '\n';
    return outs;
}
//====================       LIST       ====================
template <class T>
LListNode<T>* LList<T>::recursiveCopy(const LListNode<T>* rhs) {
    /*
    LListItr<T> temp = rhs.begin();
    while (temp != rhs.end()) {
        push_back(*temp);
        temp++;
    }
    */
    if (rhs == nullptr)
        return nullptr;
    return new LListNode<T>(rhs->data, recursiveCopy(rhs.next));
}
template <class T>
void LList<T>::insertAfter(const LListItr<T>& pos, T value) {
    LListNode<T>* prev = pos.ptr;
    prev->next = new LListNode<T>(value, prev->next);
}
template <class T>
void LList<T>::removeNext(const LListItr<T>& pos) {
    LListNode<T>* temp = pos.ptr;
    LListNode<T>* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}
template <class T>
T LList<T>::popFront() {
    if (tail->prev == head) //empty list!
        return T();
    T retval = head->next->data;
    LListNode<T>* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    head->next->prev = head;
    delete nodeToDelete;
    return retval;
}
template <class T>
T LList<T>::popBack() {
    if (tail->prev == head) //empty list!
        return T();
    T retval = tail->prev->data;
    LListNode<T>* nodeToDelete = tail->prev;
    tail->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    delete nodeToDelete;
    return retval;
}
template <class T>
int LList<T>::size() {
    LListNode<T>* ptr = head->next;
    int count = 0;
    while (ptr != tail) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
    head = new LListNode<T>();
    tail = new LListNode<T>();
    head->next = tail;
    tail->prev = head;
    *this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList() { //build two nodes, as "Dummies" for teh sake of making things easier
    head = new LListNode<T>();
    tail = new LListNode<T>();
    head->next = tail;
    tail->prev = head;
}
template <class T>
LList<T>::~LList() {
    clear();
    delete head;
    delete tail;
}
//====================     ITERATOR     ====================
template <class T>
LListItr<T>& LListItr<T>::operator++() {
    if (ptr != nullptr) {
        ptr = ptr->next;
    }
    return *this;
}
template <class T>
LListItr<T> LListItr<T>::operator++(int) {
    LListItr<T> temp = *this;
    if (ptr != nullptr) {
        ptr = ptr->getNext();
    }
    return temp;
}