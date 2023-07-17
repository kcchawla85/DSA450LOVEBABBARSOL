/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
#include <bits/stdc++.h>

Node *addTwoNumbers(Node *num1, Node *num2)

{

    Node* ans=NULL, *p1 = num1, *p2=num2, *ansPointer=NULL;

    int carry = 0;

    while(p1 || p2 || carry!=0){

        int sum = (p1?p1->data:0) + (p2?p2->data:0) + carry;

        carry = sum/10;

        sum %= 10;

        Node* newNode = new Node(sum);

        if(ans==NULL){

            ans = newNode;

            ansPointer = newNode;

        }else{

            ansPointer->next= newNode;

            ansPointer = newNode;

        }

        p1 = p1?p1->next:p1;

        p2 = p2?p2->next:p2;

    }

    return ans;

}
