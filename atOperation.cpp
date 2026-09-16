#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
 
template <typename T>
class DataFrame {
private:
    vector<string> columnNames;   // names of each column
    vector<vector<T>> data;       // data[row][col]
 
public:
    // Constructor: takes the grid of values + column names
    DataFrame(vector<vector<T>> values, vector<string> names)
        : columnNames(names), data(values) {}   // matches declaration order
 
    // at(): returns a single element by row and column position
    T at(size_t rowIndex, size_t colIndex) const {
        if (rowIndex >= data.size() || colIndex >= data[0].size()) {
            throw out_of_range("at(): index out of range");
        }
        return data[rowIndex][colIndex];
    }
};
 
int main() {
    // Example DataFrame of doubles
    vector<vector<double>> values = {
        {10, 60},
        {20, 70},
        {30, 80}
    };
    vector<string> names = {"food", "Bread"};
 
    DataFrame<double> df(values, names);
 
    cout << "at(1, 0): " << df.at(1, 0) << endl;
 
    // Same class, now used with strings instead of doubles
    vector<vector<string>> strValues = {
        {"a", "x"},
        {"b", "y"}
    };
    vector<string> strNames = {"col1", "col2"};
    DataFrame<string> strDf(strValues, strNames);
 
    cout << "at(0, 1): " << strDf.at(0, 1) << endl;
 
    return 0;
}