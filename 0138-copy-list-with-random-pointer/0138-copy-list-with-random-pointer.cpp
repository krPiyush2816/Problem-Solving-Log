/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            if (temp->random != nullptr) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;

        while (temp != nullptr) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        Node* clonedHead = dummyNode->next;
        delete dummyNode;
        return clonedHead;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};