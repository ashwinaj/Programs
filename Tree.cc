#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<list>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

class Tree
{
public:

    Tree() { root = NULL;}
    virtual ~Tree()
    {
        removeTree(root);
    }

    int insertNode(int aInData);
    int deleteNode(int aInData);
    void printInOrder(struct node* aInRoot);
    void printIterativeInOrder();
    void printPreOrder(struct node* aInRoot);
    void printPostOrder();
    void removeTree(struct node* aInNode);
    struct node* findSuccessor(int aInData);
    struct node* findPath(struct node* aInNode1, struct node* aInNode2);
    struct node * getRoot() { return root;}
    struct node* findNode(struct node* aInNode, int aInData);
    struct node* getNode(int aInData);
    void treeToList();
    struct node* treeToListUtility(struct node* aInNode);
    struct node* treeToListAppend(struct node* aInNode1, struct node* aInNode2);
    void PrintList(struct node* aInNode);
    void findMaxPath();
    bool printMaxPath(struct node* node, struct node* aInTarget);
    void findMaxPathHelper(struct node* aInNode, int aInCurrentSum, int& aInMaxSum,
                           struct node*& aInOutTargetNode);
private:
    struct node* root;
    struct node* addNode(struct node* aInNode, int aInData);
    struct node* deleteNodeHelper(struct node* aInNode, int aInData);
    struct node* newNode(int aInData);
    struct node* minNode(struct node* aInNode);
    //struct node* findNode(struct node* aInNode, int aInData);
    struct node* getParent(struct node* aInNode);
};

bool Tree::printMaxPath(struct node* node, struct node* aInTarget)
{
    if (node == NULL)
        return false;

    if (node == aInTarget || printMaxPath(node->left, aInTarget)
            || printMaxPath(node->right, aInTarget)) {
        cout<<node->data<<" ";
        return true;
    }

    return false;
}

void Tree::findMaxPath()
{
    int currentSum =0;
    int maxSum = 0;
    struct node* targetNode = NULL;

    findMaxPathHelper(root, currentSum, maxSum, targetNode);
    cout<<endl<<"Max: "<<maxSum<<endl;
    printMaxPath(root, targetNode);
}

void Tree::findMaxPathHelper(struct node* aInNode, int aInCurrentSum,
                             int& aInMaxSum, struct node*& aInOutTargetNode)
{
    if (aInNode ==  NULL)
        return;

    aInCurrentSum += aInNode->data;

    if (aInNode->left == NULL && aInNode->right == NULL) {
        if (aInCurrentSum > aInMaxSum)
            aInMaxSum = aInCurrentSum;

        aInOutTargetNode = aInNode;

        return;
    }

    if (aInCurrentSum > aInMaxSum) {
        aInMaxSum = aInCurrentSum;
    }

    findMaxPathHelper(aInNode->left, aInCurrentSum, aInMaxSum, aInOutTargetNode);
    findMaxPathHelper(aInNode->right, aInCurrentSum, aInMaxSum, aInOutTargetNode);


}

struct node* Tree::treeToListUtility(struct node* aInNode)
{
    if (aInNode == NULL) {
        return NULL;
    }

    struct node* list1 = treeToListUtility(aInNode->left);
    struct node* list2 = treeToListUtility(aInNode->right);
    aInNode->left = aInNode;
    aInNode->right = aInNode;
    list1 = treeToListAppend(list1, aInNode);
    list1 = treeToListAppend(list1, list2);

    return list1;
}

struct node* Tree::treeToListAppend(struct node* a, struct node* b)
{

    if (a==NULL) {
        return b;
    }

    if (b==NULL) {
        return a;
    }

    struct node *aLeft=a->left;
    struct node *bLeft=b->left;
    aLeft->right=b;
    b->left=aLeft;
    a->left=bLeft;
    bLeft->right=a;
    return a;
}


void Tree::treeToList()
{
    struct node* tmp = treeToListUtility(root);
    struct node* tmpLeft = tmp->left;
    tmp->left->right = NULL;

    PrintList(tmp);
}


void Tree::PrintList(struct node* aInNode)
{
    cout<<endl<<"List is: ";
    while (aInNode) {
        cout<<aInNode->data<<endl;
        aInNode = aInNode->right;
    }
}


struct node* Tree::getParent(struct node* aInNode)
{
    struct node* temp = root;
    if (!aInNode) {
        return NULL;
    }

