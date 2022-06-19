char *trimWhiteSpace(char *str) {
  int i = 0, j = 0;

  while (*str != '\0' && isspace(*str)) ++str;

  while (str[i] != '\0') {
    if (!isspace(str[i])) j = i;
    ++i;
  }

  str[j] = '\0';
  return str;
}

char *getSegmentUntilElem(char *str, char elem) {
  int lengthStr = strlen(str);
  char c, *result = (char*)malloc(sizeof(char) * lengthStr);

  for (int i = 0; i < lengthStr; i++) {
    if ((c = str[i]) == elem || c == EOF) {
      result[i] = '\0';
      break;
    } 
    result[i] = str[i];
  }

  return result;  
}
