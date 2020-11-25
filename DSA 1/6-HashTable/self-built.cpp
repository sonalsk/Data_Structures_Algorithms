#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

class Entry {
    public:

        int key;
        string value;
    
        Entry (int k, string v) {
            key = k;
            value = v;
        }
};

class HashTable {
    private:
        forward_list <Entry> entries[5];
        int hash(int k) {
            return k % 5;
        }
    public:
        void put(int key, string value) {
            int index = hash(key);
            if (entries[index].empty()) {
                entries[index] = forward_list<Entry>();
            }

            for (Entry entry: entries[index]) {
                if (entry.key == key) {
                    entry.value = value;
                    return;
                }
            }
            
            entries[index].push_front(Entry(key, value));
            
        }

        string get(int key) {
            int index = hash(key);
            if (!entries[index].empty()) {
                for (Entry entry: entries[index]) {
                    if (entry.key == key) {
                        return entry.value;
                    }
                }
            }
            return "null";
        }

        // void remove(int key) {
        //     int index = hash(key);
        //     if (entries[key].empty()) {
        //         return;
        //     }
        //     if (!entries[index].empty()) {
        //         for (Entry entry: entries[index]) {
        //             if (entry.key == key) {
        //                 entries[index].remove(entry);
        //                 return;
        //             }
        //         }
        //     }
        //     return;
        // }
};

int main() {
    HashTable table = HashTable();
    table.put(6, "A");
    table.put(8, "B");
    table.put(11, "C");
    table.put(6, "A+");

    cout << table.get(6) << endl;
    return 0;
}