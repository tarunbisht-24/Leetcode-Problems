class Solution {
public:
	Node* connect(Node* root) {
        if(!root) return root;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			Node* prev = NULL;
			while (sz--) {
				auto node = q.front(); q.pop();
				if (prev) prev->next = node;
				prev = node;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return root;
	}
};
