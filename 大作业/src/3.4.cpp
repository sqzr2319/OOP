#include <flat_map>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>

int main() {
    constexpr int DATA_SIZE = 10000;
    
    // 创建随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(1, DATA_SIZE * 10);
    
    // 准备数据
    std::vector<int> keys;
    std::vector<double> values;
    
    keys.reserve(DATA_SIZE);    // 提前分配空间
    values.reserve(DATA_SIZE);  // 提前分配空间
    
    // 生成随机数据
    for (int i = 0; i < DATA_SIZE; ++i) {
        keys.push_back(keyDist(gen));
        values.push_back(static_cast<double>(i) / 10.0);
    }
    
    // 使用预分配的容器构造flat_map
    auto start = std::chrono::high_resolution_clock::now();
    std::flat_map<int, double> dataMap(std::move(keys), std::move(values));
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "构造并排序包含 " << dataMap.size() 
              << " 个元素的flat_map耗时: " << duration.count() 
              << " 毫秒" << std::endl;
    
    return 0;
}