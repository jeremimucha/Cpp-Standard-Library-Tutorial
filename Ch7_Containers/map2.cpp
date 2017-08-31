// Chapter 7 Containers -- map
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;


int main()
{
    // create map / associative array
    // - keys are strings
    // - values are floats
    typedef map<string, float> StringFloatMap;

    StringFloatMap stocks;      // create empty container
    
    // insert some elements
    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemens"] = 842.00;
    stocks["Valve"] = 869.00;

    // print each element
    StringFloatMap::iterator pos;
    cout << left;   // left-adjust values
    for(pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
    }
    cout << endl;

    // boom (all prices double)
    for(pos = stocks.begin(); pos != stocks.end(); ++pos){
        pos->second *= 2;
    }

    // print all elements
    for(pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
    }

    // rename key from "VW" to "Volkswagen"
    // - provided only by exchanging element
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    // rename key from "Valve" to "Steam"
    // - a different approach
    pos = stocks.find("Valve");
    if(pos != stocks.end()){
        stocks.insert(make_pair("Steam", pos->second));
        stocks.erase(pos);  
    }
    else{
        cout << "Did not find elem with key \"Valve\"" << endl;
    }

    // print all elements
    cout << "\nAfter removal:" << endl;
    for(pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
    }

}
