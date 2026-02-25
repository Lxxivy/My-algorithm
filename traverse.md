# 二叉树遍历

---

## 一、基础结构

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
```

---

## 二、三种遍历顺序

| 类型 | 顺序 |
|------|------|
| 前序 | root → left → right |
| 中序 | left → root → right |
| 后序 | left → right → root |

---

## 三、非递归遍历模板

核心思想：  
用栈模拟递归过程。

时间复杂度：O(n)  
空间复杂度：O(h)（h 为树高，最坏 O(n)）

---

### 1. 前序遍历



访问当前节点 → 右入栈 → 左入栈

```cpp
vector<int> preorder(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        res.push_back(node->val);

        if (node->right) st.push(node->right);
        if (node->left)  st.push(node->left);
    }
    return res;
}
```

---

### 2. 中序遍历



一路向左入栈  
出栈访问  
转向右子树

```cpp
vector<int> inorder(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;

    while (cur || !st.empty()) {

        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();

        res.push_back(cur->val);

        cur = cur->right;
    }
    return res;
}
```


---

### 3. 后序遍历（方法一：反转前序法）


前序：root → left → right  
改造：root → right → left  
最后翻转

```cpp
vector<int> postorder(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        res.push_back(node->val);

        if (node->left)  st.push(node->left);
        if (node->right) st.push(node->right);
    }

    reverse(res.begin(), res.end());
    return res;
}
```


---

### 4. 后序遍历（方法二：单栈标准写法）



```cpp
vector<int> postorder(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;

    while (cur || !st.empty()) {

        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();

        if (!cur->right || cur->right == prev) {
            res.push_back(cur->val);
            st.pop();
            prev = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }

    return res;
}
```


---

## 四、记忆方式

前序：
访问 → 右入栈 → 左入栈

中序：
一直向左 → 出栈访问 → 转向右

后序：
改造前序 + 翻转
或
判断右子树是否访问过

---

## 五、复杂度总结

所有遍历：

时间复杂度：O(n)  
空间复杂度：O(h)

---

## 六、递归 vs 非递归

| 方式 | 优点 | 缺点 |
|------|------|------|
| 递归 | 简洁 | 可能爆栈 |
| 非递归 | 稳定 | 代码复杂 |

- n ≤ 1e5 时优先考虑非递归
- 深度可能为 n 时要警惕栈溢出

