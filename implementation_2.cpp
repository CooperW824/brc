#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>


void process_line(
    std::string &line,
    std::unordered_map<std::string, std::vector<float>> &measures);

void output_file(
    const std::unordered_map<std::string, std::vector<float>> &measures,
    const std::vector<std::string> &locations);

int main()
{
    std::unordered_map<std::string, std::vector<float>> measures;

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
    std::unordered_map<std::string, std::vector<float>> &measures)
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

    if (!(measures.count(line)))
    {
        measures.emplace(line, std::vector<float>(1, temp));
    }
    else
    {
        measures.at(line).push_back(temp);
    }
}

// Does not take much time
void output_file(
    const std::unordered_map<std::string, std::vector<float>> &measures,
    const std::vector<std::string> &locations)
{
  
    std::ofstream out_file("output.txt");
    for (const std::string &location : locations)
    {
        const std::vector<float> & temp = measures.at(location);
        float min = *(std::min_element(temp.begin(), temp.end()));
        float max = *(std::max_element(temp.begin(), temp.end()));
        float sum;
        int size = temp.size();

        for(int i = 0; i < size; i++){
            sum += temp[i];
        }
        
        out_file << location << ";" << min << ";" << std::ceil((sum/size) * 10) / 10 << ";" << max << "\n";
    }
}
