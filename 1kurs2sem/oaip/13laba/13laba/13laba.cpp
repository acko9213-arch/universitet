#include <iostream>
using namespace std;

struct Tree {
    int key;
    char text[5];
    Tree* Left, * Right;
};

Tree* createEl(Tree* Root, char t[5], int key);

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

Tree* createEl(Tree*, char t[5], int key)
{
    Tree* now = new Tree;
    now->key = key;
    for (int i = 0; i < 5; i++)
        now->text[i] = t[i];
    now->Left = now->Right = nullptr;
    return now;
}

Tree* findkey(Tree* Root, int key)
{
    if (Root == nullptr) return nullptr;

    if (Root->key == key) return Root;
    else if (key < Root->key) return findkey(Root->Left, key);
    else return findkey(Root->Right, key);
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


int countRight(Tree* t)
{
    if (!t) return 0;
    return 1 + countRight(t->Left) + countRight(t->Right);
}

bool delAll(Tree* t)
{
    if (t) {
        delAll(t->Left);
        delAll(t->Right);
        delete t;
    }
    return true;
}

int main()
{
    setlocale(0, "Russian");
    int key, choice;
    Tree* root = nullptr;
    char s[5];

    for (;;)
    {
        cout << "\n1 - добавление элемента\n";
        cout << "2 - поиск по ключу\n";
        cout << "3 - удаление элемента\n";
        cout << "4 - вывод дерева\n";
        cout << "5 - кол-во узлов правого поддерева\n";
        cout << "6 - очистка дерева\n";
        cout << "7 - выход\n";
        cout << "ваш выбор?\n";

        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Введите слово (до 4 символов): ";
            cin >> s;
            root = insert(root, s, key);
            cout << "Добавлено\n";
            break;

        case 2:
        {
            cout << "Введите ключ: ";
            cin >> key;
            Tree* f = findkey(root, key);
            if (f) {
                cout << "Найдено: ";
                puts(f->text);
            }
            else cout << "Не найдено\n";
            break;
        }

        case 3:
            cout << "Введите ключ: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Удалено\n";
            break;

        case 4:
            if (!root) cout << "Дерево пустое\n";
            else view(root, 0);
            break;

        case 5:
            cout << "Узлов справа: " << countRight(root->Right) << endl;
            break;

        case 6:
            delAll(root);
            root = nullptr;
            cout << "Очищено\n";
            break;

        case 7:
            delAll(root);
            return 0;

        default:
            cout << "Ошибка\n";
        }
    }
}