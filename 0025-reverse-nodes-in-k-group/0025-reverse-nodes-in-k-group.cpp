class Solution {
public:

ListNode* reverse_node(ListNode* head, int k, int len)
{
// check the condition if length is less than k return head. 
    if(len < k)
    {
        return head;
    }
	// take count variable to reverse the linked list till size k and break the loop when the count reaches size == k
    int count = 0;
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
	// simple code to reverse linked list.
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
	//  here we will call recursion with (length- k) size and assign value to head next (here head is   the last node of reverse list) and connect the linked list. 
    head->next = reverse_node(next,k,len-k);
	// return prev which is actual  head of the linked list.
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
   // first we will count the size of linked list. 
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
	// again assigning the value of head to temparory list.
    temp = head;
	// call the function (reverse_node) with linked list, length of linked list and size k. 
   return reverse_node(temp,k,len);
    
}
};