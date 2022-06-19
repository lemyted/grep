#include "./DocumentInfos.c"
#include "./StringManipulations.c"

typedef struct {
  char *content;
  DocumentInfos *infos;
} Document;

Document *createDocument() {
  return (Document*)malloc(sizeof(Document));
}

void deleteDocument(Document *doc) {
  free(doc->content);
  free(doc->infos);
  free(doc);
}

Document *getContentFromDocument(char *path, Document *doc) {
  DocumentInfos *infos = getDocumentInfos(path, createDocumentInfos());
  FILE *file = fopen(path, "r");
  doc->content = (char*)malloc(sizeof(char) * infos->numChars);
  int i = 0;

  while (1) {
    doc->content[(i++)] = fgetc(file);
    if (feof(file)) break;
  }

  fclose(file);
  doc->infos = infos;
  return doc;
}

void printfDocument(Document *doc, char *docName) {
  printf(
    "name: %s\nnum chars: %d\nnum lines: %d\ncontent:\n%s\n", 
    docName, 
    doc->infos->numChars, 
    doc->infos->numLines, 
    trimWhiteSpace(doc->content)
  );
}

void searchDocument(Document *doc, char *word) {
  int previousDocIndex = 0;
  for (int i = 0; i < doc->infos->numLines; i++) {
    char *line = getSegmentUntilElem(doc->content + previousDocIndex, '\n');
    if (strstr((const char*)line, (const char*)word)) {
      printf("%d - %s\n", i + 1, line);
    }
    previousDocIndex += strlen(line) + 1;
  }
}