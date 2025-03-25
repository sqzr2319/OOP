#ifndef GRADE_MANAGER_HPP
#define GRADE_MANAGER_HPP

#include <unordered_map>
#include <string>

class GradeManager {
private:
    std::unordered_map<int, int> gradeTable; // 学号 -> 成绩 的映射

public:
    // 构造函数
    GradeManager();
    
    // 从文件加载成绩表单
    bool loadFromFile(const std::string& filename);
    
    // 添加学生成绩
    void addGrade(int studentId, int grade);
    
    // 删除指定学生的成绩
    bool removeGrade(int studentId);
    
    // 清空成绩表单
    void clearAll();
    
    // 更新学生成绩
    bool updateGrade(int studentId, int newGrade);
    
    // 查找学生成绩
    bool findGrade(int studentId, int& grade) const;
    
    // 显示所有成绩
    void displayAll() const;
    
    // 保存到文件
    bool saveToFile(const std::string& filename) const;
};

#endif // GRADE_MANAGER_HPP