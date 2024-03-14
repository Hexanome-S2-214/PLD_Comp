#pragma once

#include <string>
#include <vector>

using namespace std;

/*
 * Split string by delimiter
 *
 * @param s string to split
 * @param delimiter delimiter to split by
 * 
 * @return vector of strings
 */
vector<string> split(const string &s, char delimiter);

/*
 * Join a list of string by delimiter
 *
 * @param arr list of strings to join
 * @param delimiter delimiter to join by
 *
 * @return joined string
 */
string join(vector<string> arr, char delimiter = ' ');

/*
 * Pad string to a given length (default to left padding)
 *
 * @param str string to pad
 * @param length length to pad to
 * @param paddingChar character to pad with
 * 
 * @return padded string
 */
string padString(const string &str, size_t length, char paddingChar);

/*
 * Pad string to a given length
 *
 * @param str string to pad
 * @param length length to pad to
 * @param paddingChar character to pad with
 * @param padLeft whether to pad on the left or right
 * 
 * @return padded string
 */
string padString(const string &str, size_t length, char paddingChar, bool padLeft);