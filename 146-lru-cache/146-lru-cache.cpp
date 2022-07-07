class Node
{
    
    public:
    int key;
    int val; 
    Node* front; 
    Node* back;
        Node()
        {
            front=NULL;
            back=NULL;
        }
        Node(int v1, int v2)
        {
                key=v1;
                val=v2;
                front=NULL;
                back=NULL;
        }
};





class LRUCache {
    Node* dll;
    Node* taildll;
    int len;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        len=capacity;
        dll=NULL;
        taildll=NULL;
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        else
        {
            Node* temp=mp[key];
            if(dll==temp) return temp->val;
            
            if(temp->front==NULL) 
            {    
                temp->back->front=NULL;
                taildll=temp->back;
                temp->front=dll;
                temp->back=NULL;
                dll=temp;
                temp->front->back=temp;
               
            }
            else
            {
                temp->front->back=temp->back;
                temp->back->front=temp->front;
                temp->front=dll;
                temp->back=NULL;
                dll=temp;
                temp->front->back=temp;
            }
             return temp->val;
        }
    }
    
    void put(int key, int value) {
         if(!mp.count(key)) 
             {      if(len==1 and dll!=NULL) {if(mp.count(dll->key)) mp.erase(dll->key); dll=new Node(key, value); taildll=dll;}
                    if(mp.size()==len)
                    {
                        taildll->back->front=NULL;
                        mp.erase(taildll->key);
                        taildll=taildll->back;
                    }
                    Node* temp=new Node(key, value);
                    mp[key]=temp;
                    temp->front=dll;
                    dll=temp;
                    if(temp->front!=NULL)
                        temp->front->back=temp;
                   if(mp.size()==1) taildll=dll;
             }
        else
        {
            Node* temp=mp[key];
            temp->val=value;
            get(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */