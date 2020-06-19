//Question link
//https://www.hackerrank.com/challenges/structuring-the-document/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    doc.data = (struct paragraph*)malloc(1 * sizeof(struct paragraph));
    doc.paragraph_count = 0;

    doc.data[0].data = (struct sentence*)malloc(1 * sizeof(struct sentence));
    doc.data[0].sentence_count = 0;

    doc.data[0].data[0].data = (struct word*)malloc(1 * sizeof(struct word));
    doc.data[0].data[0].word_count = 0;

    doc.data[0].data[0].data[0].data = (char*)malloc(sizeof(char));

    int p = 0, s = 0, w = 0, c = 0;
    while(*text != '\0'){
        if(*text == ' ' || *text == '.'){
            doc.data[p].data[s].word_count = ++w;
            if(*text == '.'){
                doc.data[p].sentence_count = ++s;
                if(*(text+1) == '\n'){
                    doc.paragraph_count = ++p;
                    doc.data = (struct paragraph*)realloc(doc.data, (p+1) * sizeof(struct paragraph));
                    doc.data[p].data = (struct sentence*)malloc(1 * sizeof(struct sentence));
                    doc.data[p].sentence_count = s = 0;
                    text++;
                }
                doc.data[p].data = (struct sentence*)realloc(doc.data[p].data, (s+1)*sizeof(struct sentence));
                doc.data[p].data[s].data = (struct word*)malloc(1 * sizeof(struct word));
                doc.data[p].data[s].word_count = w = 0;
            }
            doc.data[p].data[s].data = (struct word*)realloc(doc.data[p].data[s].data, (w+1) * sizeof(struct word));
            doc.data[p].data[s].data[w].data = (char*)malloc(sizeof(char));
            c = 0;
        }
        else{
            doc.data[p].data[s].data[w].data = (char*)realloc(doc.data[p].data[s].data[w].data, (c+2)*sizeof(char));
            doc.data[p].data[s].data[w].data[c] = *text;
            doc.data[p].data[s].data[w].data[++c] = '\0';
        }
        text++;
    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    struct word w = Doc.data[n-1].data[m-1].data[k-1];
    return w;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    struct sentence sen = Doc.data[m-1].data[k-1];
    return sen;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    struct paragraph para = Doc.data[k-1];
    return para;
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}

/*
A document is represented as a collection paragraphs, a paragraph is represented as a collection of sentences, a sentence is represented as a collection of words and a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters. You will convert a raw text document into its component paragraphs, sentences and words. To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.

Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:

A word is described by:
struct word {
    char* data;
};
A sentence is described by:
struct sentence {
    struct word* data;
    int word_count;//the number of words in a sentence
};
The words in the sentence are separated by one space (" "). The last word does not end with a space.

A paragraph is described by:
struct paragraph {
    struct sentence* data  ;
    int sentence_count;//the number of sentences in a paragraph
};
The sentences in the paragraph are separated by one period (".").

A document is described by:
struct document {
    struct paragraph* data;
    int paragraph_count;//the number of paragraphs in a document
};
The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

For example:

Learning C is fun.
Learning pointers is more fun.It is good to have pointers.

The only sentence in the first paragraph could be represented as:
struct sentence first_sentence_in_first_paragraph;
first_sentence_in_first_paragraph.data = {"Learning", "C", "is", "fun"};
The first paragraph itself could be represented as:
struct paragraph first_paragraph;
first_paragraph.data = {{"Learning", "C", "is", "fun"}};
The first sentence in the second paragraph could be represented as:
struct sentence first_sentence_in_second_paragraph;
first_sentence_in_second_paragraph.data = {"Learning", "pointers", "is", "more", "fun"};
The second sentence in the second paragraph could be represented as:
struct sentence second_sentence_in_second_paragraph;
second_sentence_in_second_paragraph.data = {"It", "is", "good", "to", "have", "pointers"};
The second paragraph could be represented as:
struct paragraph second_paragraph;
second_paragraph.data = {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}};
Finally, the document could be represented as:
struct document Doc;
Doc.data = {{{"Learning", "C", "is", "fun"}}, {{"Learning", "pointers", "is", "more", "fun"}, {"It", "is", "good", "to", "have", "pointers"}}};
Alicia has sent a document to her friend Teodora as a string of characters, i.e. represented by  not . Help her convert the document to  form by completing the following functions:

 to intialise the document. You have to intialise the global variable  of type .
 to return the  paragraph in the document.
 to return the  sentence in the  paragraph.
 to return the  word in the  sentence of the  paragraph.
Input Format

The first line contains the integer .
Each of the next  lines contains a paragraph as a single string.
The next line contains the integer , the number of queries.
Each of the next  lines contains a query in one of the following formats:

: This corresponds to calling the function .
: This corresponds to calling the function .
: This corresponds to calling the function .
Constraints

The text which is passed to  has words separated by a spaces(" "), sentences separated by a period(".") and paragraphs separated by a newline("\n").
The last word in a sentence does not end with a space.
The last paragraph does not end with a newline.
The words contain only upper-case and lower-case English letters.
 number of characters in the entire document .
 number of paragraphs in the entire document .
Output Format

Print the paragraph, sentence or the word corresponding to the query to check the logic of your code.

Sample Input 0

2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2 1 1
3 1 1 1
Sample Output 0

Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning
Explanation 0

The first query returns the second paragraph.
The second query returns the first sentence of the first paragraph.
The third query returns the first word of the first sentence of the first paragraph.
*/