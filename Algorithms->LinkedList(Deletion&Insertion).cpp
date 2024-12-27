//Linked List deletiion and insertion.
// To delete the head of the LL
Node * removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
//To remove the tail of the LL
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next !=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
//To delete the kth element of LL.
Node* deleteNode(Node* head,int k){
    if(head==NULL) return NULL;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=1;Node* temp=head;Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
//To delete the any element of LL.
Node* deleteNode(Node* head,int ele){
    if(head==NULL) return NULL;
    if(head->data==ele){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(temp->data==ele){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
//Insert an element before head
Node* beforeHead(Node* head,int val){
    return new Node(val,head);
}
//Insert an element after tail
Node* afterTail(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}
//Insert an element at kth position;
Node* atKthPos(Node* head,int val){
    if(head==NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1) return new Node(val,head);
    Node* temp=head;int cnt=1;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=val;
            break;
        }
        temp=temp->next;
    }
    return head;
}
//Insert an element before any other element;
Node* atKthPos(Node* head,int val,int ele){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val) return new Node(val,head);
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==ele){
            Node* newNode=new Node(val,temp->next);
            temp->next=val;
            break;
        }
        temp=temp->next;
    }
    return head;
}
