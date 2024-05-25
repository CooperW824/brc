#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef struct
{
    double sum;
    double min;
    double max;
    int count;
} measurements;

void process_line(
    std::string &line,
    std::unordered_map<std::string, measurements> &measures,
    std::set<std::string> &locations);

void output_file(
    const std::unordered_map<std::string, measurements> &measures,
    const std::set<std::string> &locations);

int main()
{
    std::unordered_map<std::string, measurements> measures;
    std::set<std::string> locations;

    std::ifstream file("measurements.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: file not found" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while (std::getline(file, line))
    {
        process_line(line, measures, locations);
    }

    output_file(measures, locations);
    return EXIT_SUCCESS;
}

void process_line(
    std::string &line,
    std::unordered_map<std::string, measurements> &measures,
    std::set<std::string> &locations)
{
    std::string tempString;
    while (line.back() != ';')
    {
        tempString.push_back(line.back());
        line.pop_back();
    }

    line.pop_back(); // Remove the semicolon

    // Reverse the temp string because I assembled it backwards...
    std::reverse(tempString.begin(), tempString.end());

    double temp = std::stod(tempString);

    auto emplace_result = locations.emplace(line);

    if (emplace_result.second == true)
    {
        // Means that we have not seen this city yet and can just insert it into the map
        measures.emplace(line, (measurements){temp, temp, temp, 1});
    }
    else
    {
        // means we have seen this city and we need to adjust the measures
        measurements & current = measures.at(line);
        current.sum += temp;
        current.count++;

        if (current.max < temp)
            current.max = temp;

        if (current.min > temp)
            current.min = temp;
    }
}

void output_file(
    const std::unordered_map<std::string, measurements> &measures,
    const std::set<std::string> &locations)
{
    measurements temp; 
    std::ofstream out_file  =  std::ofstream("output.txt");
    for (const std::string &location : locations)
    {
        temp = measures.at(location);
        out_file << location <<";"<< temp.min <<";"<< std::ceil((temp.sum / temp.count)*10)/10 << ";" << temp.max << "\n";
    }
}
