#pragma once
#include "ICompleteOrder.h"
#include "ICreateOrder.h"
#include "ISimulate.h"

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <random>

using std::cin;
using std::cout;
using std::string;
using std::priority_queue;
using std::map;
using std::vector;
using std::mt19937;
using std::uniform_int_distribution;

mt19937 rand;
