#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    string name;
    int tasks;
    int errors;
    int hours;
};

vector<Employee> inputPerformance() {
    vector<Employee> e;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Employee x;
        getline(cin, x.name);
        cin >> x.tasks >> x.errors >> x.hours;
        cin.ignore();

        if (x.tasks < 0) x.tasks = 0;
        if (x.errors < 0) x.errors = 0;
        if (x.hours < 0) x.hours = 0;

        e.push_back(x);
    }
    return e;
}

double calculateScore(Employee e) {
    double s = 0;

    if (e.tasks > 50) s = e.tasks * 1.5;
    else s = e.tasks;

    if (e.errors > 10) s -= e.errors * 2;
    else s -= e.errors;

    if (e.hours > 160) s += 10;

    if (s < 0) s = 0;
    if (s > 100) s = 100;

    return s;
}

string generateFeedback(Employee e) {
    double s = calculateScore(e);

    if (s >= 80) return "Excellent";
    if (s >= 50) return "Good";
    return "Poor";
}

void display(vector<Employee> e) {
    cout << "All employees:" << endl;

    for (int i = 0; i < e.size(); i++) {
        cout << e[i].name << " | "
             << (int)calculateScore(e[i]) << " | "
             << generateFeedback(e[i]) << endl;
    }
}

int main() {
    vector<Employee> employees = inputPerformance();
    display(employees);
    return 0;
}