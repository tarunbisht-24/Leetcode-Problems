class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

	if(headA == nullptr || headB == nullptr)return nullptr;

	ListNode* pA = headA, *pB = nullptr;
	while(pA != nullptr)
	  {
		pB = headB;           
		while(pB != nullptr)
	  {
		if(pA == pB)return pA;
			pB = pB -> next;             
	  }
		pA = pA -> next;        
	  }

	return nullptr;        
	}
};
