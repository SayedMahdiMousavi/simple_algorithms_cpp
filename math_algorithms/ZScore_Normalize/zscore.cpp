#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>


std::vector<double> ZScoreNormalize(const std::vector<double>& data){
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    double variance = 0.0;
    for(const auto& val: data){
        variance += std::pow(val -mean, 2);
    }
    variance /= data.size();
    double stddev = std::sqrt(variance);

    std::vector<double> normalizeData;
    for(const auto& val: data){
        normalizeData.push_back((val - mean) / stddev);
    }
    return normalizeData;
}

int main(){
    std::vector<double> array = {1,2,3,4,5,6,7,8,9};
    auto zscore = ZScoreNormalize(array);

    for(auto i: zscore){
        std::cout << i << " ";
    }
    return 0;
}