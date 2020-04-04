/*

04/APR/2020
O. Hakan YARAN

Sophomore assignment, partialy coded by me (indicated by comments)



Assignment:

Add the following methods:

find1 method that takes one int parameter and returns a pointer to the node containing the parameter value if such a node exists, and null pointer if such a node is not in the tree. This method will not use recursion.

find2 method that functions the same as find1, but uses a recursive implementation. There will be two methods, a public find1 that takes one int param, and a recursive helper method that takes two parameters, one the int to find, the other a pointer to the root of the subtree to search in.

node_count method that takes no parameters and returns the number of nodes in the tree. Implement this using a recursive helper method.

node_sum method that takes no parameters and returns the sum of the nodes in the tree. Implement this using a recursive helper method.

*/



#include <iostream>

using namespace std;


//=====================================================================
struct Node {
    int x;

// pointer variables of "Node" datatype: left & right
    Node * left;
    Node * right;
};


//=====================================================================
class Tree 
{
	
	// root Node

    Node * root;
    public:
        Tree() 
        {
            root = NULL;
        }
        
    //-----------------------------------------------------------------

	/* 
		insertion method creates new Node inserts x into the new node
		and assigns left and right pointers to NULL
	*/
    void insert(int x) 
    {
        Node * ptr = new Node;

        ptr -> x = x;
        ptr -> left = NULL;
        ptr -> right = NULL;

        cout << "\n-------------------------------------" << endl;
        cout << "Node Address: " << ptr << endl;

	/*
		check if there is a root, it there is no root then the new node is the root
	*/
        if (root == NULL)
            root = ptr;
        else 
        {
            Node * temp = root;

            while (true) 
            {
            	
            	/*
            		if statement to decide whether it is a left node (smaller) or a right node (greater)
            	*/
            	
                if (temp -> x > x) 
                {
                    if (temp -> left == NULL) {
                        cout << "Node Parent Address: " << temp << endl;
                        cout << "Node Parent Value: " << temp -> x << endl;
                        temp -> left = ptr;
                        break;
                    } else
                        temp = temp -> left;
                } else 
                {
                    if (temp -> right == NULL) 
                    {
                        cout << "Node Parent Address: " << temp << endl;
                        cout << "Node Parent Value: " << temp -> x << endl;
                        temp -> right = ptr;
                        break;
                    } else
                        temp = temp -> right;
                }
            }
        }

        cout << "Root: " << root << endl;
        cout << "-------------------------------------" << endl;
    }
       
	//=====================================================================
	/*
		traversal methods
	*/ 
    //-----------------------------------------------------------------
    
