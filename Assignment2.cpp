#include <iostream>
#include <string>
using namespace std;

struct Equipment {
    int id;
    string name;
    string category;
    string manufacturer;
    string modelNumber;
    string condition;
    string lastMaintenanceDate;
};
const int MAX = 100;

//Preload dummy record
Equipment records[MAX] = {
    {101, "Laser Cutter", "Machines", "XYZ Corp.", "XYZ-123", "Good", "2024-01-15"},
    {102, "3D Printer", "Machines", "ABC Corp.", "ABC-123", "Good", "2024-02-20"},
    {103, "Impact Tester", "Test Equipment", "DEF Corp.", "DEF-123", "Good", "2024-09-01"},
};
int recordCount = 3;

//Function prototype list
void insertionSort(int A[], int size);
int binarySearch(const int array[], int key, int low, int high);
int linearSearch(const string array[], const string key, int size);
void displayRecords(Equipment records[], int recordCount);
void sortByName(Equipment records[], int recordCount);
void sortByDate(Equipment records[], int recordCount);
void searchById(Equipment records[], int recordCount);
void searchByCategory(Equipment records[], int recordCount);
void searchByCondition(Equipment records[], int recordCount);
void searchByManufacturerAndModel(Equipment records[], int recordCount);
void displayMenu();
void processRecord();

int main() {
    processRecord();
}

// Provided insertion sort
void insertionSort(int A[], int size) {
    int i, j, current;
    for (i = 1; i < size; i++) {
        current = A[i];
        j = i;
        while (j > 0 && current < A[j - 1]) {
            A[j] = A[j - 1];
            j--;
            A[j] = current;
        }
    }
}

// Provided binary search
int binarySearch(const int array[], int key, int low, int high) {
    int middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (key == array[middle]) return middle;
        else if (key < array[middle]) high = middle - 1;
        else low = middle + 1;
    }
    return -1;
}

// Provided linear search
int linearSearch(const string array[], const string key, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i; // Return the location in array
        }
    }
    return -1; // Key not found
}

// Function to display all records
void displayRecords(Equipment records[], int recordCount) {
    for (int i = 0; i < recordCount; i++) {
        cout << "ID: " << records[i].id << "\n"
            << "Name: " << records[i].name << "\n"
            << "Category: " << records[i].category << "\n"
            << "Manufacturer: " << records[i].manufacturer << "\n"
            << "Model Number: " << records[i].modelNumber << "\n"
            << "Condition: " << records[i].condition << "\n"
            << "Last Maintenance Date: " << records[i].lastMaintenanceDate << "\n\n";
    }
}

// Function to sort records by name using insertion sort
void sortByName(Equipment records[], int recordCount) {
    for (int i = 1; i < recordCount; i++) {
        Equipment current = records[i];
        int j = i;
        while (j > 0 && records[j - 1].name > current.name) {
            records[j] = records[j - 1];
            j--;
            records[j] = current;
        }
    }
}

// Function to sort records by last maintenance date using insertion sort
void sortByDate(Equipment records[], int recordCount) {
    for (int i = 1; i < recordCount; i++) {
        Equipment current = records[i];
        int j = i;
        while (j > 0 && records[j - 1].lastMaintenanceDate > current.lastMaintenanceDate) {
            records[j] = records[j - 1];
            j--;
            records[j] = current;
        }
    }
}

// Function to search for a record by ID using binary search
void searchById(Equipment records[], int recordCount) {
    int ids[MAX];
    for (int i = 0; i < recordCount; i++) {
        ids[i] = records[i].id;
    }
    insertionSort(ids, recordCount);  //sort before search

    int targetId;
    cout << "Enter equipment ID: ";
    cin >> targetId;

    int result = binarySearch(ids, targetId, 0, recordCount - 1);
    if (result != -1) {
        for (int i = 0; i < recordCount; i++) {
            if (records[i].id == ids[result]) {
                cout << "\nFound:\n";
                cout << "Name: " << records[i].name << "\n";
                cout << "Category: " << records[i].category << "\n";
                cout << "Manufacturer: " << records[i].manufacturer << "\n";
                cout << "Model Number: " << records[i].modelNumber << "\n";
                cout << "Condition: " << records[i].condition << "\n";
                cout << "Last Maintenance Date: " << records[i].lastMaintenanceDate << "\n\n";
            }
        }
    }
    else {
        cout << "ID not found!\n";
    }
}

