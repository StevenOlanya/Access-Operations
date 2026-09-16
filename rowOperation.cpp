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
 
    //  nth(): returns a column by its position
    vector<T> nth(size_t colIndex) const {
        if (data.empty() || colIndex >= data[0].size()) {
            throw out_of_range("nth(): column index out of range");
        }
        vector<T> column;
        for (size_t r = 0; r < data.size(); r++) {
            column.push_back(data[r][colIndex]);
        }
        return column;
    }
 
    // row(): returns a row by its position
    vector<T> row(size_t rowIndex) const {
        if (rowIndex >= data.size()) {
            throw out_of_range("row(): row index out of range");
        }
        return data[rowIndex];
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
 
    cout << "row(1): ";
    for (double v : df.row(1)) cout << v << " ";
    cout << endl;
 
    // Same class, now used with strings instead of doubles
    vector<vector<string>> strValues = {
        {"a", "x"},
        {"b", "y"}
    };
    vector<string> strNames = {"col1", "col2"};
    DataFrame<string> strDf(strValues, strNames);
 
    cout << "row(0): ";
    for (const string& v : strDf.row(0)) cout << v << " ";
    cout << endl;
 
    return 0;
}
 