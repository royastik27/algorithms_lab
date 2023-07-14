#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    char task_name;
    int start;
    int finish;
}Task;

bool cmp(Task a, Task b)
{
    return a.start < b.start;
}

Task task[100];
int last_time[100];
vector <char> schedule[100];

int find_machine1(int nMachines)
{
    int i, mn = INT_MAX, machine = -1;

    for(i = 0; i < nMachines; ++i)
    {
        if(last_time[i] < mn)
        {
            mn = last_time[i];
            machine = i;
        }
    }

    return machine;
}

int find_machine(int start_time, int nMachines)
{
    int i;

    for(i = 0; i < nMachines; ++i)
    {
        if(last_time[i] <= start_time)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int nTasks, nMachines, i, j, machine, sz;
    Task temp;

    cout << "Enter the number of tasks: ";
    cin >> nTasks;

    cout << "\nTask data:\n";
    for(i = 0; i < nTasks; ++i)
    {
        cout << "For task " << (i+1) << ":\n";

        cout << "Task name: ";
        cin >> temp.task_name;

        cout << "Start time: ";
        cin >> temp.start;

        cout << "Finish time: ";
        cin >> temp.finish;

        cout << '\n';

        task[i] = temp;
    }

    cout << "Enter the number of machines: ";
    cin >> nMachines;

    for(i = 0; i < nMachines; ++i)
        last_time[i] = 0;

    sort(task, task+nTasks, cmp);

    for(i = 0; i < nTasks; ++i)
    {
        machine = find_machine(task[i].start, nMachines);

        schedule[machine].push_back(task[i].task_name);
        last_time[machine] = task[i].finish;
    }

    cout << "\nScheduling:\n";
    for(i = 0; i < nMachines; ++i)
    {
        cout << "M" << (i+1) << ": ";

        sz = schedule[i].size();
        for(j = 0; j < sz; ++j)
            cout << schedule[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}