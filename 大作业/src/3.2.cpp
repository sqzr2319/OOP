#include <flat_map>
#include <iostream>
#include <string>

// 自定义坐标类型
struct Point {
    int x, y;

    // 便于输出的友元函数
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

// 自定义比较器，按点的曼哈顿距离排序
struct PointCompare {
    bool operator()(const Point& a, const Point& b) const {
        // 计算到原点的曼哈顿距离
        int distA = std::abs(a.x) + std::abs(a.y);
        int distB = std::abs(b.x) + std::abs(b.y);
        
        if (distA == distB) {
            // 距离相等时先比较x再比较y
            return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
        }
        return distA < distB;
    }
};

int main() {
    // 使用自定义键类型和比较器
    std::flat_map<Point, std::string, PointCompare> locations;
    
    // 添加一些位置
    locations.insert({{3, 4}, "传感器A"});
    locations.insert({{1, 1}, "传感器B"});
    locations.insert({{5, 0}, "传感器C"});
    locations.insert({{-2, 3}, "传感器D"});
    
    // 遍历元素（将按自定义比较器排序）
    std::cout << "按到原点距离排序的位置:" << std::endl;
    for (const auto& [pos, name] : locations) {
        std::cout << name << " 位置: " << pos << std::endl;
    }
    
    return 0;
}