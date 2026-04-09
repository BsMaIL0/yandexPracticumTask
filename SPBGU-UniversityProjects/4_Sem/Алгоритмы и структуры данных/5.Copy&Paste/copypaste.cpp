#include <fstream>
#include <iostream>

const int MAX_STR_LEN = 1001;

class TextNode {
 public:
  char* data;
  TextNode* prev;
  TextNode* next;

  TextNode() : prev(nullptr), next(nullptr) {
    data = new char[MAX_STR_LEN];
    data[0] = '\0';
  }

  TextNode(const char* text) : prev(nullptr), next(nullptr) {
    data = new char[MAX_STR_LEN];
    int i = 0;
    while (text[i] != '\0' && text[i] != '\r' && i < MAX_STR_LEN - 1) {
      data[i] = text[i];
      i++;
    }
    data[i] = '\0';
  }

  ~TextNode() { delete[] data; }

 private:
  TextNode(const TextNode&);
  TextNode& operator=(const TextNode&);
};

class TextContainer {
 private:
  TextNode* first;
  TextNode* last;
  int itemCount;

 public:
  TextContainer() : first(nullptr), last(nullptr), itemCount(0) {}

  ~TextContainer() { purge(); }

  void purge() {
    TextNode* current = first;
    while (current != nullptr) {
      TextNode* next = current->next;
      delete current;
      current = next;
    }
    first = nullptr;
    last = nullptr;
    itemCount = 0;
  }

  void addToEnd(const char* text) {
    TextNode* newNode = new TextNode(text);
    if (first == nullptr) {
      first = newNode;
      last = newNode;
    } else {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    }
    itemCount++;
  }

  TextNode* findNode(int pos) const {
    if (pos < 0 || pos >= itemCount) {
      return nullptr;
    }

    TextNode* current;
    if (pos < itemCount / 2) {
      current = first;
      int steps = pos;
      while (steps > 0) {
        current = current->next;
        steps--;
      }
    } else {
      current = last;
      int steps = itemCount - pos - 1;
      while (steps > 0) {
        current = current->prev;
        steps--;
      }
    }
    return current;
  }

  void insertAtPosition(int pos, const char* text) {
    if (pos < 0 || pos > itemCount) {
      return;
    }

    TextNode* newNode = new TextNode(text);

    if (pos == 0) {
      newNode->next = first;
      if (first != nullptr) {
        first->prev = newNode;
      }
      first = newNode;
      if (last == nullptr) {
        last = newNode;
      }
    } else if (pos == itemCount) {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    } else {
      TextNode* target = findNode(pos);
      TextNode* before = target->prev;

      before->next = newNode;
      newNode->prev = before;
      newNode->next = target;
      target->prev = newNode;
    }
    itemCount++;
  }

  void deleteRange(int startIdx, int endIdx) {
    if (startIdx < 0 || endIdx >= itemCount || startIdx > endIdx) {
      return;
    }

    TextNode* startNode = findNode(startIdx);
    TextNode* endNode = findNode(endIdx);
    if (startNode == nullptr || endNode == nullptr) {
      return;
    }

    TextNode* beforeStart = startNode->prev;
    TextNode* afterEnd = endNode->next;

    TextNode* current = startNode;
    while (current != afterEnd) {
      TextNode* next = current->next;
      delete current;
      current = next;
    }

    if (beforeStart != nullptr) {
      beforeStart->next = afterEnd;
    } else {
      first = afterEnd;
    }

    if (afterEnd != nullptr) {
      afterEnd->prev = beforeStart;
    } else {
      last = beforeStart;
    }

    itemCount -= (endIdx - startIdx + 1);
  }

  const char* getTextAt(int pos) const {
    TextNode* node = findNode(pos);
    if (node != nullptr) {
      return node->data;
    }
    return "";
  }

  int getSize() const { return itemCount; }

  void copyRange(int start, int end, TextContainer& dest) const {
    dest.purge();
    if (start > end || start >= itemCount) {
      return;
    }

    int actualEnd = (end < itemCount) ? end : itemCount - 1;
    TextNode* current = findNode(start);

    for (int i = start; i <= actualEnd && current != nullptr; ++i) {
      dest.addToEnd(current->data);
      current = current->next;
    }
  }

