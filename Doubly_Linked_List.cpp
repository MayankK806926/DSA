#include<bits/stdc++.h>
using namespace std;

//Doubly-Linked List
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
        back=NULL;
    }
};

Node* convertArrToDLL(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<n;++i){
        Node* tmp=new Node(arr[i],NULL,prev);
        prev->next=tmp;
        prev=tmp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL) {
        delete head;
        return NULL;
    }    
    Node* temp=head;
    head=head->next;
    head->back=NULL;
    temp->next=NULL;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    Node* tail=temp->next;
    temp->next=NULL;
    tail->back=NULL;
    delete tail;
    return head;
}

Node* deleteElement(Node* head,int ele){
    if(head==nullptr) return head;
    if(head->data==ele) return deleteHead(head);
    Node* temp=head;
    while(temp){
        if(temp->data==ele) break;
        temp=temp->next;
    }
    if(!temp) return head;
    if(temp->next==NULL) return deleteTail(head);
    Node* prev=temp->back;
    prev->next=temp->next;
    temp->next->back=prev;
    temp->next=NULL;temp->back=NULL;
    delete temp;
    return head;
}

Node* deleteKthElement(Node* head,int k){
    if(head==nullptr || k<=0) return head;
    if(k==1) return deleteHead(head);
    Node* temp=head;
    for(int i = 1; i < k && temp; ++i) temp = temp->next;
    if(temp==NULL) return head;
    if(temp->next==NULL) return deleteTail(head);
    Node* prev=temp->back;
    prev->next=temp->next;
    temp->next->back=prev;
    temp->next=NULL;temp->back=NULL;
    delete temp;
    return head;
}

Node* insertbeforeHead(Node* head,int ele){
    if(head==NULL){
        Node* newHead=new Node(ele);
        return newHead;
    }

    Node* newHead=new Node(ele);
    newHead->next=head;
    head->back=newHead;
    return newHead;
}

Node* insertbeforeTail(Node* head,int ele){
    if(head==NULL){
        Node* newHead=new Node(ele);
        return newHead;
    }
    if(head->next == NULL) return insertbeforeHead(head, ele);
    Node* temp=head;
    while(temp->next->next) temp=temp->next;
    Node* x=new Node(ele,temp->next,temp);
    temp->next->back=x;
    temp->next=x;
    return head;
}

Node* insertbeforeNode(Node* head,int ele,int x){
    Node* temp=head;
    while(temp && temp->next){
        if(temp->next->data==x) break;
        temp=temp->next;
    }
    if(temp==NULL) return head;
    Node* a=new Node(ele,temp->next,temp);
    temp->next->back=a;
    temp->next=a;
    return head;
}

Node* insertbeforeKthNode(Node* head,int ele,int k){
    Node* temp=head;
    if(k <= 1) return insertbeforeHead(head, ele);
    for(int i = 1; i < k-1 && temp; ++i) temp = temp->next;
    if(temp==NULL) return head;
    Node* a=new Node(ele,temp->next,temp);
    temp->next->back=a;
    temp->next=a;
    return head;
}

void printDLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    Node* head=convertArrToDLL(arr,n);
    printDLL(head);
    head=deleteHead(head);
    printDLL(head);
    head=deleteTail(head);
    printDLL(head);
    head=deleteElement(head,5);
    printDLL(head);
    head=deleteKthElement(head,5);
    printDLL(head);
    head=insertbeforeHead(head,7);
    printDLL(head);
    head=insertbeforeTail(head,7);
    printDLL(head);
    head=insertbeforeNode(head,7,4);
    printDLL(head);
    head=insertbeforeKthNode(head,7,3);
    printDLL(head);
    return 0;
}
