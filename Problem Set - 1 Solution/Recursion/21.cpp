    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        if(!A) return B;
        if(!B) return A;
        ListNode *Ans;
        if(A->val > B->val){
            B->next = mergeTwoLists(A,B->next);
            Ans = B;
        }
        else{
            A->next = mergeTwoLists(A->next,B);
            Ans = A;
        }
        return Ans;
    }