  void insertMultiple(int pos, TextContainer* source) {
    if (source == nullptr || source->getSize() == 0) {
      return;
    }

    int srcSize = source->getSize();

    if (pos == itemCount) {
      TextNode* current = source->findNode(0);
      while (current != nullptr) {
        addToEnd(current->data);
        current = current->next;
      }
    } else {
      TextNode* target = (pos == 0) ? first : findNode(pos);
      TextNode* before = (pos == 0) ? nullptr : target->prev;
      TextNode* current = source->findNode(0);

      while (current != nullptr) {
        TextNode* newNode = new TextNode(current->data);

        if (before == nullptr) {
          newNode->next = first;
          if (first != nullptr) {
            first->prev = newNode;
          }
          first = newNode;
        } else {
          newNode->next = target;
          newNode->prev = before;
          before->next = newNode;
          if (target != nullptr) {
            target->prev = newNode;
          }
        }

        before = newNode;
        if (target == nullptr && pos + srcSize - 1 >= itemCount) {
          last = newNode;
        }
        current = current->next;
      }
      itemCount += srcSize;
    }
  }
};

class FileHandler {
 public:
  static int countFileEntries(std::ifstream& file) {
    char buffer[MAX_STR_LEN];
    int counter = 0;
    std::streampos savedPos = file.tellg();

    file.clear();
    file.seekg(0, std::ios::beg);

    while (file.getline(buffer, MAX_STR_LEN)) {
      counter++;
    }

    file.clear();
    file.seekg(savedPos);
    return counter;
  }

  static void loadIntoContainer(std::ifstream& file, TextContainer& container,
                                int maxItems) {
    char buffer[MAX_STR_LEN];
    int loaded = 0;

    while (loaded < maxItems && file.getline(buffer, MAX_STR_LEN)) {
      int len = 0;
      while (buffer[len] != '\0' && buffer[len] != '\r') {
        len++;
      }
      buffer[len] = '\0';
      container.addToEnd(buffer);
      loaded++;
    }
  }

  static void saveContainerToFile(std::ofstream& file, TextContainer& container,
                                  bool useCRLF, bool addFinalNewline) {
    int total = container.getSize();
    const char* newline = useCRLF ? "\r\n" : "\n";

    for (int i = 0; i < total; ++i) {
      file << container.getTextAt(i);
      if (i < total - 1 || addFinalNewline) {
        file << newline;
      }
    }
  }

  static bool detectNewlineFormat(std::ifstream& file) {
    char ch;
    std::streampos savedPos = file.tellg();

    file.clear();
    file.seekg(0, std::ios::beg);

    while (file.get(ch)) {
      if (ch == '\r') {
        file.clear();
        file.seekg(savedPos);
        return true;
      }
      if (ch == '\n') {
        break;
      }
    }

    file.clear();
    file.seekg(savedPos);
    return false;
  }

  static bool checkTrailingNewline(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();

    if (size > 0) {
      file.seekg(-1, std::ios::cur);
      char lastChar;
      file.get(lastChar);
      file.clear();
      file.seekg(0, std::ios::beg);
      return lastChar == '\n';
    }

    file.clear();
    file.seekg(0, std::ios::beg);
    return false;
  }

  static void trimNewline(char* str) {
    int len = 0;
    while (str[len] != '\0') {
      len++;
    }
    if (len > 0 && str[len - 1] == '\n') {
      len--;
      str[len] = '\0';
    }
    if (len > 0 && str[len - 1] == '\r') {
      str[len - 1] = '\0';
    }
  }

