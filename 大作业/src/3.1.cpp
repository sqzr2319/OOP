#include <flat_map>
#include <iostream>
#include <string>

int main() {
    // 创建并初始化flat_map
    std::flat_map<int, std::string> studentIds = {
        {1001, "张三"},
        {1002, "李四"},
        {1003, "王五"}
    };

    // 使用operator[]添加新元素
    studentIds[1004] = "赵六";

    // 使用emplace添加新元素
    studentIds.emplace(1005, "钱七");

    // 访问元素
    std::cout << "学号1003对应学生: " << studentIds[1003] << std::endl;

    // 检查键是否存在
    if (studentIds.contains(1006)) {
        std::cout << "学号1006存在" << std::endl;
    } else {
        std::cout << "学号1006不存在" << std::endl;
    }

    // 遍历所有元素
    std::cout << "所有学生信息:" << std::endl;
    for (const auto& [id, name] : studentIds) {
        std::cout << "学号: " << id << ", 姓名: " << name << std::endl;
    }

    return 0;
}