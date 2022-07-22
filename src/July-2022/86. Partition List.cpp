class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL) {
            return head;
        }
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ans;
        for(int i=0; i<v.size(); i++){
            if(v[i] < x) {
                ans.push_back(v[i]);
            }
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] >= x) {
                ans.push_back(v[i]);
            }
        }
        ListNode* javab = new ListNode(ans[0]);
        temp = javab;
        for(int i=1;i<ans.size(); i++) {
            ListNode* newnode = new ListNode(ans[i]); 
            temp->next = newnode;
            temp = temp->next;
        }
        return javab;
    }
};