// Function to search for records by category using linear search
void searchByCategory(Equipment records[], int recordCount) {
    string targetCategory;
    cin.ignore(); // ignore newline after previous cin
    cout << "Enter category: ";
    getline(cin, targetCategory);
    bool found;
    found = false;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].category == targetCategory) {
            found = true;
            cout << "\nFound:\n";
            cout << "ID: " << records[i].id << "\n";
            cout << "Name: " << records[i].name << "\n";
            cout << "Manufacturer: " << records[i].manufacturer << "\n";
            cout << "Model Number: " << records[i].modelNumber << "\n";
            cout << "Condition: " << records[i].condition << "\n";
            cout << "Last Maintenance Date: " << records[i].lastMaintenanceDate << "\n\n";
        }
    }
    if (!found) {
        cout << "Category not found. Please check again." << endl;
    }
}

// Function to search for records by condition using linear search
void searchByCondition(Equipment records[], int recordCount) {
    string targetCondition;
    cin.ignore(); // ignore newline after previous cin
    cout << "Enter condition: ";
    getline(cin, targetCondition);
    bool found;
    found = false;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].condition == targetCondition) {
            found = true;
            cout << "\nFound:\n";
            cout << "ID: " << records[i].id << "\n";
            cout << "Name: " << records[i].name << "\n";
            cout << "Category: " << records[i].category << "\n";
            cout << "Manufacturer: " << records[i].manufacturer << "\n";
            cout << "Model Number: " << records[i].modelNumber << "\n";
            cout << "Last Maintenance Date: " << records[i].lastMaintenanceDate << "\n\n";
        }
    }
    if (!found) {
        cout << "Condition not found. Please check again." << endl;
    }
}

// Function to search for records by manufacturer and model using linear search
void searchByManufacturerAndModel(Equipment records[], int recordCount) {
    string targetManufacturer, targetModel;
    cin.ignore(); // ignore newline after previous cin
    cout << "Enter manufacturer: ";
    getline(cin, targetManufacturer);
    cout << "Enter model number: ";
    getline(cin, targetModel);

    bool found;
    found = false;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].manufacturer == targetManufacturer && records[i].modelNumber == targetModel) {
            found = true;
            cout << "\nFound:\n";
            cout << "ID: " << records[i].id << "\n";
            cout << "Name: " << records[i].name << "\n";
            cout << "Category: " << records[i].category << "\n";
            cout << "Condition: " << records[i].condition << "\n";
            cout << "Last Maintenance Date: " << records[i].lastMaintenanceDate << "\n\n";
        }
    }
    if (!found) {
        cout << "Manufacturer and Model Number not found. Please check again." << endl;
    }
}

void displayMenu() {
    cout << "====================================================================\n";
    cout << "Engineering Lab Equipment Management System (ELEMS)" << endl;
    cout << "====================================================================\n";
    cout << "1. Search by Equipment ID" << endl;
    cout << "2. View by Category" << endl;
    cout << "3. View by Condition" << endl;
    cout << "4. View by Manufacturer and Model" << endl;
    cout << "5. View all Equipment Records" << endl;
    cout << "6. Sort by Equipment Name" << endl;
    cout << "7. Sort by Last Maintenance Date" << endl;
    cout << "====================================================================\n";
}

void processRecord() {
    char resume = 'y';
    char choice = ' ';

    while (resume == 'y' || resume == 'Y') {
        displayMenu();
        cout << "Enter choice (1/2/3/4/5/6/7): ";
        cin >> choice;

        switch (choice) {
        case '1':
            searchById(records, recordCount);
            break;
        case '2':
            searchByCategory(records, recordCount);
            break;
        case '3':
            searchByCondition(records, recordCount);
            break;
        case '4':
            searchByManufacturerAndModel(records, recordCount);
            break;
        case '5':
            cout << "\n=== All Lab Equipment Records ===\n";
            displayRecords(records, recordCount);
            break;
        case '6':
            sortByName(records, recordCount);
            cout << "\n=== Records sorted by name === \n";
            displayRecords(records, recordCount);
            break;
        case '7':
            sortByDate(records, recordCount);
            cout << "\n=== Records sorted by maintenance date ===\n";
            displayRecords(records, recordCount);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "Continue (y/n): ";
        cin >> resume;
        cout << "\n\n\n";
        if (resume == 'n' || resume == 'N') {
            cout << "Thanks for using the system. System exiting...." << endl;
        }
    }
}