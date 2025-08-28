#include <bits/stdc++.h>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

int convertToDecimal(string value, int base) {
    int result = 0, power = 1;
    for (int i = value.size() - 1; i >= 0; i--) {
        int digit;
        if (value[i] >= '0' && value[i] <= '9')
            digit = value[i] - '0';
        else if (value[i] >= 'A' && value[i] <= 'Z')
            digit = value[i] - 'A' + 10;
        else if (value[i] >= 'a' && value[i] <= 'z')
            digit = value[i] - 'a' + 10;
        else
            return -1;
        if (digit >= base) return -1;
        result += digit * power;
        power *= base;
    }
    return result;
}

vector<double> lagrangeInterpolation(vector<double> x, vector<double> y) {
    int n = x.size();
    vector<double> coeff(n, 0.0);

    for (int i = 0; i < n; i++) {
        vector<double> term(n, 0.0);
        term[0] = 1.0;
        double denom = 1.0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            denom *= (x[i] - x[j]);

            for (int k = n - 1; k >= 1; k--)
                term[k] = term[k] * (-x[j]) + term[k - 1];
            term[0] *= -x[j];
        }

        for (int k = 0; k < n; k++)
            coeff[k] += y[i] * term[k] / denom;
    }
    return coeff;
}

int main() {
    ifstream inFile("input.json");
    if (!inFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    json input;
    inFile >> input;

    int n = input["keys"]["n"];
    int k = input["keys"]["k"];

    vector<double> x, y;

    for (auto& [key, val] : input.items()) {
        if (key == "keys") continue;
        int base = stoi(val["base"].get<string>());
        string v = val["value"];
        int decoded = convertToDecimal(v, base);
        x.push_back(stoi(key));
        y.push_back(decoded);
    }

    vector<double> coeff = lagrangeInterpolation(x, y);
    cout << coeff[coeff.size()-1];

    return 0;
}
