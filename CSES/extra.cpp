
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


pair<ListNode*,int> cycleInLinkedList(ListNode* head) {
    if(!head || !(head->next)) return {NULL,-1} ;

    ListNode * slow = head ;
    ListNode * fast = head ;

    while(fast){

        fast = fast -> next ;
        if(fast){
            slow = slow -> next ;
            fast = fast -> next ;
        }

        if(slow == fast) break ;
    }

    if(fast == NULL) return {NULL,-1} ;

    ListNode * randomNodeInCycle = fast ;
    ListNode * cur = head ;
    while(cur != randomNodeInCycle){
        cur = cur->next ;
        randomNodeInCycle = randomNodeInCycle->next ;
    }

    ListNode * cycleHead = randomNodeInCycle ;
    int len = 1 ;
    ListNode* temp = cycleHead -> next ;
    while(temp != cycleHead){
        len++;
        temp = temp->next ;
    }

    return {cycleHead,len} ;

    
}


ListNode* GetList(int n, vector<int> &num, int lastLink) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < n; i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }

    if(lastLink) {
        ListNode* temp = head;
        for(int i = 0; i < lastLink - 1; i++) {
            temp = temp->next;
        }
        cur->next = temp;
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int lastLink;
    cin >> lastLink;

    ListNode* head = GetList(n, num, lastLink);

    pair<ListNode*,int> ans = cycleInLinkedList(head);

    cout << (ans.first ? ans.first->val : -1) << " " << ans.second << "\n";
    
    return 0;
}
