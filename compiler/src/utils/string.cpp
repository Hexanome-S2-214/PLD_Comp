#include "string.h"
#include <sstream>

vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;

    for (char c : s)
    {
        if (c == delimiter)
        {
            tokens.push_back(token);
            token.clear();
        }
        else
        {
            token += c;
        }
    }

    if (!token.empty())
    {
        tokens.push_back(token);
    }

    return tokens;
}

string join(vector<string> arr, char delimiter)
{
    stringstream buffer;

    for (int i = 0; i < arr.size(); ++i)
    {
        buffer << arr[i];
        if (i < arr.size() - 1)
        {
            buffer << delimiter;
        }
    }

    return buffer.str();
}

string padString(const string &str, size_t length, char paddingChar) {
    return padString(str, length, paddingChar, true);
}

string padString(const string &str, size_t length, char paddingChar, bool padLeft)
{
    if (str.length() >= length)
    {
        return str; // No need to pad, return original string
    }

    string paddedStr;
    paddedStr.reserve(length); // Reserve space to avoid reallocation

    // Pad on the left
    if (padLeft)
    {
        paddedStr.append(length - str.length(), paddingChar); // Append padding characters
        paddedStr.append(str);                                // Append original string
    }
    // Pad on the right
    else
    {
        paddedStr.append(str);                                // Append original string
        paddedStr.append(length - str.length(), paddingChar); // Append padding characters
    }

    return paddedStr;
}