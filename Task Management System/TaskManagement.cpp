#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }

    void markComplete(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully!\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                taskManager.addTask(description);
                break;
            }
            case 2:
                taskManager.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter the task index to mark as completed: ";
                cin >> index;
                taskManager.markComplete(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task index to delete: ";
                cin >> index;
                taskManager.deleteTask(index);
                break;
            }
            case 5:
                cout << "Exiting Task Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
