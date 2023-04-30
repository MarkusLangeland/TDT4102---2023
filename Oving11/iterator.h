#pragma once

#include <vector>
#include <iostream>
#include <set>

void iteratorVectorForward(std::vector<std::string> vec);
void iteratorVectorBackward(std::vector<std::string> vec);
void replace(std::vector<std::string> &vec, std::string old, std::string replacement);

void iteratorSetForward(std::set<std::string> s);
void iteratorSetBackwards(std::set<std::string> s);
void replaceSet(std::set<std::string> &s, std::string old, std::string replacement);
