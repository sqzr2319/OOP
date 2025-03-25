#ifndef GRADE_MANAGER_HPP
#define GRADE_MANAGER_HPP

#include <unordered_map>
#include <string>

class GradeManager {
private:
    std::unordered_map<int, int> gradeTable; // ѧ�� -> �ɼ� ��ӳ��

public:
    // ���캯��
    GradeManager();
    
    // ���ļ����سɼ���
    bool loadFromFile(const std::string& filename);
    
    // ���ѧ���ɼ�
    void addGrade(int studentId, int grade);
    
    // ɾ��ָ��ѧ���ĳɼ�
    bool removeGrade(int studentId);
    
    // ��ճɼ���
    void clearAll();
    
    // ����ѧ���ɼ�
    bool updateGrade(int studentId, int newGrade);
    
    // ����ѧ���ɼ�
    bool findGrade(int studentId, int& grade) const;
    
    // ��ʾ���гɼ�
    void displayAll() const;
    
    // ���浽�ļ�
    bool saveToFile(const std::string& filename) const;
};

#endif // GRADE_MANAGER_HPP