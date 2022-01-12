#pragma once

#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <Windows.h>
#include <map>
#include <vector>

using namespace std;

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif