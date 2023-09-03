class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *r1,Node *r2){
        if(!r1 and !r2)             return true;
        else if(!r1 or !r2)         return false;
        if(r1->data != r2->data)    return false;
        
        if(isIsomorphic(r1->left, r2->left) == false)
            if(isIsomorphic(r1->left, r2->right) == false)
                return false;
                    
        if(isIsomorphic(r1->right, r2->left) == false)
            if(isIsomorphic(r1->right, r2->right) == false)
                return false;
        
        return true;
    }
};