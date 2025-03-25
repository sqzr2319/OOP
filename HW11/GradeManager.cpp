#include "GradeManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

GradeManager::GradeManager() {
    // 构造函数，初始化为空表单
}

bool GradeManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int studentId, grade;
        if (iss >> studentId >> grade) {
            gradeTable[studentId] = grade;
        }
    }
    
    file.close();
    return true;
}

void GradeManager::addGrade(int studentId, int grade) {
    gradeTable[studentId] = grade;
}

bool GradeManager::removeGrade(int studentId) {
    auto it = gradeTable.find(studentId);
    if (it != gradeTable.end()) {
        gradeTable.erase(it);
        return true;
    }
    return false;
}

void GradeManager::clearAll() {
    gradeTable.clear();
}

bool GradeManager::updateGrade(int studentId, int newGrade) {
    auto it = gradeTable.find(studentId);
    if (it != gradeTable.end()) {
        it->second = newGrade;
        return true;
    }
    return false;
}

bool GradeManager::findGrade(int studentId, int& grade) const {
    auto it = gradeTable.find(studentId);
    if (it != gradeTable.end()) {
        grade = it->second;
        return true;
    }
    return false;
}

void GradeManager::displayAll() const {
    if (gradeTable.empty()) {
        std::cout << "成绩表单为空" << std::endl;
        return;
    }
    
    std::cout << "学号\t成绩" << std::endl;
    for (const auto& entry : gradeTable) {
        std::cout << entry.first << "\t" << entry.second << std::endl;
    }
}

bool GradeManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行写入: " << filename << std::endl;
        return false;
    }
    
    for (const auto& entry : gradeTable) {
        file << entry.first << " " << entry.second << std::endl;
    }
    
    file.close();
    return true;
}