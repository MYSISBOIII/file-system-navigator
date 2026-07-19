#include <iostream>
#include <vector>
#include <string.h>

typedef std::string string;

// git bash test

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

void createFile(const string name, const string text, Directory& desiredDir) {
    File file(name);

    file.write(text);

    desiredDir.pushFile(file);
}

void renameFile(const string curName, const string targetName, Directory& curDir) {
    for (File file : curDir.getFiles()) {
        if (file.getName() == curName) {
            file.setName(targetName);
        }
    }
}

void deleteFile(const string name, const string foo, Directory& curDir) {
    curDir.deleteFile(name);
}

void(*cmds[5])(string, string, Directory&) { // tried making a lookup table kind of thing
    createFile,
    renameFile,
    deleteFile
};

int main() {

    Directory dir("/");

    bool notExit = true;

    while (notExit) {
    
    
    }
    

    return 0;
}
