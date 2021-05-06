#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> symbol_equivalence;
map<string, float> credit_equivalence;

// useful dictionaries
map<string, string> pt_en = {
        {"Prata", "Silver"},
        {"Ouro", "Gold"},
        {"Ferro", "Iron"}
};
map<string, int> roman_numbers = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
};
struct QUERY_TYPES {
    static const int REPRESENTS_RULE = 0;
    static const int WORTH_RULE = 1;
    static const int ROMAN_QUESTION = 2;
    static const int PRICE_QUESTION = 3;
    static const int INVALID_QUERY = -1;
};

int is_coin_word(const string& word) {
    if(word == "Iron" || word == "Ferro") return 1;
    if(word == "Gold" || word == "Ouro") return 1;
    if(word == "Silver" || word == "Prata") return 1;
    return 0;
}

/*
 * a function to convert an array with roman numbers like {100, 1000, 1, 1, 1}
 * to an int, 1903 in the example
 *
 * @param the vector with the roman numbers values.
 * @return the equivalent in decimal notation.
 */
int roman_int_to_number(const vector<int>& roman) {

    int hi = roman[0];
    int number = roman[0];
    int cnt = 1;
    map<int, bool> subtracted = {
            {1, false},
            {10, false},
            {100, false},
    };
    for(int k = 1; k < roman.size(); k++) {
        if(roman[k] == hi) {
            if(roman[k] == 500 || roman[k] == 50 || roman[k] == 5) return -1;
            cnt++;
            number += roman[k];
        }
        if(roman[k] < hi) {
            if(subtracted[roman[k]]) return -1;
            hi = roman[k];
            cnt = 1;
            number += roman[k];
        } else if(roman[k] > hi) {
            if( (((roman[k] == 5 || roman[k] == 10) && hi == 1) ||
                 ((roman[k] == 50 || roman[k] == 100) && hi == 10) ||
                 ((roman[k] == 500 || roman[k] == 1000) && hi == 100))
                 && (cnt < 2))   {
                subtracted[hi] = true;
                number -= hi;
                number += roman[k] - hi;
                hi = roman[k];
                cnt = 1;
            } else return -1;
        }
        if(cnt > 3) return -1;
    }
    return number;
}

int define_query_type(const vector<string>& input_array) {
    if(input_array[1] == "representa") return QUERY_TYPES::REPRESENTS_RULE;
    else if(input_array[3] == "valem") return QUERY_TYPES::WORTH_RULE;
    else if(input_array[0] == "quanto") return QUERY_TYPES::ROMAN_QUESTION;
    else if(input_array[0] == "quantos") return QUERY_TYPES::PRICE_QUESTION;
    else return QUERY_TYPES::INVALID_QUERY;
}

void process_represents_rule(const vector<string>& input_array) {

    // get essential data for processing the input
    string name = input_array[0];
    string roman_letter = input_array[2];
    int roman_number = roman_numbers[roman_letter];
    symbol_equivalence[name] = roman_number;

}

void process_worth_rule(const vector<string>& input_array) {

    // get essential data for processing the input
    vector<int> coin_prefix;
    string coin_type;
    int k;
    for(k = 0; k < input_array.size(); k++) {
        if(is_coin_word(input_array[k])) {
            coin_type = input_array[k];
            break;
        }
        if(symbol_equivalence.find(input_array[k]) == symbol_equivalence.end()) {
            cout << "Nem ideia do que isto significa!" << endl;
            return;
        }
        coin_prefix.push_back(symbol_equivalence[input_array[k]]);
    }
    int credits = stoi(input_array[k+2]);
    if(pt_en.find(coin_type) != pt_en.end()) coin_type = pt_en[coin_type];
    int decimal_number = roman_int_to_number(coin_prefix);
    if(decimal_number == -1) {
        cout << "Nem ideia do que isto significa!" << endl;
        return;
    }
    credit_equivalence[coin_type] = (float) credits / (float) decimal_number;

}

void process_roman_question(const vector<string>& input_array) {

    // get essential data for processing the input
    vector<int> romans;
    vector<string> output;
    for(int k = 2; k < input_array.size() - 1; k++) {
        if(symbol_equivalence.find(input_array[k]) == symbol_equivalence.end()) {
            cout << "Nem ideia do que isto significa!" << endl;
            return;
        }
        romans.push_back(symbol_equivalence[input_array[k]]);
        output.push_back(input_array[k]);
    }
    int decimal_number = roman_int_to_number(romans);
    if(decimal_number == -1) {
        cout << "Nem ideia do que isto significa!" << endl;
        return;
    }
    for(const string& k : output) {
        cout << k << " ";
    }
    cout << "vale " << decimal_number << endl;

}

void process_price_question(const vector<string>& input_array) {

    // get essential data for processing the input
    vector<int> romans;
    vector<string> output;
    string coin_type;
    for (int k = 3; k < input_array.size() - 1; ++k) {
        output.push_back(input_array[k]);
        if(is_coin_word(input_array[k])) {
            coin_type = input_array[k];
            break;
        }
        if(symbol_equivalence.find(input_array[k]) == symbol_equivalence.end()) {
            cout << "Nem ideia do que isto significa!" << endl;
            return;
        }
        romans.push_back(symbol_equivalence[input_array[k]]);
    }
    if(pt_en.find(coin_type) != pt_en.end()) coin_type = pt_en[coin_type];
    int decimal_number = roman_int_to_number(romans);
    if(decimal_number == -1) {
        cout << "Nem ideia do que isto significa!" << endl;
        return;
    }
    for(string& k : output) {
        cout << k << " ";
    }
    cout << "custa " << (float) decimal_number*credit_equivalence[coin_type] << " créditos" << endl;
}

int main() {

    /* unit routine to test roman_int_to_number */
    /*vector<int> roman = {10, 100, 10};
    cout << roman_int_to_number(roman) << endl;
    roman = {10, 10, 10, 100};
    cout << roman_int_to_number(roman) << endl;
    roman = {50, 50};
    cout << roman_int_to_number(roman) << endl;
    roman = {5, 5};
    cout << roman_int_to_number(roman) << endl;
    roman = {100, 500};
    cout << roman_int_to_number(roman) << endl;
    */

    string input_line;
    while(getline(cin, input_line)) {
        if(input_line.empty())
            break;

        string delimiter = " ";
        vector<string> input_array;
        int pos;
        while((pos = input_line.find(delimiter)) != string::npos)  {
            input_array.push_back(input_line.substr(0, pos));
            input_line.erase(0, pos + delimiter.length());
        }
        input_array.push_back(input_line);
        int query_type = define_query_type(input_array);
        switch (query_type) {
            case QUERY_TYPES::REPRESENTS_RULE:
                process_represents_rule(input_array);
                break;
            case QUERY_TYPES::WORTH_RULE:
                process_worth_rule(input_array);
                break;
            case QUERY_TYPES::ROMAN_QUESTION:
                process_roman_question(input_array);
                break;
            case QUERY_TYPES::PRICE_QUESTION:
                process_price_question(input_array);
                break;
            default:
                cout << "Nem ideia do que isto significa!" << endl;
        }
    }
}
