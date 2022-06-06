class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		// edge case
		if(headA == nullptr || headB == nullptr)return nullptr;

		// find intersection
		ListNode* pA = headA, *pB = nullptr;
		while(pA != nullptr)
		{
			pB = headB;           // each time pA move to a new position, pB starts from headB again
			while(pB != nullptr)
			{
				if(pA == pB)return pA;
				pB = pB -> next;             
			}
			pA = pA -> next;        
		}

		// not found
		return nullptr;        
	}
};
