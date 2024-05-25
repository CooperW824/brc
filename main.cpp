#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

typedef struct
{
    float sum = 0;
    float min = 0;
    float max = 0;
    int count = 0;
} measurements;

void process_line(
    std::string &line,
    std::unordered_map<std::string, measurements> &measures);

void output_file(
    const std::unordered_map<std::string, measurements> &measures,
    const std::vector<std::string> &locations);

int main()
{
    std::unordered_map<std::string, measurements> measures(20000);

    std::ifstream file("measurements.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: file not found" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while (std::getline(file, line))
    {
        process_line(line, measures);
    }

    // Sort the list of cities
    std::vector<std::string> tempList;
    for (const auto &city : measures)
        tempList.push_back(city.first);
    std::sort(tempList.begin(), tempList.end());

    output_file(measures, tempList);
    return EXIT_SUCCESS;
}

void process_line(
    std::string &line,
    std::unordered_map<std::string, measurements> &measures)
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

    float temp = std::stof(tempString);

    measurements &current = measures[line];
    current.sum += temp;
    current.count++;

    if (current.max < temp)
        current.max = temp;

    if (current.min > temp)
        current.min = temp;
}

// Does not take much time
void output_file(
    const std::unordered_map<std::string, measurements> &measures,
    const std::vector<std::string> &locations)
{
    measurements temp;
    std::ofstream out_file("output.txt");
    for (const std::string &location : locations)
    {
        temp = measures.at(location);
        out_file << location << ";" << temp.min << ";" << std::ceil((temp.sum / temp.count) * 10) / 10 << ";" << temp.max << "\n";
    }
}