    public: void inOrder(){ inOrder(root); }
    private: void inOrder(Node * temp) {
        if (temp != NULL) 
        {
            inOrder(temp -> left);
            cout << temp -> x << " ";
            inOrder(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    public: void preOrder(){ inOrder(root); }
    private: void preOrder(Node * temp) 
    {
        if (temp != NULL) {
            cout << temp -> x << " ";
            preOrder(temp -> left);
            preOrder(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    public: void postOrder(){ inOrder(root); }
    private: void postOrder(Node * temp) 
    {
        if (temp != NULL) {
            postOrder(temp -> left);
            postOrder(temp -> right);
            cout << temp -> x << " ";
        }
    }
    
    //=====================================================================
    
    
        
    //-----------------------------------------------------------------
    public: Node * getRoot() {
        return root;
    }
        
    //-----------------------------------------------------------------
    public: void display(){ display(root); }
    private: void display(Node * temp) 
    {
        if (temp != NULL) {
            cout << endl;
            cout << "Parent: " << temp -> x << endl;
            cout << " Left Child of " << temp -> x << ": ";
            if (temp -> left == NULL)
                cout << "NULL" << endl;
            else
                cout << temp -> left -> x << endl;

            cout << " Right Child of " << temp -> x << ": ";
            if (temp -> right == NULL)
                cout << "NULL" << endl;
            else
                cout << temp -> right -> x << endl;
            display(temp -> left);
            display(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    bool isEmpty() 
    {
        if (root == NULL)
            return true;

        return false;
    }
    
    public:     
    //-----------------------------------------------------------------
    void removeAll(int value) 
    {
        while (true) 
        {
            Node * temp = root, * ptemp = root;

            while (temp != NULL && temp -> x != value) 
            {
                ptemp = temp;
                if (temp -> x < value)
                    temp = temp -> right;
                else if (temp -> x > value)
                    temp = temp -> left;
            }

            if (temp == NULL) 
            {
                cout << "All nodes cotaining " << value << " are deleted" << endl;
                break;
            } else 
            {
                if (temp -> left == NULL && temp -> right == NULL) 
                {
                    if (temp == root)
                        root = NULL;
                    else if (ptemp -> left == temp)
                        ptemp -> left = NULL;
                    else if (ptemp -> right == temp)
                        ptemp -> right = NULL;
                } else if (temp -> left == NULL && temp -> right != NULL) 
                {
                    if (temp == root)
                        root = temp -> right;
                    else if (ptemp -> left == temp)
                        ptemp -> left = temp -> right;
                    else if (ptemp -> right == temp)
                        ptemp -> right = temp -> left;
                } else if (temp -> right == NULL && temp -> left != NULL) 
                {
                    if (temp == root)
                        root = temp -> left;
                    else if (ptemp -> left == temp)
                        ptemp -> left = temp -> left;
                    else if (ptemp -> right == temp)
                        ptemp -> right = temp -> right;
                } else if (temp -> left != NULL && temp -> right != NULL) 
                {
                    Node * tempHolder = temp, * ptempHolder = temp;

                    while (tempHolder -> left != NULL) 
                    {
                        ptempHolder = tempHolder;
                        tempHolder = tempHolder -> left;
                    }

                    temp -> x = tempHolder -> x;
                    ptempHolder -> left = tempHolder -> right;

                    temp = tempHolder;
                }

                delete temp;
                cout << "Node Removed Successfully." << endl;
            }
        }
    }
        
    //-----------------------------------------------------------------
    void remove(int value) 
    {
        Node * temp = root, * ptemp = root;

        while (temp != NULL && temp -> x != value) 
        {
            ptemp = temp;
            if (temp -> x < value)
                temp = temp -> right;
            else if (temp -> x > value)
                temp = temp -> left;
        }

        if (temp == NULL) {
            cout << "Value Not Found...." << endl;
        } else 
        {
            if (temp -> left == NULL && temp -> right == NULL) 
            {
                if (temp == root)
                    root = NULL;
                else if (ptemp -> left == temp)
                    ptemp -> left = NULL;
                else if (ptemp -> right == temp)
                    ptemp -> right = NULL;
            } else if (temp -> left == NULL && temp -> right != NULL) 
            {
                if (temp == root)
                    root = temp -> right;
                else if (ptemp -> left == temp)
                    ptemp -> left = temp -> right;
                else if (ptemp -> right == temp)
                    ptemp -> right = temp -> left;
            } else if (temp -> right == NULL && temp -> left != NULL) 
            {
                if (temp == root)
                    root = temp -> left;
                else if (ptemp -> left == temp)
                    ptemp -> left = temp -> left;
                else if (ptemp -> right == temp)
                    ptemp -> right = temp -> right;
            } else if (temp -> left != NULL && temp -> right != NULL) 
            {
                Node * tempHolder = temp, * ptempHolder = temp;

                while (tempHolder -> left != NULL) 
                {
                    ptempHolder = tempHolder;
                    tempHolder = tempHolder -> left;
                }

                temp -> x = tempHolder -> x;
                ptempHolder -> left = tempHolder -> right;

                temp = tempHolder;
            }

            delete temp;
            cout << "Node Removed Successfully." << endl;
        }
    }
        
    //-----------------------------------------------------------------
    void deleteAllNodes(Node * temp) {
        if (temp != NULL) {
            deleteAllNodes(temp -> left);
            deleteAllNodes(temp -> right);
            cout << "Address: " << temp << endl;
            cout << "Value: " << temp -> x << endl << endl;
            delete temp;
        }
    }
        
    //-----------------------------------------------------------------
    



	//=====================================================================
		
	//	Assignment starts here
		
	//=====================================================================
    
    
    // This method counts the number of the nodes inserted to an object
    
    public:
    	
    	int node_count()
    	{
    		
    		return node_count(root);
    		
		}
		
	private:
		
		// helper method
		
		int node_count(Node *temp)
		{
			if(temp == NULL) return 0;
			
			return 1 + node_count(temp->left) + node_count(temp->right);
		}
		
		

	//-----------------------------------------------------------------	
	
	
	// This method sums values of all nodes in an object
	
	public:
		
		int node_sum()
		{
			return node_sum(root);
		}
	
	private:
		
		// helper method
		
		int node_sum(Node *temp)
		{
			if(temp == NULL) return 0;
			
			return temp->x + node_sum(temp->left) + node_sum(temp->right);
		}
	
		
	//-----------------------------------------------------------------	
		
	// This method finds given value and returns the adress of the node (iterated version)
	
	public:
		
		Node *find1(int key)
		{
			Node *temp = root;
			
			while(temp != NULL)
			{
				if(key == temp->x)
					return temp;
				
				if(key < temp->x)
					temp = temp -> left;
					
				else
					temp = temp -> right;
			}
			return temp;
		}
		
		
		//-----------------------------------------------------------------	
		
		
		// This method finds given value and returns the adress of the node (recursive version)
		
		public:
		Node* find2(int x) 
		{	
    		return find2(x, root);
		}
		
		
		// find2 helper method
		
		private:	
		Node* find2(int x, Node *key) 
		{
    	
			if(key == NULL) 
			{
        
			return key;
    	
			}
		    if(key->x == x) {
		        return key;
		    } else if(key->x < x) {
		        return find2(x, key->right);
		    } else {
		        return find2(x, key->left);
		    }
		}
		
		
		
	//=====================================================================
		
	//	Assignment ends here
		
	//=====================================================================
		
    public:
    ~Tree() {
        cout << "Below Nodes Deleted Successfully:" << endl;
        deleteAllNodes(root);
    }
};


//=====================================================================

int main(){
    Tree T;
    
    T.insert(50);
    T.insert(20);
    T.insert(80);
    T.insert(60);
    T.insert(90);
    
    T.display();
    
    
    // Parts written by me to show my methods are working
    
    cout << "\n\n==================\nNode Count: " << T.node_count() << endl;
    cout << "Node sum: " << T.node_sum() << endl;
    cout << "find1 output: " << T.find1(50) << endl;
    cout << "find2 output: " << T.find2(50) << endl;
    cout << "\nEnd of the work...\n" << endl;
    
    system("pause");
	return 0;
}


