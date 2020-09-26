// SalesByMatchSocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const vertex& ver) {
    stream << ver.x << "," << ver.y << "," << ver.z;
    return stream;
}

void vector_display(std::vector<vertex>& vec)
{
    for (vertex& v : vec) {
        std::cout << v << endl;
    }
}

int main()
{
    std::vector<vertex> vec;
    
    vec.push_back({ 1,2,3 });
    vec.push_back({ 1,1,1 });
    vec.push_back({ 3,2,1 });

	vector_display(vec);
}