  static bool compareStrings(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0' && *a == *b) {
      a++;
      b++;
    }
    return *a == *b;
  }
};

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <input> <commands> <output>\n";
    return 1;
  }

  std::ifstream inputFile(argv[1], std::ios::binary);
  if (!inputFile.is_open()) {
    std::cerr << "Cannot open input file\n";
    return 1;
  }

  bool windowsFormat = FileHandler::detectNewlineFormat(inputFile);
  bool hasTrailingNewline = FileHandler::checkTrailingNewline(inputFile);

  std::ifstream cmdFile(argv[2]);
  if (!cmdFile.is_open()) {
    std::cerr << "Cannot open commands file\n";
    inputFile.close();
    return 1;
  }

  std::ofstream outputFile(argv[3], std::ios::binary);
  if (!outputFile.is_open()) {
    std::cerr << "Cannot open output file\n";
    inputFile.close();
    cmdFile.close();
    return 1;
  }

  int totalEntries = FileHandler::countFileEntries(inputFile);
  inputFile.clear();
  inputFile.seekg(0, std::ios::beg);

  TextContainer mainContainer;
  FileHandler::loadIntoContainer(inputFile, mainContainer, totalEntries);
  inputFile.close();

  int cursorPos = 0;
  bool shiftMode = false;
  int markPos = -1;
  TextContainer* clipboard = nullptr;

  char cmd[20];
  while (cmdFile.getline(cmd, 20)) {
    FileHandler::trimNewline(cmd);

    if (FileHandler::compareStrings(cmd, "Down")) {
      if (cursorPos < mainContainer.getSize()) {
        cursorPos++;
      }
    } else if (FileHandler::compareStrings(cmd, "Up")) {
      if (cursorPos > 0) {
        cursorPos--;
      }
    } else if (FileHandler::compareStrings(cmd, "Shift")) {
      shiftMode = true;
      markPos = cursorPos;
    } else if (FileHandler::compareStrings(cmd, "Ctrl+X")) {
      int start = cursorPos;
      int end = cursorPos;

      if (shiftMode && markPos != -1 && markPos != cursorPos) {
        if (markPos < cursorPos) {
          start = markPos;
          end = cursorPos - 1;
        } else {
          start = cursorPos;
          end = markPos - 1;
        }
      }

      if (start < 0) {
        start = 0;
      }
      if (end >= mainContainer.getSize()) {
        end = mainContainer.getSize() - 1;
      }

      if (start <= end && start < mainContainer.getSize()) {
        delete clipboard;
        clipboard = new TextContainer();
        mainContainer.copyRange(start, end, *clipboard);
        mainContainer.deleteRange(start, end);

        int removed = end - start + 1;
        if (cursorPos > end) {
          cursorPos -= removed;
        } else if (cursorPos >= start) {
          cursorPos = start;
        }
      } else {
        delete clipboard;
        clipboard = nullptr;
      }

      if (cursorPos < 0) {
        cursorPos = 0;
      }
      if (cursorPos > mainContainer.getSize()) {
        cursorPos = mainContainer.getSize();
      }

      shiftMode = false;
      markPos = -1;
    } else if (FileHandler::compareStrings(cmd, "Ctrl+V")) {
      if (clipboard != nullptr && clipboard->getSize() != 0) {
        int insertPos = cursorPos;

        if (shiftMode && markPos != -1 && markPos != cursorPos) {
          int removeStart = (markPos < cursorPos) ? markPos : cursorPos;
          int removeEnd = (markPos < cursorPos) ? cursorPos - 1 : markPos - 1;

          if (removeStart < 0) {
            removeStart = 0;
          }
          if (removeEnd >= mainContainer.getSize()) {
            removeEnd = mainContainer.getSize() - 1;
          }

          if (removeStart <= removeEnd &&
              removeStart < mainContainer.getSize()) {
            mainContainer.deleteRange(removeStart, removeEnd);
            insertPos = removeStart;
          }
        }

        if (insertPos < 0) {
          insertPos = 0;
        }
        if (insertPos > mainContainer.getSize()) {
          insertPos = mainContainer.getSize();
        }

        mainContainer.insertMultiple(insertPos, clipboard);
        cursorPos = insertPos + clipboard->getSize();
      }

      shiftMode = false;
      markPos = -1;
    }
  }

  FileHandler::saveContainerToFile(outputFile, mainContainer, windowsFormat,
                                   hasTrailingNewline);

  cmdFile.close();
  outputFile.close();
  delete clipboard;

  return 0;
}