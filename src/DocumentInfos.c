typedef struct {
  int numChars;
  int numLines;
} DocumentInfos;

DocumentInfos *createDocumentInfos() {
  return (DocumentInfos*)malloc(sizeof(DocumentInfos));
}

void deleteDocumentInfos(DocumentInfos *docInfos) {
  free(docInfos);
}

DocumentInfos *getDocumentInfos(char *path, DocumentInfos *docInfos) {
  FILE *file = fopen(path, "r");
  int i = 0, l = 0;

  while (1) {
    char c = fgetc(file);
    if (feof(file)) {
      ++l;
      break;
    }  
    if (c == '\n') ++l;
    ++i;
  }

  fclose(file);
  docInfos->numChars = i;
  docInfos->numLines = l;
  return docInfos;
}