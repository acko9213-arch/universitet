#include <iostream>
#include <iomanip>
using namespace std;
struct Tree {
    int key;
    char text[5];
    Tree* Left, * Right;
};
Tree* createEl(Tree*, char t[5], int key)
{
    Tree* now = new Tree;
    now->key = key;
    for (int i = 0; i < 5; i++)
        now->text[i] = t[i];
    now->Left = now->Right = nullptr;
    return now;
}
Tree* insert(Tree* Root, char t[5], int key)
{
    if (key < 0) exit(1);
    if (Root == nullptr) {
        Root = new Tree;
        Root->key = key;
        for (int i = 0; i < 5; i++)
            Root->text[i] = t[i];
        Root->Left = Root->Right = nullptr;
        return Root;
    }
    Tree* prev = nullptr;
    Tree* cur = Root;
    while (cur) {
        prev = cur;
        if (key == cur->key) return Root;
        else if (key < cur->key) cur = cur->Left;
        else cur = cur->Right;
    }
    Tree* node = createEl(nullptr, t, key);
    if (key < prev->key) prev->Left = node;
    else prev->Right = node;
    return Root;
}
Tree* deleteNode(Tree* root, int key)
{
    if (!root) return nullptr;
    if (key < root->key)
        root->Left = deleteNode(root->Left, key);
    else if (key > root->key)
        root->Right = deleteNode(root->Right, key);
    else {
        if (!root->Left) {
            Tree* temp = root->Right;
            delete root;
            return temp;
        }
        else if (!root->Right) {
            Tree* temp = root->Left;
            delete root;
            return temp;
        }
        Tree* temp = root->Right;
        while (temp->Left) temp = temp->Left;
        root->key = temp->key;
        for (int i = 0; i < 5; i++)
            root->text[i] = temp->text[i];
        root->Right = deleteNode(root->Right, temp->key);
    }
    return root;
}
int view(Tree* t, int level)
{
    if (t) {
        view(t->Right, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << t->key << " ";
        puts(t->text);
        view(t->Left, level + 1);
    }
    return 0;
}
int poisk(Tree* root, int level)
{
    if (!root) return 0;
    if (level == 0) return 1;
    return poisk(root->Left, level - 1) + poisk(root->Right, level - 1);
}
int getKey(Tree* root, int level, int pos, int* counter)
{
    if (!root) return -1;
    if (level == 0) {
        if (*counter == pos) return root->key;
        (*counter)++;
        return -1;
    }
    int found = getKey(root->Left, level - 1, pos, counter);
    if (found != -1) return found;
    return getKey(root->Right, level - 1, pos, counter);
}
Tree* del(Tree* root, int level, int pos)
{
    int total = poisk(root, level);
    if (total == 0) { cout << "Уровень не существует." << endl; return root; }
    if (pos < 0 || pos >= total) { cout << "Позиция не существует." << endl; return root; }
    int counter = 0;
    int key = getKey(root, level, pos, &counter);
    return deleteNode(root, key);
}
int main()
{
    setlocale(0, "Russian");
    int key, choice;
    Tree* root = nullptr;
    char s[] = "Яцко";
    root = insert(root, s, 30);
    root = insert(root, s, 15);
    root = insert(root, s, 10);
    root = insert(root, s, 18);
    root = insert(root, s, 24);
    root = insert(root, s, 17);
    root = insert(root, s, 2);
    root = insert(root, s, 50);
    root = insert(root, s, 100);
    root = insert(root, s, 14);
    root = insert(root, s, 40);
    view(root, 0); cout << endl << endl << endl;
   

    cout << endl << endl;
    int lvl, pos;
    cout << "Введите уровень: "; cin >> lvl;
    cout << "Введите позицию: "; cin >> pos;
    root = del(root, lvl, pos);
    view(root, 0);

    return 0;
}