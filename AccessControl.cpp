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
 
    // nth(): returns a column by its position
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
 
    // get(): returns a column by its name
    vector<T> get(const string& colName) const {
        for (size_t i = 0; i < columnNames.size(); i++) {
            if (columnNames[i] == colName) {
                return nth(i);   // reuse nth() once we know the position
            }
        }
        throw invalid_argument("get(): column name not found");
    }
 
    // row(): returns a row by its position
    vector<T> row(size_t rowIndex) const {
        if (rowIndex >= data.size()) {
            throw out_of_range("row(): row index out of range");
        }
        return data[rowIndex];
    }
 
    // last(): returns the last row
    vector<T> last() const {
        if (data.empty()) {
            throw out_of_range("last(): DataFrame is empty");
        }
        return data[data.size() - 1];
    }
 
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
 
    cout << "nth(0): ";
    for (double v : df.nth(0)) cout << v << " ";
    cout << endl;
 
    cout << "get(\"Bread\"): ";
    for (double v : df.get("Bread")) cout << v << " ";
    cout << endl;
 
    cout << "row(1): ";
    for (double v : df.row(1)) cout << v << " ";
    cout << endl;
 
    cout << "last(): ";
    for (double v : df.last()) cout << v << " ";
    cout << endl;
 
    cout << "at(1, 0): " << df.at(1, 0) << endl;
 
    // Same class, now used with strings instead of doubles
    vector<vector<string>> strValues = {
        {"a", "x"},
        {"b", "y"}
    };
    vector<string> strNames = {"col1", "col2"};
    DataFrame<string> strDf(strValues, strNames);
 
    cout << "nth(1): ";
    for (const string& v : strDf.nth(1)) cout << v << " ";
    cout << endl;
 
    cout << "get(\"col1\"): ";
    for (const string& v : strDf.get("col1")) cout << v << " ";
    cout << endl;
 
    cout << "row(0): ";
    for (const string& v : strDf.row(0)) cout << v << " ";
    cout << endl;
 
    cout << "last(): ";
    for (const string& v : strDf.last()) cout << v << " ";
    cout << endl;
 
    cout << "at(0, 1): " << strDf.at(0, 1) << endl;
 
    return 0;
}