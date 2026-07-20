#include <iostream>
#include <vector>
#include <string.h>

typedef std::string string;

class File {
    string name;
    string content;

  public:
    File(string identifier) {
        name = identifier;
    }

    string getName() {
        return name;
    }

    void setName(const string identifier) {
        name = identifier;
    }

    void write(const string text) {
        content = text;
    }
};

class Directory {

    std::vector<File> files;
    
    string name;

  public:

    Directory(const string identifier) {
        name = identifier;
    }

    void pushFile(const File file) {
        files.push_back(file);
    }

    void deleteFile(const string name) {

        for (int i{0}; i < files.size(); i++) {
            if (files[i].getName() == name) {
                files.erase(files.begin() + i);
            }
        }
    }

    std::vector<File> getFiles() {
        return files;
    }
};

void create_file(const string name, const string text, Directory& desiredDir) {
    File file(name);

    file.write(text);

    desiredDir.pushFile(file);
}

void rename_file(const string curName, const string targetName, Directory& curDir) {
    for (File file : curDir.getFiles()) {
        if (file.getName() == curName) {
            file.setName(targetName);
        }
    }
}

void delete_file(const string name, const string foo, Directory& curDir) {
    curDir.deleteFile(name);
}

void(*cmds[5])(string, string, Directory&) { 
    create_file,
    rename_file,
    delete_file
};

std::vector<string> string_explode(string str) {
    std::vector<string> arr; // maybe make an actual array for once
 
    string container;

    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == ' ') {
            arr.push_back(container);
            container.clear();
        }
        else {
            container.push_back(*it);
        }
    }

    return arr;
}

int main() {

    Directory dir("/");

    bool notExit = true;
    int action;

    while (notExit) {
        std::cout << "Choose your action: ";
        std::cin >> action;

        if (action == 0) {
            notExit = false;
        }
        else {
            
        }
    }
    

    return 0;
}