    while (temp) {
        if (temp->right == aInNode || temp->left == aInNode) {
            return temp;
        } else if (temp->data > aInNode->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
}

struct node* Tree::findPath(struct node* aInNode1, struct node* aInNode2)
{
    // Find the depth of the nodes
    int depth1 = 0;
    int depth2 = 0;
    stack<struct node*> st;
    list<struct node*> l;
    struct node* temp = root;
    struct node* node1 = NULL;
    struct node* node2 = NULL;

    while (temp) {
        if (temp->data > aInNode1->data) {
            temp = temp->left;
        } else if (temp->data < aInNode1->data) {
            temp = temp->right;
        } else {
            //depth1++;
            break;
        }

        depth1++;
    }

    temp = root;
    while (temp) {
        if (temp->data > aInNode2->data) {
            temp = temp->left;
        } else if (temp->data < aInNode2->data) {
            temp = temp->right;
        } else {
            //depth2++;
            break;
        }

        depth2++;
    }

    node1 = aInNode1;
    node2 = aInNode2;

    if (depth1 < depth2) {
        // Move aInNode2 up to the level of aInNode1
        struct node* temp = aInNode2;
        while (depth2 != depth1) {
            st.push(temp);
            temp =getParent(temp);
            node2 = temp;
            depth2--;
        }

        //node2 = temp;
    } else {
        struct node* temp = aInNode1;
        while (depth1 != depth2) {
            l.push_back(temp);
            temp = getParent(temp);
            node1 = temp;
            depth1--;
        }

        //node1 = temp;
    }

    if (!node1) {
        node1 = getRoot();
    }

    if (!node2) {
        node2 = getRoot();
    }

    // Move node1 and node2 simultaneously until they meet
    while (node1 != node2) {
        if (node1 != getRoot()) {
            if (node1 != NULL) {
                l.push_back(node1);
            } else {
                node1 = getRoot();
            }
            node1 = getParent(node1);
            if (node1 == getRoot()) {
                l.push_back(node1);
            }
        }

        if (node2 != getRoot()) {
            if (node2 != NULL) {
                st.push(node2);
            } else {
                node2 = getRoot();
            }

            node2 = getParent(node2);
        }

    }

    // Add the nodes from the stack to the back of the queue
    while (!st.empty()) {
        struct node* stackNode = st.top();
        l.push_back(st.top());
        st.pop();
    }

    cout<<endl<<"Length of the path: "<<l.size();
    cout<<endl<<"Path: "<<endl;
    list<struct node*>::iterator it = l.begin();

    while (it != l.end()) {
        struct node* temp = *it;
        cout<<temp->data<<"  "<<endl;
        it++;
    }
}

void Tree::printIterativeInOrder()
{
    stack<struct node*> st;
    bool done = false;
    struct node* temp = root;

    if (root == NULL) {
        return;
    }

    while (!st.empty() || temp) {
        if (temp) {
            st.push(temp);
            temp = temp->left;
        } else {
            temp = st.top();
            st.pop();
            cout<<endl<<temp->data;
            temp = temp->right;
        }
    }

    cout<<endl;

    return;
}

struct node* Tree::deleteNodeHelper(struct node* aInNode, int aInData)
{
    if (aInNode == NULL) {
        return NULL;
    }

    if (aInData < aInNode->data) {
        aInNode->left = deleteNodeHelper(aInNode->left, aInData);
    } else if (aInData > aInNode->data) {
        aInNode->right = deleteNodeHelper(aInNode->right, aInData);
    }

    if (aInNode->data == aInData) {
        struct node* temp;
        if (aInNode->left == NULL) {
            temp = aInNode->right;
            delete(aInNode);
            return temp;
        } else if (aInNode->right == NULL) {
            temp = aInNode->left;
            delete(aInNode);
            return temp;
        } else {
            struct node* successor = findSuccessor(aInNode->left->data);
            aInNode->data = successor->data;
            aInNode->left = deleteNodeHelper(aInNode->left, aInNode->data);
        }
    }
}

int Tree::deleteNode(int aInData)
{
    if (root == NULL) {
        cout<<"Root is NULL"<<endl;
        return -1;
    }
    deleteNodeHelper(root, aInData);

    return 0;
}

struct node* Tree::getNode(int aInData)
{
    struct node* temp = getRoot();

    while (temp) {
        if (temp->data < aInData) {
            temp = temp->right;
        } else if (temp->data > aInData) {
            temp = temp->left;
        } else {
            return temp;
        }
    }

    return NULL;
}

struct node* Tree::findNode(struct node* aInNode, int aInData)
{
    if (aInNode == NULL) {
        cout<<"Node not found"<<endl;

        return NULL;
    }

    if (aInNode->data < aInData) {
        return findNode(aInNode->left, aInData);
    } else if (aInNode->data > aInData) {
        return findNode(aInNode->right, aInData);
    } else {
        return aInNode;
    }
}

struct node* Tree::minNode(struct node* aInNode)
{
    // Go to the rightmost node
    while (aInNode->left) {
        aInNode = aInNode->left;
    }

    return aInNode;
}

struct node* Tree::findSuccessor(int aInData)
{
    struct node* node = findNode(getRoot(), aInData);
    if (node == NULL || root == NULL) {
        cout<<"No successor exists"<<endl;
        return NULL;
    }

    if (node->right != NULL) {
        return minNode(node->right);
    }

    struct node* temp = root;
    struct node* succ = root;

    while (temp) {
        if (temp->data < aInData) {
            temp = temp->right;
        } else if (temp->data > aInData) {
            succ = temp;
            temp = temp->left;
        } else
            break;
    }

    return succ;
}


struct node* Tree::addNode(struct node* aInNode, int aInData)
{
    if (aInNode == NULL) {
        aInNode = newNode(aInData);
        if (aInNode == NULL) {
            cout<<"Cannot allocate memeory";

            return NULL;
        }
    } else {
        if (aInNode->data >= aInData) {
            aInNode->left = addNode(aInNode->left, aInData);
        } else {
            aInNode->right = addNode(aInNode->right, aInData);
        }

        return aInNode;
    }
}

struct node* Tree::newNode(int aInData)
{
    struct node* temp;
    temp = new node;
    if (temp == NULL) {
        cout<<"Cannot allocate memeory";

        return NULL;
    }

    temp->data = aInData;
    temp->left = temp->right = NULL;

}

int Tree::insertNode(int aInData)
{
    root = addNode(root, aInData);

    if (root == NULL) {
        return -1;
    }

    return 0;
}

void Tree::printInOrder(struct node* aInNode)
{
    if (aInNode == NULL) {
        return;
    }

    printInOrder(aInNode->left);
    cout<<aInNode->data<<endl;
    printInOrder(aInNode->right);

    return;


}

void Tree::printPreOrder(struct node* aInNode)
{
    if (aInNode == NULL) {
        return;
    }

    cout<<aInNode->data<<endl;
    printPreOrder(aInNode->left);
    printPreOrder(aInNode->right);

    return;


}

void Tree::printPostOrder()
{
    if (root == NULL) {
        return;
    }

    stack<struct node*> s1, s2;

    s1.push(root);

    while (!s1.empty()) {
        struct node* temp = s1.top();
        s1.pop();

        s2.push(temp);
        if (temp->left) {
            s1.push(temp->left);
        }

        if (temp->right) {
            s1.push(temp->right);
        }
    }

    while (!s2.empty()) {
        struct node* temp = s2.top();
        cout<<temp->data<<endl;
        s2.pop();
    }
}

void Tree::removeTree(struct node* aInNode)
{
    if (aInNode == NULL)
        return;

    removeTree(aInNode->right);
    removeTree(aInNode->left);
    delete(aInNode);
    return;
}


int main()
{
    Tree t;

    t.insertNode(5);
    t.insertNode(3);
    t.insertNode(15);
    t.insertNode(20);
    t.insertNode(8);
    t.insertNode(13);
    t.insertNode(6);

    cout<<"Inorder: "<<endl;
    t.printInOrder(t.getRoot());
    cout<<"Iterative Inorder:"<<endl;
    t.printIterativeInOrder();

    //cout<<"Preorder: "<<endl;
    //t.printPreOrder(t.getRoot());

    //struct node* temp = t.findSuccessor(5);
    //cout<<"successor: "<<temp->data<<endl;
    //cout<<endl<<endl;
    //t.printPostOrder();
    //t.findPath(t.getNode(3), t.getNode(20));

    //t.treeToList();
    t.findMaxPath();

    return 0;
}
