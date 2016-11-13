
int getContentInsideTag(char *output)
{
	char message[1000]="BUFF <HEAD> message content </HEAD> BUFF";
	
	
	char *tagName="HEAD";
	
	char l_headTag[MAX_TAG_SIZE], l_tailTag[MAX_TAG_SIZE];
	memset(l_headTag,0,sizeof(l_headTag));
	memset(l_tailTag,0,sizeof(l_tailTag));
	
	sprintf(l_headTag,"<%s>",tagName);
	sprintf(l_tailTag,"</%s>",tagName);
	

	
	char *l_headPos=strstr(message,l_headTag);
	
	if(NULL == l_headPos)
		return 0;
	
	
	char *l_tailPos=strstr(message,l_tailTag);
	
	if(NULL == l_tailPos)
		return 0;	
	
	int l_contentLength=(l_tailPos-l_headPos)+strlen(l_tailTag);
	
	strncpy(output,l_headPos,l_contentLength);
	
	output[l_contentLength]='\0';
	
	printf("OUTPUT %s",output);
}
