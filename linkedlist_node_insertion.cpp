void oper (Node** head_ref, int new_data) 
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) 
        last = last->next;

    last->next = new_node;
    return;
}
