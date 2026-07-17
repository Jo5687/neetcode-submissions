class LinkNode {
public:
    int val;
    LinkNode* next;

    LinkNode(int initialVal) : val(initialVal), next(nullptr) {}
    LinkNode(int initialVal, LinkNode* next) : val(initialVal), next(next) {}
};

class LinkedList {
private:
    LinkNode* head;
    LinkNode* tail;
public:
    LinkedList() {
        head = new LinkNode(-1);
        tail = head;
    }

    int get(int index) {
        LinkNode* curr = head->next;
        int listIndex = 0;
        while(curr != nullptr)
        {
            if(listIndex == index)
            {
                return curr->val;
            }
            listIndex++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        LinkNode* newHead = new LinkNode(val);
        newHead->next = head->next;
        head->next = newHead;
        if(newHead->next == nullptr)
        {
            tail = newHead;
        }
    }
    
    void insertTail(int val) {
        tail->next = new LinkNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        LinkNode* curr = head;
        int listIndex = 0;
        while(curr != nullptr && curr->next != nullptr)
        {
            if(listIndex == index)
            {
                LinkNode* toDelete = curr->next;
                curr->next = curr->next->next;
                if (toDelete == tail) {
                    tail = curr;
                }
                delete toDelete;
                return true;
            }
            listIndex++;
            curr = curr->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values{};
        LinkNode* curr = head->next;
        while(curr != nullptr)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};