#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "src/Document.c"

#define MAX_CHARS (100)
#define MAX_LINES (1000)

int main (int argc, char* argv[]) {
  char *docName = argv[1];
  char *word = argv[2];
  Document *doc = getContentFromDocument(docName, createDocument());
  searchDocument(doc, word);
  deleteDocument(doc);
}