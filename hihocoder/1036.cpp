#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1000005
char buff[L];

struct trie_node{
    char ch;
    char is_end;
    struct trie_node *child;
    struct trie_node *sibling;
    struct trie_node *next;
};
struct trie_node *dict;

struct trie_node *new_node(char ch)
{
    struct trie_node *node = (struct trie_node *)malloc(sizeof(struct trie_node));
    node->ch = ch;
    node->is_end = 0;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

struct trie_node *find_sub(struct trie_node *root,char ch)
{
    struct trie_node *m;
    for (m = root->child;m != NULL && m->ch != ch;m = m->sibling);
    return m;
}

struct trie_node *insert_ch(char ch,struct trie_node *root)
{
    struct trie_node *m;
    m = find_sub(root,ch);
    if (m == NULL)
    {
        m = new_node(ch);
        m->sibling = root->child;
        root->child = m;
    }
    return m;
}

void freeall(struct trie_node *root)
{
    struct trie_node *p,*q;
    for (p = root->child;p;p = q)
    {
        q = p->sibling;
        free(p);
    }
    free(root);
}

void add_word(char *s)
{
    struct trie_node *m,*cur,*matched;
    if (*s == '\0') return;
    cur = insert_ch(*s++,dict);
    cur->next = dict;
    matched = dict;
    while (*s != '\0')
    {
        cur = insert_ch(*s++,cur);
        m = NULL;
        while (matched != dict && m == NULL)
        {
            m = find_sub(matched,cur->ch);
            if (m == NULL)  matched = matched->next;
        }
        if (m == NULL)  m = find_sub(matched,cur->ch);
        if (m != NULL && m->ch == cur->ch)  matched = m;
        cur->next = matched;
    }
    cur->is_end = 1;
}

void search(char *s)
{
    struct trie_node *matched,*m;
    char ch;
    matched = dict;
    while ((ch = *s++) != '\0')
    {
        m = NULL;
        while (matched != dict && m == NULL)
        {
            m = find_sub(matched,ch);
            if (m == NULL)  matched = matched->next;
        }
        if (m == NULL)  m = find_sub(matched,ch);
        if (m != NULL && m->ch == ch)
        {
            matched = m;
            if (m->is_end)
            {
                printf("YES\n");
                return;
            }
        }

    }
    printf("NO\n");
}

int main()
{
    int n;
    char *s;
    dict = new_node(0);
    scanf("%d",&n);
    s = buff;
    while (n-- > 0)
    {
        scanf("%s",s);
        add_word(s);
        s += strlen(s);
    }
    scanf("%s",buff);
    search(buff);
    freeall(dict);
    return 0;
}