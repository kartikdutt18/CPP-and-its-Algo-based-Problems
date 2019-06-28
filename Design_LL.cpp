//https://leetcode.com/problems/design-linked-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next, *prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};
class MyLinkedList {
private:
    Node *head, *tail;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void print(){
        Node* ptr = head;
        while(ptr){
            printf("%d->",ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
        
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index + 1 > size || head == NULL || index < 0){
            return -1;
        }
        Node* ptr = head;
       // printf("%d",head->next->next->val);
        for(int i=0 ; i<index; i++){
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        if(head)
            head->prev = temp;
        head = temp;
        if(tail == NULL)
            tail = head;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(tail){
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        else{
            head = temp;
            tail = temp;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<=size){
            Node* temp = new Node(val);
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                if(index == size){
                    Node* ptr = head;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                }
                else{
                    Node* ptr = head;
                    for(int i=0;i<index;i++)
                        ptr = ptr->next;
                    temp->next = ptr;
                    temp->prev = ptr->prev;
                    if(ptr->prev)
                        ptr->prev->next = temp;
                    else
                        head = temp;
                    ptr->prev = temp;
                }
            }
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index+1 <= size && head != NULL && index>-1){
            Node* ptr = head;
            for(int i =0; i<index;i++)
                ptr = ptr->next;
            if(ptr->prev){
                if(ptr->next){
                    printf("dfsdf");
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                else{
                    ptr->prev->next = NULL;
                    tail = ptr->prev;
                }
            }
            else{
                if(ptr->next){
                    ptr->next->prev = NULL;
                    head = ptr->next;
                        
                }
                else{
                    head = NULL;
                    tail = NULL;
                }
            }
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
