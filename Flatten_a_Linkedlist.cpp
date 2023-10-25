Node* join(Node* a, Node* b)
{
    Node* tail = NULL;
    
    if(a->data<b->data)
    {
        tail = a;
        a = a->bottom;
    }
    else
    {
        tail = b;
        b = b->bottom;
    }
    Node* ret = tail;
    
    while(a && b)
    {
        if(a->data<b->data)
        {
            tail->bottom = a;
            tail = tail->bottom;
            a = a->bottom;
        }
        
        else
        {
            tail->bottom = b;
            tail = tail->bottom;
            b = b->bottom;
        }
    }
    
    if(a)
    {
        tail->bottom = a;
    }
    if(b)
    {
        tail->bottom = b;
    }
    
    return ret;
    
}
Node *flatten(Node *root)
{
    if(root->next == NULL)
    {
        return root;
    }
    
    Node* aage = flatten(root->next);
    
    Node* joined = join(root,aage);
    
    return joined;
    
    
   // Your code here
}
