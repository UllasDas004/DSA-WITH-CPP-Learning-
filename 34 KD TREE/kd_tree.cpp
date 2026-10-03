/*
 * ============================================================================
 * Approach: Building a K-Dimensional Tree (KD-Tree)
 * ============================================================================
 * 1. Concept: A KD-Tree is a binary search tree that organizes spatial points 
 *    in k-dimensional space by recursively partitioning space along dimensions.
 *
 * 2. Alternating Dimensions: At each level (depth) of the tree, partitioning 
 *    switches to the next dimension using:
 *    current_dimension (cd) = depth % k
 *
 * 3. Divide and Conquer Construction:
 *    - Sort the subarray from index `l` to `r` based on coordinate `cd`.
 *    - Pick the median element at index `mid` to serve as the local root node.
 *      This guarantees that the generated tree is height-balanced (depth ~ O(log N)).
 *    - Recursively build the left subtree from range [l, mid - 1] at (depth + 1).
 *    - Recursively build the right subtree from range [mid + 1, r] at (depth + 1).
 *
 * 4. Time & Space Complexity:
 *    - Construction Time: O(N * log^2 N) using std::sort at each recursive level.
 *    - Space Complexity: O(N) memory allocation for N tree nodes.
 * ============================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Represents a single node in the KD-Tree
class KDNode
{
    public:
    vector<int> vals;   // K-dimensional coordinates of the point
    KDNode* left;       // Pointer to left subtree
    KDNode* right;      // Pointer to right subtree

    // Constructor to initialize a node with a given point
    KDNode(vector<int>& vals)
    {
        this->vals = vals;
        left = right = nullptr;
    }

    // Destructor to recursively free dynamically allocated memory
    ~KDNode()
    {
        vals.clear();
        delete left;    // Triggers recursive destructor call on left child
        delete right;   // Triggers recursive destructor call on right child
    }
};

// Represents the KD-Tree data structure and handles construction
class KDTree
{
    public:
    int k;          // Dimensionality of space (number of coordinates per point)
    int n;          // Total number of points
    KDNode* root;   // Pointer to root node of the tree
    vector<vector<int>> v;  // Copy of original point dataset used for tree construction

    // Recursive helper function to build a balanced KD-Tree
    KDNode* buildTree(int l,int r,int depth)
    {
        // Base Case 1: Invalid range, subtree is empty
        if(l > r) return nullptr;

        // Base Case 2: Single element left in current range
        if(l == r)
        {
            KDNode* newNode = new KDNode(v[l]);
            return newNode;
        }

        // Determine current splitting dimension (cycles 0 -> 1 -> ... -> k-1 -> 0)
        int cd = depth % k;

        // Sort elements in range [l, r] based on current dimension `cd`
        // Note: r + 1 is used because std::sort uses half-open intervals [first, last)
        sort(v.begin() + l, v.begin() + r + 1, 
            [cd](const vector<int>& a, const vector<int>& b)
            {
                return a[cd] < b[cd];
            }
        );

        // Find median index to ensure optimal height balance
        int mid = l + (r - l) / 2;

        // Create current root node using the median element
        KDNode* curr = new KDNode(v[mid]);

        // Recursively construct left and right subtrees with incremented depth
        curr->left = buildTree(l,mid-1,depth+1);
        curr->right = buildTree(mid+1,r,depth+1);

        return curr;
    }
    
    // Main constructor to build tree from an array of k-dimensional points
    KDTree(vector<vector<int>>& v)
    {
        // Validation: Check for empty input array or invalid dimension size
        if(v.size() == 0 || v[0].size() == 0)
        {
            cerr<<"Empty array is not allowed"<<endl;
            exit(1);
        }

        this->v = v;
        n = v.size();
        k = v[0].size();
        root = buildTree(0,n-1,0);
    }
};

// Add this helper function above your main() to visualize the tree structure.
// It uses pre-order traversal and indents based on depth.
void printTree(KDNode* node, int depth, int k) 
{
    if (node == nullptr) return;

    // Create indentation for visual hierarchy
    for (int i = 0; i < depth; ++i) {
        cout << "    ";
    }
    
    // Print current node and the dimension it splits by
    cout << "|-- (";
    for (int i = 0; i < k; ++i) {
        cout << node->vals[i] << (i == k - 1 ? "" : ", ");
    }
    cout << ")  [Splits on dim " << (depth % k) << "]" << endl;

    // Recursively print left and right children
    printTree(node->left, depth + 1, k);
    printTree(node->right, depth + 1, k);
}

int main() 
{
    /*
    ==========================================
    TEST CASE (Copy and paste this into terminal)
    ==========================================
    6 2
    2 3
    5 4
    9 6
    4 7
    8 1
    7 2
    ==========================================
     */

    int n, k;
    cout << "=== KD-Tree Builder ===" << endl;
    cout << "Enter the number of points (N) and dimensions (K): ";
    if (!(cin >> n >> k)) return 0;

    vector<vector<int>> points(n, vector<int>(k));

    cout << "Enter the " << n << " points (" << k << " space-separated integers per line):" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < k; ++j) 
        {
            cin >> points[i][j];
        }
    }

    cout << "\nBuilding KD-Tree..." << endl;
    KDTree tree(points);
    cout << "KD-Tree built successfully!\n" << endl;

    cout << "Tree Structure (Pre-order Traversal):" << endl;
    cout << "-------------------------------------" << endl;
    printTree(tree.root, 0, tree.k);
    cout << "-------------------------------------" << endl;

    return 0;
}