#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "immintrin.h"

void process_line(
    std::string &line,
    std::unordered_map<std::string, std::vector<float>> &measures);

void output_file(
    const std::unordered_map<std::string, std::vector<float>> &measures,
    const std::vector<std::string> &locations);

float simd_max(const std::vector<float> &values);
float simd_min(const std::vector<float> &values);
float simd_mean(const std::vector<float> &values);

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
        const std::vector<float> &temp = measures.at(location);
        
        out_file << location << ";" << simd_min(temp) << ";" << simd_mean(temp) << ";" << simd_max(temp) << "\n";
    }
}

float simd_max(const std::vector<float> &values)
{
    int n = values.size();

    __m256 max_val = _mm256_set1_ps(-std::numeric_limits<float>::infinity());

    int i = 0;
    for (; i <= n - 8; i += 8)
    {
        __m256 chunk = _mm256_loadu_ps(&values[i]);
        max_val = _mm256_max_ps(max_val, chunk);
    }

    float max_array[8];
    _mm256_storeu_ps(max_array, max_val);

    float max_result = *std::max_element(max_array, max_array + 8);
    for (; i < n; ++i)
    {
        if (values[i] > max_result)
        {
            max_result = values[i];
        }
    }

    return max_result;
}

float simd_min(const std::vector<float> &values)
{
    int n = values.size();

    __m256 min_val = _mm256_set1_ps(std::numeric_limits<float>::infinity());

    int i = 0;
    for (; i <= n - 8; i += 8)
    {
        __m256 chunk = _mm256_loadu_ps(&values[i]);
        min_val = _mm256_min_ps(min_val, chunk);
    }

    float max_array[8];
    _mm256_storeu_ps(max_array, min_val);

    float min_result = *std::min_element(max_array, max_array + 8);
    for (; i < n; ++i)
    {
        if (values[i] < min_result)
        {
            min_result = values[i];
        }
    }

    return min_result;
}
float horizontal_sum(__m256 vec)
{
    // First, we will horizontally sum the elements within each 128-bit lane
    __m128 low = _mm256_castps256_ps128(vec);    // Extract lower 128 bits
    __m128 high = _mm256_extractf128_ps(vec, 1); // Extract higher 128 bits

    low = _mm_add_ps(low, high); // Add the lower and higher 128-bit parts

    // Now we have the sum in the lower 128-bit lane. We need to further reduce it.
    __m128 shuf = _mm_movehdup_ps(low); // Duplicate even-index elements
    low = _mm_add_ps(low, shuf);        // Sum pairs of elements

    shuf = _mm_movehl_ps(shuf, low); // Move high parts to low
    low = _mm_add_ss(low, shuf);     // Sum remaining parts

    return _mm_cvtss_f32(low); // Extract the result
}

float simd_mean(const std::vector<float> &values)
{
    int size = values.size();
    // Function to sum an array of floats using AVX

    __m256 sum_vec = _mm256_setzero_ps(); // Initialize a 256-bit vector to zero

    int i = 0;
    for (; i <= size - 8; i += 8)
    {
        __m256 vec = _mm256_loadu_ps(&values[i]); // Load 8 floats into a 256-bit register
        sum_vec = _mm256_add_ps(sum_vec, vec);    // Add to the sum vector
    }

    // Horizontal sum the final vector
    float sum = horizontal_sum(sum_vec);

    // Handle the remaining elements
    for (; i < size; ++i)
    {
        sum += values[i];
    }

    return std::ceil(sum / size * 10) / 10;
}
