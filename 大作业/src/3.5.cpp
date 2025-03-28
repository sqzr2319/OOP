#include <flat_map>
#include <iostream>
#include <string>

int main() {
    // 创建flat_multimap存储学生课程信息
    std::flat_multimap<std::string, std::string> studentCourses;
    
    // 插入数据（每个学生可以选多门课程）
    studentCourses.insert({"李明", "数学"});
    studentCourses.insert({"张华", "物理"});
    studentCourses.insert({"李明", "英语"});  // 李明的第二门课
    studentCourses.insert({"王芳", "化学"});
    studentCourses.insert({"张华", "生物"});  // 张华的第二门课
    studentCourses.insert({"李明", "历史"});  // 李明的第三门课
    
    // 按学生分组打印选课情况
    std::string currentStudent;
    std::cout << "学生选课情况：" << std::endl;
    
    for (const auto& [student, course] : studentCourses) {
        if (student != currentStudent) {
            currentStudent = student;
            std::cout << "\n" << student << " 选修的课程：";
        }
        std::cout << " " << course;
    }
    std::cout << std::endl;
    
    // 查找特定学生的所有课程
    std::string targetStudent = "李明";
    auto [begin, end] = studentCourses.equal_range(targetStudent);
    
    std::cout << "\n使用equal_range查找 " << targetStudent << " 的所有课程：";
    for (auto it = begin; it != end; ++it) {
        std::cout << " " << it->second;
    }
    std::cout << std::endl;
    
    // 计算特定学生的课程数量
    std::cout << targetStudent << " 总共选修了 " 
              << studentCourses.count(targetStudent) << " 门课程" << std::endl;
    
    return 0;
}