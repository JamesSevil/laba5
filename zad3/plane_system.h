#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void create_plane(map<string, vector<string>>& kal);
void planes_for_town(const map<string, vector<string>>& kal, const string& town);
void towns_for_plane(const map<string, vector<string>>& kal, int plane);
void planes(const map<string, vector<string>>& kal);

enum class Type {
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    EXIT,
    OTHERS
};