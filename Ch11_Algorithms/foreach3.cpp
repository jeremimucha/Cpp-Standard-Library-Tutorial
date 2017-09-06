// Chapter 11 Algorithms -- for_each
#include "algostuff.hpp"
using namespace std;


// function object to process the mean value
class MeanValue
{
private:
    long num;
    long sum;
public:
    // ctor
    MeanValue()
        : num(0), sum(0)
        { }
    // function call
    // - process one more element of the sequence
    void operator()(int elem)
        {
            ++num;          // increment count
            sum += elem;    // add value
        }
    // return mean value (implicit type conversion)
    operator double()
        { return static_cast<double>(sum) / static_cast<double>(num); }
};


int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 8);

    // process and print mean value
    double mv = for_each(coll.begin(), coll.end(),
                         MeanValue());
    cout << "mean value: " << mv << endl;
}
