#include <flat_map>
#include <iostream>
#include <vector>

int main() {
    // 创建flat_map
    std::flat_map<int, double> dataPoints = {
        {5, 10.5}, {3, 7.2}, {8, 12.3}, {1, 5.1}
    };
    
    // 直接访问键容器和值容器
    std::cout << "键容器内容:" << std::endl;
    for (const auto& key : dataPoints.keys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
    
    std::cout << "值容器内容:" << std::endl;
    for (const auto& value : dataPoints.values()) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // 提取底层容器
    auto [keys, values] = std::move(dataPoints).extract();
    
    // 手动创建新的容器
    std::vector<int> newKeys = {10, 20, 30};
    std::vector<double> newValues = {100.1, 200.2, 300.3};
    
    // 使用新容器创建flat_map
    std::flat_map<int, double> newDataPoints(std::move(newKeys), std::move(newValues));
    
    // 在插入无序元素后使用手动排序
    std::flat_map<int, std::string> events;
    events.emplace(50, "中点事件");
    events.emplace(10, "起始事件");
    events.emplace(90, "结束事件");
    events.emplace(30, "早期事件");
    events.emplace(70, "后期事件");
    
    // 遍历排序后的元素
    std::cout << "排序后的事件:" << std::endl;
    for (const auto& [time, desc] : events) {
        std::cout << "时间: " << time << ", 描述: " << desc << std::endl;
    }
    
    return 0;
}