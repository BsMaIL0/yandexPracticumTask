#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class WarehouseStorage {
public:
    WarehouseStorage(const std::vector<int>& items)
      : items_{items} {}
    
    WarehouseStorage operator+(const std::vector<int>& vec) const {
        std::vector<int> new_items = items_;
        new_items.insert(new_items.end(), vec.begin(), vec.end());
        return WarehouseStorage(new_items);
    }
    
     WarehouseStorage operator-(const std::vector<int>& vec) const {
        std::vector<int> new_items = items_;
        
        for (int val : vec) {
            auto it = new_items.begin();
            while (it != new_items.end()) {
                if (*it == val) {
                    it = new_items.erase(it);
                } else {
                    ++it;
                }
            }
        }
        
        return WarehouseStorage(new_items);
    }
    
    void Print(std::ostream &stream, const std::string& name) const {
        stream << name << ": ";
        int i{};
        for (auto &item : items_) {
            if (i++) {
                stream << " ";
            }
            stream << item;
        }
        stream << std::endl;
    }

private:
    std::vector<int> items_;
};

std::vector<int> Read(std::istream &stream) {
    std::string line;
    std::getline(stream, line);
    std::istringstream line_stream(line);

    std::vector<int> ret;
    int val;
    while(line_stream >> val) {
        ret.push_back(val);
    }

    return ret;
}

int main() {
    auto origin = Read(std::cin);
    auto items = Read(std::cin);
    
    const WarehouseStorage storage{origin};
    storage.Print(std::cout, "Origin");
    (storage + items).Print(std::cout, "Supply");
    (storage - items).Print(std::cout, "Disposal");
}