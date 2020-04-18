#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <vector <char>> charField (20, vector <char> (60, ' '));

    charField.at(2).at(5) = '#';
    charField.at(3).at(5) = '#';
    charField.at(4).at(5) = '#';
    charField.at(2).at(6) = '#';
    charField.at(3).at(7) = '#';
    
    charField.at(10).at(3) = '#';
    charField.at(10).at(4) = '#';
    charField.at(10).at(5) = '#';
    charField.at(10).at(6) = '#';
    charField.at(10).at(7) = '#';
    charField.at(10).at(8) = '#';
    charField.at(10).at(9) = '#';
    charField.at(10).at(10) = '#';
    charField.at(10).at(11) = '#';
    charField.at(10).at(12) = '#';

    vector <int> rows (3, 0);
    vector <int> cols (3, 0);
    int steps {};
    int sum {};

    for (unsigned i {0}; i < charField.size(); i++) {
        for (unsigned j {0}; j < charField.at(0).size(); j++) {
            cout << charField.at(i).at(j);
        }
        cout << endl;
    }
    
    while (1) {
        cout << "Steps to take: ";
        cin >> steps;

        if (steps < 0) {
            break;
        }

        for (int s {0}; s < steps; s++) {
            vector <vector <unsigned>> died;
            vector <vector <unsigned>> born;
            for (unsigned i {0}; i < charField.size(); i++) {
                for (unsigned j {0}; j < charField.at(0).size(); j++) {
                    vector <unsigned> index {i, j};
                    rows.at(0) = ((i >= 1) ? i - 1 : charField.size() - 1);
                    rows.at(1) = i;
                    rows.at(2) = ((i + 1 < charField.size()) ? i + 1 : 0);
                    
                    cols.at(0) = ((j >= 1) ? j - 1 : charField.at(0).size() - 1);
                    cols.at(1) = j;
                    cols.at(2) = ((j + 1 < charField.at(0).size()) ? j + 1 : 0);

                    sum = 0;
                    for (int r {0}; r < 3; r++) {
                        for (int c {0}; c < 3; c++) {
                            if (charField.at(rows.at(r)).at(cols.at(c)) == '#') {
                                sum += 1;
                            }
                        }
                    }
                    if (sum == 3) {
                        born.push_back(index);
                    }
                    else if (sum != 4) {
                        died.push_back(index);
                    }
                }
            }
            for (unsigned i {0}; i < born.size(); i++) {
                charField.at(born.at(i).at(0)).at(born.at(i).at(1)) = '#';
            }
            for (unsigned i {0}; i < died.size(); i++) {
                charField.at(died.at(i).at(0)).at(died.at(i).at(1)) = ' ';
            }
        }
        for (unsigned i {0}; i < charField.size(); i++) {
            for (unsigned j {0}; j < charField.at(0).size(); j++) {
                cout << charField.at(i).at(j);
            }
            cout << endl;
        }
    }
    return 0;
}