#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void create_plane(map<int, vector<string>>& kal);
void planes_for_town(const map<int, vector<string>>& kal, const string& town);
void towns_for_plane(const map<int, vector<string>>& kal, int plane);
void planes(const map<int, vector<string>>& kal);

enum class Type {
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    EXIT
};