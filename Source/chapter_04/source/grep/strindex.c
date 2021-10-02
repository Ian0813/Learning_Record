/*  strindex : return index of t in s, -1 if none */

int strindex(char s[], char t[]){
	//printf("%s called, pattern : %s\n", __func__, t);
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++){
		
		for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++)
			;

		if(k > 0 && t[k] == '\0'){
			return i;
		}
	}
	
	return -1;
}
