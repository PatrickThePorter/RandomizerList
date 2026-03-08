#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> names;

void addNameToList(string name)
{
    names.push_back(name);
}

void removeNameFromList(string name)
{
    int index = -1;
    for (int i = 0; i < names.size(); i++)
    {
        if (names[i] == name)
        {
            index = i;
            return;
        }
    }
    if (index != -1)
    {
        names.erase(names.begin() + index);
        cout << "Erased " << name << " from list." << endl;
    }
    else
    {
        cout << "Error: Name not in list." << endl;
    }
}

void randomizeList()
{
    for (int i = 0; i < 2500; i++)
    {
        int randomX = rand() % names.size();
        int randomY = rand() % names.size();

        string tempName = names[randomX];
        names[randomX] = names[randomY];
        names[randomY] = tempName;
    }
}

string showList()
{
    string nameList = "";
    for (int i = 0; i < names.size(); i++)
    {
        nameList = nameList + names[i] + "\n";
    }
    return nameList;
}

string showFirstInList()
{
    return names[0];
}

string showIndexInList(int i)
{
    return names[i];
}

void removeFirstFromList()
{
    names.erase(names.begin());
}

string returnHelpStatement()
{
    string help = "stop: Stops the program.\nadd: Allows you to add another name to the list.\nrandom: Randomizes the list.\nshowAll: Shows all the names in a list.";
    help += "\nremove: Erases a name from the list.\nshow: Shows the name at a certain index in the list. (NOTE THAT INDEXING STARTS AT 0.)";
    help += "\nshowTop: Shows the first element in the list";
    help += "\nclear: Removes all names from the list.";
    help += "\npop: Displays and removes name at the index. (NOTE THAT INDEXING STARTS AT 0.)";
    help += "\npopTop: Displays and removes the first element in the list.";
    return help;
}

void eraseList()
{
    names.clear();
}

int main()
{
    string cmd = "";
    cout << "Welcome to the name randomizer program.\n" << endl;
    cout << "To begin, type in a command or type \"help\" to see a list of commands" << endl;
    while (cmd != "stop")
    {
        cout << "Enter command: ";
        cin >> cmd;
        if (cmd == "stop")
        {
            continue;
        }
        else if (cmd == "add")
        {
            cout << "\nType in the name here:\n";
            string newName;
            cin >> newName;
            addNameToList(newName);
        }
        else if (cmd == "random")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nRandomizing list...\n";
            randomizeList();
        }
        else if (cmd == "showAll")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nShowing all names...\n";
            string fullNameList = showList();
            cout << fullNameList;
        }
        else if (cmd == "help")
        {
            string help = returnHelpStatement();
            cout << help << endl;
        }
        else if (cmd == "remove")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nType in the name here:\n";
            string removeName;
            cin >> removeName;
            removeNameFromList(removeName);
        }
        else if (cmd == "showTop")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            string firstName = showFirstInList();
            cout << firstName << endl;
        }
        else if (cmd == "show")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nType in the index here:\n";
            int index;
            cin >> index;
            string name = showIndexInList(index);
            cout << name << endl;
        }
        else if (cmd == "clear")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nClearing list..." << endl;
            eraseList();
        }
        else if (cmd == "pop")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            cout << "\nEnter index:\n";
            int index;
            cin >> index;
            string name = showIndexInList(index);
            cout << "\nErasing " << name << " at index " << index << endl;
            removeNameFromList(name);
        }
        else if (cmd == "popTop")
        {
            if (names.empty())
            {
                cout << "The list is empty. Use the \"add\" command to add a name to the list.";
                cmd == "";
                continue;
            }
            string name = showIndexInList(0);
            cout << "\nIt is now " << name << "'s turn!" << endl;
            removeNameFromList(name);
        }
        else
        {
            cout << "Invalid command. " << endl;
        }
        cmd = "";
    }
    return 0;
}