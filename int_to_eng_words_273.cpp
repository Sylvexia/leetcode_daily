// 273. Integer to English Words

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    unordered_map<int, string> less_20, tens;
    string get_3_digit_str(int num)
    {
        if (num == 0)
            return "";

        int last_2_num = num % 100;
        int mid_num = last_2_num / 10;
        int last_num = last_2_num % 10;
        string last_2_string;
        if (last_2_num < 20)
            last_2_string = less_20[last_2_num];
        else if (last_num == 0)
            last_2_string = tens[mid_num];
        else
            last_2_string = tens[mid_num] + " " + less_20[last_num];

        int first_num = num / 100;
        if (first_num == 0)
            return last_2_string;
        if (last_2_string == "")
            return less_20[first_num] + " " + "Hundred";

        return less_20[first_num] + " " + "Hundred" + " " + last_2_string;
    }

public:
    string numberToWords(int num)
    {
        less_20 = {{1, "One"},       {2, "Two"},        {3, "Three"},
                   {4, "Four"},      {5, "Five"},       {6, "Six"},
                   {7, "Seven"},     {8, "Eight"},      {9, "Nine"},
                   {10, "Ten"},      {11, "Eleven"},    {12, "Twelve"},
                   {13, "Thirteen"}, {14, "Fourteen"},  {15, "Fifteen"},
                   {16, "Sixteen"},  {17, "Seventeen"}, {18, "Eighteen"},
                   {19, "Nineteen"}};

        tens = {{2, "Twenty"}, {3, "Thirty"},  {4, "Forty"},  {5, "Fifty"},
                {6, "Sixty"},  {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

        string billion_str = get_3_digit_str(num / 1000000000 % 1000);
        string million_str = get_3_digit_str(num / 1000000 % 1000);
        string thousand_str = get_3_digit_str(num / 1000 % 1000);
        string last_str = get_3_digit_str(num % 1000);

        if (billion_str == "")
            if (million_str == "")
                if (thousand_str == "")
                    if (last_str == "")
                        return "Zero";

        string res;

        if (billion_str != "")
            res += billion_str + " " + "Billion" + " ";
        if (million_str != "")
            res += million_str + " " + "Million" + " ";
        if (thousand_str != "")
            res += thousand_str + " " + "Thousand" + " ";
        if (last_str != "")
            res += last_str;

        if (res[res.size() - 1] == ' ')
            res.pop_back();

        return res;
    }
};