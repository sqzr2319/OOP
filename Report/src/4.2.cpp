#include <chrono>
#include <iostream>
#include <map>
#include <flat_map>
#include <random>
#include <vector>
#include <iomanip>
#include <string>
#include <memory>

// 计时帮助函数
template<typename Func>
auto measure_time(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

template<typename Map, typename MultiMap>
void benchmark_containers(size_t size, size_t operation_count) {
    std::cout << "\n============================================\n";
    std::cout << "容器大小: " << size << ", 操作次数: " << operation_count << std::endl;
    std::cout << "============================================\n";
    
    // 准备随机数据
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, size * 10);
    
    // 创建测试用的键值对
    std::vector<std::pair<int, int>> data;
    data.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        data.emplace_back(dist(gen), i);
    }
    
    // 准备查找和插入用的键
    std::vector<int> testKeys;
    testKeys.reserve(operation_count);
    for (size_t i = 0; i < operation_count; ++i) {
        testKeys.push_back(dist(gen));
    }
    
    // 测试结果结构
    struct TestResults {
        double lookup_time = 0;
        double insert_time = 0;
        double construction_time = 0;
        double iteration_time = 0;
        size_t memory_usage = 0;
    };
    
    TestResults map_results, flat_map_results;
    
    std::cout << "测试标准 map/multimap...\n";
    
    // 批量构造测试 - map
    map_results.construction_time = measure_time([&]() {
        Map regularMap(data.begin(), data.end());
    });
    
    // 创建测试实例
    Map regularMap;
    
    // 插入测试 - map
    map_results.insert_time = measure_time([&]() {
        for (size_t i = 0; i < operation_count; ++i) {
            regularMap.insert({testKeys[i], i});
        }
    });
    
    // 查找测试 - map
    size_t found = 0;
    map_results.lookup_time = measure_time([&]() {
        for (const auto& key : testKeys) {
            if (regularMap.find(key) != regularMap.end()) {
                ++found;
            }
        }
    });
    
    // 遍历测试 - map
    volatile int sum = 0;
    map_results.iteration_time = measure_time([&]() {
        for (const auto& [key, value] : regularMap) {
            sum += value;
        }
    });
    
    std::cout << "测试 flat_map/flat_multimap...\n";
    
    // 批量构造测试 - flat_map
    flat_map_results.construction_time = measure_time([&]() {
        MultiMap flatMap(data.begin(), data.end());
    });
    
    // 创建测试实例
    MultiMap flatMap;
    
    // 插入测试 - flat_map
    flat_map_results.insert_time = measure_time([&]() {
        for (size_t i = 0; i < operation_count; ++i) {
            flatMap.insert({testKeys[i], i});
        }
    });
    
    // 查找测试 - flat_map
    found = 0;
    flat_map_results.lookup_time = measure_time([&]() {
        for (const auto& key : testKeys) {
            if (flatMap.find(key) != flatMap.end()) {
                ++found;
            }
        }
    });
    
    // 遍历测试 - flat_map
    sum = 0;
    flat_map_results.iteration_time = measure_time([&]() {
        for (const auto& [key, value] : flatMap) {
            sum += value;
        }
    });

    // 输出结果
    std::cout << "----------- 性能对比 -----------\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(15) << "操作" 
            << std::setw(18) << "标准容器 (ms)" 
            << std::setw(18) << "flat容器 (ms)" 
            << std::setw(18) << "性能比" << std::endl;
            
    std::cout << std::left << std::setw(15) << "查找" 
            << std::setw(15) << map_results.lookup_time
            << std::setw(15) << flat_map_results.lookup_time
            << std::setw(15) << map_results.lookup_time / flat_map_results.lookup_time << std::endl;
            
    std::cout << std::left << std::setw(15) << "插入" 
            << std::setw(15) << map_results.insert_time
            << std::setw(15) << flat_map_results.insert_time
            << std::setw(15) << map_results.insert_time / flat_map_results.insert_time << std::endl;
            
    std::cout << std::left << std::setw(17) << "批量构造" 
            << std::setw(15) << map_results.construction_time
            << std::setw(15) << flat_map_results.construction_time
            << std::setw(15) << map_results.construction_time / flat_map_results.construction_time << std::endl;
            
    std::cout << std::left << std::setw(15) << "遍历" 
            << std::setw(15) << map_results.iteration_time
            << std::setw(15) << flat_map_results.iteration_time
            << std::setw(15) << map_results.iteration_time / flat_map_results.iteration_time << std::endl;
}

int main() {
    // 为了测试的完整性，测试不同大小的容器
    // 但较小的数据量以快速获得结果
    std::vector<size_t> sizes = {10000, 100000, 1000000};
    
    // 调整操作次数以平衡测试时间
    std::vector<size_t> operations = {10000, 100000, 1000000};
    
    for (size_t i = 0; i < sizes.size(); ++i) {
        size_t size = sizes[i];
        size_t ops = operations[i];
        
        std::cout << "\n===== Map vs Flat_map =====\n";
        benchmark_containers<std::map<int, int>, std::flat_map<int, int>>(size, ops);
        
        std::cout << "\n===== Multimap vs Flat_multimap =====\n";
        benchmark_containers<std::multimap<int, int>, std::flat_multimap<int, int>>(size, ops);
    }
    
    return 0;
}