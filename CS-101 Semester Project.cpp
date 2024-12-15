#include <iostream>
#include <string>
using namespace std;

int ids[30];
string titles[50];
string labels[50];
string deadlines[50];
string priorities[50];
bool statuses[50];
int taskCounter = 0;
int taskCount = 0;

void addTask();
void editTask();
void deleteTask();
void markTask();
void displayTasks();
void searchTask();
void filterTasks();
void showProgress();

int main(){
    int choice;

    while(true){
        cout << "\n====== TO-DO LIST MENU ======\n";
        cout << "1. Add Task\n";
        cout << "2. Edit Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task Complete/Incomplete\n";
        cout << "5. View All Tasks\n";
        cout << "6. Search Tasks\n";
        cout << "7. Filter Tasks\n";
        cout << "8. View Progress\n";
        cout << "9. Exit\n";
        cout << "Select an option (1-9): ";
        cin >> choice;

        switch(choice){
            case 1:
                addTask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                markTask();
                break;
            case 5:
                displayTasks();
                break;
            case 6:
                searchTask();
                break;
            case 7:
                filterTasks();
                break;
            case 8:
                showProgress();
                break;
            case 9:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}

void addTask(){
    if(taskCount >= 30){
        cout << "Task list is full. Cannot add more tasks.\n";
        return;
    }

    ids[taskCount] = ++taskCounter;
    cout << "Enter task title: ";
    cin >> titles[taskCount];
    cout << "Enter task label: ";
    cin >> labels[taskCount];
    cout << "Enter task deadline: ";
    cin >> deadlines[taskCount];
    cout << "Enter priority(Low, Medium, High): ";
    cin >> priorities[taskCount];
    statuses[taskCount] = false;

    taskCount++;
    cout << "Task added successfully!\n";
}

void editTask(){
    int id;
    cout << "Enter task ID to edit: ";
    cin >> id;

    for(int i = 0; i < taskCount; ++i){
        if(ids[i] == id){
            cout << "Editing task: " << titles[i] << "\n";
            cout << "Enter new title (or type 'no' to skip): ";
            string title;
            cin >> title;
            if(title != "no"){
                titles[i] = title;
            }

            cout << "Enter new label (or type 'no' to skip): ";
            string label;
            cin >> label;
            if(label != "no"){
                labels[i] = label;
            }

            cout << "Enter new deadline (or type 'no' to skip): ";
            string deadline;
            cin >> deadline;
            if(deadline != "no"){
                deadlines[i] = deadline;
            }

            cout << "Enter new priority (or type 'no' to skip): ";
            string priority;
            cin >> priority;
            if(priority != "no"){
                priorities[i] = priority;
            }

            cout << "Task updated successfully!\n";
            return;
        }
    }

    cout << "Task not found (Please Find Again).\n";
}

void deleteTask(){
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;

    for(int i = 0; i < taskCount; ++i){
        if(ids[i] == id) {
            for(int j = i; j < taskCount - 1; ++j){
                ids[j] = ids[j + 1];
                titles[j] = titles[j + 1];
                labels[j] = labels[j + 1];
                deadlines[j] = deadlines[j + 1];
                priorities[j] = priorities[j + 1];
                statuses[j] = statuses[j + 1];
            }
            --taskCount;
            cout << "Task deleted successfully!\n";
            return;
        }
    }

    cout << "Task not found.\n";
}

void markTask(){
    int id;
    cout << "Enter task ID to toggle status: ";
    cin >> id;

    for(int i = 0; i < taskCount; ++i){
        if(ids[i] == id){
            statuses[i] = !statuses[i];
            cout << "Task status updated successfully!\n";
            return;
        }
    }

    cout << "Task not found.\n";
}

void displayTasks(){
    if(taskCount == 0){
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nDisplaying all tasks:\n";
    for(int i = 0; i < taskCount; ++i){
        cout << "Task ID: " << ids[i] << "\n";
        cout << "Title: " << titles[i] << "\n";
        cout << "Label: " << labels[i] << "\n";
        cout << "Deadline: " << deadlines[i] << "\n";
        cout << "Priority: " << priorities[i] << "\n";
        cout << "Status: " << (statuses[i] ? "Complete" : "Incomplete") << "\n";
        cout << "-----------------------\n";
    }
}

void searchTask(){
    string keyword;
    cout << "Enter title or label to search: ";
    cin >> keyword;

    cout << "\nSearch Results:\n";
    bool found = false;

    for(int i = 0; i < taskCount; ++i){
        bool titleMatch = false;
        bool labelMatch = false;

        for(int j = 0; j <= titles[i].length() - keyword.length(); ++j){
            if(titles[i].substr(j, keyword.length()) == keyword){
                titleMatch = true;
                break;
            }
        }

        for(int j = 0; j <= labels[i].length() - keyword.length(); ++j){
            if(labels[i].substr(j, keyword.length()) == keyword){
                labelMatch = true;
                break;
            }
        }

        if(titleMatch || labelMatch){
            cout << "Task ID: " << ids[i] << "\n";
            cout << "Title: " << titles[i] << "\n";
            cout << "Label: " << labels[i] << "\n";
            cout << "-----------------------\n";
            found = true;
        }
    }

    if(!found){
        cout << "No tasks found matching the keyword.\n";
    }
}

void filterTasks(){
    int filterOption;
    cout << "Filter options: 1) All  2) Active  3) Completed\n";
    cout << "Enter filter option: ";
    cin >> filterOption;

    cout << "\nFiltered Tasks:\n";
    for(int i = 0; i < taskCount; ++i){
        if((filterOption == 2 && !statuses[i]) || (filterOption == 3 && statuses[i]) || filterOption == 1){
            cout << "Task ID: " << ids[i] << "\n";
            cout << "Title: " << titles[i] << "\n";
            cout << "Status: " << (statuses[i] ? "Complete" : "Incomplete") << "\n";
            cout << "-----------------------\n";
        }
    }
}

void showProgress(){
    int completed = 0;
    for(int i = 0; i < taskCount; ++i){
        if(statuses[i]){
            ++completed;
        }
    }

    cout << "\nProgress: " << completed << " / " << taskCount << " tasks completed.\n";
}