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
 
    // last(): returns the last row
    vector<T> last() const {
        if (data.empty()) {
            throw out_of_range("last(): DataFrame is empty");
        }
        return data[data.size() - 1];
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
 
    cout << "last(): ";
    for (double v : df.last()) cout << v << " ";
    cout << endl;
 
    // Same class, now used with strings instead of doubles
    vector<vector<string>> strValues = {
        {"a", "x"},
        {"b", "y"}
    };
    vector<string> strNames = {"col1", "col2"};
    DataFrame<string> strDf(strValues, strNames);
 
    cout << "last(): ";
    for (const string& v : strDf.last()) cout << v << " ";
    cout << endl;
 
    return 0;
}