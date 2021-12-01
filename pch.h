#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <random>
#include "ExcelFormat/ExcelFormat.h"
#include "ExcelEditor.h"

using namespace ExcelFormat;

using std::cin;
using std::cout;
using std::string;
using std::priority_queue;
using std::map;
using std::vector;
using std::mt19937;
using std::uniform_int_distribution;
using std::pair;

static mt19937 Mt_rnd;


static vector<string> currentSimulationProducts = {
"1", "2", "3",
"4", "5", "6",
"7", "8"
};


