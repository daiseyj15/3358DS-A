#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& bst_root,int anInt)
{
    btNode* cursor = bst_root;

	if (bst_root == 0)

	{

		bst_root = new btNode;

		bst_root->data = anInt;

		bst_root->left = bst_root->right = 0;


		return;
	}



	while (cursor != 0)

	{
	    if(anInt == cursor->data)
            return;

	  	 if (anInt < cursor->data)

	 	 {

				if (cursor->left != 0)

					cursor = cursor->left;

				else

				{

					cursor->left = new btNode;

					cursor->left->data = anInt;

					cursor->left->left = cursor->left->right = 0;

					return;

				}

	 	 }

		 else 	//if (anInt > cursor->data)

	  	 {

				if (cursor->right != 0)

					cursor = cursor->right;

				else

				{

					cursor->right = new btNode;

					cursor->right->data = anInt;

					cursor->right->left = cursor->right->right = 0;

					return;

				}

	  	 }

	}

	return;
}

bool bst_remove(btNode*& bst_root,int anInt)
{
    if(bst_root==0) return false;
    if(anInt<bst_root->data)
        bst_remove(bst_root->left, anInt);
    if(anInt>bst_root->data)
        bst_remove(bst_root->right, anInt);
    if(anInt==bst_root->data)
    {
        if(bst_root->left==0 && bst_root->right==0)
        {
            bst_root=0;
        }
        if(bst_root->left==0)
        {
           bst_root=bst_root->right;
        }
        if(bst_root->right=0)
        {
            btNode* old_bst_root = bst_root;
             bst_root = bst_root->left;
              delete old_bst_root;
        }
        if(bst_root->left&&bst_root->right)
        {
             bst_remove_max(bst_root->left, bst_root->data);

        }
    }
    return true;
}

void bst_remove_max(btNode*& bst_root,int& data_removed)
{
    if(bst_root->right==0)
    {
        data_removed=bst_root->data;
        btNode* old_bst_root=bst_root;
        bst_root=bst_root->left;
        delete old_bst_root;
    }
    else
    {
        bst_remove_max(bst_root->right, bst_root->data);
    }

}

