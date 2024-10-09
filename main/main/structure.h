#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string> // ����������� ���������� ��� ������ �� ��������
using namespace std; // ������������� ������������ ������������ ����
// ��������� ��� ������������� ������������
struct Pipeline {
    string name = "none"; // ��� ������������
    int length; // ����� ������������
    int diameter; // ������� ������������
    bool hasRepair; // ������� ������� (��/���)
};
// ��������� ��� ������������� CS
struct CS {
    string name = "none"; // ��� CS
    int mountOfDepartments; // ����� ���������� �������
    int workingDepartments; // ���������� ������� �������
    double coefficientEfficiency; // ����������� �������������
};
#endif // STRUCTURE_H
