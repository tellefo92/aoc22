#include "utils.hpp"

using namespace std;

struct file;
struct dir;

struct file {
    string name;
    int size;
    file(){};
    file(string filename, int filesize) {
        name = filename;
        size = filesize;
    };
};

struct dir {
    dir * parent_dir = nullptr;
    string name;
    vector<file> files;
    vector<dir> dirs;
    dir(){};
    dir(string dirname) {
        name = dirname;
    };
    dir(dir * pdir, string dirname) {
        name = dirname;
        parent_dir = pdir;
    };
    void extend(dir d) {
        dirs.push_back(d);
    };
    void extend(file f) {
        files.push_back(f);
    };
    dir * go_to(string dirname){
        for (size_t i = 0; i < dirs.size(); i++) {
            if (dirs[i].name == dirname) {
                return &dirs[i];
            }
        }
        cout << "Could not find directory " << dirname << " in " << name << endl;
        return this;
    };
    uint64_t file_size() {
        uint64_t sum = 0;
        for (auto f: files) {
            sum += f.size;
        }
        return sum;
    };
    uint64_t dir_size() {
        uint64_t sum = 0;
        sum += file_size();
        for (auto d: dirs) {
            sum += d.dir_size();
        }
        return sum;
    };
    uint64_t sum_dirs(uint64_t max_size) {
        uint64_t sum = 0;
        if (dir_size() <= max_size) sum += dir_size();
        for (auto d: dirs) {
            sum += d.sum_dirs(max_size);
        }
        return sum;
    }
    uint64_t find_smallest_dir_to_delete(uint64_t threshold) {
        vector<uint64_t> sizes;
        if (dir_size() >= threshold) {
            sizes.push_back(dir_size());
        } else {
            return uint64_t(70000000);
        }
        for (auto d: dirs) {
            sizes.push_back(d.find_smallest_dir_to_delete(threshold));
        }
        sort(sizes.begin(), sizes.end());
        return sizes[0];
    }
    void print(int indent) {
        string output = "";
        for (int i=0; i<indent; i++) output += " ";
        output += "- ";
        for (int i=0; i<dirs.size(); i++) {
            cout << output << dirs[i].name << " (dir, size=" << dirs[i].dir_size() << ")" << endl;
            dirs[i].print(indent+2);
        }
        for (auto f: files) {
            cout << output << f.name << " (file, size=" << f.size << ")" << endl;
        }
    }
    void print() {
        int indent = 0;
        string output = "- ";
        for (int i=0; i<dirs.size(); i++) {
            cout << output << dirs[i].name << " (dir, size=" << dirs[i].dir_size() << ")" << endl;
            dirs[i].print(indent+=2);
        }
        for (auto f: files) {
            cout << f.name << " (file) size: " << f.size << endl;
        }
    };
};

int main() {
    string line, fname;
    vector<string> l;
    int fsize;
    file f;
    dir *curr_dir, root("/"), d;
    while (getline(cin, line)) {
        l = splitString<string>(line);
        if (l[0] == "$") {
            if (l[1] == "cd") {
                if (l[2] == "/") {
                    curr_dir = &root;
                } else if (l[2] == "..") {
                    curr_dir = curr_dir->parent_dir;
                } else {
                    curr_dir = curr_dir->go_to(l[2]);
                }
            }
        } else {
            if (l.size() == 2) {
                if (l[0] == "dir") {
                    d = dir(curr_dir, l[1]);
                    curr_dir->extend(d);
                } else {
                    fname = l[1];
                    fsize = stoi(l[0]);
                    f = file(fname, fsize);
                    curr_dir->extend(f);
                }
            }
        }
    }
    // Part 1
    cout << root.sum_dirs(100000) << endl;

    // Part 2
    uint64_t total_space = 70000000, used_space = root.dir_size(), required_space = 30000000;
    uint64_t unused_space = total_space - used_space;
    uint64_t threshold = required_space - unused_space;
    cout << root.find_smallest_dir_to_delete(threshold) << endl;
}