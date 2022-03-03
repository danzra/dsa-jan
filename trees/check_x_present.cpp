#include<bits/stdc++.h>
using namespace std;
template<typename t>
class treeNode{
public:
	t data;
	vector<treeNode<t>*> children;
	treeNode(t data)
	{
		this->data = data;

	}

};

treeNode<int>* input()
{
	int data;
	cin>>data;
	treeNode<int>* root = new treeNode<int>(data);
	queue<treeNode<int>*> q;
	q.push(root);

	while(!q.empty())
	{
		treeNode<int> *front = q.front();
		q.pop();

		int n;
		cin>>n;
		for(int i =0;i<n;i++)
		{
			int data2;
			cin>>data2;
			treeNode<int>* child = new treeNode<int>(data2);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;

}

void print(treeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}

	queue<treeNode<int>*> q;
	q.push(root);

	while(!q.empty())
	{
		treeNode<int>* front = q.front();
		q.pop();
		cout<<front->data<<":";
		for(int i =0;i<front->children.size();i++)
		{
			if(front->children.size()-1 == i)
			{
				cout<<front->children[i]->data;
			}
			else
			{
				cout<<front->children[i]->data<<",";
			}
			q.push(front->children[i]);  
		}
		cout<<endl;
	}
}

int check(treeNode<int>* root , int x)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->data == x)
	{
		return 1;
		//return;
	}
	
	for(int i =0;i<root->children.size();i++)
	{
		return check(root->children[i] , x);
	}
	
}
int main()
{
	treeNode<int>* root= input();
	print(root);
	cout<<endl;
	cout<<check(root,2);
}