int getContentInsideTag(char *input,char *output,char *tagName)
{
	char l_headTag[MAX_TAG_SIZE], l_tailTag[MAX_TAG_SIZE];
	memset(l_headTag,0,sizeof(l_headTag));
	memset(l_tailTag,0,sizeof(l_tailTag));
	
	sprintf(l_headTag,"<%s>",tagName);
	sprintf(l_tailTag,"</%s>",tagName);
	

	
	char *l_headPos=strstr(input,l_headTag);
	
	if(NULL == l_headPos)
		return 0;
	
	
	char *l_tailPos=strstr(input,l_tailTag);
	
	if(NULL == l_tailPos)
		return 0;	
	
	int l_contentLength=(l_tailPos-l_headPos)-strlen(l_tailTag)+1;
	
	char *copyPos=l_headPos+strlen(l_headTag);
	
	strncpy(output,copyPos,l_contentLength);
	
	output[l_contentLength]='\0';	
	
	return 1;
}
