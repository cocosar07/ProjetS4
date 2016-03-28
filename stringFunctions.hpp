#ifndef STRINGFUNCTIONS_HPP_INCLUDED
#define STRINGFUNCTIONS_HPP_INCLUDED

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

#endif // STRINGFUNCTIONS_HPP_INCLUDED
