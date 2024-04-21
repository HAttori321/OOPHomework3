#include <iostream>

using namespace std;
//**************************************TASK1****************************************
class Overcoat
{
    string type;
    int size;
    int price;
public:
    Overcoat()
    {
        type = "object";
        size = 0;
        price = 0;
    }
    Overcoat(string type, int size, int price) : type(type), size(size), price(price) {}
    Overcoat& operator=(const Overcoat& other)
    {
        if (this != &other)
        {
            size = other.size;
        }
        return *this;
    }
    friend ostream& operator << (ostream& out, const Overcoat& p1);
    friend bool operator==(const Overcoat& p1, const Overcoat& p2);
    friend bool operator > (const Overcoat& p1, const Overcoat& p2);
};
bool operator > (const Overcoat& p1, const Overcoat& p2)
{
    if (p1.type == p2.type) {
        return p1.price > p2.price;
    }
    else
    {
        return 0;
    }
}
bool operator==(const Overcoat& p1, const Overcoat& p2)
{
    return p1.type == p2.type;
}

ostream& operator << (ostream& out, const Overcoat& p1)
{
    out << "size : " << p1.size << endl;
    return out;
}
//**************************************TASK2****************************************
class Flat {
private:
    int area;
    int price;

public:
    Flat(int area, int price) : area(area), price(price) {}

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }
};
int main() {
    //**************************************TASK1****************************************
    cout << "-------Overcoat------- " << endl;

    Overcoat p1("Summer", 70, 450);
    Overcoat p2("Winter", 100, 290);
    Overcoat p3("Summer", 50, 376);

    bool p4 = p3 > p1;
    cout << p4 << endl;

    p1 = p3;
    cout << p1;

    bool TrueFalse = p1 == p3;
    cout << TrueFalse << endl;
    //**************************************TASK2****************************************
    Flat flat1(200, 300000);
    Flat flat2(220, 350000);
    Flat flat3(300, 480000);

    if (flat1 == flat3) {
        cout << "The apartments have the same area." << endl;
    }
    else {
        cout << "Apartments have different areas." << endl;
    }

    if (flat2 > flat1) {
        cout << "Apartments 2 is more expensive than Apartments 1." << endl;
    }
    else {
        cout << "Apartments 2 isn`t more expensive than Apartments 1." << endl;
    }
}